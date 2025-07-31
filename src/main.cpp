#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/LinkedList.h"
using namespace std;

void displayMenu() {
    cout << "\n========= Travel Planner Menu =========" << endl;
    cout << "1. Show all tourist spots" << endl;
    cout << "2. Search spots by city" << endl;
    cout << "3. Search spot by name" << endl;
    cout << "4. Show spots above a rating" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LinkedList list;

    // Load tourist_spots.csv
    ifstream spotsFile("data/tourist_spots.csv");
    if (!spotsFile.is_open()) {
        cout << "Error opening tourist_spots.csv!" << endl;
        return 1;
    }

    string line;
    getline(spotsFile, line); // Skip header
    while (getline(spotsFile, line)) {
        string city, spot, ratingStr, type, lonStr, latStr;
        stringstream ss(line);

        getline(ss, city, ',');
        getline(ss, spot, ',');
        getline(ss, ratingStr, ',');
        getline(ss, type, ',');
        getline(ss, lonStr, ',');
        getline(ss, latStr, ',');

        list.insertSpot(city, spot, stod(ratingStr), type, stod(lonStr), stod(latStr));
    }
    spotsFile.close();

    // Load spot_reviews.csv
    ifstream reviewFile("data/spot_reviews.csv");
    if (!reviewFile.is_open()) {
        cout << "Error opening spot_reviews.csv!" << endl;
        return 1;
    }

    getline(reviewFile, line); // Skip header
    while (getline(reviewFile, line)) {
        string city, spot, ratingStr, review;
        stringstream ss(line);

        getline(ss, city, ',');
        getline(ss, spot, ',');
        getline(ss, ratingStr, ',');
        getline(ss, review, ',');

        list.addReviewToSpot(spot, review, stod(ratingStr));
    }
    reviewFile.close();

    // Interactive menu
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear buffer

        if (choice == 1) {
            list.displayAll();
        } 
        else if (choice == 2) {
            string city;
            cout << "Enter city name: ";
            getline(cin, city);
            list.displayByCity(city);
        } 
        else if (choice == 3) {
            string spot;
            cout << "Enter spot name: ";
            getline(cin, spot);
            Spot* found = list.findSpot(spot);
            if (found) {
                cout << "\n" << found->spotName << " (" << found->city << ") [" << found->rating << "⭐]" << endl;
                cout << "Type: " << found->type << " | Location: (" << found->latitude << ", " << found->longitude << ")" << endl;

                Review* rev = found->reviews;
                if (rev) {
                    cout << "  Reviews:" << endl;
                    while (rev) {
                        cout << "   - [" << rev->rating << "⭐] " << rev->reviewText << endl;
                        rev = rev->next;
                    }
                } else {
                    cout << "  No reviews yet." << endl;
                }
            } else {
                cout << "Spot not found!" << endl;
            }
        } 
        else if (choice == 4) {
            double minRating;
            cout << "Enter minimum rating: ";
            cin >> minRating;
            cin.ignore();
            list.displayAboveRating(minRating);
        } 
        else if (choice == 5) {
            cout << "Exiting Travel Planner. Goodbye!" << endl;
        } 
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
