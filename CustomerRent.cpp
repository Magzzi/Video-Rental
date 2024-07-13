#include "CustomerRent.h"
#include <iostream>

CustomerRent::CustomerRent(int id) : customerID(id), top(nullptr) {}

CustomerRent::~CustomerRent() {
    Node* current = top;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void CustomerRent::rentVideo(int videoID) {
    // TODO: Logic to push a videoID onto the stack
}

void CustomerRent::returnVideo(int videoID) {
    // TODO: Logic to pop a videoID from the stack
}

void CustomerRent::printRentedVideos() const {
    // TODO: Logic to print all videoIDs in the stack
}

int CustomerRent::getCustomerID() const {
    return customerID;
}

std::vector<int> CustomerRent::getRentedVideoIDs() const {
    // TODO: Logic to return a vector of all videoIDs in the stack
    // Collect all video IDs

    //  std::vector<int> videoIDs;

    // Traverse the linked list (stack) and collect video IDs into the vector

    // Return stack
}
