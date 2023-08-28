#include "mutexadapter.h"

MutexAdapter::MutexAdapter()
{

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
