#include "employes.h"

// Главная функция
int main() {
    setlocale(LC_ALL, "RUSSIAN");



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

    // Проверяем, к какому сотруднику относится введенное имя, и выводим список сотрудников его отдела
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
