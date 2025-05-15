PakWheels-like Vehicle Management System
This is a C++ console-based project that simulates a simplified version of a vehicle listing and management system like PakWheels. The system allows Admins, Sellers, and Buyers to interact with a list of vehicles for sale, providing functionality for adding, viewing, and managing vehicle records.

🧾 Features
Admin Panel

View all vehicle listings

Manage user roles and access

Seller Panel

Add vehicles for sale

Edit or delete existing listings

Buyer Panel

Browse available vehicles

Search for vehicles by filters (brand, model, price)

Vehicle Records

Store information like make, model, year, price, and condition

🗂 File Structure
.
├── admin.cpp / admin.h      # Admin functionalities
├── buyer.cpp / buyer.h      # Buyer functionalities
├── seller.cpp / seller.h    # Seller functionalities
├── person.cpp / person.h    # Base class for users
├── vehicle.cpp / vehicle.h  # Vehicle-related data and operations
└── main.cpp                 # Entry point of the program

🛠️ Requirements
C++11 or higher
g++ or any compatible C++ compiler

🚀 How to Run
Compile the program:
g++ main.cpp admin.cpp buyer.cpp seller.cpp person.cpp vehicle.cpp -o pakwheels
Run the executable:
./pakwheels
📌 Notes
This project is designed for educational purposes.

File handling or persistent storage is not yet implemented (unless you’ve added it).
