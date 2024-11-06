#include "time.h"
#include <iostream>
#include <string>
using namespace std;




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
