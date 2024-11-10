// Name.cpp
#include "name.h"
#include <iostream>

using namespace std;

// Конструктор с инициализацией полей
Name::Name(string s, string f, string p) : surname(s), first_name(f), patronymic(p) {}

// Метод для вывода имени
void Name::print() const {
    if (!surname.empty()) cout << surname;
    if (!first_name.empty()) cout << (surname.empty() ? "" : " ") << first_name;
    if (!patronymic.empty()) cout << ((surname.empty() && first_name.empty()) ? "" : " ") << patronymic;
    cout << endl;
}

// Метод для преобразования имени к строковому виду
string Name::to_string() const {
    string result;
    if (!surname.empty()) result += surname;
    if (!first_name.empty()) result += (result.empty() ? "" : " ") + first_name;
    if (!patronymic.empty()) result += (result.empty() ? "" : " ") + patronymic;
    return result;
}
