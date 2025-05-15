#pragma once
#ifndef _BUYER_H
#define _BUYER_H
#include "Person.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Buyer : public Person
{
protected:
    string buyer_name;
    string buyer_ID;
    string buyer_password;
    string buyer_address;
    string buyer_phone;
    string buyer_email;

public:
    Buyer();
    Buyer(string buyer_name, string buyer_ID, string buyer_password, string buyer_address, string buyer_phone, string buyer_email);
    //destructor
    ~Buyer();
    // Overridden virtual functions
    void wellcome() override;
    void registration_info() override;
    void vehicles() override;
    //void buyer_data();//in this function we will
    void menu();    //menu for buyer
    void view() override;
    void notification() override;
    bool check_buyer_data();
    void logout() override;
    void isnpection_report();
    bool contact_info();
    void view_auction();

};
#endif