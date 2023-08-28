#ifndef MUTEXADAPTER_H
#define MUTEXADAPTER_H

#include <pthread.h>
#include "mutexexception.h"

/*!
 * \brief Класс, организующий использование мьютекса
 * без синхронизации определённой последовательности передачи
 */
class MutexAdapter
{
    /// объект мьютекса, позволяющий организовывать
    /// потокобезопасное использование других объектов
    pthread_mutex_t mutex;
public:
    MutexAdapter();

    virtual ~MutexAdapter();

    /*!
     * \brief Функция ожидания освобожения mutex с последующей блокировкой
     */
    void Wait_for_lock();

    /*!
     * \brief Функция разблокировки мьютекса
     */
    void Unlock();

};

#endif // MUTEXADAPTER_H
