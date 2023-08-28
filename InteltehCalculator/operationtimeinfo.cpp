#include "operationtimeinfo.h"

OperationTimeInfo::OperationTimeInfo()
{
    // инициализация базовыми значениями по умолчанию
    currentOperation=CalculatorOperationsLib::TypesOperation::None;
    currentOperationTime = 0;
}


OperationTimeInfo::OperationTimeInfo(CalculatorOperationsLib::TypesOperation operation, int operationTime)
{
    currentOperation = operation;
    currentOperationTime = operationTime;
}


OperationTimeInfo::~OperationTimeInfo()
{
}


CalculatorOperationsLib::TypesOperation OperationTimeInfo::GetCurrentOperation()
{
    return currentOperation;
}

int OperationTimeInfo::GetCurrentOperationTime()
{
    return currentOperationTime;
}


void OperationTimeInfo::SetCurrentOperation(CalculatorOperationsLib::TypesOperation operation)
{
    this->currentOperation = operation;
}

void OperationTimeInfo::SetCurrentOperationTime(int time)
{
    this->currentOperationTime = time;
}
