#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "entity.h"
#include "Quest.h"
#include "Skill.h"
#include "Achievement.h"
#include "Buff.h"
#include "Debuff.h"
#include "Equipment.h"
#include <vector>


class player : public entity {
public:
	player(int id, int x, int y, int width, int height, int health, int damage);
	void attack(entity& target);
	void move(int deltaX, int deltaY);
	void useItem(const Item& item);
	void addQuest(const Quest& quest);
	std::vector<Quest> getQuests();
	void removeQuest(const Quest& quest);
	void completeQuest(const Quest& quest);
	void addItemToInventory(const Item& item);
	void removeItemFromInventory(const Item& item);
	void levelUp();
	int getInventorySize() const;
	std::vector<Item> getInventory() const;
	int getScore() const;
	void setScore(int newScore);
	int getLevel() const;
	void setLevel(int newLevel);
	void addEquipment(const Equipment& equipment);
	std::vector<Equipment> getEquipment();
	int getExperiencePoints() const;
	void setExperiencePoints(int newExperiencePoints);
	int getHealthPotions() const;
	void setHealthPotions(int newHealthPotions);
	int getManaPotions() const;
	void setManaPotions(int newManaPotions);
	int getGold() const;
	void setGold(int newGold);
	std::string getPlayerName() const;
	void setPlayerName(const std::string& newName);
	std::string getPlayerClass() const;


private:
	// Player-specific attributes can be added here
	// For example, inventory, score, etc.
	int inventorySize;
	std::vector<Item> inventory; // Assuming Item is a class representing items in the game
	int score;
	// Additional player attributes can be added here
	int level;
	int experiencePoints;
	int healthPotions;
	int manaPotions;
	int gold;
	std::string playerName;
	std::string playerClass; // e.g., Warrior, Mage, Archer
	std::vector<Skill> skills; // Assuming Skill is a class representing skills or abilities
	std::vector<Quest> quests; // Assuming Quest is a class representing quests or missions
	std::vector<Achievement> achievements; // Assuming Achievement is a class representing achievements
	std::vector<Buff> buffs; // Assuming Buff is a class representing temporary effects or enhancements
	std::vector<Debuff> debuffs; // Assuming Debuff is a class representing negative effects or impairments
	std::vector<Equipment> equipment; // Assuming Equipment is a class representing equipped items
};


#endif // !PLAYER_H



