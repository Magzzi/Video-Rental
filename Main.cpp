#include <iostream>
#include <stack>
#include "Video.h"
#include "Video.cpp"
#include "Customer.h"
#include "Customer.cpp"
#include "CustomerRent.h"
#include "CustomerRent.cpp"
#include <limits>

using namespace std;



int main() {

    Video vid;
    Customer cus;
    CustomerRent customerRent;
    vid.initMovies(); // initializes the list of videos
    vid.updateVideoList();
    cus.initCustomer(); // initializes the list of customers
    cus.updateCustomerList();
    
    // To add colors for aesthetics
    const std::string reset = "\033[0m";
    const std::string bold = "\033[1m";
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string yellow = "\033[33m";
    const std::string blue = "\033[34m";
    
    while (true){ 
        customerRent.updateCustomerRent();
        cout << yellow << bold << "[1] " << reset << "New Video\n";
        cout << yellow << bold << "[2] " << reset << "Rent a Video\n";
        cout << yellow << bold << "[3] " << reset << "Return a Video\n";
        cout << yellow << bold << "[4] " << reset << "Show Video Details\n";
        cout << yellow << bold << "[5] " << reset << "Display all Videos\n";
        cout << yellow << bold << "[6] " << reset << "Check Video Availability\n";
        cout << yellow << bold << "[7] " << reset << "Customer Maintenance\n";
        cout << yellow << bold << "[8] " << reset << "Exit Program\n";

        int op, customerOp, vidOP;
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
        stack<int> rented;
        stack<int> temp;
        int cusID;
        int vidID;
        char again;
        switch (op){
            case 1: // add a new video
                cout << yellow << bold << "[1] " << reset << "New Video\n";
                cout << yellow << bold << "[2] " << reset << "Add an Existing Video\n";

                cout << blue << bold << "\nEnter an option: " << reset;
                while (!(cin >> vidOP)) {
                    cout << red << bold  << "Invalid input. " << blue << "Please enter a valid option: " << reset;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl;

                switch (vidOP){
                    case 1: // add a new video
                        cout << green << bold << "[1] Add New Video\n" << reset;
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
                    case 2: // add existing video
                        cout << green << bold << "[2] Add an Existing Video\n" << reset;

                        if (vid.isEmpty()){
                            cout << red << bold << "No videos in the database.\n" << reset;
                        } else {
                            vid.displayAllVideos();
                            cout << "Enter Video ID: ";
                            cin >> vidID;
                            cout << "How many copies do you want to add? ";
                            cin >> numofcopies;
                            vid.insertExistingVideo(vidID, numofcopies);
                        }
                        break;
                    default:
                        cout << red << bold << "Invalid option. " << blue << "Please enter a valid option\n";
                }
                break;
            case 2: // rent a video
                cout << green << bold << "[2] Rent a Video\n" << reset;

                do {
                    do {
                        cout << "Enter Customer ID: ";
                        while (!(cin >> cusID)) {
                            cout << red << bold  << "Invalid input. " << blue << "Please enter a valid option: " << reset;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (!cus.checkCustomer(cusID));

                    cout << "Enter Video ID to rent: ";
                    cin >> vidID;
                    if (vid.doesExist(vidID)){
                        vid.rentVideo(vidID);
                        customerRent.rentVideo(vidID, cusID);
                        customerRent.updateCustomerRent();
                    }                    
                    cout << "Do you want to rent another video? (Y/N) ";
                    cin >> again;
                } while (again == 'Y' || again == 'y');

                break;
            case 3: // return a video
                cout << green << bold << "[3] Return a Video\n" << reset;
                do {
                    cout << "Enter Customer ID: ";
                    cin >> cusID;

                    rented = customerRent.getRentedVideoIDs(cusID);
                    temp = rented;

                    if (temp.empty()){
                        cout << "Customer " << cusID << " did not rent any videos yet. ";
                        break;
                    } else {
                        cout << "\nVideos Rented: \n";
                        while (!temp.empty()){
                            cout << "["<<temp.top() << "] " << vid.getMovieTitle(temp.top()) << endl;
                            temp.pop();
                        }
                    }                  

                    cout << endl;
                    cout << "Enter Video ID to return: ";
                    cin >> vidID;
                    customerRent.returnVideo(vidID, cusID);
                    vid.returnVideo(vidID);
                    customerRent.updateCustomerRent();
                    cout << "Do you want to return another video? (Y/N) ";
                    cin >> again;
                } while (again == 'Y' || again == 'y');
                break;
            case 4: // show video details
                cout << green << bold << "[4] Show Video Details" << reset << endl;

                cout << "Enter Video ID: ";
                cin >> vidID;
                vid.showVideoDetails(vidID);
                break;
            case 5: // display all videos
                cout << green << bold << "[5] Display all Videos\n" << reset;
                vid.displayAllVideos();
                break;
            case 6: // check video availability
                cout << green << bold << "[6] Check Video Availability\n" << reset;
                cout << "Enter Video ID: ";
                cin >> vidID;
                
                vid.isAvailable(vidID);
                break;
            case 7: // customer maintenance
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
                    case 1: // add a new customer
                        cout << green << bold << "[1] Add Customer\n" << reset;
                        cout << "Enter Customer Name: ";
                        getline(cin, name);
                        cout << "Enter Customer Address: ";
                        getline(cin, address);
                        cus.addCustomer(name, address);
                        break;
                    case 2: // show customer details
                        cout << green << bold << "[2] Show Customer Detail\n" << reset;
                        cout << "Enter Customer ID: ";
                        cin >> cusID;
                        cus.showCustomerDetails(cusID);
                        break;
                    case 3: // list of videos
                        cout << green << bold << "[3] List of Videos Rented by a Customer\n" << reset;
                        cout << "Enter Customer ID: ";
                        cin >> cusID;
                        
                        rented = customerRent.getRentedVideoIDs(cusID);
                        temp = rented;
                        cout << endl;
                        if (temp.empty()){
                            cout << bold << red << "Customer " << cusID << " has not rented any videos yet.\n" << reset;
                        } else {
                            cout << bold << green << "Movies Rented by Customer " << cusID << ": \n" << reset;
                            while (!temp.empty()){
                            cout << "Video ID: " <<temp.top() << " | Movie Title: " << vid.getMovieTitle(temp.top()) << endl;
                            temp.pop();
                        }

                        cout << endl;
                        }
                        

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