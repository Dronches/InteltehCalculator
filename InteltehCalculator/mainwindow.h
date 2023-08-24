#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*!
     * \brief Обработка события закрытия окна
     * \param event Событие закрытия окна
     */
    void closeEvent(QCloseEvent *event) override;

    /*!
     * \brief Считать сохранённые настройки
     */
    void readSettings();

private:
    /// Отображение главного окна
    Ui::MainWindow *ui;

    /// Путь к геометрии главного окна
    QString settings_mainWindow_Geometry = "MainWindow/geometry";

    /// Путь к положению главного окна
    QString settings_mainWindow_State = "MainWindow/state";

};
#endif // MAINWINDOW_H
