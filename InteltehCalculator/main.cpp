#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <memory>

#include "collectionscontainer.h"


int main(int argc, char *argv[])
{
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
    // Создание разделяемого указателя на контейнер очередей
    std::shared_ptr<CollectionsContainer> collectionsContainer =
            std::make_shared<CollectionsContainer>();


    MainWindow w(collectionsContainer);
    w.show();
    w.ReadSettings();
    return a.exec();
}
