#ifndef VERIFYINFO_MAINWINDOW_H
#define VERIFYINFO_MAINWINDOW_H

#include <QObject>

class VerifyInfo_MainWindow : public QObject
{
    Q_OBJECT

    static const uchar MaxInputLength;
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
