#include "../headers/GameEngine.h"
#include <iostream>
#include <stdexcept> // For std::runtime_error
#include <memory> // For std::unique_ptr

GameEngine::GameEngine() {
	// Default constructor implementation
	std::cout << "GameEngine created with default settings." << std::endl;
	m_frameRate = 60.0f; // Default frame rate
	m_width = 800; // Default width
	m_height = 600; // Default height
	m_initialized = false; // Set the initialized flag to false

}

GameEngine::GameEngine(int width, int height, float frameRate)
	: Engine(), m_width(width), m_height(height), m_frameRate(frameRate), m_initialized(false) {
	// Constructor implementation
	std::cout << "GameEngine created with resolution: " << width << "x" << height
		<< " and frame rate: " << frameRate << " FPS." << std::endl;

}

GameEngine::~GameEngine() = default;

void GameEngine::initialize() {
	// Initialization code here
	m_frameRate = 60.0f; // Default frame rate
	m_width = 800; // Default width
	m_height = 600; // Default height
	// Additional initialization logic if needed
	m_initialized = true; // Set the initialized flag to true
	if (!m_initialized) {
		throw std::runtime_error("GameEngine initialization failed.");
	}
	// Additional initialization logic if needed
	if (m_initialized) {
		std::cout << "GameEngine initialized successfully." << std::endl;
	}
	else {
		std::cerr << "GameEngine initialization failed." << std::endl;
	}
}
void GameEngine::start(){
	// Start the engine
	std::cout << "GameEngine started." << std::endl;
	// Additional start logic if needed

	
}
void GameEngine::stop(){
	// Stop the engine
	std::cout << "GameEngine stopped." << std::endl;
}
void GameEngine::update(float deltaTime){
	// Update game state

	std::cout << "Updating game state with deltaTime: " << deltaTime << " seconds." << std::endl;
}
void GameEngine::render()  {
	// Render game graphics
	std::cout << "Rendering game graphics..." << std::endl;

	

}
void GameEngine::handleInput()  {
	// Handle user input
	std::cout << "Handling input..." << std::endl;
	// Example input handling logic
	if (!m_initialized) {
		std::cerr << "GameEngine is not initialized. Cannot handle input." << std::endl;
		return;
	}
	// Simulate input handling
	std::cout << "Input handled successfully." << std::endl;
}
void GameEngine::cleanup()  {
	// Clean up resources
	std::cout << "Cleaning up GameEngine resources..." << std::endl;

}
void GameEngine::run()  {
	// Main loop of the engine


}
float GameEngine::getFrameRate() const  {
	return m_frameRate;
}
void GameEngine::setFrameRate(float frameRate)  {
	m_frameRate = frameRate;
}
void GameEngine::getResolution(int& width, int& height) const  {
	width = m_width;
	height = m_height;
}
void GameEngine::setResolution(int width, int height) {
	m_width = width;
	m_height = height;
}

bool GameEngine::isInitialized() const {
	return m_initialized;
}

int GameEngine::getWidth() const {
	return m_width;
}

int GameEngine::getHeight() const {
	return m_height;
}
