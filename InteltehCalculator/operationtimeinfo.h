#ifndef OPERATIONTIMEINFO_H
#define OPERATIONTIMEINFO_H

#include <QObject>
#include <calculatoroperationslib.h>

/*!
 * \brief Класс, организующий сохранение операции и текущего времени операции
 */
class OperationTimeInfo
{

    /// Текущий тип операции
    CalculatorOperationsLib::TypesOperation currentOperation;
    /// Текущее врема операции (в секундах)
    int currentOperationTime;


public:

    OperationTimeInfo();

    OperationTimeInfo(CalculatorOperationsLib::TypesOperation operation, int operationTime);

    /*!
     * \brief Получить значение текущей операции
     * \return Значение текущей операции
     */
    CalculatorOperationsLib::TypesOperation GetCurrentOperation();

    /*!
     * \brief Получить значение текущего времени операции
     * \return Значение текущего времени операции
     */
    int GetCurrentOperationTime();

    /*!
     * \brief Установить значение текущей операции
     * \param operation операция
     */
    void SetCurrentOperation(CalculatorOperationsLib::TypesOperation operation);

    /*!
     * \brief Установить значение текущего времени операции
     * \param time время операция
     */
    void SetCurrentOperationTime(int time);

};

#endif // OPERATIONTIMEINFO_H
