#include "timermilliseconds.h"

const int TimerMilliseconds::milliTimeSleep = 1;

TimerMilliseconds::TimerMilliseconds()
{
    StartTime = std::chrono::steady_clock::now();
}

void TimerMilliseconds::StartTimer()
{
   StartTime = std::chrono::steady_clock::now();
}

void TimerMilliseconds::WaitForStopTimer(int millisecodsDuration)
{
    // При наличии остатка времени производить ожидание (отрицательные значения не запукают ожидание)
    std::this_thread::sleep_for(
                // Расчёт оставшегося времени ожидания
                std::chrono::milliseconds(millisecodsDuration) -
                                std::chrono::duration_cast<std::chrono::milliseconds>
                                    (std::chrono::steady_clock::now() - StartTime)
                );


}

void TimerMilliseconds::ThreadSleep()
{
    std::this_thread::sleep_for(
                    std::chrono::milliseconds(milliTimeSleep)
                );

}

void TimerMilliseconds::ThreadSleep(int milliseconds)
{
    std::this_thread::sleep_for(
                    std::chrono::milliseconds(milliseconds)
                );

}
