#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

//Helper function to convert a string to lowercase
//This function is used to ensure that item names are handled in a case-insensitive manner
std::string ItemTracker::ToLowerCase(const std::string& str) const {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

//Constructor
//Initiates the ItemTracker with the specified input file and loads data from the file
ItemTracker::ItemTracker(std::string fileName) : inputFile(fileName) {
    LoadData(); //Load data from the input file into the itemMap
}

//Private method to load data from file
//This method reads the input file line by line , extracting item names and adding them to the itemMap
void ItemTracker::LoadData() {
    std::ifstream file(inputFile); //Open the input file for reading 
    std::string itemName;
    while (file >> itemName) { //Read each item name from the file
        AddItem(itemName); //Add the item to the map or update its frequency if it already exists
    }
    file.close(); //Close the file after reading
}

//Function to add or update an item
//This method adds a new item to the map with a frequency of 1, or increments the frequency if the item already exists
void ItemTracker::AddItem(const std::string& itemName) {
    std::string lowerName = ToLowerCase(itemName); //Converts the item name to lowercase for case-insensitive handling
    if (itemMap.find(lowerName) != itemMap.end()) { //Check if the item already exists in the map
        itemMap[lowerName].IncrementFrequency(); //If it exists, increment the frequency
    }
    else {
        itemMap[lowerName] = Item(lowerName, 1); //If it doesn't exist, add it to the map with a frequency of 1
    }
}

//Function to get an item
//This method retrieves an Item object from the map based on the item name. If the item is not found, it returns an Item with a frequency of 0
Item ItemTracker::GetItem(const std::string& itemName) const {
    std::string lowerName = ToLowerCase(itemName); //Convert the item name to lowercase for case-insensitive handling
    auto it = itemMap.find(lowerName); //Search for the item in the map
    if (it != itemMap.end()) { //If the item is found
        return it->second; //Return the corresponding Item object
    }
    return Item(lowerName, 0); //If not found, return an Item with a frequency of 0
}

//Function to print all items and their frequencies
//This method iterates over the itemMap and prints each item and its corresponding frequency
void ItemTracker::PrintAllItems() const {
    for (const auto& pair : itemMap) { //Iterate through all the items in the map
        std::cout << pair.first << " " << pair.second.GetFrequency() << std::endl; //Print the item name and its frequency
    }
}

//Function to print a histogram of item frequencies
//This method prints each item name followed by a number of asterisks representing its frequency
void ItemTracker::PrintHistogram() const {
    for (const auto& pair : itemMap) { //Iterate through all items in the map
        std::cout << pair.first << " "; //Print the item name
        for (int i = 0; i < pair.second.GetFrequency(); i++) { //Print asterisks equal to the item's frequency
            std::cout << "*";
        }
        std::cout << std::endl; //Move to the next line after printing asterisks for one item
    }
}

//Function to backup data to a file
//This method writes the current state of the itemMap to a file named frequency.dat
void ItemTracker::BackupData() const {
    std::ofstream backupFile("frequency.dat"); //Open the backup file for writing 
    for (const auto& pair : itemMap) { //Iterate through all the items in the map
        backupFile << pair.first << " " << pair.second.GetFrequency() << std::endl; //Write the item name and frequency to the file
    }
    backupFile.close(); //Close the file after writing
}