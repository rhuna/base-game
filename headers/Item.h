#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

class Item{
public:
	// Default constructor
	Item();
	Item(int id, const std::string& name, const std::string& description, int value, int durability, float weight)
		: id(id), name(name), description(description), value(value), durability(durability), weight(weight) {
	}
	int getId() const;
	std::string getName() const;
	std::string getDescription() const;
	int getValue() const;
	void setName(const std::string& newName);
	void setDescription(const std::string& newDescription);
	void setValue(int newValue);

private:
	int id; // Unique identifier for the item
	std::string name; // Name of the item
	std::string description; // Description of the item
	int value; // Value of the item, could represent cost, worth, etc.
	// Additional attributes can be added here
	int weight; // Weight of the item
	std::string itemType; // Type of the item (e.g., weapon, armor, potion)
	int durability; // Durability of the item, if applicable
	std::string rarity; // Rarity of the item (e.g., common, rare, epic, legendary)
	std::vector<std::string> effects; // Effects or bonuses provided by the item
	std::string icon; // Path to the item's icon or image
	std::string model; // Path to the item's 3D model, if applicable
	std::string category; // Category of the item (e.g., consumable, equipment, crafting material)
	std::vector<std::string> tags; // Tags for categorization or filtering (e.g., "healing", "magic", "crafting")


};



#endif // !ITEM_H



