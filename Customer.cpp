#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() : front(nullptr), rear(nullptr) {}

Customer::~Customer() {
    Node* current = front;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}


void Customer::initCustomer(){
    string customerInit[10][2] = {
        {"Zio Magugat", "Malolos, Bulacan"},
        {"Derick Odda", "Quezon City, Metro Manila"},
        {"Igon Dela Cruz", "Binangonan, Rizal"},
        {"Klyde Mejia", "Meycauayan, Bulacan"},
        {"Eugene Arago", "Tondo, Manila"},
        {"LeBron James", "Beverly Hills, California"},
        {"Anthony Edwards", "Atlanta, Georgia"},
        {"Stephen Curry", "Silicon Valley, San Francisco"},
        {"Taylor Swift", "New York City, New York"},
        {"Johnny Depp", "Somerset, England"}
    };

    for (int i = 0; i < 10; i++){
        addCustomer(customerInit[i][0], customerInit[i][1]);
    }
}
bool Customer::checkCustomer(int id) const{
    Node* current = front;
    while (current) {
        if (current->customerID == id) {
            return true;
        }
        current = current->next;
    }
    return false;


}
void Customer::addCustomer(const std::string &name, const std::string &address) {
    // TODO: Logic to add a new customer to the rear of the queue

    static int customerIdCounter = 1;
    Node* newNode = new Node(customerIdCounter, name, address);
    if (rear) {
        rear->next = newNode;
    } else {
        front = newNode;
    }
    rear = newNode;
    customerIdCounter++;
    updateCustomerList();
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

    updateCustomerList();
}

void Customer::showCustomerDetails(int id) const {
    // TODO: Logic to print details of all customers in the queue
    Node* current = front;
    while (current) {
        if (current->customerID == id) {
            std::cout << "Customer ID: " << current->customerID << "\n";
            std::cout << "Name: " << current->customerName << "\n";
            std::cout << "Address: " << current->customerAddress << "\n";
            return;
        }
        current = current->next;
    }
    cout << "\033[31m" << "\033[1m" << "Customer with ID " << id << " not found.\n" << "\033[0m";
}

void Customer::printAllCustomers() const {
    Node* current = front;
    while (current) {
        std::cout << "Customer ID: " << current->customerID << "\n";
        std::cout << "Name: " << current->customerName << "\n";
        std::cout << "Address: " << current->customerAddress << "\n";
        std::cout << "--------------------------\n";
        current = current->next;
    }
}

void Customer::updateCustomerList() const {
    ofstream MyFile("Customer.txt");

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    Node* current = front;
    MyFile << "List of All Customers:" << endl;
    MyFile << "-------------------" << endl;
    while (current) {
        MyFile << "Customer ID: " << current->customerID << "\n";
        MyFile << "Name: " << current->customerName << "\n";
        MyFile << "Address: " << current->customerAddress << "\n";
        MyFile << "--------------------------\n";
        current = current->next;
    }

    MyFile.close();
}