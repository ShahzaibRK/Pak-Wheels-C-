#pragma once
#ifndef _ADMIN_H
#define _ADMIN_H
#include "Person.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;

class Admin : public Person
{
protected:
    string admin_name;
    string admin_ID;
    string admin_password;
    string admin_address;
    string admin_phone;
    string admin_email;

public:
    Admin();
    Admin(string admin_name, string admin_ID, string admin_password, string admin_address, string admin_phone, string admin_email);
    // Overridden virtual functions
    void wellcome() override;
    void registration_info() override;
    void vehicles() override;
    //void admin_data();//in this function we will
    void menu();    //menu for admin
    void view() override;
    void notification() override;
    bool check_admin_data();
    void remove_vehicle();
    void logout() override;
    void view_notification();
    void remove_notifcation();
    void inspection_report();
    void contact_info();


};
#endif