#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Item.h"

class Equipment : Item {
public:
	// Default constructor
	Equipment();
	// Parameterized constructor
	Equipment(int id, const std::string& name, const std::string& description, int value, int durability, float weight, const std::string& type, int level);
	// Copy constructor
	Equipment(const Equipment& other);
	// Assignment operator
	Equipment& operator=(const Equipment& other);
	// Destructor
	~Equipment();
	// Getters and setters for equipment-specific members
	std::string getName() const;
	std::string getDescription() const;
	int getDurability() const;
	void setDurability(int newDurability);
	float getWeight() const;
	void setWeight(float newWeight);
	std::string getType() const;
	void setType(const std::string& newType);
	int getLevel() const;
	void setLevel(int newLevel);
	


private:
	// Private members can be added here if needed
	// For example, you might want to store the equipment's name, durability, etc.
	// This keeps the class clean and focused on its public interface while allowing for future expansion
	// Example private members:
	int durability; // Durability of the equipment
	float weight; // Weight of the equipment
	std::string name; // Name of the equipment
	std::string description; // Description of the equipment
	int value; // Value of the equipment in the game world
	int id; // Unique identifier for the equipment item
	std::string type; // Type of the equipment (e.g., weapon, armor, etc.)
	int level; // Level of the equipment, which might affect its stats or usability








protected:
	// Protected members can be added here if needed
	// For example, you might want to store the equipment's type, level, etc.
	// This allows derived classes to access these members while keeping them hidden from outside the class hierarchy
	

	// Additional methods can be added here if needed
	void displayEquipmentDetails() const {
		std::cout << "Equipment ID: " << id << "\n"
			<< "Name: " << name << "\n"
			<< "Description: " << description << "\n"
			<< "Value: " << value << "\n"
			<< "Durability: " << durability << "\n"
			<< "Weight: " << weight << "\n"
			<< "Type: " << type << "\n"
			<< "Level: " << level << std::endl;
	}



};




#endif // !1



