// Time.cpp
#include "Time.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Приведение секунд в диапазон 0–86399 (в пределах суток)
void Time::normalize() {
    seconds %= 86400; // 86400 секунд в сутках
    if (seconds < 0) {
        seconds += 86400;
    }
}

// Конструкторы
Time::Time() : seconds(0) {}

Time::Time(int sec) : seconds(sec) {
    normalize();
}

Time::Time(int hours, int minutes, int sec) {
    seconds = hours * 3600 + minutes * 60 + sec;
    normalize();
}

// Возвращает текущее время в формате ЧЧ:ММ:СС
std::string Time::getTextFormat() const {
    int hours = (seconds / 3600) % 24;
    int minutes = (seconds % 3600) / 60;
    int sec = seconds % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << sec;
    return oss.str();
}

// Выводит текущее время в формате ЧЧ:ММ:СС
void Time::print() const {
    std::cout << "Текущее время: " << getTextFormat() << std::endl;
}

// Получает текущий час
int Time::getCurrentHour() const {
    return (seconds / 3600) % 24;
}

// Получает минуты с начала текущего часа
int Time::getMinutesFromCurrentHour() const {
    return (seconds % 3600) / 60;
}

// Получает секунды с начала текущей минуты
int Time::getSecondsFromCurrentMinute() const {
    return seconds % 60;
}

// Возвращает общее количество часов
int Time::getTotalHours() const {
    return seconds / 3600;
}

// Возвращает общее количество минут
int Time::getTotalMinutes() const {
    return seconds / 60;
}

// Возвращает общее количество секунд
int Time::getTotalSeconds() const {
    return seconds;
}
