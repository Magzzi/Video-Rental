#ifndef CUSTOMERRENT_H
#define CUSTOMERRENT_H

#include <vector>

class CustomerRent {
private:
    struct Node {
        int videoID;
        Node* next;

        Node(int id) : videoID(id), next(nullptr) {}
    };

    Node* top;
    int customerID;

public:
    CustomerRent(int id);
    ~CustomerRent();

    void rentVideo(int videoID);
    void returnVideo(int videoID);
    void printRentedVideos() const;

    int getCustomerID() const;
    std::vector<int> getRentedVideoIDs() const;
};

#endif // CUSTOMERRENT_H
