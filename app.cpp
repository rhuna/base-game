

#include <iostream> // For std::cout
#include "./headers/player.h" // For player class
#include "./headers/MainQuest.h" // For MainQuest class

#include "Engine/headers/GameEngine.h"



int main() {
	
	// Create a window object
	sf::VideoMode vm({ 800, 600 }); // Set the video mode with width and height
	sf::RenderWindow vw(vm, "Game Window"); // Create a window with specified width and height

	// Set the window properties
	vw.setFramerateLimit(60); // Set frame rate limit
	vw.setVerticalSyncEnabled(true); // Enable VSync
	vw.setMouseCursorVisible(true); // Show mouse cursor
	vw.setMouseCursorGrabbed(false); // Don't grab mouse cursor
		
	// Set the window background color
	vw.clear(sf::Color(0, 0, 0, 255)); // Set background color to black


	// Create a GameEngine object
	GameEngine engine(vw); // Set resolution and frame rate
	engine.initialize(); // Initialize the engine
	engine.start(); // Start the engine
	engine.render();
	engine.run();
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