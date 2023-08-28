#ifndef CALCULATOROPERATIONSLIB_H
#define CALCULATOROPERATIONSLIB_H

#include "CalculatorOperationsLib_global.h"
#include <QMap>

/*!
 * \brief Бибилиотека, операделяющая функции выполнения операций
 */
class CALCULATOROPERATIONSLIB_EXPORT CalculatorOperationsLib
{

public:
    CalculatorOperationsLib();

    /// Перечислитель типов операции
    enum TypesOperation
    {
        None = 0, // < Отсутсвие операции
        Plus = 1, // < Сложение
        Mines = 2, // < Вычитание
        Multiplicaion = 3, // < Умножение
        Division = 4 // < Деление
    };

    /// Перечислитель типов ошибок вычислений
    /// (предполагается, что переполнение невозможно с помощью ограничения ввода UI)
    enum TypesComputationErrors
    {
        NoComputationError = 0, // < отсутсвие ошибки
        UnknownComputationError = 1, // < неизвестная ошибка
        UnknownOperationError = 2, // < неизвестная операция
        DivisionByZero = 3 // < деление на 0
    };

    /*!
     * \brief Функция выполнения арифметической операции
     * \param TypeWork тип операции
     * \param OperandA левый операнд
     * \param OperandB правый операнд
     * \param ErrorCode код ошибки (при отсутствии ошибки - 0)
     * \return результат выполнения операции (если есть)
     */
    static double dolt(TypesOperation TypeWork, double OperandA, double OperandB, TypesComputationErrors* ErrorCode);

    /*!
     * \brief Получить содержание ошибки по типу ошибки
     * \param typeError тип ошибки
     * \return Содержание ошибки
     */
    static QString GetOperationErrorMessage(TypesComputationErrors typeError);


    /*!
     * \brief Получить значок (или строку) операции по типу операции
     * \param typeOperation тип операции
     * \return Символ (или строка), обозначающая операцию
     */
    static QString GetOperationTypeSign(TypesOperation typeOperation);
private:
    /// Словарь соответсвия ошибок и их текстовых значений
    static const QMap<TypesComputationErrors, QString> errorsComputationMap;

    /// Словарь соответсвия операций и их символов
    static const QMap<TypesOperation, QString> typesOperationMap;

};

#endif // CALCULATOROPERATIONSLIB_H
