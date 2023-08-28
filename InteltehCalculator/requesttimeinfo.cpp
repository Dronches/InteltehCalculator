#include "requesttimeinfo.h"

RequestTimeInfo::RequestTimeInfo()
{
    // инициализация базовыми значениями по умолчанию
    currentOperation=CalculatorOperationsLib::TypesOperation::None;
    currentOperationTime = 0;
}


RequestTimeInfo::RequestTimeInfo(CalculatorOperationsLib::TypesOperation operation, int operationTime)
{
    currentOperation = operation;
    currentOperationTime = operationTime;
}


RequestTimeInfo::~RequestTimeInfo()
{
}


CalculatorOperationsLib::TypesOperation RequestTimeInfo::GetCurrentOperation()
{
    return currentOperation;
}

int RequestTimeInfo::GetCurrentOperationTime()
{
    return currentOperationTime;
}


void RequestTimeInfo::SetCurrentOperation(CalculatorOperationsLib::TypesOperation operation)
{
    this->currentOperation = operation;
}

void RequestTimeInfo::SetCurrentOperationTime(int time)
{
    this->currentOperationTime = time;
}
