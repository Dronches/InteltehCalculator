#ifndef CALCULATOROPERATIONSLIB_H
#define CALCULATOROPERATIONSLIB_H

#include "CalculatorOperationsLib_global.h"

class CALCULATOROPERATIONSLIB_EXPORT CalculatorOperationsLib
{
public:
    CalculatorOperationsLib();

    enum TypesOperation
    {
        None = 0,
        Plus = 1,
        Mines = 2,
        Multiplicaion = 3,
        Division = 4
    };

};

#endif // CALCULATOROPERATIONSLIB_H
