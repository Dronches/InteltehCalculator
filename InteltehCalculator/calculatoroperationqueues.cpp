#include "calculatoroperationqueues.h"

CalculatorOperationQueues::CalculatorOperationQueues(QObject *parent) : QObject(parent)
{
    // инициаилазция базовыми значениями по умолчанию
    currentOperation=CalculatorOperationsLib::TypesOperation::None;
    currentOperationTime = 0;
}


CalculatorOperationsLib::TypesOperation CalculatorOperationQueues::GetCurrentOperation()
{
    return currentOperation;
}

int CalculatorOperationQueues::GetCurrentOperationTime()
{
    return currentOperation;
}


void CalculatorOperationQueues::SetCurrentOperation(CalculatorOperationsLib::TypesOperation operation)
{
    this->currentOperation = operation;
}

void CalculatorOperationQueues::SetCurrentOperationTime(int time)
{
    this->currentOperationTime = time;
}
