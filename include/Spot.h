#ifndef SPOT_H
#define SPOT_H

#include <string>
using namespace std;

struct Review {
    string reviewText;
    double rating;
    Review* next;

    Review(string text, double r) {
        reviewText = text;
        rating = r;
        next = nullptr;
    }
};

struct Spot {
    string city;
    string spotName;
    double rating;
    string type;
    double longitude;
    double latitude;

    Spot* next;
    Review* reviews; // Linked list of reviews

    Spot(string c, string s, double r, string t, double lon, double lat) {
        city = c;
        spotName = s;
        rating = r;
        type = t;
        longitude = lon;
        latitude = lat;
        next = nullptr;
        reviews = nullptr;
    }
};

#endif
