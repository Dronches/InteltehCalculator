#include "verifyinfo_mainwindow.h"

const uchar VerifyInfo_MainWindow::MaxInputLength = (uchar)48;

const char VerifyInfo_MainWindow::FirstSymbol = '0';

VerifyInfo_MainWindow::VerifyInfo_MainWindow(QObject *parent) : QObject(parent)
{

}

char VerifyInfo_MainWindow::getFirstSymbol()
{
    return FirstSymbol;
}

bool VerifyInfo_MainWindow::VerifyInput_Digits(const QString &currentOperand)
{
    return (currentOperand.length()<MaxInputLength);
}
