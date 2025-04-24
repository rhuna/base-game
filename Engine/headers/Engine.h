#ifndef ENGINE_H
#define ENGINE_H
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


class Engine{
public:
	Engine() :m_frameRate(60), m_width(800), m_height(600) {};
	virtual ~Engine() = default;
	// Method to initialize the engine
	virtual void initialize() = 0;
	// Method to start the engine
	virtual void start() = 0;
	// Method to stop the engine
	virtual void stop() = 0;
	// Method to update the engine state
	virtual void update(float deltaTime) = 0;
	// Method to render the engine state
	virtual void render() = 0;
	// Method to handle input events
	virtual void handleInput() = 0;
	// Method to clean up resources
	virtual void cleanup() = 0;
	// Method to run the main loop of the engine
	virtual void run() = 0;
	// Method to get the current frame rate
	virtual float getFrameRate() const = 0;
	// Method to set the frame rate
	virtual void setFrameRate(float frameRate) = 0;
	// Method to get the current resolution
	virtual void getResolution(int& width, int& height) const = 0;
	// Method to set the resolution
	virtual void setResolution(int width, int height) = 0;
private:
	// Private members can be added here if needed
	// For example, you might want to store the current frame rate, resolution, etc.
	float m_frameRate;
	int m_width;
	int m_height;

};

#endif // !ENGINE_H



