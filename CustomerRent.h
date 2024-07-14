#ifndef CUSTOMERRENT_H
#define CUSTOMERRENT_H

#include <stack>
#include <vector>

class CustomerRent {
private:
    std::stack<int> rentedVideos;
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