#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::settings_WorkPlace = "Intelteh";

QString MainWindow::settings_AppName = "InteltehCalculator";

QString MainWindow::settings_MainWindow_Geometry = "MainWindow/geometry";

QString MainWindow::consoleStartString = "> ";

MainWindow::MainWindow(std::shared_ptr<CollectionsContainer> collectionsContainer, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // инициализация объектов
    this->collectionsContainer = collectionsContainer;
    operationTimeInfo = new OperationTimeInfo();

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

    // Подключение к обработке изменения количества элементов в очередях операций и результата
    connect(collectionsContainer.get(), SIGNAL(ChangeSizeOperationQueueSignal(int)), this, SLOT(ChangeSizeOperationQueueSlot(int)));
    connect(collectionsContainer.get(), SIGNAL(ChangeSizeResultQueueSignal(int)), this, SLOT(ChangeSizeResultQueueSlot(int)));
}

MainWindow::~MainWindow()
{
    delete operationTimeInfo;
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
    ui->textEdit_Console->append(consoleStartString + messageError);

    // Очистка области калькулятора
    if (needClear)
        ClearCalculatorWindow();
}

void MainWindow::PrintSuccess_MainWindow(QString messageSuccess)
{
    ui->textEdit_Console->setTextColor(Qt::green);
    ui->textEdit_Console->append(consoleStartString + messageSuccess);
}

void MainWindow::PrintRequest_MainWindow(QString messageRequest)
{
    PrintSuccess_MainWindow("Запрос: " + messageRequest);
}

void MainWindow::ClearCalculatorWindow()
{
    // Очистка окна
    ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
    ui->labelDinamic_Operation->setText("");
    ui->labelDinamic_PreviousOperand->setText("");
    // Очистка данных по операции
    operationTimeInfo->SetCurrentOperation(CalculatorOperationsLib::TypesOperation::None);
}

void MainWindow::ClearConsole()
{
    ui->textEdit_Console->setText("");
}

void MainWindow::AcceptOperation(CalculatorOperationsLib::TypesOperation typeOperation, QString textOperation)
{
    // Проверка на совпадение операций
    if (textOperation == ui->labelDinamic_Operation->text())
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::RepeatOperation));
    else
    {
        // Перенос операции
        if (ui->labelDinamic_PreviousOperand->text() == "")
            ReplaceCurrentOperandToPrevious();

        // Сохранение операции
        ui->labelDinamic_Operation->setText(textOperation);
        operationTimeInfo->SetCurrentOperation(typeOperation);
    }
}

void MainWindow::ReplaceCurrentOperandToPrevious()
{
    ui->labelDinamic_PreviousOperand->setText(ui->labelDinamic_CurrentOperand->text());
    ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
}


void MainWindow::SwitchSign()
{
    // Проверка - стоит ли начальный символ
    if (!VerifyInfo_MainWindow::VerifyInput_ExistsSymbolsToDelete(ui->labelDinamic_CurrentOperand->text()))
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::CantAddMinesToZero));
    // Определение отрицательности и удаление/добавление знака -
    else if (VerifyInfo_MainWindow::VerifyInput_NotNegativeDigit(ui->labelDinamic_CurrentOperand->text()))
        ui->labelDinamic_CurrentOperand->setText(VerifyInfo_MainWindow::minusSymbol+ui->labelDinamic_CurrentOperand->text());
    else
        ui->labelDinamic_CurrentOperand->setText(ui->labelDinamic_CurrentOperand->text().remove(0,1));
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

void MainWindow::ChangeSizeOperationQueueSlot(int currentCountOperations)
{
    ui->labelDinamic_QueueOperations->setText(QString::number(currentCountOperations));
}

void MainWindow::ChangeSizeResultQueueSlot(int currentCountResults)
{
    ui->labelDinamic_QueueResults->setText(QString::number(currentCountResults));
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
    // Проверка на наличие символов для удаления
    if (VerifyInfo_MainWindow::VerifyInput_ExistsSymbolsToDelete(ui->labelDinamic_CurrentOperand->text()))
    {
        // Проверка на знак и размер строки, из которой удаляются символы
        if (VerifyInfo_MainWindow::VerifyInput_NotNegativeDigit(ui->labelDinamic_CurrentOperand->text()))
        {
            // Проверка на размер строки, из которой удаляются символы
            if (ui->labelDinamic_CurrentOperand->text().length()>1)
                ui->labelDinamic_CurrentOperand->setText(
                            ui->labelDinamic_CurrentOperand->text().left(
                                ui->labelDinamic_CurrentOperand->text().length()-1));
            else
                ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
        }
        else
        {
            // Проверка на размер строки, из которой удаляются символы (с учётом -)
            if (ui->labelDinamic_CurrentOperand->text().length()>2)
                ui->labelDinamic_CurrentOperand->setText(
                            ui->labelDinamic_CurrentOperand->text().left(
                                ui->labelDinamic_CurrentOperand->text().length()-1));
            else
                ui->labelDinamic_CurrentOperand->setText((QString)VerifyInfo_MainWindow::firstSymbol);
        }
    }
    else
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::NotExistToDeleteCalculator));
}


