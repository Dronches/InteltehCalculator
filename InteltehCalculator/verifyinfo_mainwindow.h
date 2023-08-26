#ifndef VERIFYINFO_MAINWINDOW_H
#define VERIFYINFO_MAINWINDOW_H

#include <QObject>

/*!
 * \brief Класс, предоставляющий интерфейс проверок ввода главного окна
 * Предполагается, что в дальнейшем может давать сигналы на главное окно
 * для последующей обработки.
 */
class VerifyInfo_MainWindow : public QObject
{
    Q_OBJECT

    /// Ограничение максимального размера ввода
    static const uchar MaxInputLength;
    /// Символ по умолчанию
    static const char FirstSymbol;

public:
    explicit VerifyInfo_MainWindow(QObject *parent = nullptr);

    /*!
     * \brief Получить символ, который введён как символ по умолчанию
     * \return Символ по умолчанию
     */
    static char getFirstSymbol();

    /*!
     * \brief Проверка ввода числа
     * \param currentOperand главная строка ввода (текущий операнд)
     * \return результат проверки
     */
    static bool VerifyInput_Digits(const QString &currentOperand);

signals:

};


#endif // VERIFYINFO_MAINWINDOW_H
