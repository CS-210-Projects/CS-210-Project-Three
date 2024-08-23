#pragma once
#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <map>
#include <string>
#include "Item.h"


//The ItemTracker class is responsible for managing a collection of items and tracking their purchase frequency
//It also provides functionality to add items, retrieve item data, print item lists and histograms, and back up data to a file
class ItemTracker {
private:
    std::map<std::string, Item> itemMap; //A map to store items and their corresponding frequencies
    std::string inputFile; //The name of the input file that contains the list of items

    //LoadData reads the input file and populates the itemMap with the items and their frequency
    void LoadData();

    //ToLowerCase converts a given string to lowercase. It helps ensure case-insensitive comparisons when managing items
    std::string ToLowerCase(const std::string& str) const;

public:
    //Constructor
    //Initializes the ItemTracker with the specified input file name
    ItemTracker(std::string fileName);

    //AddItem either adds a new item to the itemMap or increments the frequency of an existing item
    void AddItem(const std::string& itemName);

    //GetItem retrieves an Item object from the itemMap
    //Returns the Item object corresponding to the given item name
    Item GetItem(const std::string& itemName) const;

    //PrintAllItems prints a list of all items in the itemMap along with their frequencies
    void PrintAllItems() const;

    //PrintHistogram prints a histogram of item frequencies
    //Each item is followed by a number of asterisks corresponding to its frequency
    void PrintHistogram() const;

    //BackupData writes the current item frequencies to a file name "frequency.dat"
    //This serves as a backup of the current state of item purchases
    void BackupData() const;
};

#endif //ITEMTRACKER_H