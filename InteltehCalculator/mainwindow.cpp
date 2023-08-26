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

    calculatorOperationQueues = new CalculatorOperationQueues();

    // Подключение клавиш чисел к обработчику кнопок
    connect(ui->buttonDigit_0, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_1, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_2, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_3, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_4, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_5, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_6, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_7, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_8, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
    connect(ui->buttonDigit_9, SIGNAL(clicked()), this, SLOT(ButtonDigitSlot()));
}

MainWindow::~MainWindow()
{
    delete calculatorOperationQueues;
    delete ui;
}


void MainWindow::ReadSettings()
{
    // Извлечение и применение настроек геометрии
    QSettings settings(settings_WorkPlace, settings_AppName);
    restoreGeometry(settings.value(settings_MainWindow_Geometry).toByteArray());
}

void MainWindow::PrintError_MainWindow(bool needClear, QString messageError)
{
    // Вывод ошибки в консоль
    ui->textEdit_Console->setTextColor(Qt::red);
    ui->textEdit_Console->append(messageError);

    // Очистка области калькулятора
    if (needClear)
        ClearCalculatorWindow();
}

void MainWindow::PrintSuccess_MainWindow(QString messageSuccess)
{
    ui->textEdit_Console->setTextColor(Qt::green);
    ui->textEdit_Console->append(messageSuccess);
}

void MainWindow::ClearCalculatorWindow()
{
    ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
    ui->labelDinamic_Operation->setText("");
    ui->labelDinamic_PreviousOperand->setText("");
}

void MainWindow::ReplaceCurrentOperandToPrevious()
{
    ui->labelDinamic_PreviousOperand->setText(ui->labelDinamic_CurrentOperand->text());
    ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    // Сохранение настроек геометрии
    QSettings settings(settings_WorkPlace, settings_AppName);
    settings.setValue(settings_MainWindow_Geometry, saveGeometry());

    // Выполнение базового функционала
    QMainWindow::closeEvent(event);
}

void MainWindow::ButtonDigitSlot()
{
    QPushButton* buttonDigit = (QPushButton*)sender();
    // Стоит начальный символ в главной области
    if (ui->labelDinamic_CurrentOperand->text() == (QString)VerifyInfo_MainWindow::firstSymbol)
        ui->labelDinamic_CurrentOperand->setText(buttonDigit->text());
    // Проверка на переполнение
    else if (VerifyInfo_MainWindow::VerifyInput_DigitsNotOverflow(ui->labelDinamic_CurrentOperand->text()))
        ui->labelDinamic_CurrentOperand->setText(ui->labelDinamic_CurrentOperand->text() + buttonDigit->text());
    // вывод ошибки переполнения
    else
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::DigitOverflow));
}


void MainWindow::on_buttonSpecial_Comma_clicked()
{
    // Проверка наличия символа разделителя
    if (VerifyInfo_MainWindow::VerifyInput_CommaNotExist(ui->labelDinamic_CurrentOperand->text()))
        ui->labelDinamic_CurrentOperand->setText(ui->labelDinamic_CurrentOperand->text()+VerifyInfo_MainWindow::commaSymbol);
    else
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::CommaExists));

}


void MainWindow::on_buttonSpecial_C_clicked()
{
    // Проверка очистки полей
    if (VerifyInfo_MainWindow::VerifyInput_NotClearedCalculator(ui->labelDinamic_CurrentOperand->text(),
                                        ui->labelDinamic_PreviousOperand->text(),
                                        ui->labelDinamic_Operation->text()))
    {
        ClearCalculatorWindow();
        PrintSuccess_MainWindow("Успешно очищено");
    }
    else
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::AlreadyClearedCalculator));
}


void MainWindow::on_buttonSpecial_X_clicked()
{
    if (VerifyInfo_MainWindow::VerifyInput_ExistsSymbolsToDelete(ui->labelDinamic_CurrentOperand->text()))
    {
        if (ui->labelDinamic_CurrentOperand->text().length()>1)
            ui->labelDinamic_CurrentOperand->setText(
                        ui->labelDinamic_CurrentOperand->text().left(
                            ui->labelDinamic_CurrentOperand->text().length()-1));
        else
            ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
    }
    else
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::NotExistToDeleteCalculator));
}


void MainWindow::on_buttonOperation_Sum_clicked()
{
    // Проверка на совпадение операций
    if (ui->buttonOperation_Sum->text() == ui->labelDinamic_Operation->text())
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::RepeatOperation));
    else
    {
        // Перенос операции
        if (ui->labelDinamic_PreviousOperand->text() == "")
            ReplaceCurrentOperandToPrevious();

        // Сохранение операции
        ui->labelDinamic_Operation->setText(ui->buttonOperation_Sum->text());
        calculatorOperationQueues->SetCurrentOperation(CalculatorOperationsLib::TypesOperation::Plus);
    }
}

