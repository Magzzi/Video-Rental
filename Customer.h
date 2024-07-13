#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    struct Node {
        int customerID;
        std::string name;
        std::string address;
        Node* next;

        Node(int id, const std::string &name, const std::string &address)
            : customerID(id), name(name), address(address), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Customer();
    ~Customer();

    void addCustomer(int id, const std::string &name, const std::string &address);
    void showCustomerDetails(int id) const;
    void printAllCustomers() const;
};

#endif // CUSTOMER_H