#include "name.h"
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


    return 0;
}
