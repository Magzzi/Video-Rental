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
    Node* newNode = new Node(id, name, address);
    if (rear) {
        rear->next = newNode;
    } else {
        front = newNode;
    }
    rear = newNode;
}

void Customer::removeCustomer() {
    // TODO: Logic to show customer details of the node with the given id
    if (front) {
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
    } else {
        std::cout << "Queue is empty. No customer to remove.\n";
    }
}

void Customer::showCustomerDetails(int id) const {
    // TODO: Logic to print details of all customers in the queue
    Node* current = front;
    while (current) {
        if (current->customerID == id) {
            std::cout << "Customer ID: " << current->customerID << "\n";
            std::cout << "Name: " << current->name << "\n";
            std::cout << "Address: " << current->address << "\n";
            return;
        }
        current = current->next;
    }
    std::cout << "Customer with ID " << id << " not found.\n";
}

void Customer::printAllCustomers() const {
    Node* current = front;
    while (current) {
        std::cout << "Customer ID: " << current->customerID << "\n";
        std::cout << "Name: " << current->name << "\n";
        std::cout << "Address: " << current->address << "\n";
        std::cout << "--------------------------\n";
        current = current->next;
    }
}
