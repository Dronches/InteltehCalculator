#include "verifyinfo_mainwindow.h"

const uchar VerifyInfo_MainWindow::maxInputLength = (uchar)48;

const char VerifyInfo_MainWindow::firstSymbol = '0';

const char VerifyInfo_MainWindow::commaSymbol = ',';

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
