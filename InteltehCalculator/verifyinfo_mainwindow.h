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

public:
    /// Символ по умолчанию
    static const char firstSymbol;
    /// Символ, используемый в качестве разделителя дробной части
    static const char commaSymbol;
    /// Символ отрицательного числа
    static const char minusSymbol;
    /// Максимальное принятое время операции (во избежание болей ожидания)
    static const int maxTimeOperation;
    /// Ограничение максимального размера ввода
    static const uchar maxInputLength;

    explicit VerifyInfo_MainWindow(QObject *parent = nullptr);

    /*!
     * \brief Проверка ввода числа
     * \param currentOperand главная строка ввода (текущий операнд)
     * \return результат проверки
     */
    static bool VerifyInput_DigitsNotOverflow(const QString &currentOperand);

    /*!
     * \brief Проверка на наличие запятой в строке
     * \param currentOperand строка, проверяемая на наличие запятой
     * \return результат проверки (успешно - true)
     */
    static bool VerifyInput_CommaNotExist(const QString &currentOperand);

    /*!
     * \brief Проверка очистки полей калькулятора
     * \param currentOperand строка текущего ввода (главная)
     * \param previousOperand строка предыдущего ввода (левый операнд)
     * \param operation операция
     * \return результат проверки (успешно - true)
     */
    static bool VerifyInput_NotClearedCalculator(const QString &currentOperand, const QString &previousOperand, const QString &operation);

    /*!
     * \brief Проверка наличия данных в главном поле для удаления
     * \param currentOperand главная строка ввода (текущий операнд)
     * \return результат проверки
     */
    static bool VerifyInput_ExistsSymbolsToDelete(const QString &currentOperand);

    /*!
     * \brief Проверка на отсуствие знака '-' в числе
     * \param currentOperand главная строка ввода (текущий операнд)
     * \return результат проверки
     */
    static bool VerifyInput_NotNegativeString(const QString &currentOperand);

    /*!
     * \brief Проверка на возможность преобразования к неотрицательному числу
     * \param currentOperand главная строка ввода (текущий операнд)
     * \return результат проверки
     */
    static bool VerifyInput_NotNegativeDigit(QString currentOperand);

    /*!
     * \brief Проверка на не превышение максимального времени операции
     * \param timeOperation время операции (сек)
     * \return результат проверки
     */
    static bool VerifyInput_MaxTimeOperation(const int& timeOperation);


signals:

};


#endif // VERIFYINFO_MAINWINDOW_H
