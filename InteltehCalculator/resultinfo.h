#ifndef RESULTINFO_H
#define RESULTINFO_H

#include "operationinfo.h"
#include "calculatoroperationslib.h"


/*!
 * \brief Класс хранения операции и её результата с ошибкой (при наличии)
 */
class ResultInfo
{
    /// Содержание информации операции
    OperationInfo* operationInfo;
    /// Результат операции
    double result;
    /// Тип ошибки (при наличии)
    CalculatorOperationsLib::TypesComputationErrors computationError;
public:

    ResultInfo(OperationInfo* operationInfo, double result,
               CalculatorOperationsLib::TypesComputationErrors typeComputationError);

    ~ResultInfo();

    /*!
     * \brief Записать результат
     * \param result записываемы результат
     */
    void SetResult(double result);

    /*!
     * \brief Записать ошибку вычисления
     * \param typeComputationError ошибка вычисления
     */
    void SetComputationError(CalculatorOperationsLib::TypesComputationErrors computationError);

    /*!
     * \brief Получить ошибку вычисления
     * \return ошибка вычисления
     */
    CalculatorOperationsLib::TypesComputationErrors GetComputationError();

    /*!
     * \brief Получить содержание ошибки
     * \return Содержание ошибки
     */
    QString GetComputationErrorString();

    /*!
     * \brief Получить результат
     * \return результат
     */
    QString GetResult();


};

#endif // RESULTINFO_H
