#include "../headers/Equipment.h"


Equipment::Equipment() : Item() {
	// Initialize equipment-specific members if needed
	durability = 100; // Default durability
	weight = 1.0f; // Default weight
	name = "Default Equipment"; // Default name
	description = "This is a piece of equipment."; // Default description
	value = 10; // Default value
	id = 0; // Default ID
	level = 1; // Default level
	type = "Generic"; // Default type
}
// Parameterized constructor
Equipment::Equipment(int id, const std::string& name, const std::string& description, int value, int durability, float weight, const std::string& type, int level)
	: Item(id,name,description,value, durability, weight), durability(durability), weight(weight), type(type), level(level) {
	// Initialize equipment-specific members
	this->name = name;
	this->description = description;
	this->value = value;
	this->id = id;
}
Equipment::Equipment(std::string name, int durability, float weight) : Item(), durability(durability), weight(weight), name(name) {
	// Initialize equipment-specific members
	this->name = name;
	this->durability = durability;
	this->weight = weight;
	this->description = "This is a piece of equipment."; // Default description
	this->value = 10; // Default value
	this->id = 0; // Default ID
	this->level = 1; // Default level
	this->type = "Generic"; // Default type
};

// Copy constructor
Equipment::Equipment(const Equipment& other) : Item(other), durability(other.durability), weight(other.weight), type(other.type), level(other.level) {
	// Copy equipment-specific members
	name = other.name;
	description = other.description;
	value = other.value;
	id = other.id;
}
// Assignment operator
Equipment& Equipment::operator=(const Equipment& other) {
	if (this != &other) {
		Item::operator=(other); // Call base class assignment operator
		durability = other.durability;
		weight = other.weight;
		type = other.type;
		level = other.level;
		name = other.name;
		description = other.description;
		value = other.value;
		id = other.id;
	}
	return *this;
}
// Destructor
Equipment::~Equipment() {
	// Cleanup if needed
	// For example, if you had dynamically allocated memory, you would release it here
}
// Getters and setters for equipment-specific members
std::string Equipment::getName() const { return name; }
std::string Equipment::getDescription() const { return description; }
int Equipment::getDurability() const { return durability; }
void Equipment::setDurability(int newDurability) { durability = newDurability; }
float Equipment::getWeight() const { return weight; }
void Equipment::setWeight(float newWeight) { weight = newWeight; }
std::string Equipment::getType() const { return type; }
void Equipment::setType(const std::string& newType) { type = newType; }
int Equipment::getLevel() const { return level; }
void Equipment::setLevel(int newLevel) { level = newLevel; }