#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#if defined(_WIN64)  
	#include <SFML/Graphics.hpp>  // Adjusted to use the default include path for Windows 64-bit
	//#include <../../../SFML/x64/include/SFML/Graphics.hpp>  
#elif defined(__APPLE__) || defined(__MACH__)  
	#include <SFML/Graphics.hpp> // Adjusted to use the default include path for macOS  
#elif defined(__linux__)  
	#include <../../../SFML/x86_64-unknown-linux-gnu/include/SFML/Graphics.hpp>  
#elif defined(_WIN32) 
	#include <SFML/Graphics.hpp>
	//#include <../../../SFML/x86/include/SFML/Graphics.hpp>
#else
	#error "Unsupported platform. Please adjust the include paths for your system."
#endif


#include "Engine.h"
#include <ctime>
#include <iostream>
#include <stdexcept> // For std::runtime_error
#include <memory> // For std::unique_ptr
#include <iomanip> // For std::put_time
#include "../../headers/player.h"
#include "../headers/MapGenerator.h"
#include "../../headers/Enemy.h"
#include "../../client/client.h"







struct GameState
{
   int ID; // Unique identifier for the game state
   enum class State; // Current state of the game
   sf::Clock clock; // Clock for measuring time
   float time; // Time since the game started
   float deltaTime; // Time between frames
   float frameTime; // Time taken to render a frame
   float fps; // Frames per second
   float lastFrameTime; // Time of the last frame
   float currentFrameTime; // Time of the current frame
   bool initialized; // Flag to check if the game state is initialized
   int width; // Width of the game window
   int height; // Height of the game window
   float frameRate; // Frame rate of the game
   sf::RenderWindow& window; // Changed from reference to value
   player player; // Player object
   std::vector<Enemy> enemies; // Changed to unique_ptr without reference
   std::vector<MapGenerator> maps; // Changed to unique_ptr without reference
   std::vector<Item> lootableItems; // Changed to value type
   std::vector<sf::Sprite> obstacles; // Vector of obstacle sprites
   std::vector<sf::Sprite> walls; // Vector of wall sprites

};   





class GameEngine : public Engine {
public:
	enum class State {
		INITIALIZING,
		RUNNING,
		PAUSED,
		STOPPED
	};

	client m_gameClient;

	GameEngine(sf::VideoMode& vm, sf::RenderWindow& window);
	virtual ~GameEngine();
	void initialize() override;
	void start() override;
	void stop() override;
	void update(float deltaTime) override;
	void render() override;
	void handleInput() override;
	void cleanup() override;
	void run() override;
	float getFrameRate() const override;
	void setFrameRate(float frameRate) override;
	void getResolution(int& width, int& height) const override;
	void setResolution(int width, int height) override;
	bool isInitialized() const;
	int getHeight() const;
	int getWidth() const;
	sf::RenderWindow& getWindow();
	bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
	

	
private:

	 // Game state object
	std::vector<sf::Sprite> m_obstacles; // Vector of obstacle sprites
	std::vector<sf::Sprite> m_walls; // Vector of wall sprites
	std::vector<MapGenerator> m_maps; // Changed to unique_ptr without reference
	std::vector<Item> m_lootableItems;
	std::vector<Enemy> m_enemies; // Pointer to the enemy object
	sf::VideoMode m_vm; // Video mode object
	int m_ID; // Unique identifier for the game engine instance
	sf::RenderWindow& m_window; // Window object
	float m_frameRate = 60.0f; // Default frame rate
	int m_width = 800; // Default width
	int m_height = 600; // Default height
	bool m_initialized = false; // Flag to check if the engine is initialize
	//time
	float m_time = 0.0f; // Time since the engine started
	//delta time
	float m_deltaTime = 0.0f; // Time between frames
	//frame time
	float m_frameTime = 0.0f; // Time taken to render a frame
	//frame count
	int m_frameCount = 0; // Number of frames rendered
	//fps
	float m_fps = 0.0f; // Frames per second
	//last frame time
	float m_lastFrameTime = 0.0f; // Time of the last frame
	//current frame time
	float m_currentFrameTime = 0.0f; // Time of the current frame
	//game state
	
	

	State m_State = State::INITIALIZING; // Current game state

	sf::Clock m_clock; // Clock for measuring time
	

};



#endif // !GAMEENGINE_H



