#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>


//The item class represents an item in the groccery store and tracks its purchase frequency
class Item {
private:
    std::string name; //Name of the item
    int frequency;    //Frequency of the item being purchased

public:
    //Default constructor
    //Initialies the item with an empty name and a frequency of 0
    Item() : name(""), frequency(0) {}

    //Parameterized constructor
    //Initializes the item with a specific name and frequency
    //itemFrequency: the intial frequency of the item (defaults to 0 if not provided)
    Item(std::string itemName, int itemFrequency = 0);

    //Gets the name of the item and returns the name of the item as a string
    std::string GetName() const;

    //Gets the frequency of the item and returns the number of times the item has been purchased
    int GetFrequency() const;

    //Increments the frequency of the item by 1
    void IncrementFrequency();
};

#endif // ITEM_H