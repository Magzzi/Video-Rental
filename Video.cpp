#include "Video.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



Video::Video() : head(nullptr) {} // constructor

Video::~Video() { // destructor
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Video::insertVideo(const std::string &movieTitle, const std::string &movieGenre, const std::string &movieProd, int copies) { // inserts a new video node into the linked list
    
    // check if movie already exist

    Node* current = head;
    while (current != nullptr) {
        if (current->title == movieTitle) {
            // Movie already exists, increment the number of copies
            current->numberOfCopies += copies;
            updateVideoList();
            return;
        }
        current = current->next;
    }

    // if not
    static int videoIDCounter = 1; // to keep in memory


    Node* newNode = new Node(videoIDCounter,movieTitle, movieGenre, movieProd, copies);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next!= nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current; // Add this line
    }

    videoIDCounter++;
    updateVideoList();
}

void Video::insertExistingVideo(int id, int copies){ // allows the user to insert an existing video; if exists, number of copies will increase
    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            current->numberOfCopies += copies;
            updateVideoList();
            return;
        }
        current = current->next;
    }

    cout << "\033[31m" << "\033[1m"  << "Unable to add existing video. Video ID " << id << " not found" << "\033[0m" << endl;
}

void Video::rentVideo(int id) { // allows the user to rent a video, which decrements the number of copies if available

    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            if (current->numberOfCopies > 0){
                current->numberOfCopies--;
                updateVideoList();
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

void Video::returnVideo(int id) { // return video and increment the copies
    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            current->numberOfCopies++;
            updateVideoList();
            return;
        } else {
            current = current->next;
        }
    }
    cout << "\033[31m" << "\033[1m" << "Video " << id << " not found.\n" << "\033[0m";
}

void Video::showVideoDetails(int id) const { // display video details of the node with the given id

    Node* current = head;

    while (current != nullptr){
        if (current->videoID == id) {
            cout << "Movie Title: " << current->title << endl;
            cout << "Genre: " << current->genre << endl;
            cout << "Production: " << current->production << endl;
            cout << "Number of Copies Available: " << current->numberOfCopies << endl;
            return;
        } else {
            current = current->next;
        }
    }

    cout << "\033[31m" << "\033[1m" << "Video not found.\n" << "\033[0m";
}

void Video::displayAllVideos() const { // display details of all videos in the linked list

    Node* current = head;

    if (head == nullptr){
        cout << "No videos available.\n";
        return;
    } else {
        cout << endl << "\033[34m" << "\033[1m" <<"List of All Videos: " << "\033[0m" << endl;
        while (current != nullptr){
            cout << "Video ID: " << current->videoID << endl;
            cout << "Movie Title: " << current->title << endl;
            cout << "Genre: " << current->genre << endl;
            cout << "Production: " << current->production << endl;
            cout << endl;
            current = current->next;
        }
    }
}

void Video::isAvailable(int id) const { // check if the video with the given id is available (number of copies > 0) or check if there are any copies available

    Node* current = head;
    while (current != nullptr) {
        if (current->videoID == id) {
            if (current->numberOfCopies > 0){
                showVideoDetails(id);
                cout << "Availability: " << "\033[1m"  << "\033[32m" << "Available" << "\033[0m" << endl;
                return;
            } else {
                showVideoDetails(id);
                cout << "Availability: " << "\033[1m" << "\033[31m" << "Not Available" << "\033[0m" << endl;
                return;
            }
        } else {
            current = current->next;
        }     
    }
    cout << "\033[31m" << "\033[1m" << "Video not found\n" << "\033[0m";
    return;
}


std::string Video::getMovieTitle(int id) const { // if movie exists, then return title
    Node* current = head;
    while (current!= nullptr) {
        if (current->videoID == id) {
            return current->title;
        } else {
            current = current->next;
        }
    }
    return "";
}

bool Video::isEmpty() const { // check if there are no videos
    return head == nullptr;
}

void Video::initMovies(){ // initialize the list of movies every start of the program; copies are set to 10 by default


    // initialize movie list

    string initMovie[25][3] = { 
    {"IT", "Box Office", "Horror"},
    {"A Quiet Place", "Paramount Pictures", "Horror"},
    {"Smile", "Paramount Pictures", "Horror"},
    {"Unfriended", "Universal Pictures", "Horror"},
    {"Cult of Chucky", "Universal Pictures", "Horror"},
    {"Titanic", "20th Century Fox", "Romance"},
    {"50 First Dates", "Happy Madison Productions", "Romance"},
    {"The Notebook", "Gran Via Production", "Romance"},
    {"About Time", "Working Title Films", "Romance"},
    {"Sweet & Sour", "KT Hitel", "Romance"},
    {"Interstellar", "Lynda Obst Production", "Sci-Fi"},
    {"Super 8", "Bad Robot Production", "Sci-Fi"},
    {"Inception", "Warner Bros. Pictures", "Sci-Fi"},
    {"The 5th Wave", "Columbia Pictures", "Sci-Fi"},
    {"Mad Max", "Kennedy Miller Productions", "Sci-Fi"},
    {"Scott Pilgrim vs. The World", "Universal Pictures", "Action"},
    {"The Dark Knight", "Warner Bros. Pictures", "Action"},
    {"The Matrix", "Warner Bros. Pictures", "Action"},
    {"Gladiator", "Warner Bros. Pictures", "Action"},
    {"John Wick", "Thunder Road Pictures", "Action"},
    {"Grown Ups", "Sony Pictures", "Comedy"},
    {"Rush Hour", "New Line Cinema", "Comedy"},
    {"The Three Stooges", "20th Century Studios", "Comedy"},
    {"21 Jump Street", "Sony Pictures", "Comedy"},
    {"Home Alone", "Warner Bros. Pictures", "Comedy"}
    };

    for (int i = 0; i < 25; i++){
        insertVideo(initMovie[i][0], initMovie[i][2], initMovie[i][1], 10);
    }
}

void Video::updateVideoList() const { // update the text file
    ofstream MyFile("Video.txt");

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    Node* current = head;

    if (head == nullptr) {
        MyFile << "No videos available." << endl;
    } else {
        MyFile << "List of All Videos:" << endl;
        MyFile << "-------------------" << endl;
        while (current != nullptr) {
            MyFile << "Video ID: " << current->videoID << endl;
            MyFile << "Movie Title: " << current->title << endl;
            MyFile << "Genre: " << current->genre << endl;
            MyFile << "Production: " << current->production << endl;
            MyFile << "Number of Copies Available: " << current->numberOfCopies << endl;
            MyFile << "-------------------" << endl;
            current = current->next;
        }
    }

    MyFile.close();
}

bool Video::doesExist(int id) const{ // check if movie id exists
    Node* current = head;
    while (current!= nullptr) {
        if (current->videoID == id) {
            return true;
        } else {
            current = current->next;
        }
    }

    cout << "\033[31m" << "\033[1m"  << "Unable to rent video. Video ID " << id << " does not exist." << "\033[0m" << endl;
    return false;
}