#ifndef TIMERMILLISECONDS_H
#define TIMERMILLISECONDS_H

#include <chrono>
#include <ctime>
#include <thread>

/*!
 * \brief Класс - таймер в милисекундах для осуществления имитации ожидания
 */
class TimerMilliseconds
{
    /// Осечка времени начала отсчёта таймера
    std::chrono::time_point<std::chrono::steady_clock> StartTime;
    /// Время ожидания (для случаев, когда нет операций в очереди)
    static const int milliTimeSleep;
public:

    TimerMilliseconds();

    /*!
     * \brief Запуск таймера (установить в таймер текущее время)
     */
    void StartTimer();

    /*!
     * \brief Ожидание для имитации задержки операции
     * \param millisecodsDuration общее время задержки в милисекундах
     */
    void WaitForStopTimer(int millisecodsDuration);

    /*!
     * \brief Ожидание потока определённое число милисекунд, заданное параметром milliTimeSleep
     */
    static void ThreadSleep();

    /*!
     * \brief Ожидание потока определённое число милисекунд, заданное параметром
     * \param milliseconds число милисекунд ожидания
     */
    static void ThreadSleep(int milliseconds);
};

#endif // TIMERMILLISECONDS_H
