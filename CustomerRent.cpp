#include "CustomerRent.h"
#include <iostream>
#include <vector>

CustomerRent::CustomerRent(int id) : customerID(id) {
    // Constructor implementation
}

CustomerRent::~CustomerRent() {
    // Destructor implementation
    // No need to manually delete nodes, the STL stack will handle memory management
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
    return std::vector<int>();
}
