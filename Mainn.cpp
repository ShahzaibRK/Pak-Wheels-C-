#include "Person.h"
#include "Seller.h"
#include "Buyer.h"
#include "Admin.h"
int main()
{
start:
    cout << endl << endl;
    Seller seller;
    Person* Ptr = &seller;
    Ptr->wellcome();
    char choice;
    const char* YELLOW_TEXT = "\033[33m";
    const char* RESET_COLOR = "\033[0m";
    cout << YELLOW_TEXT << "\n\n      Choose from the following options : \n" << RESET_COLOR;
    cout << YELLOW_TEXT << "          Press (A) or (a) if you are an Admin \n" << RESET_COLOR;
    cout << YELLOW_TEXT << "          Press (S) or (s) if you are a Seller \n" << RESET_COLOR;
    cout << YELLOW_TEXT << "          Press (B) or (b) if you are a Buyer \n" << RESET_COLOR;
    cout << YELLOW_TEXT << "          Press (E) or (e) to Exit " << RESET_COLOR;
    cin >> choice;
    //now we will use switch case to perform different operations
    switch (choice)
    {
    case 'A':
    case 'a':
    {
        // cout << "You are an Admin \n";
        Admin admin;
        Person* P = &admin;
        P->wellcome();
        P->registration_info();
        admin.check_admin_data();
        admin.menu();
        goto start;
        break;
    }
    case 'S':
    case 's':
    {
        Seller seller;
        // Using a pointer to the base class (Person) to achieve polymorphism
        Person* Ptr = &seller;
        Ptr->wellcome();
        Ptr->registration_info();
        seller.check_seller_data();
        seller.menu();
        // Ptr->logout();
        goto start;
        cout << "You are a Seller \n";
        break;
    }
    case 'B':
    case 'b':
    {
        Buyer b;
        // Using a pointer to the base class (Person) to achieve polymorphism
        Person* Ptr = &b;
        //Ptr->wellcome();
        Ptr->registration_info();
        b.check_buyer_data();
        b.menu();
        goto start;
        break;
    }
    case 'E':
    case 'e':
    {
        cout << "You are exiting the program \n";
        break;
    }
    default:
    {
        cout << "Invalid input \n";
        break;
    }
    }
    return 0;
}