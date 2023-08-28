#ifndef THREADCOMPUTATIONCOLLECTIONS_H
#define THREADCOMPUTATIONCOLLECTIONS_H

#include "timermilliseconds.h"
#include "collectionscontainer.h"
#include "calculatoroperationslib.h"

/*!
 * \brief Класс для организации выполнения вычислений на отдельном потоке
 */
class ThreadComputationCollections
{

    /// Таймер для осуществления задержек и имитации долгих вычислений
    TimerMilliseconds timer;
    /// Объект взаимодействия с очередями (shared - для многопоточности)
    std::shared_ptr<CollectionsContainer> collectionContainer;
public:

    ThreadComputationCollections(std::shared_ptr<CollectionsContainer> collectionContainer);

    /*!
     * \brief Выполнить операцию из начала очереди операций и поместить в конец очереди результатов
     * \return флаг - была ли произведена операция (= есть ли элементы в очереди операций)
     */
    bool PerformDoIt();
};

#endif // THREADCOMPUTATIONCOLLECTIONS_H
