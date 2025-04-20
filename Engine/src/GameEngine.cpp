#include "../headers/GameEngine.h"
#include <iostream>
#include <stdexcept> // For std::runtime_error
#include <memory> // For std::unique_ptr
#include <ctime> // For std::time
#include <iomanip> // For std::put_time
#include "../../headers/player.h"

GameEngine::GameEngine() 
	: Engine(), m_window(m_window), m_frameRate(60.0f), m_width(800), m_height(600),
	m_initialized(false)
{
	// Default constructor implementation
	std::cout << "GameEngine created with default settings." << std::endl;
	m_initialized = false; // Set the initialized flag to false
	sf::VideoMode vm({ static_cast<unsigned int>(m_width), static_cast<unsigned int>(m_height) });
	Window win(vm, m_window); // Create a Window object with the provided window
	//m_window = sf::RenderWindow(vm, "GameEngine Window");
	// Set default background color
	//m_window.clear(sf::Color(0, 0, 0)); // Black background



}
GameEngine::GameEngine(sf::RenderWindow& window) : Engine(), m_window(window), // Initialize the window member variable
	m_frameRate(60.0f), m_width(800), m_height(600), m_initialized(false)
{
	m_initialized = false; // Set the initialized flag to false
	sf::VideoMode vm({ static_cast<unsigned int>(m_width), static_cast<unsigned int>(m_height) });
	Window win(vm,m_window); // Create a Window object with the provided window

	//m_window = sf::RenderWindow(vm, "GameEngine Window");
	// Set default background color
	//m_window.clear(sf::Color(0, 0, 0)); // Black background

}

GameEngine::GameEngine(int width, int height, float frameRate)
	: Engine(), m_width(width), m_height(height), m_frameRate(frameRate), m_initialized(false),
	m_window(m_window)
{
	
	m_initialized = false; // Set the initialized flag to false
	sf::VideoMode vm({ static_cast<unsigned int>(m_width), static_cast<unsigned int>(m_height) });
	Window win(vm, m_window); // Create a Window object with the provided window
	//m_window = sf::RenderWindow(vm, "GameEngine Window");
	// Set default background color
	//m_window.clear(sf::Color(0, 0, 0)); // Black background
	




}

GameEngine::~GameEngine() = default;

void GameEngine::initialize() {

	// Additional initialization logic if needed
	m_initialized = true; // Set the initialized flag to true
	if (!m_initialized) {
		throw std::runtime_error("GameEngine initialization failed.");
	}else {
		std::cout << "GameEngine initialized successfully." << std::endl;
	}

	m_gameState = GameState::RUNNING;
	m_time = 0.0f; // Initialize time
	m_deltaTime = 0.0f; // Initialize delta time
	m_frameTime = 0.0f; // Initialize frame time
	m_frameCount = 0; // Initialize frame count
	m_fps = 0.0f; // Initialize FPS
	m_lastFrameTime = 0.0f; // Initialize last frame time
	m_currentFrameTime = 0.0f; // Initialize current frame time
}
void GameEngine::start(){
	
	// Start the engine
	std::cout << "GameEngine started." << std::endl;
	// Additional start logic if needed
	std::time_t t = std::time(nullptr); // Get the current time
	std::tm tm;
	m_time = static_cast<float>(std::difftime(t, 0)); // Calculate time since epoch
    if (localtime_s(&tm, &t) != 0) {
		
        std::cerr << "Failed to convert time to local time." << std::endl;
        return;
    }
	std::cout << "engine time: " << m_time;
	std::cout << "Current time: " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << std::endl; // Print the current time
	// Example of using the player class with quest class and equipment class
	
}
void GameEngine::stop(){
	// Stop the engine
	std::cout << "GameEngine stopped." << std::endl;
	// Additional stop logic if needed
	// Example of using the player class with quest class and equipment class
	
}

///// ////	////	////	//////	////	///	/	/	/	//////	/////	/////	///


/// <summary>
/// 
/// </summary>
/// <param name="vm"></param>
/// <param name="window"></param>

void GameEngine::run(sf::VideoMode vm, sf::RenderWindow window)  {
	//open window
	

	// Main loop of the engine
	while (window.isOpen()) {
	
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::KeyPressed>()) {
				if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
					std::cout << "Escape key pressed. Closing window." << std::endl;
					window.close();
				};
			}
		}

		while (m_gameState == GameState::RUNNING) {
			m_currentFrameTime = static_cast<float>(clock()) / CLOCKS_PER_SEC; // Get the current time
			m_deltaTime = m_currentFrameTime - m_lastFrameTime; // Calculate delta time
			m_lastFrameTime = m_currentFrameTime; // Update last frame time
			update(m_deltaTime); // Update the game state
			render(); // Render the game state
			handleInput(); // Handle user input
			cleanup(); // Clean up resources
		}

		window.clear();
		window.display();
	}
	

}

void GameEngine::update(float deltaTime) {
	// Update game state
	// Example delta time (60 FPS)
	m_time += deltaTime; // Update time
	m_deltaTime = deltaTime; // Update delta time
	m_frameTime = deltaTime; // Update frame time
	m_frameCount++; // Increment frame count
	if (m_frameCount >= m_frameRate) { // If frame count reaches frame rate
		m_fps = 1.0f / deltaTime; // Calculate FPS
		m_frameCount = 0; // Reset frame count
	}
	// Example update logic
	// Update game objects, physics, etc.
	// For example, update player position, check collisions, etc.


	std::cout << "Updating game state with deltaTime: " << m_time << " seconds." << std::endl;
}
void GameEngine::render() {
	// Render game graphics
	std::cout << "Rendering game graphics..." << std::endl;



}
void GameEngine::handleInput() {
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
void GameEngine::cleanup() {
	// Clean up resources
	std::cout << "Cleaning up GameEngine resources..." << std::endl;


}






/// <summary>////	////	////	/////	/////	//	//	///	////	////	//















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
