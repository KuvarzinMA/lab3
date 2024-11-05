#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
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

// Класс Name
class Name {
private:
    string surname;      // Фамилия
    string first_name;   // Имя
    string patronymic;   // Отчество

public:
    // Конструктор с параметрами по умолчанию
    Name(string s = "", string f = "", string p = "") : surname(s), first_name(f), patronymic(p) {}

    // Метод для вывода в строковом виде
    void print() const {
        if (!surname.empty()) cout << surname;
        if (!first_name.empty()) cout << (surname.empty() ? "" : " ") << first_name;
        if (!patronymic.empty()) cout << ((surname.empty() && first_name.empty()) ? "" : " ") << patronymic;
        cout << endl;
    }

    // Преобразование к строковому виду
    string to_string() const {
        string result;
        if (!surname.empty()) result += surname;
        if (!first_name.empty()) result += (result.empty() ? "" : " ") + first_name;
        if (!patronymic.empty()) result += (result.empty() ? "" : " ") + patronymic;
        return result;
    }
};

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

    // Демонстрация работы класса Name
    cout << "Имена:" << endl;
    Name cleopatra("", "Клеопатра", "");
    Name pushkin("Пушкин", "Александр", "Сергеевич");
    Name mayakovsky("Маяковский", "Владимир", "");

    cout << "Имя 1: ";
    cleopatra.print();
    cout << "Имя 2: ";
    pushkin.print();
    cout << "Имя 3: ";
    mayakovsky.print();
    cout << endl;

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
