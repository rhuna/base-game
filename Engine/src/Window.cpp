#include "../headers/Window.h"




Window::Window() 
	: width(800), height(600), title("Default Window"), fullscreen(false), resizable(true), vsync(true),
	backgroundColor{ 0.0f, 0.0f, 0.0f, 1.0f }, mouseCursorVisible(true), mouseCursorPosition{ 0, 0 },
	mouseCursorGrabbed(false), mouseCursorScale(1.0f), mouseCursorHidden(false)
{
	// Default constructor
	// Initialize default values
	// You can also initialize other members here if needed
	// For example, create a window with default values
	createWindow(width, height, title.c_str());
	// Set default background color
	setBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
};
Window::Window(int width, int height, std::string title) 
	: width(width), height(height), title(title), fullscreen(false), resizable(true), vsync(true),
	backgroundColor{ 0.0f, 0.0f, 0.0f, 1.0f }, mouseCursorVisible(true), mouseCursorPosition{ 0, 0 },
	mouseCursorGrabbed(false), mouseCursorScale(1.0f), mouseCursorHidden(false)
{
	// Constructor with parameters
	// Initialize member variables with provided values
	// You can also initialize other members here if needed
	// For example, create a window with specified values
	createWindow(width, height, title.c_str());
	// Set default background color
	setBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background



};
Window::~Window() {
	// Destructor
	// Clean up resources if needed
	// For example, close the window
	closeWindow();
	// You can also release other resources here if needed
	// For example, delete any dynamically allocated memory or objects
	// Note: If you are using smart pointers, they will automatically clean up
	// when they go out of scope, so you may not need to do anything here.
};
void Window::createWindow(int width, int height, const char* title) {
	// Create a window with the specified width, height, and title
	
	// using GLFW:
	// glfwCreateWindow(width, height, title, NULL, NULL);
	// Note: This is just a placeholder. You need to implement the actual window creation logic.
	std::cout << "Creating window: " << title << " (" << width << "x" << height << ")" << std::endl;
	// Initialize window properties
	this->width = width;
	this->height = height;
	this->title = title;
	this->fullscreen = false;
	this->resizable = true;
	this->vsync = true;
	this->backgroundColor[0] = 0.0f;
	this->backgroundColor[1] = 0.0f;
	this->backgroundColor[2] = 0.0f;
	this->backgroundColor[3] = 1.0f; // Default to black background
	this->mouseCursorVisible = true;
	this->mouseCursorPosition[0] = 0;
	this->mouseCursorPosition[1] = 0;
	this->mouseCursorGrabbed = false;
	this->mouseCursorScale = 1.0f;
	this->mouseCursorHidden = false;

	//create window with SFML library
	//sf::RenderWindow window(sf::VideoMode(width, height), title);
	//window.setFramerateLimit(60); // Set frame rate limit
	//window.setVerticalSyncEnabled(true); // Enable VSync
	//window.setMouseCursorVisible(true); // Show mouse cursor
	//window.setMouseCursorGrabbed(false); // Don't grab mouse cursor
	//window.setMouseCursorScale(1.0f); // Set mouse cursor scale
	//window.setMouseCursorHidden(false); // Don't hide mouse cursor

};
//close SFML window
void Window::closeWindow() { // need sf::window object to close
	//close SFML window
	//window.close();
};
void Window::setTitle(std::string title) {
	title = title;
	// Set the window title using SFML library
	//window.setTitle(title);
};
void Window::setSize(int width, int height) {
	this->width = width;
	this->height = height;
	// Set the window size using SFML library
	//window.setSize(sf::Vector2u(width, height));
	// You can also set the size of the window using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowSize(window, width, height);
};
void Window::setPosition(int x, int y) {
	this->mouseCursorPosition[0] = x;
	this->mouseCursorPosition[1] = y;
	// Set the window position using SFML library
	//window.setPosition(sf::Vector2i(x, y));
	// You can also set the position of the window using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowPos(window, x, y);
};
void Window::setFullscreen(bool fullscreen) {
	this->fullscreen = fullscreen;
	// Set the window to fullscreen mode using SFML library
	//window.create(sf::VideoMode::getFullscreenModes()[0], title, sf::Style::Fullscreen);
	// You can also set the window to fullscreen mode using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowMonitor(window, monitor, x, y, width, height, refreshRate);
};
void Window::setResizable(bool resizable) {
	this->resizable = resizable;
	// Set the window to be resizable using SFML library
	//window.setResizable(resizable);
	// You can also set the window to be resizable using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowAttrib(window, GLFW_RESIZABLE, resizable ? GL_TRUE : GL_FALSE);
};
void Window::setVSync(bool vsync) {
	this->vsync = vsync;
	// Set VSync using SFML library
	//window.setVerticalSyncEnabled(vsync);
	// You can also set VSync using other graphics libraries
	// For example, using GLFW:
	// glfwSwapInterval(vsync ? 1 : 0);
};
void Window::setIcon(const char* iconPath) {
	// Set the window icon using SFML library
	//sf::Image icon;
	//if (icon.loadFromFile(iconPath)) {
	//	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//}
	// 
	//using GLFW:
	// GLFWimage image;
	// image.pixels = loadImage(iconPath);
	// image.width = width;
	// image.height = height;
	// glfwSetWindowIcon(window, 1, &image);
};
void Window::setBackgroundColor(float r, float g, float b, float a) {
	this->backgroundColor[0] = r;
	this->backgroundColor[1] = g;
	this->backgroundColor[2] = b;
	this->backgroundColor[3] = a;
	// Set the background color using SFML library
	//window.clear(sf::Color(r * 255, g * 255, b * 255, a * 255));
	// You can also set the background color using other graphics libraries
	// For example, using OpenGL:
	// glClearColor(r, g, b, a);
	// glClear(GL_COLOR_BUFFER_BIT);
};
void Window::setMouseCursorVisible(bool visible) {
	this->mouseCursorVisible = visible;
	// Set the mouse cursor visibility using SFML library
	//window.setMouseCursorVisible(visible);
	// You can also set the mouse cursor visibility using other graphics libraries
	// For example, using GLFW:
	// glfwSetInputMode(window, GLFW_CURSOR, visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
};
void Window::setMouseCursorPosition(int x, int y) {
	this->mouseCursorPosition[0] = x;
	this->mouseCursorPosition[1] = y;
	// Set the mouse cursor position using SFML library
	//window.setMouseCursorPosition(sf::Vector2i(x, y));
	// You can also set the mouse cursor position using other graphics libraries
	// For example, using GLFW:
	// glfwSetCursorPos(window, x, y);
};
void Window::setMouseCursorGrabbed(bool grabbed) {
	this->mouseCursorGrabbed = grabbed;
	// Set the mouse cursor grab state using SFML library
	//window.setMouseCursorGrabbed(grabbed);
	// You can also set the mouse cursor grab state using other graphics libraries
	// For example, using GLFW:
	// glfwSetInputMode(window, GLFW_CURSOR, grabbed ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
};
void Window::setMouseCursorScale(float scale) {
	this->mouseCursorScale = scale;
	// Set the mouse cursor scale using SFML library
	//window.setMouseCursorScale(scale);
	// You can also set the mouse cursor scale using other graphics libraries
	// For example, using GLFW:
	// glfwSetCursorScale(window, scale);
};
void Window::setMouseCursorHidden(bool hidden) {
	this->mouseCursorHidden = hidden;
	// Set the mouse cursor hidden state using SFML library
	//window.setMouseCursorHidden(hidden);
	// You can also set the mouse cursor hidden state using other graphics libraries
	// For example, using GLFW:
	// glfwSetInputMode(window, GLFW_CURSOR, hidden ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);
};
