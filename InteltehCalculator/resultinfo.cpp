#include "resultinfo.h"

ResultInfo::ResultInfo(OperationInfo* operationInfo, double result,
                       CalculatorOperationsLib::TypesComputationErrors computationError)
{
    this->operationInfo = operationInfo;
    this->result = result;
    this->computationError = computationError;
}

ResultInfo::~ResultInfo()
{
    delete operationInfo;
}

void ResultInfo::SetResult(double result)
{
    this->result = result;
}

void ResultInfo::SetComputationError(CalculatorOperationsLib::TypesComputationErrors typeComputationError)
{
    this->computationError = typeComputationError;
}

CalculatorOperationsLib::TypesComputationErrors ResultInfo::GetComputationError()
{
    return computationError;
}

QString ResultInfo::GetComputationErrorString()
{
    return CalculatorOperationsLib::GetOperationErrorMessage(computationError);
}

QString ResultInfo::GetResult()
{
    return QString::number(operationInfo->GetleftOperand(), 'f')+
            CalculatorOperationsLib::GetOperationTypeSign(operationInfo->GetTypeOperation())+
            QString::number(operationInfo->GetRightOperand(), 'f')+
            "="+
            ((computationError==CalculatorOperationsLib::TypesComputationErrors::NoComputationError)?
                 QString::number(result, 'f') :
                 GetComputationErrorString());
}

