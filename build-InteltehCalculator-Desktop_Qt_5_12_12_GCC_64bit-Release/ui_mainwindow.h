/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *buttonConsole_Clear;
    QPushButton *buttonDigit_5;
    QPushButton *buttonDigit_3;
    QPushButton *buttonOperation_Sum;
    QLabel *labelStatic_QueueOperations;
    QPushButton *buttonOperation_Div;
    QPushButton *buttonSpecial_Comma;
    QLabel *labelDinamic_QueueOperations;
    QPushButton *buttonSpecial_Equal;
    QLabel *labelDinamic_PreviousOperand;
    QPushButton *buttonDigit_7;
    QPushButton *buttonDigit_1;
    QPushButton *buttonSpecial_C;
    QLabel *labelDinamic_Operation;
    QPushButton *buttonDigit_4;
    QPushButton *buttonDigit_0;
    QPushButton *buttonDigit_6;
    QLabel *labelDinamic_CurrentOperand;
    QPushButton *buttonConsole_Next;
    QLabel *labelStatic_NameConsole;
    QPushButton *buttonDigit_9;
    QPushButton *buttonOperation_Mult;
    QLabel *labelStatic_Support_1;
    QTextEdit *textEdit_Console;
    QPushButton *buttonOperation_Mines;
    QPushButton *buttonSpecial_X;
    QPushButton *buttonDigit_2;
    QPushButton *buttonSpecial_T;
    QLabel *labelStatic_Support_2;
    QPushButton *buttonDigit_8;
    QPushButton *buttonSpecial_SwitchSign;
    QLabel *labelDinamic_QueueResults;
    QLabel *labelStatic_QueueResults;
    QLabel *labelStatic_TimeOperations;
    QLabel *labelDinamic_TimeOperations;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(641, 435);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonConsole_Clear = new QPushButton(centralwidget);
        buttonConsole_Clear->setObjectName(QString::fromUtf8("buttonConsole_Clear"));
        sizePolicy.setHeightForWidth(buttonConsole_Clear->sizePolicy().hasHeightForWidth());
        buttonConsole_Clear->setSizePolicy(sizePolicy);
        buttonConsole_Clear->setMinimumSize(QSize(75, 50));
        QFont font;
        font.setPointSize(14);
        buttonConsole_Clear->setFont(font);
        buttonConsole_Clear->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 70, 53);"));

        gridLayout->addWidget(buttonConsole_Clear, 6, 7, 1, 1);

        buttonDigit_5 = new QPushButton(centralwidget);
        buttonDigit_5->setObjectName(QString::fromUtf8("buttonDigit_5"));
        sizePolicy.setHeightForWidth(buttonDigit_5->sizePolicy().hasHeightForWidth());
        buttonDigit_5->setSizePolicy(sizePolicy);
        buttonDigit_5->setMinimumSize(QSize(75, 50));
        QFont font1;
        font1.setPointSize(20);
        buttonDigit_5->setFont(font1);

        gridLayout->addWidget(buttonDigit_5, 4, 1, 1, 1);

        buttonDigit_3 = new QPushButton(centralwidget);
        buttonDigit_3->setObjectName(QString::fromUtf8("buttonDigit_3"));
        sizePolicy.setHeightForWidth(buttonDigit_3->sizePolicy().hasHeightForWidth());
        buttonDigit_3->setSizePolicy(sizePolicy);
        buttonDigit_3->setMinimumSize(QSize(75, 50));
        buttonDigit_3->setFont(font1);

        gridLayout->addWidget(buttonDigit_3, 3, 2, 1, 1);

        buttonOperation_Sum = new QPushButton(centralwidget);
        buttonOperation_Sum->setObjectName(QString::fromUtf8("buttonOperation_Sum"));
        sizePolicy.setHeightForWidth(buttonOperation_Sum->sizePolicy().hasHeightForWidth());
        buttonOperation_Sum->setSizePolicy(sizePolicy);
        buttonOperation_Sum->setMinimumSize(QSize(75, 50));
        buttonOperation_Sum->setFont(font1);
        buttonOperation_Sum->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);"));

        gridLayout->addWidget(buttonOperation_Sum, 5, 3, 1, 1);

        labelStatic_QueueOperations = new QLabel(centralwidget);
        labelStatic_QueueOperations->setObjectName(QString::fromUtf8("labelStatic_QueueOperations"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelStatic_QueueOperations->sizePolicy().hasHeightForWidth());
        labelStatic_QueueOperations->setSizePolicy(sizePolicy2);
        labelStatic_QueueOperations->setMinimumSize(QSize(150, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setItalic(true);
        labelStatic_QueueOperations->setFont(font2);
        labelStatic_QueueOperations->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        labelStatic_QueueOperations->setMargin(2);

        gridLayout->addWidget(labelStatic_QueueOperations, 8, 0, 1, 2);

        buttonOperation_Div = new QPushButton(centralwidget);
        buttonOperation_Div->setObjectName(QString::fromUtf8("buttonOperation_Div"));
        sizePolicy.setHeightForWidth(buttonOperation_Div->sizePolicy().hasHeightForWidth());
        buttonOperation_Div->setSizePolicy(sizePolicy);
        buttonOperation_Div->setMinimumSize(QSize(75, 50));
        buttonOperation_Div->setFont(font1);
        buttonOperation_Div->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);"));

        gridLayout->addWidget(buttonOperation_Div, 2, 3, 1, 1);

        buttonSpecial_Comma = new QPushButton(centralwidget);
        buttonSpecial_Comma->setObjectName(QString::fromUtf8("buttonSpecial_Comma"));
        sizePolicy.setHeightForWidth(buttonSpecial_Comma->sizePolicy().hasHeightForWidth());
        buttonSpecial_Comma->setSizePolicy(sizePolicy);
        buttonSpecial_Comma->setMinimumSize(QSize(75, 50));
        buttonSpecial_Comma->setFont(font1);

        gridLayout->addWidget(buttonSpecial_Comma, 6, 2, 1, 1);

        labelDinamic_QueueOperations = new QLabel(centralwidget);
        labelDinamic_QueueOperations->setObjectName(QString::fromUtf8("labelDinamic_QueueOperations"));
        sizePolicy2.setHeightForWidth(labelDinamic_QueueOperations->sizePolicy().hasHeightForWidth());
        labelDinamic_QueueOperations->setSizePolicy(sizePolicy2);
        labelDinamic_QueueOperations->setMinimumSize(QSize(75, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        labelDinamic_QueueOperations->setFont(font3);
        labelDinamic_QueueOperations->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        labelDinamic_QueueOperations->setMargin(2);

        gridLayout->addWidget(labelDinamic_QueueOperations, 8, 2, 1, 1);

        buttonSpecial_Equal = new QPushButton(centralwidget);
        buttonSpecial_Equal->setObjectName(QString::fromUtf8("buttonSpecial_Equal"));
        sizePolicy.setHeightForWidth(buttonSpecial_Equal->sizePolicy().hasHeightForWidth());
        buttonSpecial_Equal->setSizePolicy(sizePolicy);
        buttonSpecial_Equal->setMinimumSize(QSize(75, 50));
        buttonSpecial_Equal->setFont(font1);
        buttonSpecial_Equal->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);"));

        gridLayout->addWidget(buttonSpecial_Equal, 6, 3, 1, 1);

        labelDinamic_PreviousOperand = new QLabel(centralwidget);
        labelDinamic_PreviousOperand->setObjectName(QString::fromUtf8("labelDinamic_PreviousOperand"));
        sizePolicy.setHeightForWidth(labelDinamic_PreviousOperand->sizePolicy().hasHeightForWidth());
        labelDinamic_PreviousOperand->setSizePolicy(sizePolicy);
        labelDinamic_PreviousOperand->setMinimumSize(QSize(225, 50));
        QFont font4;
        font4.setPointSize(15);
        labelDinamic_PreviousOperand->setFont(font4);
        labelDinamic_PreviousOperand->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 255, 252);"));
        labelDinamic_PreviousOperand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelDinamic_PreviousOperand->setMargin(5);

        gridLayout->addWidget(labelDinamic_PreviousOperand, 0, 1, 1, 3);

        buttonDigit_7 = new QPushButton(centralwidget);
        buttonDigit_7->setObjectName(QString::fromUtf8("buttonDigit_7"));
        sizePolicy.setHeightForWidth(buttonDigit_7->sizePolicy().hasHeightForWidth());
        buttonDigit_7->setSizePolicy(sizePolicy);
        buttonDigit_7->setMinimumSize(QSize(75, 50));
        buttonDigit_7->setFont(font1);

        gridLayout->addWidget(buttonDigit_7, 5, 0, 1, 1);

        buttonDigit_1 = new QPushButton(centralwidget);
        buttonDigit_1->setObjectName(QString::fromUtf8("buttonDigit_1"));
        sizePolicy.setHeightForWidth(buttonDigit_1->sizePolicy().hasHeightForWidth());
        buttonDigit_1->setSizePolicy(sizePolicy);
        buttonDigit_1->setMinimumSize(QSize(75, 50));
        buttonDigit_1->setFont(font1);

        gridLayout->addWidget(buttonDigit_1, 3, 0, 1, 1);

        buttonSpecial_C = new QPushButton(centralwidget);
        buttonSpecial_C->setObjectName(QString::fromUtf8("buttonSpecial_C"));
        sizePolicy.setHeightForWidth(buttonSpecial_C->sizePolicy().hasHeightForWidth());
        buttonSpecial_C->setSizePolicy(sizePolicy);
        buttonSpecial_C->setMinimumSize(QSize(75, 50));
        buttonSpecial_C->setFont(font1);
        buttonSpecial_C->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 70, 53);"));

        gridLayout->addWidget(buttonSpecial_C, 2, 0, 1, 1);

        labelDinamic_Operation = new QLabel(centralwidget);
        labelDinamic_Operation->setObjectName(QString::fromUtf8("labelDinamic_Operation"));
        sizePolicy.setHeightForWidth(labelDinamic_Operation->sizePolicy().hasHeightForWidth());
        labelDinamic_Operation->setSizePolicy(sizePolicy);
        labelDinamic_Operation->setMinimumSize(QSize(75, 50));
        labelDinamic_Operation->setFont(font1);
        labelDinamic_Operation->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        labelDinamic_Operation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelDinamic_Operation, 0, 0, 1, 1);

        buttonDigit_4 = new QPushButton(centralwidget);
        buttonDigit_4->setObjectName(QString::fromUtf8("buttonDigit_4"));
        sizePolicy.setHeightForWidth(buttonDigit_4->sizePolicy().hasHeightForWidth());
        buttonDigit_4->setSizePolicy(sizePolicy);
        buttonDigit_4->setMinimumSize(QSize(75, 50));
        buttonDigit_4->setFont(font1);

        gridLayout->addWidget(buttonDigit_4, 4, 0, 1, 1);

        buttonDigit_0 = new QPushButton(centralwidget);
        buttonDigit_0->setObjectName(QString::fromUtf8("buttonDigit_0"));
        sizePolicy.setHeightForWidth(buttonDigit_0->sizePolicy().hasHeightForWidth());
        buttonDigit_0->setSizePolicy(sizePolicy);
        buttonDigit_0->setMinimumSize(QSize(75, 50));
        buttonDigit_0->setFont(font1);

        gridLayout->addWidget(buttonDigit_0, 6, 1, 1, 1);

        buttonDigit_6 = new QPushButton(centralwidget);
        buttonDigit_6->setObjectName(QString::fromUtf8("buttonDigit_6"));
        sizePolicy.setHeightForWidth(buttonDigit_6->sizePolicy().hasHeightForWidth());
        buttonDigit_6->setSizePolicy(sizePolicy);
        buttonDigit_6->setMinimumSize(QSize(75, 50));
        buttonDigit_6->setFont(font1);

        gridLayout->addWidget(buttonDigit_6, 4, 2, 1, 1);

        labelDinamic_CurrentOperand = new QLabel(centralwidget);
        labelDinamic_CurrentOperand->setObjectName(QString::fromUtf8("labelDinamic_CurrentOperand"));
        sizePolicy.setHeightForWidth(labelDinamic_CurrentOperand->sizePolicy().hasHeightForWidth());
        labelDinamic_CurrentOperand->setSizePolicy(sizePolicy);
        labelDinamic_CurrentOperand->setMinimumSize(QSize(300, 50));
        labelDinamic_CurrentOperand->setFont(font1);
        labelDinamic_CurrentOperand->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 255, 252);"));
        labelDinamic_CurrentOperand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelDinamic_CurrentOperand->setMargin(5);

        gridLayout->addWidget(labelDinamic_CurrentOperand, 1, 0, 1, 4);

        buttonConsole_Next = new QPushButton(centralwidget);
        buttonConsole_Next->setObjectName(QString::fromUtf8("buttonConsole_Next"));
        sizePolicy.setHeightForWidth(buttonConsole_Next->sizePolicy().hasHeightForWidth());
        buttonConsole_Next->setSizePolicy(sizePolicy);
        buttonConsole_Next->setMinimumSize(QSize(75, 50));
        buttonConsole_Next->setFont(font);
        buttonConsole_Next->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

        gridLayout->addWidget(buttonConsole_Next, 6, 4, 1, 1);

        labelStatic_NameConsole = new QLabel(centralwidget);
        labelStatic_NameConsole->setObjectName(QString::fromUtf8("labelStatic_NameConsole"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Roboto"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(true);
        font5.setWeight(75);
        labelStatic_NameConsole->setFont(font5);
        labelStatic_NameConsole->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        labelStatic_NameConsole->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        labelStatic_NameConsole->setMargin(10);

        gridLayout->addWidget(labelStatic_NameConsole, 0, 4, 1, 4);

        buttonDigit_9 = new QPushButton(centralwidget);
        buttonDigit_9->setObjectName(QString::fromUtf8("buttonDigit_9"));
        sizePolicy.setHeightForWidth(buttonDigit_9->sizePolicy().hasHeightForWidth());
        buttonDigit_9->setSizePolicy(sizePolicy);
        buttonDigit_9->setMinimumSize(QSize(75, 50));
        buttonDigit_9->setFont(font1);

        gridLayout->addWidget(buttonDigit_9, 5, 2, 1, 1);

        buttonOperation_Mult = new QPushButton(centralwidget);
        buttonOperation_Mult->setObjectName(QString::fromUtf8("buttonOperation_Mult"));
        sizePolicy.setHeightForWidth(buttonOperation_Mult->sizePolicy().hasHeightForWidth());
        buttonOperation_Mult->setSizePolicy(sizePolicy);
        buttonOperation_Mult->setMinimumSize(QSize(75, 50));
        QFont font6;
        font6.setPointSize(16);
        buttonOperation_Mult->setFont(font6);
        buttonOperation_Mult->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);"));

        gridLayout->addWidget(buttonOperation_Mult, 3, 3, 1, 1);

        labelStatic_Support_1 = new QLabel(centralwidget);
        labelStatic_Support_1->setObjectName(QString::fromUtf8("labelStatic_Support_1"));
        sizePolicy.setHeightForWidth(labelStatic_Support_1->sizePolicy().hasHeightForWidth());
        labelStatic_Support_1->setSizePolicy(sizePolicy);
        labelStatic_Support_1->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(labelStatic_Support_1, 6, 5, 1, 1);

        textEdit_Console = new QTextEdit(centralwidget);
        textEdit_Console->setObjectName(QString::fromUtf8("textEdit_Console"));
        sizePolicy.setHeightForWidth(textEdit_Console->sizePolicy().hasHeightForWidth());
        textEdit_Console->setSizePolicy(sizePolicy);
        textEdit_Console->setMinimumSize(QSize(225, 50));
        QFont font7;
        font7.setPointSize(12);
        textEdit_Console->setFont(font7);
        textEdit_Console->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit_Console->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_Console->setReadOnly(true);

        gridLayout->addWidget(textEdit_Console, 1, 4, 5, 4);

        buttonOperation_Mines = new QPushButton(centralwidget);
        buttonOperation_Mines->setObjectName(QString::fromUtf8("buttonOperation_Mines"));
        sizePolicy.setHeightForWidth(buttonOperation_Mines->sizePolicy().hasHeightForWidth());
        buttonOperation_Mines->setSizePolicy(sizePolicy);
        buttonOperation_Mines->setMinimumSize(QSize(75, 50));
        buttonOperation_Mines->setFont(font1);
        buttonOperation_Mines->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);"));

        gridLayout->addWidget(buttonOperation_Mines, 4, 3, 1, 1);

        buttonSpecial_X = new QPushButton(centralwidget);
        buttonSpecial_X->setObjectName(QString::fromUtf8("buttonSpecial_X"));
        sizePolicy.setHeightForWidth(buttonSpecial_X->sizePolicy().hasHeightForWidth());
        buttonSpecial_X->setSizePolicy(sizePolicy);
        buttonSpecial_X->setMinimumSize(QSize(75, 50));
        buttonSpecial_X->setFont(font6);
        buttonSpecial_X->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));

        gridLayout->addWidget(buttonSpecial_X, 2, 1, 1, 1);

        buttonDigit_2 = new QPushButton(centralwidget);
        buttonDigit_2->setObjectName(QString::fromUtf8("buttonDigit_2"));
        sizePolicy.setHeightForWidth(buttonDigit_2->sizePolicy().hasHeightForWidth());
        buttonDigit_2->setSizePolicy(sizePolicy);
        buttonDigit_2->setMinimumSize(QSize(75, 50));
        buttonDigit_2->setFont(font1);

        gridLayout->addWidget(buttonDigit_2, 3, 1, 1, 1);

        buttonSpecial_T = new QPushButton(centralwidget);
        buttonSpecial_T->setObjectName(QString::fromUtf8("buttonSpecial_T"));
        sizePolicy.setHeightForWidth(buttonSpecial_T->sizePolicy().hasHeightForWidth());
        buttonSpecial_T->setSizePolicy(sizePolicy);
        buttonSpecial_T->setMinimumSize(QSize(75, 50));
        buttonSpecial_T->setFont(font1);
        buttonSpecial_T->setContextMenuPolicy(Qt::DefaultContextMenu);
        buttonSpecial_T->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

        gridLayout->addWidget(buttonSpecial_T, 2, 2, 1, 1);

        labelStatic_Support_2 = new QLabel(centralwidget);
        labelStatic_Support_2->setObjectName(QString::fromUtf8("labelStatic_Support_2"));
        sizePolicy.setHeightForWidth(labelStatic_Support_2->sizePolicy().hasHeightForWidth());
        labelStatic_Support_2->setSizePolicy(sizePolicy);
        labelStatic_Support_2->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(labelStatic_Support_2, 6, 6, 1, 1);

        buttonDigit_8 = new QPushButton(centralwidget);
        buttonDigit_8->setObjectName(QString::fromUtf8("buttonDigit_8"));
        sizePolicy.setHeightForWidth(buttonDigit_8->sizePolicy().hasHeightForWidth());
        buttonDigit_8->setSizePolicy(sizePolicy);
        buttonDigit_8->setMinimumSize(QSize(75, 50));
        buttonDigit_8->setFont(font1);

        gridLayout->addWidget(buttonDigit_8, 5, 1, 1, 1);

        buttonSpecial_SwitchSign = new QPushButton(centralwidget);
        buttonSpecial_SwitchSign->setObjectName(QString::fromUtf8("buttonSpecial_SwitchSign"));
        sizePolicy.setHeightForWidth(buttonSpecial_SwitchSign->sizePolicy().hasHeightForWidth());
        buttonSpecial_SwitchSign->setSizePolicy(sizePolicy);
        buttonSpecial_SwitchSign->setMinimumSize(QSize(75, 50));
        buttonSpecial_SwitchSign->setFont(font1);

        gridLayout->addWidget(buttonSpecial_SwitchSign, 6, 0, 1, 1);

        labelDinamic_QueueResults = new QLabel(centralwidget);
        labelDinamic_QueueResults->setObjectName(QString::fromUtf8("labelDinamic_QueueResults"));
        sizePolicy2.setHeightForWidth(labelDinamic_QueueResults->sizePolicy().hasHeightForWidth());
        labelDinamic_QueueResults->setSizePolicy(sizePolicy2);
        labelDinamic_QueueResults->setMinimumSize(QSize(75, 20));
        labelDinamic_QueueResults->setFont(font3);
        labelDinamic_QueueResults->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        labelDinamic_QueueResults->setMargin(2);

        gridLayout->addWidget(labelDinamic_QueueResults, 8, 5, 1, 1);

        labelStatic_QueueResults = new QLabel(centralwidget);
        labelStatic_QueueResults->setObjectName(QString::fromUtf8("labelStatic_QueueResults"));
        sizePolicy2.setHeightForWidth(labelStatic_QueueResults->sizePolicy().hasHeightForWidth());
        labelStatic_QueueResults->setSizePolicy(sizePolicy2);
        labelStatic_QueueResults->setMinimumSize(QSize(150, 20));
        labelStatic_QueueResults->setFont(font2);
        labelStatic_QueueResults->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        labelStatic_QueueResults->setMargin(2);

        gridLayout->addWidget(labelStatic_QueueResults, 8, 3, 1, 2);

        labelStatic_TimeOperations = new QLabel(centralwidget);
        labelStatic_TimeOperations->setObjectName(QString::fromUtf8("labelStatic_TimeOperations"));
        sizePolicy2.setHeightForWidth(labelStatic_TimeOperations->sizePolicy().hasHeightForWidth());
        labelStatic_TimeOperations->setSizePolicy(sizePolicy2);
        labelStatic_TimeOperations->setMinimumSize(QSize(75, 20));
        labelStatic_TimeOperations->setFont(font2);
        labelStatic_TimeOperations->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        labelStatic_TimeOperations->setMargin(2);

        gridLayout->addWidget(labelStatic_TimeOperations, 8, 6, 1, 1);

        labelDinamic_TimeOperations = new QLabel(centralwidget);
        labelDinamic_TimeOperations->setObjectName(QString::fromUtf8("labelDinamic_TimeOperations"));
        sizePolicy2.setHeightForWidth(labelDinamic_TimeOperations->sizePolicy().hasHeightForWidth());
        labelDinamic_TimeOperations->setSizePolicy(sizePolicy2);
        labelDinamic_TimeOperations->setMinimumSize(QSize(75, 20));
        labelDinamic_TimeOperations->setFont(font3);
        labelDinamic_TimeOperations->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        labelDinamic_TimeOperations->setMargin(2);

        gridLayout->addWidget(labelDinamic_TimeOperations, 8, 7, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 641, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        buttonConsole_Clear->setText(QApplication::translate("MainWindow", "CLEAR", nullptr));
        buttonDigit_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        buttonDigit_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        buttonOperation_Sum->setText(QApplication::translate("MainWindow", "+", nullptr));
        labelStatic_QueueOperations->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\265\321\200\320\265\320\264\321\214 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        buttonOperation_Div->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
        buttonSpecial_Comma->setText(QApplication::translate("MainWindow", ",", nullptr));
        labelDinamic_QueueOperations->setText(QApplication::translate("MainWindow", "0", nullptr));
        buttonSpecial_Equal->setText(QApplication::translate("MainWindow", "=", nullptr));
        labelDinamic_PreviousOperand->setText(QString());
        buttonDigit_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        buttonDigit_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        buttonSpecial_C->setText(QApplication::translate("MainWindow", "\320\241", nullptr));
        labelDinamic_Operation->setText(QString());
        buttonDigit_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        buttonDigit_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        buttonDigit_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        labelDinamic_CurrentOperand->setText(QApplication::translate("MainWindow", "0", nullptr));
        buttonConsole_Next->setText(QApplication::translate("MainWindow", "NEXT", nullptr));
        labelStatic_NameConsole->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\201\320\276\320\273\321\214", nullptr));
        buttonDigit_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        buttonOperation_Mult->setText(QApplication::translate("MainWindow", "\342\210\227", nullptr));
        labelStatic_Support_1->setText(QString());
        textEdit_Console->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        buttonOperation_Mines->setText(QApplication::translate("MainWindow", "-", nullptr));
        buttonSpecial_X->setText(QApplication::translate("MainWindow", "\342\214\253", nullptr));
        buttonDigit_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        buttonSpecial_T->setText(QApplication::translate("MainWindow", "T", nullptr));
        labelStatic_Support_2->setText(QString());
        buttonDigit_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        buttonSpecial_SwitchSign->setText(QApplication::translate("MainWindow", "-/+", nullptr));
        labelDinamic_QueueResults->setText(QApplication::translate("MainWindow", "0", nullptr));
        labelStatic_QueueResults->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\265\321\200\320\265\320\264\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262:", nullptr));
        labelStatic_TimeOperations->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217(\321\201\320\265\320\272):", nullptr));
        labelDinamic_TimeOperations->setText(QApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
