#ifndef PLAYER_H
#define PLAYER_H

#if defined(_WIN64)  
	#include <SFML/Graphics.hpp>  // Adjusted to use the default include path for Windows 64-bit
	#include <../../../SFML/x64/include/SFML/Graphics.hpp>  
#elif defined(__APPLE__) || defined(__MACH__)  
	#include <SFML/Graphics.hpp> // Adjusted to use the default include path for macOS  
#elif defined(__linux__)  
	#include <../../../SFML/x86_64-unknown-linux-gnu/include/SFML/Graphics.hpp>  
#elif defined(_WIN32)  
	#include <../../../SFML/x86/include/SFML/Graphics.hpp>
#else
	#error "Unsupported platform. Please adjust the include paths for your system."
#endif




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
	player(int id, int x, int y, int width, int height, int health, int damage, sf::Sprite sprite);
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
	void setActive(bool active);
	bool isActive() const;
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
	void setPlayerClass(const std::string& newClass);
	void addSkill(std::unique_ptr<Skill> skill);
	std::vector<std::unique_ptr<Skill>>& getSkills();
	void removeSkill(std::unique_ptr<Skill>& skill);
	void addAchievement(const Achievement& achievement);
	void removeAchievement(const Achievement& achievement);
	std::vector<Achievement> getAchievements() const;
	void addBuff(const Buff& buff);
	void removeBuff(const Buff& buff);
	std::vector<Buff> getBuffs() const;
	void addDebuff(const Debuff& debuff);
	void removeDebuff(const Debuff& debuff);
	std::vector<Debuff> getDebuffs() const;
	sf::Sprite& getSprite() const;
	void handleInput();

private:

	//player sprite and texture setup
	sf::Sprite& m_sprite;


	// Player-specific attributes can be added here
	// For example, inventory, score, etc.
	int m_inventorySize;
	std::vector<Item> m_inventory; // Assuming Item is a class representing items in the game
	int m_score;
	bool m_active; // Assuming this is a flag to indicate if the player is active or not
	// Additional player attributes can be added here
	int m_level;
	int m_experiencePoints;
	int m_healthPotions;
	int m_manaPotions;
	int m_gold;
	std::string m_playerName;
	std::string m_playerClass; // e.g., Warrior, Mage, Archer
	std::vector<std::unique_ptr<Skill>> m_skills; // Assuming Skill is a class representing skills or abilities
	std::vector<std::unique_ptr<Quest>> m_quests; // Assuming Quest is a class representing quests or missions
	std::vector<Achievement> m_achievements; // Assuming Achievement is a class representing achievements
	std::vector<Buff> m_buffs; // Assuming Buff is a class representing temporary effects or enhancements
	std::vector<Debuff> m_debuffs; // Assuming Debuff is a class representing negative effects or impairments
	std::vector<Equipment> m_equipment; // Assuming Equipment is a class representing equipped items
};


#endif // !PLAYER_H



