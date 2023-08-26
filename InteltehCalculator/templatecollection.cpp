#include "templatecollection.h"

template <class T>
TemplateCollection<T>::TemplateCollection()
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
