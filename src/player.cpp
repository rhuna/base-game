#include "../headers/player.h"


player::player(int id, int x, int y, int width, int height, int health, int damage)
	: entity(id, x, y, width, height, health, damage) {
}
// Additional player-specific methods can be added here
void player::move(int deltaX, int deltaY) {
	this->setPosition(getX() + deltaX, getY() + deltaY);
}
void player::attack(entity& target) {
	if (isAlive() && target.isAlive()) {
		target.takeDamage(getDamage());
	}
}
void player::useItem(const Item& item) {
	// Logic to use an item, e.g., healing potion, equipment, etc.
	// This could involve modifying health, applying buffs, etc.
}
void player::addItemToInventory(const Item& item) {
	if (inventory.size() < inventorySize) {
		inventory.push_back(item);
	}
	else {
		// Handle inventory full case, e.g., notify player or drop item
	}
}
void player::removeItemFromInventory(const Item& item) {
	auto it = std::find(inventory.begin(), inventory.end(), item);
	if (it != inventory.end()) {
		inventory.erase(it);
	}
	else {
		// Handle item not found case, e.g., notify player
	}
}
void player::levelUp() {
	level++;
	experiencePoints = 0; // Reset experience points or handle accordingly
	// Logic to increase player attributes, unlock skills, etc.
}
int player::getInventorySize() const {
	return inventorySize;
}
std::vector<Item> player::getInventory() const {
	return inventory;
}
int player::getScore() const {
	return score;
}
void player::setScore(int newScore) {
	score = newScore;
}
int player::getLevel() const {
	return level;
}
void player::setLevel(int newLevel) {
	level = newLevel;
}
int player::getExperiencePoints() const {
	return experiencePoints;
}
void player::setExperiencePoints(int newExperiencePoints) {
	experiencePoints = newExperiencePoints;
}
int player::getHealthPotions() const {
	return healthPotions;
}

void player::setHealthPotions(int newHealthPotions) {
	healthPotions = newHealthPotions;
}
int player::getManaPotions() const {
	return manaPotions;
}
void player::setManaPotions(int newManaPotions) {
	manaPotions = newManaPotions;
}

int player::getGold() const {
	return gold;
}
void player::setGold(int newGold) {
	gold = newGold;
}

std::string player::getPlayerName() const {
	return playerName;
}


void player::setPlayerName(const std::string& newName) {
	playerName = newName;
}
std::string player::getPlayerClass() const {
	return playerClass;
}