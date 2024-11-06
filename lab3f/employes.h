
#ifndef UNTITLED3_NAME_H
#define UNTITLED3_NAME_H

#include "name.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

class Department; // Предварительное объявление для использования в классе Employee,
// необходимо, когда два класса ссылаются друг на друга

class Employee {
    // Содержит приватные поля: name для имени сотрудника и department — указатель на объект Department.
private:
    std::string name;
    Department* department;

public:
    // Конструктор инициализирует эти поля. Список инициализации после двоеточия
    // : передает значения для name и department, ускоряя работу, так как инициализация идет напрямую.
    Employee(const std::string& name, Department* department = nullptr)
            : name(name), department(department) {}

    // Метод для установки отдела
    void setDepartment(Department* dept) {
        department = dept;
    }

    // Получение имени
    std::string getName() const {
        return name;
    }

    // Метод для печати информации о сотруднике
    void print() const;

    // Получение отдела сотрудника
    Department* getDepartment() const {
        return department;
    }

    // Метод для проверки, является ли сотрудник начальником отдела
    bool isDepartmentHead() const;
};

class Department {
private:
    // Поля класса: name — название отдела,
    // head — указатель на начальника отдела (объект Employee), и employees — список сотрудников.
    std::string name;
    Employee* head;
    std::vector<Employee*> employees;

public:
    // Конструктор инициализирует поля напрямую через список инициализации.
    Department(const std::string& name, Employee* head = nullptr)
            : name(name), head(head) {}

    // Установка начальника отдела
    void setHead(Employee* employee) {
        head = employee;
        addEmployee(employee);
    }

    // Добавление сотрудника в отдел
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
        employee->setDepartment(this); // Устанавливаем отдел для сотрудника
    }

    // Получение названия отдела
    std::string getName() const {
        return name;
    }

    // Получение начальника отдела
    Employee* getHead() const {
        return head;
    }

    // Получение всех сотрудников отдела
    const std::vector<Employee*>& getEmployees() const {
        return employees;
    }
};

// Реализация метода print() для Employee
void Employee::print() const {
    if (department) {
        if (isDepartmentHead()) {
            std::cout << name << " начальник отдела " << department->getName() << std::endl;
        }
        else {
            std::cout << name << " работает в отделе " << department->getName()
                      << ", начальник которого " << department->getHead()->getName() << std::endl;
        }
    }
    else {
        std::cout << name << " не прикреплен к отделу" << std::endl;
    }
}

// Проверка, является ли сотрудник начальником отдела
bool Employee::isDepartmentHead() const {
    return department && department->getHead() == this;
}






#endif //UNTITLED3_NAME_H
