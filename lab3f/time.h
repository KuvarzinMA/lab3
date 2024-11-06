
#ifndef UNTITLED3_NAME_H
#define UNTITLED3_NAME_H

#include "name.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;



class Time {
private:
    int seconds; // общее количество секунд с начала суток

    // Метод для нормализации значения секунд в пределах суток, чтобы всегда оставаться в пределах одного дня
    void normalize() {
        seconds %= 86400; // 86400 секунд в сутках
        if (seconds < 0) {
            seconds += 86400;
        }
    }

public:
    // Конструктор по умолчанию
    Time() : seconds(0) {}

    // Конструктор с количеством секунд с начала суток
    Time(int sec) : seconds(sec) {
        normalize();
    }

    // Конструктор с указанием часов, минут и секунд
    Time(int hours, int minutes, int sec) {
        seconds = hours * 3600 + minutes * 60 + sec;
        normalize();
    }

    // Метод для получения текущего времени в формате ЧЧ:ММ:СС
    std::string getTextFormat() const {
        int hours = (seconds / 3600) % 24;
        int minutes = (seconds % 3600) / 60;
        int sec = seconds % 60;
        // создает объект oss, который представляет собой поток вывода, работающий со строками
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << sec;
        return oss.str();
    }

    // Вывод текущего времени в формате ЧЧ:ММ:СС
    void print() const {
        std::cout << "Текущее время: " << getTextFormat() << std::endl;
    }

    // Метод для получения текущего часа
    int getCurrentHour() const {
        return (seconds / 3600) % 24;
    }

    // Метод для получения минут с начала текущего часа
    int getMinutesFromCurrentHour() const {
        return (seconds % 3600) / 60;
    }

    // Метод для получения секунд с начала текущей минуты
    int getSecondsFromCurrentMinute() const {
        return seconds % 60;
    }

    // Метод для получения общего количества часов
    int getTotalHours() const {
        return seconds / 3600;
    }

    // Метод для получения общего количества минут
    int getTotalMinutes() const {
        return seconds / 60;
    }

    // Метод для получения общего количества секунд
    int getTotalSeconds() const {
        return seconds;
    }
};





#endif //UNTITLED3_NAME_H
