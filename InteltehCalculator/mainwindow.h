#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include "verifyinfo_mainwindow.h"
#include "errorsspecifier_mainwindow.h"
#include "calculatoroperationqueues.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
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

private:
    /// Отображение главного окна
    Ui::MainWindow *ui;
    /// Наименование организации
    static QString settings_WorkPlace;
    /// Наименование приложения
    static QString settings_AppName;
    /// Путь к геометрии главного окна
    static QString settings_MainWindow_Geometry;
    /// объект взаимодействия с очередями, операциями и хранения текущих значений
    CalculatorOperationQueues* calculatorOperationQueues;

    /*!
     * \brief Функция очистки области калькулятора
     */
    void ClearCalculatorWindow();

    /*!
     * \brief Напечатать сообщение в консоли зелёным цветом
     * \param Сообщение для печати
     */
    void PrintSuccess_MainWindow(QString messageSuccess);

};
#endif // MAINWINDOW_H
