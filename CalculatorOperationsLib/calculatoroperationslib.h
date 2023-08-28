#ifndef CALCULATOROPERATIONSLIB_H
#define CALCULATOROPERATIONSLIB_H

#include "CalculatorOperationsLib_global.h"

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



};

#endif // CALCULATOROPERATIONSLIB_H
