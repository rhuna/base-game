

#include <iostream> // For std::cout
#include "./headers/player.h" // For player class
#include "./headers/MainQuest.h" // For MainQuest class

#include "Engine/headers/GameEngine.h"



int main() {
	//we need to pass in and return the window from initialize to start to render
	//we may return a vector or array of configs that will allow for multiple returns
	// Create a window object
	Window window; // Create a window object
	// Set window properties
	window.setTitle("Game Window"); // Set window title
	window.setSize(800, 600); // Set window size
	window.setPosition(100, 100); // Set window position
	window.setFullscreen(false); // Set fullscreen mode
	window.setResizable(true); // Set resizable mode
	window.setVSync(true); // Set VSync	
	window.setBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color
	window.setMouseCursorVisible(true); // Show mouse cursor
	window.setMouseCursorPosition(400, 300); // Set mouse cursor position
	window.setMouseCursorGrabbed(false); // Don't grab mouse cursor

	// Create an instance of GameEngine
	GameEngine engine(800, 600, 60.0f); // Set resolution and frame rate
	engine.initialize(); // Initialize the engine
	engine.start(); // Start the engine
	engine.render();
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