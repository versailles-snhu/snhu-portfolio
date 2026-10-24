#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ItemTracker::ItemTracker(const string& inputFilename) {
    loadData(inputFilename);
    saveBackup("frequency.dat");
}

// Opens the grocery file and tallies up how many times each item appears
void ItemTracker::loadData(const string& filename) {
    ifstream inputFile(filename);
    string currentItem;

    if (!inputFile.is_open()) {
        cout << "Error: Could not open input data file: " << filename << endl;
        return;
    }

    while (inputFile >> currentItem) {
        // Automatically increments the counter for this specific item
        itemFrequencies[currentItem]++;
    }

    inputFile.close();
}

void ItemTracker::saveBackup(const string& filename) {
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Warning: Could not create backup file: " << filename << endl;
        return;
    }

    // Loop through the map data to save each pair onto its own line
    for (auto const& pair : itemFrequencies) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

// Menu Option 1
int ItemTracker::getItemFrequency(const string& item) {
    // Check if the item exists in the data collection
    if (itemFrequencies.find(item) != itemFrequencies.end()) {
        return itemFrequencies[item];
    }
    return 0; // If the grocery item was never bought return zero
}

// Menu Option 2
void ItemTracker::printAllFrequencies() {
    cout << "\n--- Complete Purchase Frequencies ---" << endl;
    for (auto const& pair : itemFrequencies) {
        cout << setw(15) << left << pair.first << ": " << pair.second << endl;
    }
}

// Menu Option 3
void ItemTracker::printHistogram() {
    cout << "\n--- Purchase Frequency Histogram ---" << endl;
    for (auto const& pair : itemFrequencies) {
        cout << setw(15) << left << pair.first << " ";
        
        // Loop prints an asterisk for each tracked item
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
