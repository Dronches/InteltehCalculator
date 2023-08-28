#include "calculatoroperationslib.h"

const QMap<CalculatorOperationsLib::TypesComputationErrors, QString> CalculatorOperationsLib::errorsComputationMap
{
    {NoComputationError, "Ошибка вычислений отсутствует"},
    {UnknownComputationError, "Неизвестная ошибка вычисления"},
    {UnknownOperationError, "Неизвестная операция"},
    {DivisionByZero, "Ошибка деления на 0"}
};


CalculatorOperationsLib::CalculatorOperationsLib()
{

}

double CalculatorOperationsLib::dolt(TypesOperation TypeWork, double OperandA, double OperandB, TypesComputationErrors* ErrorCode)
{
    * ErrorCode = NoComputationError;

   // выполнение операции в зависимости от её типа
   switch(TypeWork)
   {
        case CalculatorOperationsLib::TypesOperation::Mines:
            try
            {
                return OperandA-OperandB;
            }
            catch(...)
            {
                *ErrorCode = TypesComputationErrors::UnknownComputationError;
                return 0;
            }
            break;
       case CalculatorOperationsLib::TypesOperation::Plus:
           try
           {
               return OperandA+OperandB;
           }
           catch(...)
           {
               *ErrorCode = TypesComputationErrors::UnknownComputationError;
               return 0;
           }
           break;
       case CalculatorOperationsLib::TypesOperation::Multiplicaion:
           try
           {
               return OperandA*OperandB;
           }
           catch(...)
           {
               *ErrorCode = TypesComputationErrors::UnknownComputationError;
               return 0;
           }
           break;
       case CalculatorOperationsLib::TypesOperation::Division:
           try
           {
               // обработка ошибки деления на 0
               if (OperandB == 0)
               {
                   *ErrorCode  = DivisionByZero;
                   return 0;
               }
               return OperandA/OperandB;
           }
           catch(...)
           {
               *ErrorCode = TypesComputationErrors::UnknownComputationError;
               return 0;
           }
           break;
        default:
            *ErrorCode = TypesComputationErrors::UnknownOperationError;
            return 0;
   }
}

QString CalculatorOperationsLib::GetOperationErrorMessage(TypesComputationErrors typeError)
{
    return errorsComputationMap[typeError];
}
