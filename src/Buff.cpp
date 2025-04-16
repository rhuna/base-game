#include "../headers/Buff.h"
#include <string>


// Default constructor
Buff::Buff() : id(0), name(""), description(""), duration(0), effectValue(0) {}
// Parameterized constructor
Buff::Buff(int id, const std::string& name, const std::string& description, int duration, int effectValue) 
	: id(id), name(name), description(description), duration(duration), effectValue(effectValue) {
}
// Copy constructor
Buff::Buff(const Buff& other)
	: id(other.id), name(other.name), description(other.description),
	duration(other.duration), effectValue(other.effectValue) {
}
// Assignment operator
Buff& Buff::operator=(const Buff& other) {
	if (this != &other) {
		id = other.id;
		name = other.name;
		description = other.description;
		duration = other.duration;
		effectValue = other.effectValue;
	}
	return *this;
}
// Destructor
Buff::~Buff() {}
// Getters and setters
int Buff::getId() const { return id; }
void Buff::setId(int newId) { id = newId; }
std::string Buff::getName() const { return name; }
void Buff::setName(const std::string& newName) { name = newName; }
std::string Buff::getDescription() const { return description; }
void Buff::setDescription(const std::string& newDescription) { description = newDescription; }
int Buff::getDuration() const { return duration; }
void Buff::setDuration(int newDuration) { duration = newDuration; }
int Buff::getEffectValue() const { return effectValue; }
void Buff::setEffectValue(int newEffectValue) { effectValue = newEffectValue; }