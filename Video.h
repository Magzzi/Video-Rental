#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video {
private:
    struct Node {
        int videoID;
        std::string title;
        std::string genre;
        std::string production;
        int numberOfCopies;
        Node* next;
        Node* previous;

        Node(const std::string &title, const std::string &genre, const std::string &production, int copies)
            : title(title), genre(genre), production(production), numberOfCopies(copies), next(nullptr) {}
    };

    Node* head;

public:
    Video();
    ~Video();

    void insertVideo(int id, const std::string &title, const std::string &genre, const std::string &production, int copies);
    void rentVideo(int id);
    void returnVideo(int id);
    void showVideoDetails(int id) const;
    void displayAllVideos() const;
    void isAvailable(int id) const;

};

#endif // VIDEO_H
