// main.cpp
#include <iostream>
#include "Name.h"
#include "Time.h"
#include "Employee.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    // Создаем объекты класса Name
    Name cleopatra("", "Клеопатра", "");
    Name pushkin("Пушкин", "Александр", "Сергеевич");
    Name mayakovsky("Маяковский", "Владимир", "");

    // Выводим результаты работы методов
    cout << "Имена:" << endl;
    cout << "Имя 1: ";
    cleopatra.print();

    cout << "Имя 2: ";
    pushkin.print();

    cout << "Имя 3: ";
    mayakovsky.print();

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
    std::cout << "Секунд соответствуют времени 123: " << task3.getTotalSeconds() << std::endl;


    // Создаем сотрудников
    Employee petrov("Петров");
    Employee kozlov("Козлов");
    Employee sidorov("Сидоров");

    // Создаем отдел IT и назначаем Козлова начальником
    Department itDepartment("IT");
    itDepartment.setHead(&kozlov);

    // Добавляем сотрудников в отдел IT
    itDepartment.addEmployee(&petrov);
    itDepartment.addEmployee(&sidorov);

    // Выводим информацию о каждом сотруднике
    petrov.print();
    kozlov.print();
    sidorov.print();

    // Запрашиваем имя сотрудника для отображения списка сотрудников его отдела
    std::string employeeName;
    std::cout << "\nВведите имя сотрудника для отображения списка всех сотрудников его отдела: ";
    std::getline(std::cin, employeeName);

    // Определяем указатель на выбранного сотрудника
    Employee* selectedEmployee = nullptr;
    if (employeeName == "Петров") {
        selectedEmployee = &petrov;
    }
    else if (employeeName == "Козлов") {
        selectedEmployee = &kozlov;
    }
    else if (employeeName == "Сидоров") {
        selectedEmployee = &sidorov;
    }
    else {
        std::cout << "Сотрудник с именем " << employeeName << " не найден.\n";
    }

    // Если сотрудник найден и у него есть отдел, выводим список сотрудников его отдела
    if (selectedEmployee && selectedEmployee->getDepartment()) {
        Department* department = selectedEmployee->getDepartment();
        std::cout << "\nСписок сотрудников отдела " << department->getName() << ":\n";
        for (const auto& emp : department->getEmployees()) {
            std::cout << "- " << emp->getName() << std::endl;
        }
    }

    return 0;
}
