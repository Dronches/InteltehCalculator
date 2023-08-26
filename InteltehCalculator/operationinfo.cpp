#include "operationinfo.h"

OperationInfo::OperationInfo(CalculatorOperationsLib::TypesOperation typeOperation,
              double leftOperand, double rightOperand, int timeWork) :
                typeOperation(typeOperation), leftOperand(leftOperand),
                rightOperand(rightOperand), timeWork(timeWork)
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
    return typeOperation;
}

int OperationInfo::GetTimeWork()
{
    return timeWork;
}
