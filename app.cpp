

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
	GameEngine engine(vm,vw); // Set resolution and frame rate
	engine.run();	




	return 0;
}