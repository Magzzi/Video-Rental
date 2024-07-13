#include "Video.h"
#include <iostream>

Video::Video() : head(nullptr) {}

Video::~Video() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Video::insertVideo(int id, const std::string &title, const std::string &genre, const std::string &production, int copies) {
    // TODO: Logic to insert a new video node into the linked list
}

void Video::rentVideo(int id) {
    // TODO: Logic to decrement the number of copies if available
}

void Video::returnVideo(int id) {
    // TODO: Logic to increment the number of copies
}

void Video::showVideoDetails(int id) const {
    // TODO: Logic to display video details of the node with the given id
}

void Video::displayAllVideos() const {
    // TODO: Logic to display details of all videos in the linked list
}

bool Video::isAvailable(int id) const {
    // TODO: Logic to check if the video with the given id is available (number of copies > 0)
    return false;
}

Video::Node* Video::findVideo(int id) const {
    // TODO: Logic to find and return a node with the given id
    return nullptr;
}
