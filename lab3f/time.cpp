#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;



// Класс Time
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


// Главная функция
int main() {
    setlocale(LC_ALL, "RUSSIAN");


    // Демонстрация работы класса Time
    // Создание объектов времени для различных вариантов времени
    Time t1(10);          // 10 секунд с начала суток
    Time t2(10000);       // 10000 секунд с начала суток
    Time t3(100000);      // 100000 секунд с начала суток
    Time t4(2, 3, 5);     // 2 часа, 3 минуты, 5 секунд

    // Вывод различных вариантов времени в формате ЧЧ:ММ:СС
    std::cout << "Текстовая форма времени для 10 секунд: "; t1.print();
    std::cout << "Текстовая форма времени для 10000 секунд: "; t2.print();
    std::cout << "Текстовая форма времени для 100000 секунд: "; t3.print();
    std::cout << "Текстовая форма для 2 часов, 3 минут, 5 секунд: "; t4.print();

    // Вывод информации о текущем времени
    std::cout << "\nДля времени 02:03:05\n";
    std::cout << "Часы: " << t4.getCurrentHour() << std::endl;
    std::cout << "Минуты: " << t4.getMinutesFromCurrentHour() << std::endl;
    std::cout << "Секунды: " << t4.getSecondsFromCurrentMinute() << "\n" << std::endl;

    // Дополнительные задачи
    Time task1(34056);
    std::cout << "Часов соответствуют времени 34056: " << task1.getTotalHours() << std::endl;

    Time task2(4532);
    std::cout << "Минут соответствуют времени 4532: " << task2.getTotalMinutes() << std::endl;

    Time task3(123);
    std::cout << "Секунд соответствуют времени 123: " << task3.getTotalSeconds() << "\n" << std::endl;


    

    return 0;
}
