#ifndef MUTEXEXCEPTION_H
#define MUTEXEXCEPTION_H

#include <exception>

class MutexException : std::exception
{
public:
    MutexException();

    /*!
     * \brief Содержание ошибки инициализации mutex
     * \return строка ошибки
     */
    const char* what() const noexcept override;
};

#endif // MUTEXEXCEPTION_H
