#include "Seller.h"
#include "Person.h"
// Default constructor
Seller::Seller()
{
    seller_ID = "";
    seller_password = "";
    seller_name = "";
    seller_address = "";
    seller_phone = "";
    seller_email = "";
}
//destructor
Seller :: ~Seller()
{}
// Parameterized constructor
Seller::Seller(string seller_name, string seller_ID, string seller_password, string seller_address, string seller_phone, string seller_email)
// Initialize base class members
{
    this->seller_name = seller_name;
    this->seller_ID = seller_ID;
    this->seller_password = seller_password;
    this->seller_address = seller_address;
    this->seller_phone = seller_phone;
    this->seller_email = seller_email;
}
//Seller::Seller(string seller_ID, string seller_password, string seller_name, string seller_address, string seller_phone, string seller_email);
  //  : Person(seller_name, seller_ID) // Initialize base class members
void Seller::wellcome()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "====================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "                               ::  Welcome to  ::             " << endl;
    cout << "                        >::<  Shahzaib's Car Management System  >::<       " << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "====================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);


}
// Implementation of virtual functions
void Seller::registration_info()
{
    const char* GREEN_TEXT = "\033[32m";
    const char* YELLOW_TEXT = "\033[33m";
    const char* RESET_COLOR = "\033[0m";
    cin.ignore();
    cout << GREEN_TEXT << "Enter your name: " << RESET_COLOR;
    getline(cin, seller_name);

    cout << GREEN_TEXT << "Enter your password: " << RESET_COLOR;

    // Hide password input
    seller_password = "";
    char ch = _getch(); // Use getch() for Windows
    while (ch != 13) // Enter key
    {
        seller_password.push_back(ch);
        cout << '*';
        ch = _getch();
        // ch = getch();
    }

    cout << GREEN_TEXT << "\nEnter your phone: " << RESET_COLOR;
    getline(cin, seller_phone);

    cout << GREEN_TEXT << "Enter your email: " << RESET_COLOR;
    getline(cin, seller_email);

    ofstream seller_file;
    seller_file.open("seller_data.txt", ios::app); // Open the file in simple write mode

    if (seller_file.is_open())
    {
        seller_file << "Seller Name: " << seller_name << endl;
        seller_file << "Seller Password: " << seller_password << endl;
        seller_file << "Seller Phone: " << seller_phone << endl;
        seller_file << "Seller Email: " << seller_email << endl;
        cout << "\n\n" << YELLOW_TEXT << "Congratulations! You are registered as a Seller." << RESET_COLOR << "\n\n";

        seller_file.close();
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}


bool Seller::check_seller_data()
{
    const char* GREEN_TEXT = "\033[32m";
    const char* YELLOW_TEXT = "\033[33m";
    const char* RESET_COLOR = "\033[0m";
    string entered_name;
    string entered_password;
    char ch;

    do
    {
        cin.ignore(); // Clear newline character
        cout << GREEN_TEXT << "Enter details to log in as a Seller: \n" << RESET_COLOR;
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

        if (entered_name == seller_name && entered_password == seller_password)
        {
            cout << YELLOW_TEXT << "\n(login Successful) " << RESET_COLOR << endl;
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

//function to view the vehciles (data would be read from the file Vehicle.txt)
void Seller::menu()
{
    char choice;
    do
    {
        wellcome();
        cout << AQUA_TEXT << "\n          << Welcome to the Seller's Menu >>\n" << RESET_COLOR << endl;
        cout << GREEN_TEXT << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=--=" << RESET_COLOR << endl;
        cout << AQUA_TEXT << "(A) Add a vehicle" << RESET_COLOR << endl;
        cout << AQUA_TEXT << "(V) View a vehicle" << RESET_COLOR << endl;
        cout << AQUA_TEXT << "(a) to view Auction " << RESET_COLOR << endl;
        cout << AQUA_TEXT << "(R) Remove a vehicle" << RESET_COLOR << endl;
        cout << AQUA_TEXT << "(N) View notification" << RESET_COLOR << endl;
        cout << AQUA_TEXT << "(E) Logout and return to main menu " << RESET_COLOR << endl;
        cout << GREEN_TEXT << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=--=" << RESET_COLOR << endl;
        cin >> choice;
        switch (choice)
        {
        case 'A':
            cout << "You are adding a vehicle \n";
            vehicles();
            contact_info();
            break;
        case 'a':
            auction();
            break;
        case 'V':
        case 'v':
            cout << "You are viewing a vehicle \n";
            view();
            break;
        case 'R':
        case 'r':
            cout << "You are removing a vehicle \n";
            remove_vehicle();
            break;
        case 'N':
        case 'n':
            cout << "You are viewing a notification \n";
            notification();
            break;
        case 'E':
        case 'e':
            logout();
            break;
        default:
            cout << "Invalid option. Please choose again.\n";
        }
    } while (choice != 'E' && choice != 'e');
}
void Seller::vehicles()
{
    ofstream outFile;
    outFile.open("Vehicle_data.txt", ios::app);

    if (outFile.is_open())
    {
        cin.ignore(); // Clear newline character

        // Ask the user if they want to add more details
        char choice;
        cout << AQUA_TEXT << "Do you want to Add Car or Bike details? :\n " << RESET_COLOR;
        cout << AQUA_TEXT << "enter (c) to add car or (b) to add bike:" << RESET_COLOR;
        cin >> choice;

        while (choice == 'c' || choice == 'C' || choice == 'b' || choice == 'B')
        {
            string name, company, model;
            int mileage;
            double rating, price;

            cout << GREEN_TEXT << "Enter vehicle name: " << RESET_COLOR;
            cin.ignore(); // Clear newline character
            getline(cin, name);

            cout << GREEN_TEXT << "Enter company: " << RESET_COLOR;
            getline(cin, company);

            cout << GREEN_TEXT << "Enter model: " << RESET_COLOR;
            getline(cin, model);

            cout << GREEN_TEXT << "Enter mileage: " << RESET_COLOR;
            cin >> mileage;

            cout << GREEN_TEXT << "Enter rating: " << RESET_COLOR;
            cin >> rating;

            cout << GREEN_TEXT << "Enter price: " << RESET_COLOR;
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


            cout << GREEN_TEXT << "Do you want to add more vehicles?:\n " << RESET_COLOR;
            cout << GREEN_TEXT << "enter (c) to add car or (b) to add bike or (n) to return back:\n" << RESET_COLOR;
            cin >> choice;
        }
        outFile.close();
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
//view function
void Seller::view()
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
//function to remove the vehciles (data would be read from the file Vehicle.txt)
//void Seller::remove_vehicle()
void Seller::remove_vehicle()
{
    ifstream read;
    ofstream write;
    read.open("Vehicle_data.txt");
    write.open("temp.txt");
    string line;
    string name;
    cout << GREEN_TEXT << "Enter the name of the vehicle you want to remove: " << RESET_COLOR;
    cin.ignore();
    getline(cin, name);
    while (getline(read, line))
    {
        if (line.find(name) == string::npos)
        {
            write << line << endl;
        }
    }
    read.close();
    write.close();
    remove("Vehicle_data.txt");
    rename("temp.txt", "Vehicle_data.txt");
    cout << YELLOW_TEXT << "Vehicle removed successfully." << RESET_COLOR << endl;
}
//here our simple function for the sake of reading the notification from the Admin and Seller can only see the notification
void Seller::notification()
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
void Seller::logout()
{
    cout << GREEN_TEXT << "\n======================== :: Thankyou for using our Services :: ========================" << RESET_COLOR << "\n";
    cout << YELLOW_TEXT << "                                ( logged out )                                  " << RESET_COLOR << endl;
    cout << GREEN_TEXT << "=======================================================================================\n";
}

void Seller::contact_info()
{
    cout << GREEN_TEXT << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n " << RESET_COLOR;
    cout << AQUA_TEXT << " We need you to recheck and verify your Vehicle name here. \n This would be helpful to the buyer to contact you." << RESET_COLOR << endl;
    string vehicle_name;
    cout << GREEN_TEXT << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n " << RESET_COLOR;
    cout << AQUA_TEXT << "Enter the name of the vehicle you want to sell: " << RESET_COLOR;
    cin.ignore();
    getline(cin, vehicle_name);
    cout << endl;
    ofstream info;
    info.open("contact_info.txt", ios::app);
    if (info.is_open())
    {

        info << "\nVehicle Name: " << vehicle_name;
        info << "     Seller Name: " << seller_name;
        info << "     Seller Phone: " << seller_phone;
        info << "     Seller Email: " << seller_email;
        cout << endl;
        //cout << "Contact info saved successfully.";
        info.close();
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}
//our function for Auction
void Seller::auction()
{
    cout << GREEN_TEXT << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=--=" << RESET_COLOR << endl;
    cout << AQUA_TEXT << "\n\nWelcome you are in Auction mode \n\n" << RESET_COLOR;
    cout << AQUA_TEXT << "Here you can sell your vehicle to the highest bidder \n" << RESET_COLOR;
    cout << AQUA_TEXT << "You can set the minimum price for your vehicle \n" << RESET_COLOR;
    fstream auction;
    auction.open("auction_data.txt", ios::app);
    {
        string vehicle_name;
        string minimum_price;
        string state;
        cout << GREEN_TEXT << "Enter the name of the vehicle you want to sell: " << RESET_COLOR;
        cin.ignore();
        getline(cin, vehicle_name);
        cout << GREEN_TEXT << "Enter the minimum price for your vehicle: " << RESET_COLOR;
        getline(cin, minimum_price);
        cout << GREEN_TEXT << "Enter the state of Your vehicle you want to sell: \n whether it is new or used(type state of vehicle) " << RESET_COLOR;
        getline(cin, state);
        cout << endl;
        auction << "Vehicle Name: " << vehicle_name;
        auction << "   Seller Name: " << seller_name;
        auction << "   Seller Phone: " << seller_phone;
        auction << "   Minimum Price: " << minimum_price;
        auction << "   State: " << state << endl;
        //cout << "Contact info saved successfully.";
        auction.close();
    }
}

