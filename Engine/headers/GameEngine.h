#pragma once
#include "Engine.h"
class GameEngine : public Engine{
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
private:
	float m_frameRate = 60.0f; // Default frame rate
	int m_width = 800; // Default width
	int m_height = 600; // Default height
	bool m_initialized = false; // Flag to check if the engine is initialized
};

