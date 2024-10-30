#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
using namespace std;

class Department; // ��������������� ���������� ��� ������������� � ������ Employee

class Employee {
private:
    std::string name;
    Department* department;

public:
    // �����������
    Employee(const std::string& name, Department* department = nullptr)
        : name(name), department(department) {}

    // ����� ��� ��������� ������
    void setDepartment(Department* dept) {
        department = dept;
    }

    // ��������� �����
    std::string getName() const {
        return name;
    }

    // ����� ��� ������ ���������� � ����������
    void print() const;

    // ��������� ������ ����������
    Department* getDepartment() const {
        return department;
    }

    // ����� ��� ��������, �������� �� ��������� ����������� ������
    bool isDepartmentHead() const;
};

class Department {
private:
    std::string name;
    Employee* head;
    std::vector<Employee*> employees;

public:
    // �����������
    Department(const std::string& name, Employee* head = nullptr)
        : name(name), head(head) {}

    // ��������� ���������� ������
    void setHead(Employee* employee) {
        head = employee;
        addEmployee(employee);
    }

    // ���������� ���������� � �����
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
        employee->setDepartment(this); // ������������� ����� ��� ����������
    }

    // ��������� �������� ������
    std::string getName() const {
        return name;
    }

    // ��������� ���������� ������
    Employee* getHead() const {
        return head;
    }

    // ��������� ���� ����������� ������
    const std::vector<Employee*>& getEmployees() const {
        return employees;
    }
};

// ���������� ������ print() ��� Employee
void Employee::print() const {
    if (department) {
        if (isDepartmentHead()) {
            std::cout << name << " ��������� ������ " << department->getName() << std::endl;
        }
        else {
            std::cout << name << " �������� � ������ " << department->getName()
                << ", ��������� �������� " << department->getHead()->getName() << std::endl;
        }
    }
    else {
        std::cout << name << " �� ���������� � ������" << std::endl;
    }
}

// ��������, �������� �� ��������� ����������� ������
bool Employee::isDepartmentHead() const {
    return department && department->getHead() == this;
}

// ����� Name
class Name {
private:
    string surname;      // �������
    string first_name;   // ���
    string patronymic;   // ��������

public:
    // ����������� � ����������� �� ���������
    Name(string s = "", string f = "", string p = "") : surname(s), first_name(f), patronymic(p) {}

    // ����� ��� ������ � ��������� ����
    void print() const {
        if (!surname.empty()) cout << surname;
        if (!first_name.empty()) cout << (surname.empty() ? "" : " ") << first_name;
        if (!patronymic.empty()) cout << ((surname.empty() && first_name.empty()) ? "" : " ") << patronymic;
        cout << endl;
    }

    // �������������� � ���������� ����
    string to_string() const {
        string result;
        if (!surname.empty()) result += surname;
        if (!first_name.empty()) result += (result.empty() ? "" : " ") + first_name;
        if (!patronymic.empty()) result += (result.empty() ? "" : " ") + patronymic;
        return result;
    }
};

// ����� Time
class Time {
private:
    int seconds; // ����� ���������� ������ � ������ �����

    // ����� ��� ������������ �������� ������ � �������� �����
    void normalize() {
        seconds %= 86400; // 86400 ������ � ������
        if (seconds < 0) {
            seconds += 86400;
        }
    }

public:
    // ����������� �� ���������
    Time() : seconds(0) {}

    // ����������� � ����������� ������ � ������ �����
    Time(int sec) : seconds(sec) {
        normalize();
    }

    // ����������� � ��������� �����, ����� � ������
    Time(int hours, int minutes, int sec) {
        seconds = hours * 3600 + minutes * 60 + sec;
        normalize();
    }

    // ����� ��� ��������� �������� ������� � ������� ��:��:��
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

    // ����� �������� ������� � ������� ��:��:��
    void print() const {
        std::cout << "������� �����: " << getTextFormat() << std::endl;
    }

    // ����� ��� ��������� �������� ����
    int getCurrentHour() const {
        return (seconds / 3600) % 24;
    }

    // ����� ��� ��������� ����� � ������ �������� ����
    int getMinutesFromCurrentHour() const {
        return (seconds % 3600) / 60;
    }

