#include "requestinfo.h"

RequestInfo::RequestInfo(CalculatorOperationsLib::TypesOperation typeOperation,
              double leftOperand, double rightOperand, int timeOperation) :  RequestTimeInfo(typeOperation, timeOperation),
               leftOperand(leftOperand), rightOperand(rightOperand)
{
}


double RequestInfo::GetleftOperand()
{
    return leftOperand;
}

double RequestInfo::GetRightOperand()
{
    return rightOperand;
}

CalculatorOperationsLib::TypesOperation RequestInfo::GetTypeOperation()
{
    return currentOperation;
}

int RequestInfo::GetOperationTime()
{
    return currentOperationTime;
}
