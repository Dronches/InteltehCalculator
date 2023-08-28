#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <memory>

#include "collectionscontainer.h"
#include "threadcomputationcollections.h"

/// Объект потока вычислений
pthread_t threadComputation;

/*!
 * \brief Бесконечный цикл выполнения операций с очередями
 * \param voidThreadComputationCollections объект выполнения операций с очередями
 */
void * thread_ComputationPerformer(void * voidThreadComputationCollections){
    // приведение к классу выполнения операций с очередями
    ThreadComputationCollections* threadComputationCollections = (ThreadComputationCollections*)voidThreadComputationCollections;
    // бесконечный цикл выполнения операций
    while(true){
        threadComputationCollections->PerformDoIt();
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Необязательный ввод транслятора
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

    // Создание объекта выполнения операций с очередями
    ThreadComputationCollections* threadComputationCollections =
            new ThreadComputationCollections(collectionsContainer);

    // Создание потока для выполнения операций с очередями
    if (pthread_create(&threadComputation, NULL, thread_ComputationPerformer, (void*)threadComputationCollections) != 0)
        return 1;

    // Отображение окна и инициализация его обработчика
    MainWindow w(collectionsContainer);
    w.ReadSettings(); // чтение параметров
    w.show(); // отображение
    return a.exec();
}
