#include "timermilliseconds.h"

const int TimerMilliseconds::milliTimeSleep = 100;

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
    // Расчёт оставшегося времени ожидания
    std::chrono::milliseconds timeWait = std::chrono::milliseconds(millisecodsDuration) -
                    std::chrono::duration_cast<std::chrono::milliseconds>
                        (std::chrono::steady_clock::now() - StartTime);
    // При наличии остатка времени производить ожидание
    if (timeWait.count()>0)
        std::this_thread::sleep_for(
                    timeWait
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
