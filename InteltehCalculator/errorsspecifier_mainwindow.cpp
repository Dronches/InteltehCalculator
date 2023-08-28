#include "errorsspecifier_mainwindow.h"

const QMap<ErrorsSpecifier_MainWindow::MainWindow_Errors, QString> ErrorsSpecifier_MainWindow::errorsMap
{
    {NoError, "Нет ошибки"},
    {UnknownError, "Неизвестная ошибка"},
    {DigitOverflow, "Переполнение области числового ввода"},
    {CommaExists, "Разделитель уже введён"},
    {AlreadyClearedCalculator, "Область калькулятора уже очищена"},
    {NotExistToDeleteCalculator, "Нет символов для удаления"},
    {RepeatOperation, "Операция уже применена"},
    {AlreadyExistNotTimeOperation, "Невозможно изменить время, т.к. выбрана другая операция"},
    {TimeIsNotInt, "Время операции должно быть целочисленным"},
    {TimeIsNegative, "Время операции не может быть отрицательным"},
    {TimeOperationOverflow, "Время операции в секундах не может превышать максимальное значение"},
    {CantAddMinesToZero, "Число 0 не является отрицательным"},
    {NotSelectedOperation, "Операция не выбрана"}
};

ErrorsSpecifier_MainWindow::ErrorsSpecifier_MainWindow()
{

}

QString ErrorsSpecifier_MainWindow::getErrorMessage(MainWindow_Errors typeError)
{
    return errorsMap[typeError];
}
