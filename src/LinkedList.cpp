#include <iostream>
#include <iomanip>
#include "../include/LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insertSpot(string city, string spot, double rating, string type, double lon, double lat) {
    Spot* newSpot = new Spot(city, spot, rating, type, lon, lat);
    if (!head) {
        head = newSpot;
    } else {
        Spot* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newSpot;
    }
}

Spot* LinkedList::findSpot(string spotName) {
    Spot* temp = head;
    while (temp) {
        if (temp->spotName == spotName) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::addReviewToSpot(string spotName, string reviewText, double rating) {
    Spot* spot = findSpot(spotName);
    if (spot) {
        Review* newReview = new Review(reviewText, rating);
        if (!spot->reviews) {
            spot->reviews = newReview;
        } else {
            Review* temp = spot->reviews;
            while (temp->next) temp = temp->next;
            temp->next = newReview;
        }
    }
}

void LinkedList::displayAll() {
    Spot* temp = head;
    while (temp) {
        cout << "\n" << temp->spotName << " (" << temp->city << ") [" << temp->rating << "⭐]" << endl;
        cout << "Type: " << temp->type << " | Location: (" << temp->latitude << ", " << temp->longitude << ")" << endl;

        // Display reviews
        Review* rev = temp->reviews;
        if (rev) {
            cout << "  Reviews:" << endl;
            while (rev) {
                cout << "   - [" << rev->rating << "⭐] " << rev->reviewText << endl;
                rev = rev->next;
            }
        } else {
            cout << "  No reviews yet." << endl;
        }
        temp = temp->next;
    }
}

void LinkedList::displayByCity(string city) {
    Spot* temp = head;
    bool found = false;
    while (temp) {
        if (temp->city == city) {
            cout << temp->spotName << " (" << temp->rating << "⭐)" << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No spots found for city: " << city << endl;
}

void LinkedList::displayAboveRating(double minRating) {
    Spot* temp = head;
    bool found = false;
    while (temp) {
        if (temp->rating >= minRating) {
            cout << temp->spotName << " (" << temp->city << ") [" << temp->rating << "⭐]" << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No spots found with rating >= " << minRating << endl;
}