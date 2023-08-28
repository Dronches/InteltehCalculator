#ifndef COLLECTIONSCONTAINER_H
#define COLLECTIONSCONTAINER_H

#include <QObject>
#include "templatecollection.h"
#include "operationinfo.h"
#include "resultinfo.h"
#include "calculatoroperationslib.h"

/*!
 * \brief Класс контенер очередей операций и результата
 * с возможностью посылать сигналы об изменениях размеров очередей
 */
class CollectionsContainer : public QObject
{
    Q_OBJECT

    /// очередь операций
    TemplateCollection<OperationInfo> operationQueue;
    /// очередь результатов
    TemplateCollection<ResultInfo> resultQueue;

public:
    explicit CollectionsContainer(QObject *parent = nullptr);

    /*!
     * \brief Добавление операции в rjytw очереди операций
     * \param operation тип операции
     * \param leftOperand левый операнд
     * \param rightOperand правый операнд
     * \param timeWork время выполнения операции
     */
    void PushOperation(CalculatorOperationsLib::TypesOperation operation,
                       double leftOperand, double rightOperand, int timeWork);

    /*!
     * \brief Извлечение операции из начала (без удаления объекта)
     * \return Указатель на данные по операции (nullptr при отсутствии операций в очереди)
     */
    OperationInfo* PopOperation();

    /*!
     * \brief Добавление операции с вычисленным результатом в очередь операций
     * \param operationInfo Указатель на даннные по операции
     * \param typeComputationError тип ошибки вычисления
     * \param result значение результата (при наличии)
     */
    void PushResult(OperationInfo* operationInfo,
                    CalculatorOperationsLib::TypesComputationErrors typeComputationError,
                    double result);

    /*!
     * \brief Извлечь результат операции в виде строки с удалением объекта
     * \param computationError Указатель на ошибку операции (для возможности анализа на наличие ошибки)
     * \return Строка результата вычисления (при отсутствии эл-тов в очереди - пустая строка)
     */
    QString PopResult(CalculatorOperationsLib::TypesComputationErrors* computationError);


signals:
    /*!
     * \brief Сигнал изменения количества операций в очереди
     * \param currentCountOperations Новое количество операций
     */
    void ChangeSizeOperationQueueSignal(int currentCountOperations);

    /*!
     * \brief Сигнал изменения количества результатов в очереди
     * \param currentCountResults Новое количество результатов
     */
    void ChangeSizeResultQueueSignal(int currentCountResults);
};

#endif // COLLECTIONSCONTAINER_H
