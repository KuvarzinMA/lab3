// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

// Предварительное объявление класса Department
class Department;

class Employee {
private:
    std::string name;
    Department* department;

public:
    // Конструктор
    Employee(const std::string& name, Department* department = nullptr);

    // Метод для установки отдела
    void setDepartment(Department* dept);

    // Метод для получения имени
    std::string getName() const;

    // Метод для печати информации о сотруднике
    void print() const;

    // Метод для проверки, является ли сотрудник начальником отдела
    bool isDepartmentHead() const;

    // Метод для получения указателя на отдел
    Department* getDepartment() const;
};

class Department {
private:
    std::string name;
    Employee* head;
    std::vector<Employee*> employees;

public:
    // Конструктор
    Department(const std::string& name, Employee* head = nullptr);

    // Установка начальника отдела
    void setHead(Employee* employee);

    // Добавление сотрудника в отдел
    void addEmployee(Employee* employee);

    // Получение названия отдела
    std::string getName() const;

    // Получение начальника отдела
    Employee* getHead() const;

    // Получение всех сотрудников отдела
    const std::vector<Employee*>& getEmployees() const;
};

#endif // EMPLOYEE_H
