#pragma once
#ifndef _PERSON_H
#define _PERSON_H
#include<iostream>
#include<string>
#include<conio.h>
#include<cctype>
#include<windows.h>
using namespace std;
const char* AQUA_TEXT = "\033[36m";
const char* RESET_COLOR = "\033[0m";
const char* GREEN_TEXT = "\033[32m";
const char* YELLOW_TEXT = "\033[33m";

class Person
{
protected:
    string name;
    HANDLE hConsole;
    //string ID;

public:
    // Constructors
    Person();
    Person(string name);

    //destructors
   // virtual ~Person();
    // Virtual functions
    virtual void wellcome() = 0;
    virtual void registration_info() = 0;
    virtual void vehicles() = 0;
    virtual void view() = 0;
    virtual void notification() = 0;
    virtual void logout() = 0;

};
#endif
