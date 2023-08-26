#include "errorsspecifier_mainwindow.h"

const QMap<ErrorsSpecifier_MainWindow::MainWindow_Errors, QString> ErrorsSpecifier_MainWindow::errorsMap
{
    {NoError, "Нет ошибки"},
    {UnknownError, "Неизвестная ошибка"},
    {DigitOverflow, "Переполнение области числового ввода"},
    {CommaExists, "Разделитель уже введён"},
    {AlreadyClearedCalculator, "Область калькулятора уже очищена"},
    {NotExistToDeleteCalculator, "Нет символов для удаления"},
    {RepeatOperation, "Операция уже применена"}
};

ErrorsSpecifier_MainWindow::ErrorsSpecifier_MainWindow()
{

}

QString ErrorsSpecifier_MainWindow::getErrorMessage(MainWindow_Errors typeError)
{
    return errorsMap[typeError];
}
