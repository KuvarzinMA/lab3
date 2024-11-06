#ifndef UNTITLED3_NAME_H
#define UNTITLED3_NAME_H


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

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



#endif //UNTITLED3_NAME_H
