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
void player::addQuest(std::unique_ptr<Quest> quest) {
	//add quest
	m_quests.push_back(std::move(quest));

};
void player::addEquipment(const Equipment& equipment) {
	// Logic to add equipment to the player's inventory or equipment list
	// This could involve checking if the player can equip it, updating stats, etc.
	m_equipment.push_back(equipment);
	// Assuming equipmentList is a member variable of type std::vector<Equipment>

	// You might want to update player stats or notify the player about the new equipment
	// For example, if the equipment has a stat boost, apply it to the player
	// playerStats.applyEquipmentStats(equipment);
	// If the equipment has a special effect, apply it as well
	//std::cout << "Equipment " << equipment.getName() << " added to player's inventory." << std::endl;

};
std::vector<Equipment> player::getEquipment() {
	// Logic to retrieve and display player's equipment
	for (const auto& equip : m_equipment) {
		// Assuming Equipment has a method to get its name or description
		std::cout << "Equipment: " << equip.getName() << " - " << equip.getDescription() << std::endl;
	}
	// You might want to return the equipment list or perform some other action
	// For example, if you want to return the list of equipment
	return m_equipment; // Assuming m_equipment is a member variable of type std::vector<Equipment>
};
std::vector<std::unique_ptr<Quest>> player::getQuests() {
	// Logic to retrieve and display player's quests
	for (const auto& quest : m_quests) {
		// Assuming Quest has a method to get its name or description
		std::cout << "Quest: " << quest->getName() << " - " << quest->getDescription() << std::endl;
	}
	return m_quests; // Assuming you want to return the list of quests
}
void player::removeQuest(const Quest& quest) {
	//remove quest
	auto it = std::find(m_quests.begin(), m_quests.end(), quest);
	if (it != m_quests.end()) {
		m_quests.erase(it);
	}
	else {
		// Handle quest not found case, e.g., notify player
	}

};
void player::completeQuest(std::unique_ptr<Quest> quest) {
	// Logic to complete a quest, e.g., grant rewards, update status, etc.
	auto it = std::find(m_quests.begin(), m_quests.end(), quest);
	if (it != m_quests.end()) {
		// Assuming Quest has a method to mark it as completed
		(*it)->markAsCompleted(); // Assuming markAsCompleted is a method in Quest class
		// Optionally, grant rewards or update player state
	}
	else {
		// Handle quest not found case, e.g., notify player
	}
};
void player::useItem(const Item& item) {
	// Logic to use an item, e.g., healing potion, equipment, etc.
	// This could involve modifying health, applying buffs, etc.
}
void player::addItemToInventory(const Item& item) {
	if (m_inventory.size() < m_inventorySize) {
		m_inventory.push_back(item);
	}
	else {
		// Handle inventory full case, e.g., notify player or drop item
	}
}
void player::removeItemFromInventory(const Item& item) {
	auto it = std::find(m_inventory.begin(), m_inventory.end(), item);
	if (it != m_inventory.end()) {
		m_inventory.erase(it);
	}
	else {
		// Handle item not found case, e.g., notify player
	}
}
void player::levelUp() {
	m_level++;
	m_experiencePoints = 0; // Reset experience points or handle accordingly
	// Logic to increase player attributes, unlock skills, etc.
}
int player::getInventorySize() const {
	return m_inventorySize;
}
std::vector<Item> player::getInventory() const {
	return m_inventory;
}
int player::getScore() const {
	return m_score;
}
void player::setScore(int newScore) {
	m_score = newScore;
}
int player::getLevel() const {
	return m_level;
}
void player::setLevel(int newLevel) {
	m_level = newLevel;
}
int player::getExperiencePoints() const {
	return m_experiencePoints;
}
void player::setExperiencePoints(int newExperiencePoints) {
	m_experiencePoints = newExperiencePoints;
}
int player::getHealthPotions() const {
	return m_healthPotions;
}

void player::setHealthPotions(int newHealthPotions) {
	m_healthPotions = newHealthPotions;
}
int player::getManaPotions() const {
	return m_manaPotions;
}
void player::setManaPotions(int newManaPotions) {
	m_manaPotions = newManaPotions;
}

int player::getGold() const {
	return m_gold;
}
void player::setGold(int newGold) {
	m_gold = newGold;
}

std::string player::getPlayerName() const {
	return m_playerName;
}


void player::setPlayerName(const std::string& newName) {
	m_playerName = newName;
}
std::string player::getPlayerClass() const {
	return m_playerClass;
}