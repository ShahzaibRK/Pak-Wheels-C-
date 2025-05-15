#include"Person.h"
#include"Buyer.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
Buyer::Buyer()
{}
Buyer::Buyer(string buyer_name, string buyer_ID, string buyer_password, string buyer_address, string buyer_phone, string buyer_email)
{
    this->buyer_name = buyer_name;
    this->buyer_ID = buyer_ID;
    this->buyer_password = buyer_password;
    this->buyer_address = buyer_address;
    this->buyer_phone = buyer_phone;
    this->buyer_email = buyer_email;
}
Buyer :: ~Buyer()
{}
void Buyer::wellcome()
{
    cout << "----------------------------------------- Welcome to Buyer MOdule -------------------------------------\n";
}
void Buyer::registration_info()
{
    cin.ignore();
    cout << GREEN_TEXT << "\n\n-=-=-=-=-=-=-=-=-=--=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "                      Buyer's Registration Form\n";
    cout << GREEN_TEXT << "-=-=-=-=-=-=-=-=-=--=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=\n" << RESET_COLOR << endl;
    cout << YELLOW_TEXT << "Enter name: " << RESET_COLOR;
    getline(cin, buyer_name);
    cout << YELLOW_TEXT << "Enter password: " << RESET_COLOR;
    // Hide password input
    buyer_password = "";
    char ch;
    while ((ch = _getch()) != 13) // Enter key
    {
        buyer_password.push_back(ch);
        cout << '*';
    }

    ofstream buyer_file;
    buyer_file.open("buyer.txt", ios::out);

    if (buyer_file.is_open())
    {
        // cout << "\nFile created successfully." << endl;
        buyer_file << " Buyer Name: " << buyer_name << endl;
        buyer_file << " Buyer Password: " << buyer_password << endl;

        cout << YELLOW_TEXT << "     \n\n (registeration successfull)\n\n" << endl;
        buyer_file.close();
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

bool Buyer::check_buyer_data()
{
    string entered_name;
    string entered_password;
    char ch;

    do
    {
        cin.ignore(); // Clear newline character
        cout << YELLOW_TEXT << "Enter details to log in as a Seller: \n" << RESET_COLOR;
        cout << GREEN_TEXT << "Enter name: " << RESET_COLOR;
        getline(cin, entered_name);

        cout << GREEN_TEXT << "Enter Password: " << RESET_COLOR;

        // Hide password input
        entered_password = "";
        ch = _getch(); // Use getch() for Windows
        while (ch != 13) // Enter key
        {
            entered_password.push_back(ch);
            cout << '*';
            ch = _getch();
            // ch = getch();
        }

        if (entered_name == buyer_name && entered_password == buyer_password)
        {
            // cout << YELLOW_TEXT << "\n\n             (Successfully logged in) \n\n " << RESET_COLOR << endl;
            return true;
        }
        else
        {
            cout << "\nLogin failed. Please check your credentials." << endl;
            cout << "Do you want to try again? (y/n): ";
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

void Buyer::menu()
{
menu:
    char choice;
    const char* GREEN_TEXT = "\033[32m";
    const char* AQUA_TEXT = "\033[36m";
    const char* RESET_COLOR = "\033[0m";
    //const char* RED_TEXT = "\033[31m";
    cout << GREEN_TEXT << "\n\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "                  :: Welcome to Buyer's Menu ::                    " << RESET_COLOR << "\n";
    cout << GREEN_TEXT << "-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "Choose from the following options : \n" << RESET_COLOR;
    cout << AQUA_TEXT << "  (V) to view vehicles \n" << RESET_COLOR;
    cout << AQUA_TEXT << "  (N) to view notifications \n" << RESET_COLOR;
    cout << AQUA_TEXT << "  (A) to view auction \n" << RESET_COLOR;
    cout << AQUA_TEXT << "  (I) request for inspection report (you can also comment). \n" << RESET_COLOR;
    cout << AQUA_TEXT << "  (C) to view contact information of seller \n" << RESET_COLOR;
    cout << AQUA_TEXT << "  (E) to Exit " << RESET_COLOR;
    cout << GREEN_TEXT << "\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==--=-=-=" << RESET_COLOR << endl;

    cin >> choice;
    //now we will use switch case to perform different operations
    switch (choice)
    {
    case 'A':
    case 'a':
    {
        view_auction();
        goto menu;
        break;
    }
    case 'V':
    case 'v':
    {
        cout << "You are viewing vehicles \n";
        view();
        goto menu;
        break;
    }
    case 'N':
    case 'n':
    {
        cout << "You are viewing notifications \n";
        notification();
        goto menu;
        break;
    }
    case 'E':
    case 'e':
    {
        cout << "You are exiting the program \n";
        logout();
        // goto menu;
        break;
    }
    case 'I':
    case 'i':
    {
        cout << "You are viewing inspection report \n";
        isnpection_report();
        goto menu;
        break;
    }
    case 'C':
    case 'c':
    {
        cout << "You are viewing contact information \n";
        contact_info();
        goto menu;
        break;
    }
    default:
    {
        cout << "Invalid choice \n";
        break;
    }
    }
}
void Buyer::vehicles()
{
    ofstream outFile;
    outFile.open("Vehicle_data.txt", ios::app);

    if (outFile.is_open())
    {
        cout << "File opened successfully." << endl;
        cin.ignore(); // Clear newline character

        // Ask the user if they want to add more details
        char choice;
        cout << "Do you want to Add Car or Bike details? (c or  b): ";
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

            outFile << "\n------------------------------------------------------------------------------------------------------------------------------\n";
            outFile << "  Name :: [" << name << "]  |  "
                << "Company :: [" << company << "]  |  "
                << "Model :: [" << model << "]  |  "
                << "Mileage :: [" << mileage << "]  |  "
                << "Rating :: [" << rating << "]  |  "
                << "Price :: " << price << "$\n"
                << "-----------------------------------------------------------------------------------------------------------------------------\n";

            cout << "Do you want to add more vehicles? (c/b/n): ";
            cin >> choice;
        }

        cout << "Data written to vehicle_data.txt successfully." << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

//view function
void Buyer::view()
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
//notification function
void Buyer::notification()
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
// function bnaengy ek file alag sa bnygi jhan buyer apni choice select kryga or is file the vehicle ka naam save ho jaega 
// or buyer ki trf sa inspection ki request send ho jaegi
// or aagy sara admin ka kaam h
void Buyer::isnpection_report()
{  // Displaying vehicle details using the view function
    view();
    // Clearing the newline character from the buffer
    cin.ignore();
    string vehicleName;
    cout << "Enter the name of the vehicle you want to request for an inspection report:\n";
    getline(cin, vehicleName);
    ofstream outFile("inspection_report.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "\n----------------------------------------------------------------------------------\n";
        outFile << "Name of the Buyer: " << buyer_name << endl;
        outFile << "Vehicle Inspection Report Request for: " << vehicleName << endl;
        outFile << "----------------------------------------------------------------------------------\n\n";
        cout << "\nYour request for an inspection report has been sent to the admin. \n\n\n";
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for inspection report request. \n\n";
    }
}

bool Buyer::contact_info() {
    ifstream read;
    ofstream write;

    read.open("contact_info.txt");
    write.open("temp.txt");
    string line;
    string name;

    cin.ignore();
    cout << "Enter the name of the vehicle you want to see details of: ";
    getline(cin, name);

    bool vehicleFound = false;

    while (getline(read, line))
    {
        if (line.find(name) != string::npos)
        {
            // Display details only for the specific vehicle
            cout << line << endl;
            vehicleFound = true;
        }
        else {
            write << line << endl;
        }
    }

    read.close();
    write.close();

    if (!vehicleFound) {
        cout << "Vehicle not found." << endl;
    }

    return vehicleFound; // Return whether the vehicle was found or not
}
//auction
void Buyer::view_auction()
{
    string line;
    ifstream fin;
    string bid;
    fin.open("auction_data.txt");
    cout << GREEN_TEXT << "\n=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "                  :: Welcome to Auction ::                    " << RESET_COLOR << "\n";
    cout << GREEN_TEXT << "=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << endl;

    // Display auction details
    while (getline(fin, line)) {
        cout << line << endl;
    }

    // Ask for bid details
    cin.ignore();
    cout << YELLOW_TEXT << "Enter the name of the vehicle you want to bid on: " << RESET_COLOR;
    string desired_Vehicle;
    getline(cin, desired_Vehicle);

    cout << YELLOW_TEXT << "Enter your bid for " << desired_Vehicle << ": " << RESET_COLOR;
    getline(cin, bid);

    fin.close();

    // Append the new bid to the file
    ofstream fout("auction_data.txt", ios::app);
    fout << GREEN_TEXT << "\n=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << endl;
    fout << AQUA_TEXT << "Bidder Name :: " << buyer_name << RESET_COLOR;
    fout << AQUA_TEXT << "    Vehcile  ::  " << desired_Vehicle << " : " << RESET_COLOR << "  Bid :" << bid << RESET_COLOR << endl;
    fout << GREEN_TEXT << "=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << RESET_COLOR << endl;
    fout.close();
}

void Buyer::logout()
{
    cout << GREEN_TEXT << "======================== :: Thankyou for using our Services :: ========================" << RESET_COLOR << "\n\n";
    cout << YELLOW_TEXT << "                                ( logged out )                                  " << RESET_COLOR << "\n" << endl;
    cout << GREEN_TEXT << "=======================================================================================\n";
}