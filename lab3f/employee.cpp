// Employee.cpp
#include "Employee.h"
#include <iostream>

// Реализация конструктора для Employee
Employee::Employee(const std::string& name, Department* department)
    : name{ name }, department{ department } {}

// Установка отдела
void Employee::setDepartment(Department* dept) {
    department = dept;
}

// Получение имени сотрудника
std::string Employee::getName() const {
    return name;
}

// Вывод информации о сотруднике
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

// Получение указателя на отдел
Department* Employee::getDepartment() const {
    return department;
}

// Реализация конструктора для Department
Department::Department(const std::string& name, Employee* head)
    : name{ name }, head{ head } {
    if (head) {
        addEmployee(head); // Добавляем начальника в список сотрудников
    }
}

// Установка начальника отдела
void Department::setHead(Employee* employee) {
    head = employee;
    addEmployee(employee); // Добавляем начальника в список сотрудников
}

// Добавление сотрудника в отдел
void Department::addEmployee(Employee* employee) {
    employees.push_back(employee);
    employee->setDepartment(this);
}

// Получение названия отдела
std::string Department::getName() const {
    return name;
}

// Получение начальника отдела
Employee* Department::getHead() const {
    return head;
}

// Получение всех сотрудников отдела
const std::vector<Employee*>& Department::getEmployees() const {
    return employees;
}
