#include "CustomerRent.h"

#include <iostream>
#include <stack>

using namespace std;


CustomerRent::CustomerRent() : head(nullptr) {
    // Constructor initializes any necessary data structures
}

CustomerRent::~CustomerRent() {
    // Destructor to clean up allocated memory, if any
    while (head) {
        customerNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void CustomerRent::rentVideo(int videoID, int cusID) {
    // TODO: Logic to push a videoID onto the stack
    // add to all rented video list


    customerNode* current = head;

    while (current){
        if (current->customerID == cusID){
            // customer found
            current->CustomerRentedVideoIDs.push(videoID);
            AllRentedVideoIDs.push(videoID); // add to the list of all rented video IDs
            return;
        }
        current = current->next;
    }

    // if customer not found

    customerNode* newNode = new customerNode(cusID);
    newNode->CustomerRentedVideoIDs.push(videoID);
    newNode->next = head;
    head = newNode;
    AllRentedVideoIDs.push(videoID); // add to the list of all rented video IDs

}

void CustomerRent::returnVideo(int videoID, int cusID) {


    // search for customer

    customerNode* current = head;

    while (current){
        if (current->customerID == cusID){
            // customer found
            stack<int> tempStack;
            bool found = false;
            while (!current->CustomerRentedVideoIDs.empty()) {
                int vid = current->CustomerRentedVideoIDs.top();
                current->CustomerRentedVideoIDs.pop();
                if (vid == videoID) {
                    found = true; // Video found
                    break;
                }
                tempStack.push(vid);
            }

            // restore the values of the original stack

            while (!tempStack.empty()) {
                current->CustomerRentedVideoIDs.push(tempStack.top());
                tempStack.pop();
            }

            // if the video was found

            if (found){
                stack<int> tempAllRented; // another temporary stack for all rented videos
                while (!AllRentedVideoIDs.empty()) {
                    int vid = AllRentedVideoIDs.top();
                    AllRentedVideoIDs.pop();
                    if (vid != videoID) {
                        tempAllRented.push(vid); // Keep other videos in temporary stack
                    }
                }

                // Restore original stack
                while (!tempAllRented.empty()) {
                    AllRentedVideoIDs.push(tempAllRented.top());
                    tempAllRented.pop();
                }

                cout << "Video ID " << videoID << " returned by customer ID " << cusID << endl;
                } else {
                    cout << "Customer ID " << cusID << " did not rent video ID " << videoID << endl;
                }
                return;
            }

            current = current->next;
        }
        
    cout << "Customer ID " << cusID << " not found" << endl;

}

void CustomerRent::printRentedVideos() const {
    // TODO: Logic to print all videoIDs in the stack
    
    customerNode* current = head;

    while (current){
        cout << "Customer ID: " << current->customerID << " , Rented Videos: ";
        stack<int>tempStack =  current->CustomerRentedVideoIDs;

        while (!tempStack.empty()){
            cout << tempStack.top() << " ";
            tempStack.pop();
        }

        cout << endl;
        current = current->next;
    }

}


stack<int> CustomerRent::getRentedVideoIDs(int cusID) const {
    // TODO: Logic to return a vector of all videoIDs in the stack

    // find the customer
    customerNode* current = head;
    while (current) {
        if (current->customerID == cusID) {
            // if customer found, then return rented video id/s
            return current->CustomerRentedVideoIDs;
        }
        current = current->next;
    }
    // if not found, then return empty stack
    return stack<int>();
}

void CustomerRent::updateCustomerRent() const {
    // TODO: Logic to update the rented video id/s in the stack
   // Customer Id       |    Video ID     | Video Title
   // 1                 |  1              | The Matrix

   ofstream MyFile("CustomerRent.txt");

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }


    customerNode* current = head; // start at the first customer
    while (current) {
        int customerId = current->customerID;
        stack<int> rentedVideoIDs = current->CustomerRentedVideoIDs;

        while (!rentedVideoIDs.empty()) {
            int videoId = rentedVideoIDs.top();
            rentedVideoIDs.pop();


            MyFile << "Customer ID: " << customerId << " | Video ID: " << videoId << "\n";
        }

        current = current->next;
    }

    MyFile.close();
}