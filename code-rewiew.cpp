#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

class Department;

class Employee {
    
private:
    std::string name;
    Department* department;

public:

    Employee(const std::string& name, Department* department = nullptr)
        : name(name), department(department) {
    }

    void setDepartment(Department* dept) {
        department = dept;
    }

    std::string getName() const {
        return name;
    }

    void print() const;

    Department* getDepartment() const {
        return department;
    }

    bool isDepartmentHead() const;
};


class Department {
private:

    std::string name;
    Employee* head;
    std::vector<Employee*> employees;

public:

    Department(const std::string& name, Employee* head = nullptr)
        : name(name), head(head) {
    }

    void setHead(Employee* employee) {
        head = employee;
        addEmployee(employee);
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
        employee->setDepartment(this); 
    }

    std::string getName() const {
        return name;
    }

    Employee* getHead() const {
        return head;
    }

    const std::vector<Employee*>& getEmployees() const {
        return employees;
    }
};

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

bool Employee::isDepartmentHead() const {
    return department && department->getHead() == this;
}


class Name {
private:

    string surname;      
    string first_name;   
    string patronymic;   

public:

    Name(string s = "", string f = "", string p = "") : surname(s), first_name(f), patronymic(p) {}

    void print() const {
        if (!surname.empty()) cout << surname;
        if (!first_name.empty()) cout << (surname.empty() ? "" : " ") << first_name;
        if (!patronymic.empty()) cout << ((surname.empty() && first_name.empty()) ? "" : " ") << patronymic;
        cout << endl;
    }

    string to_string() const {
        string result;
        if (!surname.empty()) result += surname;
        if (!first_name.empty()) result += (result.empty() ? "" : " ") + first_name;
        if (!patronymic.empty()) result += (result.empty() ? "" : " ") + patronymic;
        return result;
    }
};


class Time {
private:
    int seconds; 


    void normalize() {
        seconds %= 86400; 
        if (seconds < 0) {
            seconds += 86400;
        }
    }

public:

    Time() : seconds(0) {}

    Time(int sec) : seconds(sec) {
        normalize();
    }

    Time(int hours, int minutes, int sec) {
        seconds = hours * 3600 + minutes * 60 + sec;
        normalize();
    }

    std::string getTextFormat() const {
        int hours = (seconds / 3600) % 24;
        int minutes = (seconds % 3600) / 60;
        int sec = seconds % 60;
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << sec;
        return oss.str();
    }

    void print() const {
        std::cout << "Текущее время: " << getTextFormat() << std::endl;
    }

    int getCurrentHour() const {
        return (seconds / 3600) % 24;
    }

    int getMinutesFromCurrentHour() const {
        return (seconds % 3600) / 60;
    }

    int getSecondsFromCurrentMinute() const {
        return seconds % 60;
    }

    int getTotalHours() const {
        return seconds / 3600;
    }

    int getTotalMinutes() const {
        return seconds / 60;
    }

    int getTotalSeconds() const {
        return seconds;
    }
};



int main() {
    setlocale(LC_ALL, "RUSSIAN");

    try {
        cout << "Введите имена для демонстрации (Фамилия Имя Отчество):" << endl;

        Name names[3];
        for (int i = 0; i < 3; i++) {
            string last, first, middle;
            cout << "Имя " << i + 1 << " (введите через пробелы): ";
            cin >> last >> first;
            cin.ignore(); 
            getline(cin, middle); 

            names[i] = Name(last, first, middle);
        }

        cout << "\nВведенные имена:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Имя " << i + 1 << ": ";
            names[i].print();
        }
        cout << endl;

        cout << "Введите время в разных форматах:" << endl;

        int seconds;
        cout << "Введите время в секундах: ";
        while (!(cin >> seconds) || seconds < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        }
        Time t1(seconds);
        cout << "Текстовая форма времени: "; t1.print();

        int h, m, s;
        cout << "Введите время (часы минуты секунды): ";
        while (!(cin >> h >> m >> s) || h < 0 || m < 0 || m >= 60 || s < 0 || s >= 60) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите корректное время (часы 0-23, минуты 0-59, секунды 0-59): ";
        }
        Time t2(h, m, s);
        cout << "Текстовая форма времени: "; t2.print();

        vector<Employee> employees;
        vector<Department> departments;

        int empCount;
        cout << "\nСколько сотрудников вы хотите создать? ";
        while (!(cin >> empCount) || empCount <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        }
        cin.ignore(); 

        for (int i = 0; i < empCount; i++) {
            string name;
            cout << "Введите имя сотрудника " << i + 1 << ": ";
            getline(cin, name);
            employees.emplace_back(name);
        }

        int deptCount;
        cout << "\nСколько отделов вы хотите создать? ";
        while (!(cin >> deptCount) || deptCount <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        }
        cin.ignore(); 

        for (int i = 0; i < deptCount; i++) {
            string name;
            cout << "Введите название отдела " << i + 1 << ": ";
            getline(cin, name);
            departments.emplace_back(name);

            if (!employees.empty()) {
                cout << "Выберите начальника для отдела " << name << " (введите номер сотрудника 1-" << employees.size() << "): ";
                int headIdx;
                while (!(cin >> headIdx) || headIdx < 1 || headIdx > employees.size()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка! Введите номер от 1 до " << employees.size() << ": ";
                }
                departments.back().setHead(&employees[headIdx - 1]);
            }

            cout << "Добавьте сотрудников в отдел " << name << " (введите номера через пробел, 0 для завершения): ";
            cin.ignore();
            string input;
            getline(cin, input);

            size_t pos = 0;
            while (pos < input.length()) {
                size_t end = input.find(' ', pos);
                if (end == string::npos) end = input.length();

                string numStr = input.substr(pos, end - pos);
                if (!numStr.empty() && numStr != "0") {
                    try {
                        int empNum = stoi(numStr);
                        if (empNum >= 1 && empNum <= employees.size()) {
                            departments.back().addEmployee(&employees[empNum - 1]);
                        }
                    }
                    catch (...) {
                       
                    }
                }
                pos = end + 1;
            }
        }

        cout << "\nИнформация о сотрудниках:" << endl;
        for (auto& emp : employees) {
            emp.print();
        }

        string searchName;
        cout << "\nВведите имя сотрудника для поиска: ";
        getline(cin, searchName);

        bool found = false;
        for (auto& emp : employees) {
            if (emp.getName() == searchName) {
                found = true;
                cout << "Сотрудник найден:" << endl;
                emp.print();

                if (emp.getDepartment()) {
                    cout << "\nСписок сотрудников отдела " << emp.getDepartment()->getName() << ":" << endl;
                    for (const auto& deptEmp : emp.getDepartment()->getEmployees()) {
                        cout << "- " << deptEmp->getName() << endl;
                    }
                }
                else {
                    cout << "Сотрудник не принадлежит ни к одному отделу." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Сотрудник с именем '" << searchName << "' не найден." << endl;
        }

    }
    catch (const exception& e) {
        cerr << "Произошла ошибка: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Произошла неизвестная ошибка" << endl;
        return 2;
    }

    return 0;
}
