#ifndef ERRORSSPECIFIER_MAINWINDOW_H
#define ERRORSSPECIFIER_MAINWINDOW_H

#include <QString>
#include <QMap>

/*!
 * \brief Класс, определяющий ошибки main window
 * хранит ошибки и позволяет получить их содержание
 * (не Exception формат)
 */
class ErrorsSpecifier_MainWindow
{

public:
    /// Перечислитель видов ошибок ввода MainWindow
    enum MainWindow_Errors
    {
        NoError = 0, // < ошибка отсутствует
        UnknownError= 1, // < неизвестная ошибка
        DigitOverflow = 2, // < переполнение по ограничению кол-ва чисел
        CommaExists = 3, // < наличие в числе запятой (при повторном вводе запятой)
        AlreadyClearedCalculator = 4, // < калькулятор уже очищен
        NotExistToDeleteCalculator = 5, // < нет символов для удаления
        RepeatOperation = 6, // < ошибка повтора ввода операции
        AlreadyExistNotTimeOperation = 7, // < уже существует операция не времени
        TimeIsNotInt = 8, // < время не целочисленное
        TimeIsNegative = 9, // < время отрицательное
        TimeOperationOverflow = 10, // < переполнение максимального времени операции
        CantAddMinesToZero = 11, // < невозможность применить отрицательность к 0
        NotSelectedOperation = 12 // < операция не выбрана
    };

    ErrorsSpecifier_MainWindow();

    /*!
     * \brief Получить содержание ошибки по её типу
     * \param typeError вид ошибки по enum MainWindow_Errors
     * \return содержние ошибки
     */
    static QString getErrorMessage(MainWindow_Errors typeError);

private:

    /// Словарь, позволяющий соотносить вид ошибки и её содержание
    static const QMap<MainWindow_Errors, QString> errorsMap;
};

#endif // ERRORSSPECIFIER_MAINWINDOW_H
