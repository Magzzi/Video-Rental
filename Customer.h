#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    struct Node {
        int customerID;
        std::string customerName;
        std::string customerAddress;
        Node* next;

        Node(int id, const std::string &name, const std::string &address)
            : customerID(id), customerName(name), customerAddress(address), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Customer();
    ~Customer();
    void initCustomer();
    bool checkCustomer(int id) const;
    void addCustomer(const std::string &name, const std::string &address); // Enqueue
    void removeCustomer(); // Dequeue
    void showCustomerDetails(int id) const;
    void printAllCustomers() const;
};


#endif // CUSTOMER_H
