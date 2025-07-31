#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Spot.h"
#include <string>
using namespace std;

class LinkedList {
private:
    Spot* head;
public:
    LinkedList();
    void insertSpot(string city, string spot, double rating, string type, double lon, double lat);
    Spot* findSpot(string spotName);
    void addReviewToSpot(string spotName, string reviewText, double rating);
    void displayAll();
    void displayByCity(string city);
    void displayAboveRating(double minRating);
};

#endif
