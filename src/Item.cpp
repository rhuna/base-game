#include "../headers/Item.h"


Item::Item() : id(0), name("Default Item"), description("This is a default item."), value(0), durability(100), weight(1.0f) {};
Item::Item(int id, const std::string& name, const std::string& description, int value, int durability, float weight)
	: id(id), name(name), description(description), value(value), durability(durability), weight(weight) {
}
int Item::getId() const { return id; }
std::string Item::getName() const { return name; }
std::string Item::getDescription() const { return description; }
int Item::getValue() const { return value; }
void Item::setName(const std::string& newName) { name = newName; }
void Item::setDescription(const std::string& newDescription) { description = newDescription; }
void Item::setValue(int newValue) { value = newValue; }