

#include <iostream> // For std::cout
#include "./headers/player.h" // For player class
#include "./headers/MainQuest.h" // For MainQuest class

#include "Engine/headers/GameEngine.h"



int main() {


	// Create an instance of GameEngine
	GameEngine engine(800, 600, 60.0f); // Set resolution and frame rate
	engine.initialize(); // Initialize the engine
	engine.start(); // Start the engine
	// Create a player object
	player p1(1, 0, 0, 50, 50, 100, 10); // Example player object
	// Create a quest object
	MainQuest quest(1, "Main Quest", "This is the main quest.", true); // Example quest object
	// Add the quest to the player
	p1.addQuest(std::make_unique<MainQuest>(quest)); // Add quest to player
	// Start the quest
	quest.start(); // Start the quest
	// Complete the quest
	quest.complete(); // Complete the quest
	// Print quest details
	std::cout << "Quest Name: " << quest.getName() << std::endl;
	std::cout << "Quest Description: " << quest.getDescription() << std::endl;
	std::cout << "Quest Active: " << (quest.isActive() ? "Yes" : "No") << std::endl;
	// Print player details
	std::cout << "Player ID: " << p1.getId() << std::endl;
	std::cout << "Player Health: " << p1.getHealth() << std::endl;
	std::cout << "Player Damage: " << p1.getDamage() << std::endl;
	// Print quest details
	std::cout << "Quest Name: " << quest.getName() << std::endl;
	std::cout << "Quest Description: " << quest.getDescription() << std::endl;
	std::cout << "Quest Active: " << (quest.isActive() ? "Yes" : "No") << std::endl;



	return 0;
}