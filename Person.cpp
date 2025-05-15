#include "Person.h"
// Default constructor
Person::Person()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
// Parameterized constructor
Person::Person(string name)
{
    this->name = name;
}
//destructor
/*Person::~Person()
{
    cout << "Person destructor called" << endl;
}*/
void Person::wellcome()
{
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "====================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "                               ::  Welcome to  ::             " << endl;
    cout << "                          Umar's Car Management System         " << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "====================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}