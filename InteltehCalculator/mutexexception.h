#ifndef MUTEXEXCEPTION_H
#define MUTEXEXCEPTION_H

#include <exception>

/*!
 * \brief Класс определяющий выброс исключения при инициализации мьютекса
 */
class MutexException : public std::exception
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
