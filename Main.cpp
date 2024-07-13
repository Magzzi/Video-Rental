#include <iostream>
#include "Video.h"
#include "Customer.h"
#include "CustomerRent.h"

using namespace std;

Video vid;

int main(){

    
    while (true){ 
        cout << "[1] New Video\n";
        cout << "[2] Rent a Video\n";
        cout << "[3] Return a Video\n";
        cout << "[4] Show Video Details\n";
        cout << "[5] Display all Videos\n";
        cout << "[6] Check Video Availability\n";
        cout << "[7] Customer Maintenance\n";
        cout << "[8] Exit Program\n";

        int op;
        cin >> op;


        std::string title, prod, genre;
        int numofcopies;

        int cusID;
        int vidID;
        char again;
        switch (op){
            case 1:
                cout << "[1] New Video\n";
                cout << "Enter Movie Title: \n";
                getline(cin, title);
                cout << "Enter Genre: \n";
                getline (cin, genre);
                cout << "Enter Producer: \n";
                getline (cin, prod);
                cout << "Enter Number of Copies: \n";
                cin >> numofcopies;
                vid.insertVideo(title, prod, genre, numofcopies);
                break;
            case 2:
                cout << "[2] Rent a Video\n";

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
                cout << "[3] Return a Video\n";
                break;
            case 4:
                cout << "[4] Show Video Details\n";

                cout << "Enter Video ID: ";
                cin >> vidID;

                vid.showVideoDetails(vidID);
                break;
            case 5:
                cout << "[5] Display all Videos\n";
                vid.displayAllVideos();
                break;
            case 6:
                cout << "[6] Check Video Availability\n";
                cout << "Enter Video ID: ";
                cin >> vidID;

                vid.isAvailable(vidID);
                break;
            case 7:
                cout << "[1] Add Customer\n";
                cout << "[2] Show Customer Details\n";
                cout << "[3] List of Videos Rented by a Customer\n";
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid option. Please choose a valid option.\n";
            
        }   

    }

    return 0;
}