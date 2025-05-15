#include "admin.h"
#include "Person.h"
Admin::Admin()
{}
Admin::Admin(string admin_name, string admin_ID, string admin_password, string admin_address, string admin_phone, string admin_email)
{
    this->admin_name = admin_name;
    this->admin_ID = admin_ID;
    this->admin_password = admin_password;
    this->admin_address = admin_address;
    this->admin_phone = admin_phone;
    this->admin_email = admin_email;
}
void Admin::wellcome()
{
    cout << GREEN_TEXT << "\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << "\n";
    cout << YELLOW_TEXT << "                 ( Welcome to Admin Module  )                     " << RESET_COLOR << endl;
    cout << GREEN_TEXT << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

}
void Admin::registration_info()
{
    //here we will write data of admin in file Admin_data.txt and we will write it in append mode
    cin.ignore();
    ofstream admin_file;
    admin_file.open("Admin_data.txt", ios::app);
    admin_file << "Admin name : " << "Admin" << endl;
    admin_file << "Admin Password : " << "Admin@123" << endl;
    admin_file.close();
}

void Admin::menu()
{
again:
    cout << GREEN_TEXT << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << "\n";
    cout << AQUA_TEXT << "1. View vehicles Available in inventory " << RESET_COLOR << endl;
    cout << AQUA_TEXT << "2. Add a new Vehicle to Inventory " << RESET_COLOR << endl;
    cout << AQUA_TEXT << "3. Remove Vehicle from existing Vehicles " << RESET_COLOR << endl;
    cout << AQUA_TEXT << "4. Add notification or to rate a vehicle as an Admin " << RESET_COLOR << endl;
    cout << AQUA_TEXT << "5. Back to main menu" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "6. View Notification" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "7. Remove notification or the comment added." << RESET_COLOR << endl;
    cout << AQUA_TEXT << "8. Manage inspection report " << RESET_COLOR << endl;
    cout << AQUA_TEXT << "9. Logout" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "Enter your choice: " << RESET_COLOR;
    cout << GREEN_TEXT << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << "\n";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        view();
        // vehicles();
        goto again;
    }
    else if (choice == 2)
    {
        vehicles();
        contact_info();
        // remove_vehicle();
        goto again;
    }
    else if (choice == 3)
    {
        //view();
        remove_vehicle();
        goto again;
    }
    else if (choice == 4)
    {
        notification();
        goto again;
    }
    else if (choice == 5)
    {
        menu();
        goto again;
    }
    else if (choice == 6)
    {
        view_notification();
        goto again;
    }
    else if (choice == 7)
    {
        view_notification();
        remove_notifcation();
        goto again;
    }
    else if (choice == 8)
    {
        inspection_report();
        goto again;
    }
    else if (choice == 9)
    {
        logout();
    }
    else if (choice >= 0 || choice < 1000)
    {
        cout << "Invalid choice" << endl;
        goto again;
    }
    else
    {
        cout << "Invalid choice" << endl;
        goto again;
    }
}


