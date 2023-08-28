#ifndef TEMPLATECOLLECTION_H
#define TEMPLATECOLLECTION_H

#include <queue>
#include "mutexadapter.h"

template <class T>
/*!
 * \brief Класс, обеспечивающий взаимодействие с очередями (для операций/результатов)
 */
class TemplateCollection : public MutexAdapter
{
    /// Очередь объектов используемого типа (операция/результат)
    std::queue<T*> queueData;

public:
    TemplateCollection();

    ~TemplateCollection();

    /*!
     * \brief Получить размер очереди
     * \return
     */
    int GetSize();

    /*!
     * \brief Добавить элемент в конец очереди
     * \param element добавляемый элемент
     */
    void PushBack(T* element);

    /*!
     * \brief Извлечь элемент из начала очереди
     * \return извлечённый элемент
     */
    T* PopFront();
};

template <class T>
TemplateCollection<T>::TemplateCollection() : MutexAdapter()
{

}

template <class T>
TemplateCollection<T>::~TemplateCollection()
{
    // безопасное удаление всех элементов в очереди
    while(GetSize()>0)
    {
        delete queueData.front();
        queueData.pop();
    }
}

template <class T>
int TemplateCollection<T>::GetSize()
{
    return queueData.size();
}

template <class T>
void TemplateCollection<T>::PushBack(T* element)
{
    queueData.push(element);
}

template <class T>
T* TemplateCollection<T>::PopFront()
{
    T* tempData = queueData.front();
    queueData.pop();
    return tempData;
}


#endif // TEMPLATECOLLECTION_H
