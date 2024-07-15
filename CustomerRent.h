#ifndef CUSTOMERRENT_H
#define CUSTOMERRENT_H

#include <stack>
#include <iostream>
#include "Video.h"

class CustomerRent {
private:
    struct customerNode {
        int customerID;
        std::stack<int> CustomerRentedVideoIDs;
        customerNode* next;

        customerNode(int id) : customerID(id), next(nullptr) {}
    };

    std::stack<int> AllRentedVideoIDs; // Track all rented video IDs
    customerNode* head; // Example of a linked list head for customer nodes

public:
    CustomerRent();
    ~CustomerRent();
    // Operations
    void rentVideo(int videoID, int cusID);
    void returnVideo(int videoID, int cusID);
    void printRentedVideos() const;
    void updateCustomerRent() const;
    // Getters (assuming you want to retrieve specific customer's rented videos)
    std::stack<int> getRentedVideoIDs(int cusID) const;
};

#endif // CUSTOMERRENT_H
