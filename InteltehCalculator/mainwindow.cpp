#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::settings_WorkPlace = "Intelteh";

QString MainWindow::settings_AppName = "InteltehCalculator";

QString MainWindow::settings_MainWindow_Geometry = "MainWindow/geometry";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readSettings()
{
    // Извлечение и применение настроек геометрии
    QSettings settings(settings_WorkPlace, settings_AppName);
    restoreGeometry(settings.value(settings_MainWindow_Geometry).toByteArray());
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    // Сохранение настроек геометрии
    QSettings settings(settings_WorkPlace, settings_AppName);
    settings.setValue(settings_MainWindow_Geometry, saveGeometry());

    // Выполнение базового функционала
    QMainWindow::closeEvent(event);
}


