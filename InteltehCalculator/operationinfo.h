#ifndef OPERATIONINFO_H
#define OPERATIONINFO_H

#include "calculatoroperationslib.h"

/*!
 * \brief Класс хранения информации об операции
 */
class OperationInfo
{
    CalculatorOperationsLib::TypesOperation typeOperation; /// < тип операции
    double leftOperand; /// < левый операнд
    double rightOperand; /// < правый операнд
    int timeWork; /// < время операции

public:

    OperationInfo(CalculatorOperationsLib::TypesOperation typeOperation,
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
    int GetTimeWork();


};

#endif // OPERATIONINFO_H
