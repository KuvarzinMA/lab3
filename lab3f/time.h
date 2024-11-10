// Time.h
#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
private:
    int seconds; // Количество секунд с начала суток

    void normalize(); // Приведение секунд в диапазон 0–86399

public:
    // Конструкторы
    Time();                      // Конструктор по умолчанию
    Time(int sec);               // Конструктор с количеством секунд
    Time(int hours, int minutes, int sec); // Конструктор с часами, минутами, секундами

    // Методы для получения времени в различных форматах
    std::string getTextFormat() const;
    void print() const;

    // Методы для получения текущего часа, минут с начала часа и секунд с начала минуты
    int getCurrentHour() const;
    int getMinutesFromCurrentHour() const;
    int getSecondsFromCurrentMinute() const;

    // Методы для получения общего количества часов, минут и секунд
    int getTotalHours() const;
    int getTotalMinutes() const;
    int getTotalSeconds() const;
};

#endif // TIME_H