void Admin::vehicles()
{
    ofstream outFile;
    outFile.open("Vehicle_data.txt", ios::app);

    if (outFile.is_open())
    {
        // cout << "File opened successfully." << endl;
        cin.ignore(); // Clear newline character

        // Ask the user if they want to add more details
        char choice;
        cout << "Do you want to Add Car or Bike details? : \n";
        cout << "(C) to add car : \n";
        cout << "(B) to add Bike : \n";
        cin >> choice;

        while (choice == 'c' || choice == 'C' || choice == 'b' || choice == 'B')
        {
            string name, company, model;
            int mileage;
            double rating, price;

            cout << "Enter vehicle name: ";
            cin.ignore(); // Clear newline character
            getline(cin, name);

            cout << "Enter company: ";
            getline(cin, company);

            cout << "Enter model: ";
            getline(cin, model);

            cout << "Enter mileage: ";
            cin >> mileage;

            cout << "Enter rating: ";
            cin >> rating;

            cout << "Enter price: ";
            cin >> price;

            if (choice == 'c' || choice == 'C')
            {
                //  outFile << "Car Details:";
                 // cout <<endl;
            }
            else if (choice == 'b' || choice == 'B')
            {
                //  outFile << "Bike Details:";
                //  cout <<endl;
            }
            outFile << AQUA_TEXT << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=--=" << RESET_COLOR << endl;
            outFile << YELLOW_TEXT << "  Name :: (" << name << ")      "
                << "Company :: (" << company << ")      "
                << "Model :: (" << model << ")      "
                << "Mileage :: (" << mileage << ")      "
                << "Rating :: (" << rating << ")      "
                << "Price :: " << price << "$\n"
                << AQUA_TEXT << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=--=\n";

            cout << "Do you want to add more vehicles?: \n";
            cout << "(C) to add car : \n";
            cout << "(B) to add Bike : \n";
            cout << "(E) to exit and return to main menu :\n";
            cin >> choice;
        }

        // cout << "Data written to vehicle_data.txt successfully." << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

bool Admin::check_admin_data()
{
    string entered_name;
    string entered_password;
    char ch;
    do
    {
        cin.ignore(); // Clear newline character
        cout << "Enter details for admin: \n";
        cout << "Enter name: ";
        getline(cin, entered_name);
        cout << "Enter Password: ";

        // Hide password input
        entered_password = "";
        ch = _getch();
        while (ch != 13) // Enter key
        {
            entered_password.push_back(ch);
            cout << '*';
            ch = _getch();
            // ch = getch();
        }

        if (entered_name == "Admin" && entered_password == "Admin@123")
        {
            cout << YELLOW_TEXT << "\n\n                 (login Successfully)                      " << RESET_COLOR << "\n" << endl;
            return true;
        }
        else
        {
            cout << "\nLogin failed. Please check your credentials." << endl;
            cout << "Do you want to try again?: ";
            cout << "Press (Y) to try again or (N) to exit:";
            char choice;
            cin >> choice;

            if (choice != 'y' && choice != 'Y')
            {
                cout << "Exiting login process." << endl;
                return false;
            }
        }
    } while (true); // Infinite loop until correct credentials are entered
}

void Admin::notification()
{
    cin.ignore();
    string notification;
    string rating;
    //we will write notification to notifcation.txt as an admin
    cout << "do you want to add Notification or rating? (N/R): ";
    char choice;
    cin >> choice;
    if (choice == 'R' || choice == 'r')
    {
        cin.ignore();
        cout << "Enter rating as an Admin: (add a bit more description)";
        getline(cin, rating);
        // Write notification to notification.txt
        ofstream n_file("notification.txt", ios::app); // Open file in append mode
        if (n_file.is_open())
        {
            n_file << rating << endl;
            // cout << "Rating added as an Admin." << endl;
            n_file.close();
        }
    }
    else if (choice == 'N' || choice == 'n')
    {
        cin.ignore();
        cout << "Enter notification as an Admin: ";
        getline(cin, notification);
        // Write notification to notification.txt
        ofstream n_file("notification.txt", ios::app); // Open file in append mode
        if (n_file.is_open())
        {
            n_file << notification << endl;
            // cout << "Notification added as an Admin." << endl;
            n_file.close();
        }
    }
}
void Admin::view()
{
    string line;
    ifstream fin;
    fin.open("Vehicle_data.txt");
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
}

void Admin::remove_vehicle()
{
    ifstream read;
    ofstream write;
    read.open("Vehicle_data.txt");
    write.open("temp.txt");
    string line;
    string name;
    cout << AQUA_TEXT << "Enter the name of the vehicle you want to remove: " << RESET_COLOR;
    cin.ignore();
    getline(cin, name);
    while (getline(read, line)) {
        if (line.find(name) == string::npos) {
            write << line << endl;
        }
    }
    read.close();
    write.close();
    remove("Vehicle_data.txt");
    rename("temp.txt", "Vehicle_data.txt");
    cout << "Vehicle removed successfully." << endl;
}


void Admin::logout()
{
    cout << GREEN_TEXT << "======================== :: Thank you for using our Services :: ========================" << RESET_COLOR << "\n";
    cout << YELLOW_TEXT << "                                ( logged out )                                  " << RESET_COLOR << endl;
    cout << GREEN_TEXT << "=======================================================================================\n";
}

//vfunction to view notification
void Admin::view_notification()
{
    string line;
    ifstream fin;
    fin.open("notification.txt");
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
}

void Admin::remove_notifcation()
{
    ifstream read;
    ofstream write;
    read.open("notification.txt");
    write.open("temp.txt");
    string line;
    string name;
    cout << "Enter notification to be removed: ";
    cin.ignore();
    getline(cin, name);
    while (getline(read, line)) {
        if (line.find(name) == string::npos) {
            write << line << endl;
        }
    }
    read.close();
    write.close();
    remove("notification.txt");
    rename("temp.txt", "notification.txt");
    cout << "Notification removed successfully." << endl;
}
//manage inspection report admin check kryga koi request aai h k nhi or agr aai ha tu aagy ki karwai kryga
//agr request aai ha koi tu wo aagy krwai kryga
void Admin::inspection_report()
{
    cout << YELLOW_TEXT << "\nInspection report of selected vehicle: \n\n" << RESET_COLOR;
    string line;
    ifstream fin;
    fin.open("inspection_report.txt");
    while (getline(fin, line))
    {
        cout << GREEN_TEXT << line << RESET_COLOR << endl;
    }
    fin.close();
    //ab admin ispection report tyar kryga selected gari ki
    string name;
    string engine_number;
    string chassis_number;
    string color;
    string registered_city;
    string current_city;
again:
    cout << YELLOW_TEXT << "Enter name of the buyer: " << RESET_COLOR;
    cin.ignore();
    getline(cin, name);
    cout << YELLOW_TEXT << "Enter engine number of the vehicle: " << RESET_COLOR;
    cin.ignore();
    getline(cin, engine_number);
    cout << YELLOW_TEXT << "Enter chassis number of the vehicle: " << RESET_COLOR;
    getline(cin, chassis_number);
    cout << YELLOW_TEXT << "Enter color of the vehicle: " << RESET_COLOR;
    getline(cin, color);
    cout << YELLOW_TEXT << "Enter registered city of the vehicle: " << RESET_COLOR;
    getline(cin, registered_city);
    cout << YELLOW_TEXT << "Enter current city of the vehicle: " << RESET_COLOR;
    getline(cin, current_city);
    //ab hum is data ko file ma save kryga
    ofstream inspection_report;
    inspection_report.open("inspection_report.txt", ios::app);
    inspection_report << "Name of the buyer:: " << name
        << "   Engine number:: " << engine_number
        << "   Chassis number:: " << chassis_number
        << "   Color:: " << color
        << "   Registered city:: " << registered_city
        << "   Current city:: " << current_city << endl;
    inspection_report.close();
    cout << YELLOW_TEXT << "Inspection report is ready for the buyer: \n" << RESET_COLOR;
    cout << YELLOW_TEXT << "Do you want to add more inspection report? (Y/N): " << RESET_COLOR;
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        goto again;
    }
    else
    {
        cout << YELLOW_TEXT << "Inspection report is ready for the buyer: \n" << RESET_COLOR;
    }
}
void Admin::contact_info()
{
    cout << GREEN_TEXT << "\n\n We need you to recheck and verify your Vehicle name here. \n This would be helpful to the buyer to contact you. \n\n" << RESET_COLOR << endl;
    string vehicle_name;
    string seller_name;
    string seller_phone;
    string seller_email;
    cout << GREEN_TEXT << "Enter the name of the vehicle you want to sell: " << RESET_COLOR;
    cin.ignore();
    getline(cin, vehicle_name);
    cout << GREEN_TEXT << "Enter seller's name: " << RESET_COLOR;
    getline(cin, seller_name);
    cout << GREEN_TEXT << "Enter seller's phone number: " << RESET_COLOR;
    getline(cin, seller_phone);
    cout << GREEN_TEXT << "Enter seller's email: " << RESET_COLOR;
    getline(cin, seller_email);

    cout << endl;
    ofstream info;
    info.open("contact_info.txt", ios::app);
    if (info.is_open())
    {

        info << "\nVehicle Name: " << vehicle_name;
        info << "   Seller Name: " << seller_name;
        info << "   Seller Phone: " << seller_phone;
        info << "   Seller Email: " << seller_email << endl;
        //cout << "Contact info saved successfully.";
        info.close();
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}