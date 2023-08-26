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
        NoError = 0,
        UnknownError= 1,
        DigitOverflow = 2
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
