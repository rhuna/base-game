#include "client.h"
#include <iostream>

client::client()
	: m_initialized(false), m_time(0.0f), m_deltaTime(0.0f),
	m_frameTime(0.0f), m_frameRate(60.0f), m_frameCount(0),
	m_fps(0.0f), m_lastFrameTime(0.0f), m_currentFrameTime(0.0f),
	m_State(State::STOPPED) // Initialize the state to STOPPED
{

};
client::~client() {
	std::cout << "Client destroyed." << std::endl;
	m_State = State::STOPPED; // Set the state to STOPPED
	m_initialized = false; // Set the initialized flag to false
	m_time = 0.0f; // Reset time
	m_deltaTime = 0.0f; // Reset delta time
	m_frameTime = 0.0f; // Reset frame time
	m_frameCount = 0; // Reset frame count
	m_fps = 0.0f; // Reset FPS
	m_lastFrameTime = 0.0f; // Reset last frame time
	m_currentFrameTime = 0.0f; // Reset current frame time
};
void client::initialize() {
	
	// Initialize the client
	m_initialized = true; // Set the initialized flag to true
	if (!m_initialized) {
		throw std::runtime_error("Client initialization failed.");
	}
	else {
		std::cout << "Client initialized successfully." << std::endl;
	}
	m_State = State::INITIALIZING; // Set the state to RUNNING
	m_time = 0.0f; // Initialize time
	m_deltaTime = 0.0f; // Initialize delta time
	m_frameTime = 0.0f; // Initialize frame time
	m_frameCount = 0; // Initialize frame count
	m_fps = 0.0f; // Initialize FPS
	m_lastFrameTime = 0.0f; // Initialize last frame time
	m_currentFrameTime = 0.0f; // Initialize current frame time
};
void client::start() {
	// Start the client
	m_State = State::RUNNING; // Set the state to RUNNING
	std::cout << "Client started." << std::endl;
	std::time_t t = std::time(nullptr); // Get the current time
	m_time = static_cast<float>(t); // Set the time to the current time
	m_deltaTime = 0.0f; // Initialize delta time
	m_frameTime = 0.0f; // Initialize frame time
	m_frameCount = 0; // Initialize frame count
	m_fps = 0.0f; // Initialize FPS
	m_lastFrameTime = 0.0f; // Initialize last frame time
	m_currentFrameTime = 0.0f; // Initialize current frame time
};
void client::render() {
	// Render client graphics
	std::cout << "Rendering client graphics..." << std::endl;
	// Example rendering logic
	if (!m_initialized) {
		std::cerr << "Client is not initialized. Cannot render." << std::endl;
		return;
	}
	// Simulate rendering
	std::cout << "Client graphics rendered successfully." << std::endl;
};
void client::update() {
	// Update client state
	std::cout << "Updating client state..." << std::endl;
	// Example update logic
	if (!m_initialized) {
		std::cerr << "Client is not initialized. Cannot update." << std::endl;
		return;
	}
	m_time += m_deltaTime; // Update time
	m_deltaTime = 0.0f; // Reset delta time
	m_frameTime = 0.0f; // Reset frame time
	m_frameCount++; // Increment frame count
	if (m_frameCount >= m_frameRate) { // If frame count reaches frame rate
		m_fps = 1.0f / m_deltaTime; // Calculate FPS
		m_frameCount = 0; // Reset frame count
	}
	std::cout << "Client state updated successfully." << std::endl;
};
void client::run() {
	// Run the client
	std::cout << "Running client..." << std::endl;
	if (!m_initialized) {
		std::cerr << "Client is not initialized. Cannot run." << std::endl;
		return;
	}
	while (m_State == State::RUNNING) {
		m_currentFrameTime = static_cast<float>(std::clock()) / CLOCKS_PER_SEC; // Get the current time
		m_deltaTime = m_currentFrameTime - m_lastFrameTime; // Calculate delta time
		m_lastFrameTime = m_currentFrameTime; // Update last frame time
		update(); // Update the client state
		render(); // Render the client graphics
	}
	std::cout << "Client run completed." << std::endl;
};
void client::stop() {
	// Stop the client
	std::cout << "Stopping client..." << std::endl;
	m_State = State::STOPPED; // Set the state to STOPPED
	m_initialized = false; // Set the initialized flag to false
	std::cout << "Client stopped." << std::endl;
};