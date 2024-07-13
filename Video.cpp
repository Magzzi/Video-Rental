#include "Video.h"
#include <iostream>

using namespace std;


Video::Video() : head(nullptr) {}

Video::~Video() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Video::insertVideo(const std::string &title, const std::string &genre, const std::string &production, int copies) {
    // TODO: Logic to insert a new video node into the linked list

    static int videoIDCounter = 1; // to keep in memory


    Node* newNode = new Node(title, genre, production, copies);
    newNode->videoID = videoIDCounter;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        if (current->title == title){
            current->numberOfCopies += copies;
        }
        while (current->next!= nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current; // Add this line
    }

    videoIDCounter++;
}

void Video::rentVideo(int id) {
    // TODO: Logic to decrement the number of copies if available

    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            if (current->numberOfCopies > 0){
                current->numberOfCopies--;
                return;
            } else {
                cout << "Sorry, video " << id << " is not available or currently out of stock\n.";
                return;
            }
        } else {
            current = current->next;
        }     
    }
}

void Video::returnVideo(int id) {
    // TODO: Logic to increment the number of copies
    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            current->numberOfCopies++;
            return;
        } else {
            current = current->next;
        }
    }
    cout << "Video " << id << " not found.\n";
}

void Video::showVideoDetails(int id) const {
    // TODO: Logic to display video details of the node with the given id]

    Node* current = head;

    while (current != nullptr){
        if (current->videoID == id) {
            cout << "Movie Title: " << current->title << endl;
            cout << "Genre: " << current->genre << endl;
            cout << "Production: " << current->production << endl;
            cout << "Number of Copies Available: " << current->numberOfCopies << endl;
        } else {
            current = current->next;
        }
    }
}

void Video::displayAllVideos() const {
    // TODO: Logic to display details of all videos in the linked list

    Node* current = head;

    if (head == nullptr){
        cout << "No videos available.\n";
    } else {
        cout << "Videos: " << endl;
        while (current != nullptr){
            cout << "Video ID: " << current->videoID << endl;
            cout << "Movie Title: " << current->title;
            cout << "Genre: " << current->genre << endl;
            cout << "Production: " << current->production << endl;
            cout << endl;
            current = current->next;
        }
    }
}

void Video::isAvailable(int id) const {
    // TODO: Logic to check if the video with the given id is available (number of copies > 0)

    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            if (current->numberOfCopies > 0){
                showVideoDetails(id);
                cout << "Availability: Available" << endl;
            } else {
                showVideoDetails(id);
                cout << "Availability: Not Available" << endl;
            }
        } else {
            current = current->next;
        }     
    }

}

