#include "../headers/player.h"
#include "../Engine/headers/MapGenerator.h"
#include <conio.h> // For _kbhit() and _getch()


player::player(int id, float x, float y, int width, int height, int health, int damage, sf::Sprite sprite)
	: entity(id, x, y, width, height, health, damage), m_gold(0), m_inventorySize(10), m_score(0), m_level(1), m_experiencePoints(0),
	m_healthPotions(0), m_manaPotions(0), m_playerName("Default Player"), m_playerClass("Warrior"), m_active(true),
	m_quests(), m_equipment(), m_inventory(), m_skills(), m_achievements(), m_buffs(), m_debuffs(), m_sprite(sprite)
{

	m_sprite.setPosition({ x, y });
	setPosition(x, y);
	

}
void player::setSprite(sf::Sprite& sprite) {
	m_sprite = sprite;
};

sf::Sprite& player::getSprite() const {
	return m_sprite;
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
void player::setActive(bool active) {
	
	m_active = active; // Assuming m_active is a member variable of type bool
	//std::cout << "Player active status set to: " << (active ? "true" : "false") << std::endl;


};

void player::handleInput() {
	float moveSpeed = 5.0f; // Adjust speed as needed

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		move(0.0f, -moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		move(0.0f, moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		move(-moveSpeed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		move(moveSpeed, 0.0f);
	}

	// Update sprite position to match entity position
	m_sprite.setPosition({ static_cast<float>(getX()), static_cast<float>(getY()) });
	std::cout << "player health = " << this->getHealth() << "\n";
}
bool player::isActive() const {

	return m_active; // Assuming m_active is a member variable of type bool
	//std::cout << "Player active status: " << (m_active ? "true" : "false") << std::endl;
};
void player::addEquipment(const Equipment& equipment) {
	
	m_equipment.push_back(equipment);

};
std::vector<Equipment> player::getEquipment() {
	// Logic to retrieve and display player's equipment
	for (const auto& equip : m_equipment) {
		
		std::cout << "Equipment: " << equip.getName() << " - " << equip.getDescription() << std::endl;
	}
	
	return m_equipment; 
};
std::vector<std::unique_ptr<Quest>>& player::getQuests() {
	// Logic to retrieve and display player's quests
	for (const auto& quest : m_quests) {
		
		std::cout << "Quest: " << quest->getName() << " - " << quest->getDescription() << std::endl;
	}
	return m_quests; // Assuming you want to return the list of quests
}
void player::removeQuest(std::unique_ptr<Quest>& quest) {
	//remove quest
	auto it = std::find_if(m_quests.begin(), m_quests.end(),
		[&quest](const std::unique_ptr<Quest>& q) {
			return *q == *quest;
		});

	if (it != m_quests.end()) {
		m_quests.erase(it);
	}
	else {
		
	}
};

void player::completeQuest(std::unique_ptr<Quest> quest) {
	// Logic to complete a quest, e.g., grant rewards, update status, etc.
	auto it = std::find(m_quests.begin(), m_quests.end(), quest);
	if (it != m_quests.end()) {
		
		(*it)->markAsCompleted(); 
		// Optionally, grant rewards or update player state
	}
	else {
		// Handle quest not found case, e.g., notify player
	}
};
void player::useItem(const Item& item) {
	// Logic to use an item, e.g., healing potion, equipment, etc.
	
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



void player::setPlayerClass(const std::string& newClass) {
	m_playerClass = newClass;
};
void player::addSkill(std::unique_ptr<Skill> skill) {
	
	m_skills.push_back(std::move(skill));

};
std::vector<std::unique_ptr<Skill>>& player::getSkills() {
	// Logic to retrieve and display player's skills
	for (const auto& skill : m_skills) {
		// Assuming Skill has a method to get its name or description
		std::cout << "Skill: " << skill->getName() << " - " << skill->getDescription() << std::endl;
	}
	return m_skills; // Assuming you want to return the list of skills
};
void player::removeSkill(std::unique_ptr<Skill>& skill) {
	
	auto it = std::find_if(m_skills.begin(), m_skills.end(),
		[&skill](const std::unique_ptr<Skill>& s) {
			return *s == *skill;
		});
	if (it != m_skills.end()) {
		m_skills.erase(it);
	}
	else {
		// Handle skill not found case, e.g., notify player
	}
};
void player::addAchievement(const Achievement& achievement) {
	
	m_achievements.push_back(achievement);
	
};
void player::removeAchievement(const Achievement& achievement) {
	
	auto it = std::find(m_achievements.begin(), m_achievements.end(), achievement);
	if (it != m_achievements.end()) {
		m_achievements.erase(it);
	}
	else {
		// Handle achievement not found case, e.g., notify player
	}
};
std::vector<Achievement> player::getAchievements() const {
	// Logic to retrieve and display player's achievements
	for (const auto& achievement : m_achievements) {
		
		std::cout << "Achievement: " << achievement.getName() << " - " << achievement.getDescription() << std::endl;
	}
	return m_achievements; // Assuming you want to return the list of achievements
};
void player::addBuff(const Buff& buff) {
	
	m_buffs.push_back(buff);
	
};
void player::removeBuff(const Buff& buff) {
	
	auto it = std::find(m_buffs.begin(), m_buffs.end(), buff);
	if (it != m_buffs.end()) {
		m_buffs.erase(it);
	}
	else {
		// Handle buff not found case, e.g., notify player
	}
};
std::vector<Buff> player::getBuffs() const {
	// Logic to retrieve and display player's buffs
	for (const auto& buff : m_buffs) {
		// Assuming Buff has a method to get its name or description
		std::cout << "Buff: " << buff.getName() << " - " << buff.getDescription() << std::endl;
	}
	return m_buffs; // Assuming you want to return the list of buffs
};
void player::addDebuff(const Debuff& debuff) {

	m_debuffs.push_back(debuff);
}

void player::removeDebuff(const Debuff& debuff) {
	// Logic to remove a debuff from the player
	// This could involve checking if the player can undebuff it, updating stats, etc.
	auto it = std::find(m_debuffs.begin(), m_debuffs.end(), debuff);
	if (it != m_debuffs.end()) {
		m_debuffs.erase(it);
	}
	else {
		// Handle debuff not found case, e.g., notify player
	}
};
std::vector<Debuff> player::getDebuffs() const {
	// Logic to retrieve and display player's debuffs
	for (const auto& debuff : m_debuffs) {
		// Assuming Debuff has a method to get its name or description
		std::cout << "Debuff: " << debuff.getName() << " - " << debuff.getDescription() << std::endl;
	}
	return m_debuffs; // Assuming you want to return the list of debuffs
};