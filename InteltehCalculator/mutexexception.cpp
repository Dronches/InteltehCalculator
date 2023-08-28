#include "mutexexception.h"

MutexException::MutexException()
{

}

const char* MutexException::what() const noexcept
{
    return "Failed mutex Initialization";
}
