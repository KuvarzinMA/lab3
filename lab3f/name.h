// Name.h
#ifndef NAME_H
#define NAME_H

#include <string>

// Объявление класса Name
class Name {
private:
    std::string surname;      // Фамилия
    std::string first_name;   // Имя
    std::string patronymic;   // Отчество

public:
    // Конструктор с параметрами
    Name(std::string s = "", std::string f = "", std::string p = "");

    // Метод для вывода имени
    void print() const;

    // Метод для преобразования к строковому виду
    std::string to_string() const;
};

#endif // NAME_H
