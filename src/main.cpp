#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/LinkedList.h"
using namespace std;

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

    cout << "\nAll Tourist Spots with Reviews:\n";
    list.displayAll();

    return 0;
}
