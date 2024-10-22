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

        Node(int id, const std::string &movieTitle, const std::string &movieGenre, const std::string &movieProd, int copies)
            : videoID(id), title(movieTitle), genre(movieGenre), production(movieProd), numberOfCopies(copies), next(nullptr), previous(nullptr) {}
    };

    Node* head;

public:
    Video();
    ~Video();


    void initMovies(); // initialize a list of movies
    void insertVideo(const std::string &movieTitle, const std::string &movieGenre, const std::string &movieProd, int copies);
    void insertExistingVideo(int id, int copies);
    void rentVideo(int id);
    void returnVideo(int id);
    void showVideoDetails(int id) const;
    void displayAllVideos() const;
    void isAvailable(int id) const;
    std::string getMovieTitle(int id) const;
    void updateVideoList() const;
    bool isEmpty() const;
    bool doesExist(int id) const;

};

#endif // VIDEO_H