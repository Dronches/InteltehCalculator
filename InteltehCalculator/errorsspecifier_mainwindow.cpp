#include "errorsspecifier_mainwindow.h"

const QMap<ErrorsSpecifier_MainWindow::MainWindow_Errors, QString> ErrorsSpecifier_MainWindow::errorsMap
{
    {NoError, "Нет ошибки"},
    {UnknownError, "Неизвестная ошибка"},
    {DigitOverflow, "Переполнение области числового ввода"}
};

ErrorsSpecifier_MainWindow::ErrorsSpecifier_MainWindow()
{

}

QString ErrorsSpecifier_MainWindow::getErrorMessage(MainWindow_Errors typeError)
{
    return errorsMap[typeError];
}
