

#include <iostream> // For std::cout
#include "./headers/player.h" // For player class
#include "./headers/MainQuest.h" // For MainQuest class
#include <conio.h> // For _kbhit() and _getch()
#include "Engine/headers/GameEngine.h"

void run(player& p1) {
	while (true) {
		if (_kbhit()) { // Check if a key is pressed
			char key = _getch();

			switch (key) {
			case 'w': p1.move(0, -1);  break; // Up
			case 's': p1.move(0, 1);   break; // Down
			case 'a': p1.move(-1, 0);  break; // Left
			case 'd': p1.move(1, 0);   break; // Right
			}

			// Print new position
			std::cout << "Position: (" << p1.getX() << ", " << p1.getY() << ")\n";
		}
	}
}

int main() {

	GameEngine gameEngine; // Create an instance of GameEngine
	gameEngine.initialize(); // Initialize the game engine
	gameEngine.start(); // Start the game engine
	// Check if the game engine is initialized
	if (!gameEngine.isInitialized()) {
		std::cerr << "GameEngine initialization failed." << std::endl;
		return 1; // Exit if initialization fails
	}
	// Print the frame rate and resolution
	std::cout << "GameEngine Frame Rate: " << gameEngine.getFrameRate() << " FPS" << std::endl;
	std::cout << "GameEngine Resolution: " << gameEngine.getWidth() << "x" << gameEngine.getHeight() << std::endl;

	
	//example of using the player class with quest class and equipment class
	player p1(1, 5,5, 100, 50, 100, 5);
	p1.setPosition(10, 20);
	p1.setPlayerName("Hero");
	p1.takeDamage(20);
	std::cout << "Player ID: " << p1.getId() << std::endl;
	std::cout << "Player Name: " << p1.getPlayerName() << std::endl;
	std::cout << "Player Health: " << p1.getHealth() << std::endl;
	std::cout << "Player Position: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
	std::cout << "Player Alive: " << (p1.isAlive() ? "Yes" : "No") << std::endl;
	// Example of using the player class with quest class and equipment class
	player p2(2, 6,6, 100, 50, 100, 3);
	p2.setPlayerName("god like being");
	p2.setPosition(15, 25);
	p2.takeDamage(30);
	std::cout << "Player ID: " << p2.getId() << std::endl;
	std::cout << "Player Name: " << p2.getPlayerName() << std::endl;
	std::cout << "Player Health: " << p2.getHealth() << std::endl;
	std::cout << "Player Position: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;

	MainQuest quest1(1, "Find the treasure", "Locate the hidden treasure in the forest.", true);
	MainQuest quest2(2, "Find the treasure", "Locate the hidden treasure in the forest.", true);
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


	run(p1); // Start the game loop with player p1


		


	return 0;
}