#include "mainwindow.h"
#include "ui_mainwindow.h"

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



void MainWindow::closeEvent(QCloseEvent *event)
{
    // Сохранение настроек геометрии
    QSettings settings("Intelteh", "InteltehCalculator");
    settings.setValue("MainWindow/geometry", saveGeometry());

    // Выполнение базового функционала
    QMainWindow::closeEvent(event);
}

void MainWindow::readSettings()
{
    // Извлечение и применение настроек геометрии
    QSettings settings("Intelteh", "InteltehCalculator");
    restoreGeometry(settings.value("MainWindow/geometry").toByteArray());
}
