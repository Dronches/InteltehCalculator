#ifndef RESULTINFO_H
#define RESULTINFO_H

#include "requestinfo.h"
#include "calculatoroperationslib.h"


/*!
 * \brief Класс хранения операции и её результата с ошибкой (при наличии)
 */
class ResultInfo
{
    /// Содержание информации операции
    RequestInfo* requestInfo;
    /// Результат операции
    double result;
    /// Тип ошибки (при наличии)
    CalculatorOperationsLib::TypesComputationErrors computationError;
public:

    ResultInfo(RequestInfo* requestInfo,
               CalculatorOperationsLib::TypesComputationErrors computationError);

    ResultInfo(RequestInfo* requestInfo,
               CalculatorOperationsLib::TypesComputationErrors computationError,
               double result);

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
