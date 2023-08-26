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
    virtual ~MainWindow();

    /*!
     * \brief Обработка события закрытия окна
     * \param event Событие закрытия окна
     */
    void closeEvent(QCloseEvent *event) override;

    /*!
     * \brief Считать сохранённые настройки
     */
    void ReadSettings();

public slots:


private:
    /// Отображение главного окна
    Ui::MainWindow *ui;

    /// Наименование организации
    static QString settings_WorkPlace;

    // Наименование приложения
    static QString settings_AppName;

    /// Путь к геометрии главного окна
    static QString settings_MainWindow_Geometry;

};
#endif // MAINWINDOW_H
