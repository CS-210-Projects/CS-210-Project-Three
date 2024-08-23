#include "Item.h"

//Paramaterized constructor
//Initializes an item object with the provided name and frequency
//itemFrequency: the initial frequency of the item
Item::Item(std::string itemName, int itemFrequency) : name(itemName), frequency(itemFrequency) {}

//Gets the name of the item and returns the name of the item as a string
std::string Item::GetName() const {
    return name;
}

//Gets the frequency of the item and returns the frequency, which is the number of times it has been purchased
int Item::GetFrequency() const {
    return frequency;
}

//Function to increment frequency of the item by 1
void Item::IncrementFrequency() {
    frequency++;
}