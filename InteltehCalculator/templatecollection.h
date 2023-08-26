#ifndef TEMPLATECOLLECTION_H
#define TEMPLATECOLLECTION_H

#include <queue>


template <class T>
class TemplateCollection
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

#endif // TEMPLATECOLLECTION_H
