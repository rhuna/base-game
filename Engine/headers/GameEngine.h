#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Engine.h"
#include <ctime>

class GameEngine : public Engine {
public:
	GameEngine();
	GameEngine(int width, int height, float frameRate);
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
	//game loop
	void gameLoop() {
		while (m_gameState == GameState::RUNNING) {
			m_currentFrameTime = static_cast<float>(clock()) / CLOCKS_PER_SEC; // Get the current time
			m_deltaTime = m_currentFrameTime - m_lastFrameTime; // Calculate delta time
			m_lastFrameTime = m_currentFrameTime; // Update last frame time
			update(m_deltaTime); // Update the game state
			render(); // Render the game state
			m_frameCount++; // Increment frame count
			if (m_frameCount >= m_frameRate) { // If frame count reaches frame rate
				m_fps = 1.0f / m_deltaTime; // Calculate FPS
				m_frameCount = 0; // Reset frame count
			}
		}
	}
private:
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



