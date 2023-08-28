#ifndef REQUESTTIMEINFO_H
#define REQUESTTIMEINFO_H

#include <QObject>
#include <calculatoroperationslib.h>

/*!
 * \brief Класс, организующий сохранение операции и текущего времени операции
 */
class RequestTimeInfo
{
protected:

    /// Текущий тип операции
    CalculatorOperationsLib::TypesOperation currentOperation;
    /// Текущее врема операции (в секундах)
    int currentOperationTime;


public:

    RequestTimeInfo();

    RequestTimeInfo(CalculatorOperationsLib::TypesOperation operation, int operationTime);

    virtual ~RequestTimeInfo();


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

#endif // REQUESTTIMEINFO_H
