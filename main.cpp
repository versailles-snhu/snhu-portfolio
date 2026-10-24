#include "ItemTracker.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "\n=====================================" << endl;
    cout << "     Corner Grocer Item Tracker      " << endl;
    cout << "=====================================" << endl;
    cout << "1. Search for an item's frequency" << endl;
    cout << "2. Print total purchase frequencies" << endl;
    cout << "3. Print graphical text histogram" << endl;
    cout << "4. Exit application" << endl;
    cout << "Enter selection (1-4): ";
}

int main() {
    ItemTracker grocerApp("CS210_Project_Three_Input_File.txt");
    int userChoice = 0;

    while (userChoice != 4) {
        displayMenu();
        cin >> userChoice;

        // Validates input structure
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input type. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (userChoice) {
            case 1: {
                string searchItem;
                cout << "Enter the item name to look up: ";
                cin >> searchItem;
                
                int count = grocerApp.getItemFrequency(searchItem);
                cout << "\nResult: " << searchItem << " was purchased " << count << " times." << endl;
                break;
            }
            case 2:
                grocerApp.printAllFrequencies();
                break;
            case 3:
                grocerApp.printHistogram();
                break;
            case 4:
                cout << "\nExiting application. Data safely preserved in frequency.dat. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid menu number. Please select an option from 1 to 4." << endl;
                break;
        }
    }

    return 0;
}