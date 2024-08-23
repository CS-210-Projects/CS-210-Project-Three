#include "ItemTracker.h"
#include <iostream>
//Roger Fisher 8/18/2024

int main() {
    //Initialize the itemTracker with the input file "produce.txt"
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");

    int choice; //Variable to store the user's menu choice
    do {
        std::cout << "1. Find Frequency of an Item\n";
        std::cout << "2. Print All Item Frequencies\n";
        std::cout << "3. Print Histogram of Frequencies\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; //Get the user's choice

        switch (choice) {
        case 1: { //Option 1: Find the frequency of an Item
            std::string itemName;
            std::cout << "Enter item name: ";
            std::cin >> itemName; //Get the item name from the user
            Item item = tracker.GetItem(itemName); //Retrieve the item from the tracker
            std::cout << "Frequency of " << item.GetName() << " is " << item.GetFrequency() << std::endl;
            break;
        }
        case 2: //Option 2: Print all the item frequencies
            tracker.PrintAllItems(); //Print the list of all items and their frequencies
            break;
        case 3: //Option 3: Print Histogram of frequencies
            tracker.PrintHistogram(); //Print a histogram representing item frequencies
            break;
        case 4: //Option 4: Exit
            std::cout << "Exiting..." << std::endl;
            break;
        default: //Invalid choice handling
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 4); //Repeat the menu until the user chooses exit

    //Backup the item data to "frequency.dat" before exiting 
    tracker.BackupData();
    return 0; //Return 0 to indicate successful execution
}