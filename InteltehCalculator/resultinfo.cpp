#include "resultinfo.h"


ResultInfo::ResultInfo(RequestInfo* requestInfo,
           CalculatorOperationsLib::TypesComputationErrors computationError) :
                ResultInfo(requestInfo, computationError, 0)
{

}

ResultInfo::ResultInfo(RequestInfo* requestInfo,
                       CalculatorOperationsLib::TypesComputationErrors computationError,
                       double result)
{
    this->requestInfo = requestInfo;
    this->computationError = computationError;
    this->result = result;
}

ResultInfo::~ResultInfo()
{
    delete requestInfo;
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
    return "(" + QString::number(requestInfo->GetleftOperand(), 'f')+ ")" +
            CalculatorOperationsLib::GetOperationTypeSign(requestInfo->GetTypeOperation()) +
            "(" + QString::number(requestInfo->GetRightOperand(), 'f') + ")" +
            "="+
            ((computationError==CalculatorOperationsLib::TypesComputationErrors::NoComputationError)?
                 QString::number(result, 'f') :
                 GetComputationErrorString());
}

