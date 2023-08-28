#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <memory>
#include "verifyinfo_mainwindow.h"
#include "errorsspecifier_mainwindow.h"
#include "operationtimeinfo.h"
#include "collectionscontainer.h"
#include "calculatoroperationslib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(std::shared_ptr<CollectionsContainer> collectionsContainer, QWidget *parent = nullptr);
    virtual ~MainWindow();

    /*!
     * \brief Считать сохранённые настройки
     */
    void ReadSettings();

    /*!
     * \brief Вывод ошибки типа MainWindow_Errors
     * \param needClear нужна ли очистка области калькулятора
     * \param typeError тип ошибки по MainWindow_Errors
     */
    void PrintError_MainWindow(bool needClear, QString message);

public slots:

private slots:

    /*!
     * \brief Обработка события закрытия окна
     * \param event Событие закрытия окна
     */
    void closeEvent(QCloseEvent *event) override;

    /*!
     * \brief Слот для обработки сигналов нажатия кнопок
     */
    void ButtonDigitSlot();

    /*!
     * \brief Обработка нажатия на кнопку разделителя
     */
    void on_buttonSpecial_Comma_clicked();

    /*!
     * \brief Обработка нажатия на кнопку очистки калькулятора
     */
    void on_buttonSpecial_C_clicked();

    /*!
     * \brief Обработка нажатия на кнопку удаления символа
     */
    void on_buttonSpecial_X_clicked();

    /*!
     * \brief Обработка нажатия на операцию сложения
     */
    void on_buttonOperation_Sum_clicked();

    /*!
     * \brief Обработка нажатия на операцию вычитания
     */
    void on_buttonOperation_Mines_clicked();

    /*!
     * \brief Обработка нажатия на операцию умножения
     */
    void on_buttonOperation_Mult_clicked();

    /*!
     * \brief Обработка нажатия на операцию деления
     */
    void on_buttonOperation_Div_clicked();

    /*!
     * \brief Обработка установки времени
     */
    void on_buttonSpecial_T_clicked();

    /*!
     * \brief Обработка нажатия на кнопку изменения знака числа
     */
    void on_buttonSpecial_SwitchSign_clicked();

    /*!
     * \brief Обработка нажатия на кнопку очистки консоли
     */
    void on_buttonConsole_Clear_clicked();

    /*!
     * \brief Обработка нажатия на кнопку добавления операции в очередь
     */
    void on_buttonSpecial_Equal_clicked();

private:
    /// Отображение главного окна
    Ui::MainWindow *ui;
    /// Наименование организации
    static QString settings_WorkPlace;
    /// Наименование приложения
    static QString settings_AppName;
    /// Путь к геометрии главного окна
    static QString settings_MainWindow_Geometry;
    /// Строка, с которой начинается единица сообщения в консоли
    static QString consoleStartString;
    /// Объект хранения текущей операции и информации о времени операций
    OperationTimeInfo* operationTimeInfo;
    /// Объект взаимодействия с очередями (shared - для многопоточности)
    std::shared_ptr<CollectionsContainer> collectionsContainer;

    /*!
     * \brief Функция очистки области калькулятора
     */
    void ClearCalculatorWindow();

    /*!
     * \brief Функция очистки данных консоли
     */
    void ClearConsole();

    /*!
     * \brief Напечатать сообщение в консоли зелёным цветом
     * \param messageSuccess Сообщение для печати
     */
    void PrintSuccess_MainWindow(QString messageSuccess);

    /*!
     * \brief Напечатать сообщение - запрос
     * \param messageRequest Сообщение запроса
     */
    void PrintRequest_MainWindow(QString messageRequest);

    /*!
     * \brief AcceptOperation Применить операцию на интерфейсе калькулятора в соответствии с проверками
     * \param typeOperation тип операции
     * \param textOperation текст кнопки операции
     */
    void AcceptOperation(CalculatorOperationsLib::TypesOperation typeOperation, QString textOperation);

    /*!
     * \brief Перенести текущий операнд на предыдущий
     */
    void ReplaceCurrentOperandToPrevious();

    /*!
     * \brief изменить знак числа в текущем поле
     */
    void SwitchSign();

};
#endif // MAINWINDOW_H
