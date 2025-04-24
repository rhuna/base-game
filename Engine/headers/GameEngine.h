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

class GameEngine : public Engine {
public:
	GameEngine(sf::RenderWindow& window);
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

	
private:
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
	enum class GameState {
		INITIALIZING,
		RUNNING,
		PAUSED,
		STOPPED
	};
	GameState m_gameState = GameState::INITIALIZING; // Current game state

};



#endif // !GAMEENGINE_H



