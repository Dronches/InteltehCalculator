#include "operationinfo.h"

OperationInfo::OperationInfo(CalculatorOperationsLib::TypesOperation typeOperation,
              double leftOperand, double rightOperand, int timeOperation) :  OperationTimeInfo(typeOperation, timeOperation),
               leftOperand(leftOperand), rightOperand(rightOperand)
{
}


double OperationInfo::GetleftOperand()
{
    return leftOperand;
}

double OperationInfo::GetRightOperand()
{
    return leftOperand;
}

CalculatorOperationsLib::TypesOperation OperationInfo::GetTypeOperation()
{
    return currentOperation;
}

int OperationInfo::GetOperationTime()
{
    return currentOperationTime;
}
