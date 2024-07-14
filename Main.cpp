#include <iostream>
#include "Video.h"
#include "Video.cpp"
#include "Customer.h"
#include "Customer.cpp"
#include "CustomerRent.h"
#include <limits>

using namespace std;

Video vid;
Customer cus;

int main() {

    // To add colors for aesthetics
    const std::string reset = "\033[0m";
    const std::string bold = "\033[1m";
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string yellow = "\033[33m";
    const std::string blue = "\033[34m";
    
    while (true){ 
        cout << yellow << bold << "[1] " << reset << "New Video\n";
        cout << yellow << bold << "[2] " << reset << "Rent a Video\n";
        cout << yellow << bold << "[3] " << reset << "Return a Video\n";
        cout << yellow << bold << "[4] " << reset << "Show Video Details\n";
        cout << yellow << bold << "[5] " << reset << "Display all Videos\n";
        cout << yellow << bold << "[6] " << reset << "Check Video Availability\n";
        cout << yellow << bold << "[7] " << reset << "Customer Maintenance\n";
        cout << yellow << bold << "[8] " << reset << "Exit Program\n";

        int op, customerOp;
        cout << blue << bold << "\nEnter an option: " << reset;
        while (!(cin >> op)) {
            cout << red << bold  << "Invalid input. " << blue << "Please enter a valid option: " << reset;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        std::string title, prod, genre, name, address;
        int numofcopies;

        int cusID;
        int vidID;
        char again;
        switch (op){
            case 1:
                cout << green << bold << "[1] New Video\n" << reset;
                cout << "Enter Movie Title: ";
                getline(cin, title);
                cout << "Enter Genre: ";
                getline (cin, genre);
                cout << "Enter Producer: ";
                getline (cin, prod);
                cout << "Enter Number of Copies: ";
                cin >> numofcopies;
                vid.insertVideo(title, prod, genre, numofcopies);
                break;
            case 2:
                cout << green << bold << "[2] Rent a Video\n" << reset;

                do {
                    cout << "Enter Customer ID: ";
                    cin >> cusID;


                    cout << "Enter Video ID to rent: ";
                    cin >> vidID;
                    vid.rentVideo(vidID);

                    cout << "Do you want to rent another video? (Y/N)";
                    cin >> again;
                } while (again == 'Y' || again == 'y');
                break;
            case 3:
                cout << green << bold << "[3] Return a Video\n" << reset;
                break;
            case 4:
                cout << green << bold << "[4] Show Video Details" << reset << endl;

                cout << "Enter Video ID: ";
                cin >> vidID;
                vid.showVideoDetails(vidID);
                break;
            case 5:
                cout << green << bold << "[5] Display all Videos\n" << reset;
                vid.displayAllVideos();
                break;
            case 6:
                cout << green << bold << "[6] Check Video Availability\n" << reset;
                cout << "Enter Video ID: ";
                cin >> vidID;

                vid.isAvailable(vidID);
                break;
            case 7:
                cout << yellow << bold << "[1] " << reset << "Add Customer\n";
                cout << yellow << bold << "[2] " << reset << "Show Customer Details\n";
                cout << yellow << bold << "[3] " << reset << "List of Videos Rented by a Customer\n";

                cout << blue << bold << "\nEnter an option: " << reset;
                
                while (!(cin >> customerOp)) {
                    cout << red << bold  << "Invalid input. " << blue << "Please enter a valid option: " << reset;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl;

                switch (customerOp){
                    case 1:
                        cout << green << bold << "[1] Add Customer\n" << reset;
                        cout << "Enter Customer Name: ";
                        getline(cin, name);
                        cout << "Enter Customer Address: ";
                        getline(cin, address);
                        cus.addCustomer(name, address);
                        break;
                    case 2:
                        cout << green << bold << "[2] Show Customer Detail\n" << reset;
                        cout << "Enter Customer ID: ";
                        cin >> cusID;
                        cus.showCustomerDetails(cusID);
                        break;
                    case 3:
                        cout << green << bold << "[3] List of Videos Rented by a Customer\n" << reset;
                        cout << "Enter Customer ID: ";
                        cin >> cusID;
                        // cus.displayAllVideosRentedByCustomer(cusID);
                        break;
                    default:
                        cout << red << bold << "Invalid option. " << blue << "Please enter a valid option\n";
                }
                break;
            case 8:
                return 0;
            default:
                cout << red << bold << "Invalid option. Please choose a valid option.\n" << reset;
            
        }   

        cout << endl << endl;

    }

    return 0;
}