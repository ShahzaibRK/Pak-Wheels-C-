// vehicle.h
#pragma once
#ifndef _VEHICLE_H
#define _VEHICLE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    string* name;
    string* company;
    string* model;
    int mileage;
    double price;
    int rating;

public:
    Vehicle();//default constructor
    Vehicle(const Vehicle& veh);//copy constructor
    ~Vehicle();//destructor
    Vehicle(string name, string company, string model, int mileage, double price, int rating);
    void input_data();
    void vehicle_details();
    void display_details();
    void writeToFile() const;
    // void remove_vehcile();
};
#endif