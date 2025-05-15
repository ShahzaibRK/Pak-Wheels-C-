#pragma once
#ifndef _SELLER_H
#define _SELLER_H
#include "Person.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Seller : public Person
{
protected:
    string seller_name;
    string seller_ID;
    string seller_password;
    string seller_address;
    string seller_phone;
    string seller_email;

public:
    Seller();
    Seller(string seller_name, string seller_ID, string seller_password, string seller_address, string seller_phone, string seller_email);
    //destructor
    ~Seller();

    // Overridden virtual functions
    void wellcome() override;
    void registration_info() override;
    void vehicles() override;
    //void seller_data();//in this function we will
    bool check_seller_data();
    void remove_vehicle();
    void menu();    //menu for seller
    void view() override;
    void notification() override;
    void logout() override;
    void contact_info();
    void auction();

};

#endif
