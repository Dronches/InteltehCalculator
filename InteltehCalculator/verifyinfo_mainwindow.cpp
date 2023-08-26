#include "verifyinfo_mainwindow.h"

const uchar VerifyInfo_MainWindow::maxInputLength = (uchar)48;

const char VerifyInfo_MainWindow::firstSymbol = '0';

const char VerifyInfo_MainWindow::commaSymbol = ',';

const char VerifyInfo_MainWindow::minusSymbol = '-';

const int VerifyInfo_MainWindow::maxTimeOperation = 100;

VerifyInfo_MainWindow::VerifyInfo_MainWindow(QObject *parent) : QObject(parent)
{

}

bool VerifyInfo_MainWindow::VerifyInput_DigitsNotOverflow(const QString &currentOperand)
{
    // проверка на неотрицательность с проверкой размера (знак '-' в подсчёте не учитывается)
    return (VerifyInput_NotNegativeDigit(currentOperand)? currentOperand.length()<maxInputLength : currentOperand.length()<maxInputLength+1) ;
}

bool VerifyInfo_MainWindow::VerifyInput_CommaNotExist(const QString &currentOperand)
{
    return !currentOperand.contains(commaSymbol);
}

bool VerifyInfo_MainWindow::VerifyInput_NotClearedCalculator(const QString &currentOperand, const QString &previousOperand, const QString &operation)
{
    return !(currentOperand == firstSymbol && previousOperand == "" && operation == "");
}

bool VerifyInfo_MainWindow::VerifyInput_ExistsSymbolsToDelete(const QString &currentOperand)
{
    return !(currentOperand == firstSymbol);
}

bool VerifyInfo_MainWindow::VerifyInput_NotNegativeDigit(const QString &currentOperand)
{
    return !currentOperand.contains(minusSymbol);
}

bool VerifyInfo_MainWindow::VerifyInput_MaxTimeOperation(const int& timeOperation)
{
    return timeOperation<=maxTimeOperation;
}

