#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <queue>
#include <QDebug>

int main(int argc, char *argv[])
{

    std::queue<int*> q;
    int* i = new int(5);
    q.push(i);
    int *p = q.front();
    q.pop();
    qDebug() << q.size();
    qDebug() << *p;


    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "InteltehCalculator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();
    w.ReadSettings();
    return a.exec();
}
