#include "mutexadapter.h"

MutexAdapter::MutexAdapter()
{
    if (pthread_mutex_init(&mutex, NULL) != 0)
        throw std::exception();
}

MutexAdapter::~MutexAdapter()
{
    pthread_mutex_destroy(&mutex);
}

void MutexAdapter::Wait_for_lock()
{
    pthread_mutex_lock(&mutex);
}

void MutexAdapter::Unlock()
{
    pthread_mutex_unlock(&mutex);
}