void MainWindow::on_buttonOperation_Sum_clicked()
{
    AcceptOperation(CalculatorOperationsLib::TypesOperation::Plus, ui->buttonOperation_Sum->text());
}


void MainWindow::on_buttonOperation_Mines_clicked()
{
    AcceptOperation(CalculatorOperationsLib::TypesOperation::Mines, ui->buttonOperation_Mines->text());
}


void MainWindow::on_buttonOperation_Mult_clicked()
{
    AcceptOperation(CalculatorOperationsLib::TypesOperation::Multiplicaion, ui->buttonOperation_Mult->text());
}


void MainWindow::on_buttonOperation_Div_clicked()
{
    AcceptOperation(CalculatorOperationsLib::TypesOperation::Division, ui->buttonOperation_Div->text());
}


void MainWindow::on_buttonSpecial_T_clicked()
{
    // Проверка на отсутствие операции и запятой в главном поле
    if (ui->labelDinamic_Operation->text() != "")
            PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                      ErrorsSpecifier_MainWindow::MainWindow_Errors::AlreadyExistNotTimeOperation));
    // проверка на целочисленность
    else if (!VerifyInfo_MainWindow::VerifyInput_CommaNotExist(ui->labelDinamic_CurrentOperand->text()))
        PrintError_MainWindow(true, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::TimeIsNotInt));
    // Проверка на неотрицательность
    else if (!VerifyInfo_MainWindow::VerifyInput_NotNegativeDigit(ui->labelDinamic_CurrentOperand->text()))
        PrintError_MainWindow(true, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::TimeIsNegative));
    else
    {
        int timeOperation = ui->labelDinamic_CurrentOperand->text().toInt();
        // проверка на переполнение времени операции
        if (VerifyInfo_MainWindow::VerifyInput_MaxTimeOperation(timeOperation))
        {
            // применить введённое время операции
            operationTimeInfo->SetCurrentOperationTime(timeOperation);
            ui->labelDinamic_TimeOperations->setText(ui->labelDinamic_CurrentOperand->text());
            PrintSuccess_MainWindow("Время операции " + ui->labelDinamic_CurrentOperand->text() + " (сек.) успешно применено");
            ClearCalculatorWindow();
        }
        else
            PrintError_MainWindow(true, ErrorsSpecifier_MainWindow::getErrorMessage(
                                      ErrorsSpecifier_MainWindow::MainWindow_Errors::TimeOperationOverflow)
                                      + " " + QString::number(VerifyInfo_MainWindow::maxTimeOperation));
    }

}


void MainWindow::on_buttonSpecial_SwitchSign_clicked()
{
   // сменить знак
   SwitchSign();
}


void MainWindow::on_buttonConsole_Clear_clicked()
{
    ClearConsole();
}


void MainWindow::on_buttonSpecial_Equal_clicked()
{
    // Проверка на наличие операции
    if (ui->labelDinamic_Operation->text() == "")
    {
        PrintError_MainWindow(false, ErrorsSpecifier_MainWindow::getErrorMessage(
                                  ErrorsSpecifier_MainWindow::MainWindow_Errors::NotSelectedOperation));
        return;
    }

    // Произвести добавление в очередь операций
    collectionsContainer->PushOperation(operationTimeInfo->GetCurrentOperation(),
                                ui->labelDinamic_PreviousOperand->text().replace(",", ".").toDouble(),
                                ui->labelDinamic_CurrentOperand->text().replace(",", ".").toDouble(),
                                operationTimeInfo->GetCurrentOperationTime());
    // Произвести печать запроса
    PrintRequest_MainWindow("(" + ui->labelDinamic_PreviousOperand->text() + ")" +
                            CalculatorOperationsLib::GetOperationTypeSign(operationTimeInfo->GetCurrentOperation()) +
                            "(" + ui->labelDinamic_CurrentOperand->text() + ")");
    // Осуществить очистку
    ClearCalculatorWindow();
}

