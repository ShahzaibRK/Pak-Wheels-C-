#include "vehicle.h"
Vehicle::Vehicle()
{
    name = new string;
    company = new string;
    model = new string;
}
// copy constructor inplmentation
Vehicle::Vehicle(const Vehicle& obj)
{
    name = new string;
    company = new string;
    model = new string;
    *name = *obj.name;
    *company = *obj.company;
    *model = *obj.model;
    mileage = obj.mileage;
    price = obj.price;
    rating = obj.rating;
}
// destructors
Vehicle::~Vehicle()
{
    delete name;
    delete company;
    delete model;
}

void Vehicle::input_data()
{
    cout << "\nEnter vehicle details:\n";
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, *name);

    cout << "Enter company: ";
    getline(cin, *company);

    cout << "Enter model: ";
    getline(cin, *model);

    cout << "Enter mileage: ";
    cin >> mileage;

    cout << "Enter price: ";
    cin >> price;

    cout << "Enter rating: ";
    cin >> rating;

    cout << endl;
}

void Vehicle::display_details()
{
    cout << "\n============Vehicle Details========:\n";
    cout << "Name: " << name << endl;
    cout << "Company: " << company << endl;
    cout << "Model: " << model << endl;
    cout << "Mileage: " << mileage << " km/l" << endl;
    cout << "Price: $" << price << endl;
    cout << "Rating: " << rating << "/5" << endl;
}

void Vehicle::writeToFile() const
{
    ofstream outFile;
    outFile.open("vehicle_data.txt", ios::app);

    if (outFile.is_open())
    {
        cin.ignore(); // Clear newline character
        cout << "File opened successfully." << endl;
        // Ask the user if they want to add more details
        cout << "Do you want to add vehicle details? (y/n): ";
        char choice;
        cin >> choice;
        while (choice == 'y' || choice == 'Y')
        {
            string name, company, model;
            int mileage;
            double rating, price;

            cout << "Enter vehicle name...........(v): ";
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

            // Write user-input details to the file
            // outFile << name << " | " << company << " | " << model << " | " << mileage << " | " << rating << " | " << price << endl;
            // outFile << "  Name :: [" << name << "]  Company :: [" << company << "]  Model :: [" << model << "]  Mileage :: [" << mileage<< "]  Rating :: ["<< rating << "]  Price :: " << price <<"$ "<< endl;
            outFile << "  Name     :: [" << name << "]\n"
                << "  Company  :: [" << company << "]\n"
                << "  Model    :: [" << model << "]\n"
                << "  Mileage  :: [" << mileage << "]\n"
                << "  Rating   :: [" << rating << "]\n"
                << "  Price    :: " << price << "$\n"
                << endl;

            cout << "Do you want to add more vehicles? (y/n): ";
            cin >> choice;
        }

        cout << "Data written to vehicle_data.txt successfully." << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file." << endl;
    }
}

//so here is the child class of vehicle class (bikes)
class Bikes : public Vehicle
{
protected:
    string* bike_name;
    string* bike_company;
    string* bike_model;
    int bike_mileage;
    double bike_price;
    int bike_rating;

public:
    //parameterized constructor
    Bikes();
    Bikes(Bikes& obj);
    ~Bikes();
    Bikes(string bike_name, string bike_company, string bike_model, int bike_mileage, double bike_price, int bike_rating);
    void input_data();
    void display_details();
    void writeToFile() const;
};
Bikes::Bikes()
{
    bike_name = new string;
    bike_company = new string;
    bike_model = new string;
}
// copy constructor inplmentation
Bikes::Bikes(Bikes& obj)
{
    bike_name = new string;
    bike_company = new string;
    bike_model = new string;
    *bike_name = *obj.bike_name;
    *bike_company = *obj.bike_company;
    *bike_model = *obj.bike_model;
    bike_mileage = obj.bike_mileage;
    bike_price = obj.bike_price;
    bike_rating = obj.bike_rating;
}
//destructors implementation
Bikes::~Bikes()
{
    delete bike_name;
    delete bike_company;
    delete bike_model;
}
void Bikes::input_data()
{
    cout << "\nEnter bike details:\n";
    //inherit from the base class
    Vehicle::input_data();
}
void Bikes::display_details()
{
    //inherit from the base class
    Vehicle::display_details();
}
void Bikes::writeToFile() const
{
    //inherit from the base class
    Vehicle::writeToFile();
}

