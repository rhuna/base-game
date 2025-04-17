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
	void addQuest(std::unique_ptr<Quest> quest);
	std::vector<std::unique_ptr<Quest>>& getQuests();
	void removeQuest(std::unique_ptr<Quest>& quest);
	void completeQuest(std::unique_ptr<Quest> quest);
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
	int m_inventorySize;
	std::vector<Item> m_inventory; // Assuming Item is a class representing items in the game
	int m_score;
	// Additional player attributes can be added here
	int m_level;
	int m_experiencePoints;
	int m_healthPotions;
	int m_manaPotions;
	int m_gold;
	std::string m_playerName;
	std::string m_playerClass; // e.g., Warrior, Mage, Archer
	std::vector<Skill> m_skills; // Assuming Skill is a class representing skills or abilities
	std::vector<std::unique_ptr<Quest>> m_quests; // Assuming Quest is a class representing quests or missions
	std::vector<Achievement> m_achievements; // Assuming Achievement is a class representing achievements
	std::vector<Buff> m_buffs; // Assuming Buff is a class representing temporary effects or enhancements
	std::vector<Debuff> m_debuffs; // Assuming Debuff is a class representing negative effects or impairments
	std::vector<Equipment> m_equipment; // Assuming Equipment is a class representing equipped items
};


#endif // !PLAYER_H



