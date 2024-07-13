#include "Customer.h"
#include <iostream>

Customer::Customer() : front(nullptr), rear(nullptr) {}

Customer::~Customer() {
    Node* current = front;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Customer::addCustomer(int id, const std::string &name, const std::string &address) {
    // TODO: Logic to add a new customer to the rear of the queue
}

void Customer::showCustomerDetails(int id) const {
    // TODO: Logic to show customer details of the node with the given id
}

void Customer::printAllCustomers() const {
    // TODO: Logic to print details of all customers in the queue
}
