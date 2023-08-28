#include "resultinfo.h"


ResultInfo::ResultInfo(OperationInfo* operationInfo,
           CalculatorOperationsLib::TypesComputationErrors computationError) :
                ResultInfo(operationInfo, computationError, 0)
{

}

ResultInfo::ResultInfo(OperationInfo* operationInfo,
                       CalculatorOperationsLib::TypesComputationErrors computationError,
                       double result)
{
    this->operationInfo = operationInfo;
    this->computationError = computationError;
    this->result = result;
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