    // ����� ��� ��������� ������ � ������ ������� ������
    int getSecondsFromCurrentMinute() const {
        return seconds % 60;
    }

    // ����� ��� ��������� ������ ���������� �����
    int getTotalHours() const {
        return seconds / 3600;
    }

    // ����� ��� ��������� ������ ���������� �����
    int getTotalMinutes() const {
        return seconds / 60;
    }

    // ����� ��� ��������� ������ ���������� ������
    int getTotalSeconds() const {
        return seconds;
    }
};


// ������� �������
int main() {
    setlocale(LC_ALL, "RUSSIAN");

    // ������������ ������ ������ Name
    cout << "�����:" << endl;
    Name cleopatra("", "���������", "");
    Name pushkin("������", "���������", "���������");
    Name mayakovsky("����������", "��������", "");

    cout << "��� 1: ";
    cleopatra.print();
    cout << "��� 2: ";
    pushkin.print();
    cout << "��� 3: ";
    mayakovsky.print();
    cout << endl;

    // ������������ ������ ������ Time
    // �������� �������� ������� ��� ��������� ��������� �������
    Time t1(10);          // 10 ������ � ������ �����
    Time t2(10000);       // 10000 ������ � ������ �����
    Time t3(100000);      // 100000 ������ � ������ �����
    Time t4(2, 3, 5);     // 2 ����, 3 ������, 5 ������

    // ����� ��������� ��������� ������� � ������� ��:��:��
    std::cout << "��������� ����� ������� ��� 10 ������: "; t1.print();
    std::cout << "��������� ����� ������� ��� 10000 ������: "; t2.print();
    std::cout << "��������� ����� ������� ��� 100000 ������: "; t3.print();
    std::cout << "��������� ����� ��� 2 �����, 3 �����, 5 ������: "; t4.print();

    // ����� ���������� � ������� �������
    std::cout << "\n��� ������� 02:03:05\n";
    std::cout << "����: " << t4.getCurrentHour() << std::endl;
    std::cout << "������: " << t4.getMinutesFromCurrentHour() << std::endl;
    std::cout << "�������: " << t4.getSecondsFromCurrentMinute() << "\n" << std::endl;

    // �������������� ������
    Time task1(34056);
    std::cout << "����� ������������� ������� 34056: " << task1.getTotalHours() << std::endl;

    Time task2(4532);
    std::cout << "����� ������������� ������� 4532: " << task2.getTotalMinutes() << std::endl;

    Time task3(123);
    std::cout << "������ ������������� ������� 123: " << task3.getTotalSeconds() << "\n" << std::endl;

    // ������� �����������
    Employee petrov("������");
    Employee kozlov("������");
    Employee sidorov("�������");

    // ������� ����� IT � ��������� ������� �����������
    Department itDepartment("IT");
    itDepartment.setHead(&kozlov);

    // ��������� ����������� � ����� IT
    itDepartment.addEmployee(&petrov);
    itDepartment.addEmployee(&sidorov);

    // ������� ���������� � ������ ����������
    petrov.print();
    kozlov.print();
    sidorov.print();

    // ����������� ��� ���������� ��� ����������� ������ ����������� ��� ������
    std::string employeeName;
    std::cout << "\n������� ��� ���������� ��� ����������� ������ ���� ����������� ��� ������: ";
    std::getline(std::cin, employeeName);

    // ���������, � ������ ���������� ��������� ��������� ���, � ������� ������ ����������� ��� ������
    Employee* selectedEmployee = nullptr;
    if (employeeName == "������") {
        selectedEmployee = &petrov;
    }
    else if (employeeName == "������") {
        selectedEmployee = &kozlov;
    }
    else if (employeeName == "�������") {
        selectedEmployee = &sidorov;
    }
    else {
        std::cout << "��������� � ������ " << employeeName << " �� ������.\n";
    }

    // ���� ��������� ������ � � ���� ���� �����, ������� ������ ����������� ��� ������
    if (selectedEmployee && selectedEmployee->getDepartment()) {
        Department* department = selectedEmployee->getDepartment();
        std::cout << "\n������ ����������� ������ " << department->getName() << ":\n";
        for (const auto& emp : department->getEmployees()) {
            std::cout << "- " << emp->getName() << std::endl;
        }
    }

    return 0;
}
