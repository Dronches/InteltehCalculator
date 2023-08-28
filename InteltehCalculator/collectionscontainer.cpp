#include "collectionscontainer.h"

CollectionsContainer::CollectionsContainer(QObject *parent) : QObject(parent)
{

}

void CollectionsContainer::PushRequest(CalculatorOperationsLib::TypesOperation operation, double leftOperand, double rightOperand, int timeWork)
{
    RequestInfo* info = new RequestInfo(operation, leftOperand, rightOperand, timeWork);

    // Потокобезопасное добавление операции в конец очереди
    requestQueue.Wait_for_lock();
    requestQueue.PushBack(info);
    // Сигнал изменения количества операций в очереди
    emit ChangeSizeOperationQueueSignal(requestQueue.GetSize());
    requestQueue.Unlock();
}

/*!
 * \brief Извлечение операции из начала (без удаления объекта)
 * \return Указатель на данные по операции (nullptr при отсутствии операций в очереди)
 */
RequestInfo* CollectionsContainer::PopRequest()
{
    RequestInfo* info = nullptr;
    // Потокобезопасное извлечение операции
    requestQueue.Wait_for_lock();
    if (requestQueue.GetSize()!=0)    // Проверка на наличие операции в очереди
        info = requestQueue.PopFront();
    // Сигнал изменения количества операций в очереди
    emit ChangeSizeOperationQueueSignal(requestQueue.GetSize());
    requestQueue.Unlock();
    return info;
}



/*!
 * \brief Добавление операции с вычисленным результатом в очередь операций
 * \param operationInfo Указатель на даннные по операции
 * \param typeComputationError тип ошибки вычисления
 * \param result значение результата (при наличии)
 */
void CollectionsContainer::PushResult(RequestInfo* requestInfo,
                CalculatorOperationsLib::TypesComputationErrors typeComputationError,
                double result = 0)
{
    ResultInfo* resInfo = new ResultInfo(requestInfo, typeComputationError, result);
    // Потокобезопасное добавление операции и её результата в очередь результатов
    resultQueue.Wait_for_lock();
    resultQueue.PushBack(resInfo);
    // Сигнал изменения количества результатов в очереди
    emit ChangeSizeResultQueueSignal(resultQueue.GetSize());
    resultQueue.Unlock();
}

/*!
 * \brief Извлечь результат операции в виде строки с удалением объекта
 * \param computationError Указатель на ошибку операции (для возможности анализа на наличие ошибки)
 * \return Строка результата вычисления (при отсутствии эл-тов в очереди - пустая строка)
 */
QString CollectionsContainer::PopResult(CalculatorOperationsLib::TypesComputationErrors* computationError)
{
    // Потокобезопасное извлечение результата
    resultQueue.Wait_for_lock();
    if (resultQueue.GetSize()==0) // Проверка наличия элементов в очереди
    {
        // При отсутствии элементов возврат пустой строки в качестве результата
        *computationError = CalculatorOperationsLib::TypesComputationErrors::NoComputationError;
        resultQueue.Unlock();
        return "";
    }
    ResultInfo* resInfo = resultQueue.PopFront();
    // Сигнал изменения количества результатов в очереди
    emit ChangeSizeResultQueueSignal(resultQueue.GetSize());
    resultQueue.Unlock();

    // Получение результата и ошибки
    QString resString = resInfo->GetResult();
    *computationError = resInfo->GetComputationError();
    // Освобождение данных результата
    delete resInfo;
    // Возврат строки результата вычисления
    return resString;
}
