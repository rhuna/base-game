

#include <iostream>
#include "./headers/player.h"
#include "./headers/MainQuest.h"


int main() {
	//example of using the player class with quest class and equipment class
	player p1(1, 5,5, 100, 50, 10, 5);
	p1.setPosition(10, 20);
	p1.setPlayerName("Hero");
	p1.takeDamage(20);
	std::cout << "Player ID: " << p1.getId() << std::endl;
	std::cout << "Player Name: " << p1.getPlayerName() << std::endl;
	std::cout << "Player Health: " << p1.getHealth() << std::endl;
	std::cout << "Player Position: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
	std::cout << "Player Alive: " << (p1.isAlive() ? "Yes" : "No") << std::endl;
	// Example of using the player class with quest class and equipment class
	player p2(2, 6,6, 80, 40, 8, 3);
	p2.setPosition(15, 25);
	p2.takeDamage(30);
	std::cout << "Player ID: " << p2.getId() << std::endl;
	std::cout << "Player Name: " << p2.getPlayerName() << std::endl;
	std::cout << "Player Health: " << p2.getHealth() << std::endl;
	std::cout << "Player Position: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;

	MainQuest quest1(1, "Find the treasure", "Locate the hidden treasure in the forest.", true);
	MainQuest quest2(1, "Find the treasure", "Locate the hidden treasure in the forest.", true);
	Equipment equipment1(0, "axe", "melee weapon", 15, 100, 5.7f, "melee", 17);
	Equipment equipment2(1, "shield", "blocking mechanism", 15, 100, 5.7f, "shield", 17);

		
	std::cout << "Player Alive: " << (p1.isAlive() ? "Yes" : "No") << std::endl;
	// Example of using the player class with quest class and equipment class
	p1.addQuest(std::make_unique<MainQuest>(quest1));
	p1.addEquipment(equipment1);
	std::cout << "Player Quests: " << p1.getQuests().size() << std::endl;
	std::cout << "Player Equipment: " << p1.getEquipment().size() << std::endl;
	// Example of using the player class with quest class and equipment class
	//p1.addQuest(quest2(2, "Defeat the dragon", "Slay the dragon terrorizing the village.", true));
	//p1.addEquipment(equipment2(2, "Shield", "A sturdy shield.", 5, 10));
	std::cout << "Player Quests: " << p1.getQuests().size() << std::endl;
	std::cout << "Player Equipment: " << p1.getEquipment().size() << std::endl;


		


		


	return 0;
}