#include "verifyinfo_mainwindow.h"

const uchar VerifyInfo_MainWindow::maxInputLength = (uchar)48;

const char VerifyInfo_MainWindow::firstSymbol = '0';

const char VerifyInfo_MainWindow::commaSymbol = ',';

const char VerifyInfo_MainWindow::minusSymbol = '-';

VerifyInfo_MainWindow::VerifyInfo_MainWindow(QObject *parent) : QObject(parent)
{

}

bool VerifyInfo_MainWindow::VerifyInput_DigitsNotOverflow(const QString &currentOperand)
{
    return (currentOperand.length()<maxInputLength);
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
