#ifndef REQUESTINFO_H
#define REQUESTINFO_H

#include "calculatoroperationslib.h"
#include "requesttimeinfo.h"

/*!
 * \brief Класс хранения информации об операции
 */
class RequestInfo : protected RequestTimeInfo
{
    double leftOperand; /// < левый операнд
    double rightOperand; /// < правый операнд

public:

    RequestInfo(CalculatorOperationsLib::TypesOperation typeOperation,
                  double leftOperand, double rightOperand, int timeWork);

    /*!
     * \brief Получить тип операции
     * \return тип операции
     */
    CalculatorOperationsLib::TypesOperation GetTypeOperation();

    /*!
     * \brief Получить левый операнд
     * \return левый операнд
     */
    double GetleftOperand();

    /*!
     * \brief Получить правый операнд
     * \return правый операнд
     */
    double GetRightOperand();

    /*!
     * \brief Получить время операции
     * \return время операции
     */
    int GetOperationTime();


};

#endif // REQUESTINFO_H
