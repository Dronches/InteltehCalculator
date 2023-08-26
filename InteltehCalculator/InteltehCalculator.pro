QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculatoroperationqueues.cpp \
    errorsspecifier_mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    operationinfo.cpp \
    templatecollection.cpp \
    verifyinfo_mainwindow.cpp

HEADERS += \
    calculatoroperationqueues.h \
    errorsspecifier_mainwindow.h \
    mainwindow.h \
    operationinfo.h \
    templatecollection.h \
    verifyinfo_mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    InteltehCalculator_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../build-CalculatorOperationsLib-Desktop_Qt_5_12_12_GCC_64bit-Release/ -lCalculatorOperationsLib

INCLUDEPATH += $$PWD/../CalculatorOperationsLib
DEPENDPATH += $$PWD/../CalculatorOperationsLib
