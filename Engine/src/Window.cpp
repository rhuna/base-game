#include "../headers/Window.h"




Window::Window() 
	: m_width(800), m_height(600), m_title("Default Window"), m_fullscreen(false), m_resizable(true), m_vsync(true),
	m_backgroundColor{ 0.0f, 0.0f, 0.0f, 1.0f }, m_mouseCursorVisible(true), m_mouseCursorPosition{ 0, 0 },
	m_mouseCursorGrabbed(false), m_mouseCursorScale(1.0f), m_mouseCursorHidden(false), m_window(m_window)
{
	// Default constructor
	// Initialize default values
	// You can also initialize other members here if needed
	// For example, create a window with default values
	createWindow(m_width, m_height, m_title, m_window);
	// Set default background color
	setBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
};
Window::Window(int width, int height, std::string title, sf::RenderWindow& window) 
	: m_width(width), m_height(height), m_title(title), m_fullscreen(false), m_resizable(true), m_vsync(true),
	m_backgroundColor{ 0.0f, 0.0f, 0.0f, 1.0f }, m_mouseCursorVisible(true), m_mouseCursorPosition{ 0, 0 },
	m_mouseCursorGrabbed(false), m_mouseCursorScale(1.0f), m_mouseCursorHidden(false), m_window(window)
{
	// Constructor with parameters
	// Initialize member variables with provided values
	// You can also initialize other members here if needed
	// For example, create a window with specified values
	createWindow(width, height, title.c_str(), m_window);
	// Set default background color
	setBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background



};
Window::~Window() {
	// Destructor
	m_window.close(); // Close the window if it's open

};
sf::RenderWindow& Window::createWindow(int width, int height, std::string title, sf::RenderWindow& window) {
	// Create a window with the specified width, height, and title
	
	// using GLFW:
	// glfwCreateWindow(width, height, title, NULL, NULL);

	std::cout << "Creating window: " << title << " (" << width << "x" << height << ")" << std::endl;
	// Initialize window properties
	this->m_width = width;
	this->m_height = height;
	this->m_title = title;
	this->m_fullscreen = false;
	this->m_resizable = true;
	this->m_vsync = true;
	this->m_backgroundColor[0] = 0.0f;
	this->m_backgroundColor[1] = 0.0f;
	this->m_backgroundColor[2] = 0.0f;
	this->m_backgroundColor[3] = 1.0f; // Default to black background
	this->m_mouseCursorVisible = true;
	this->m_mouseCursorPosition[0] = 0;
	this->m_mouseCursorPosition[1] = 0;
	this->m_mouseCursorGrabbed = false;
	this->m_mouseCursorScale = 1.0f;
	this->m_mouseCursorHidden = false;

	//create window with SFML library
	m_window.clear();
	m_window.create(sf::VideoMode({ 800, 600 }), title, sf::Style::Default);
	m_window.setFramerateLimit(60); // Set frame rate limit
	m_window.setVerticalSyncEnabled(true); // Enable VSync
	m_window.setMouseCursorVisible(true); // Show mouse cursor
	m_window.setMouseCursorGrabbed(false); // Don't grab mouse cursor
	
	return m_window;
};

void Window::setTitle(std::string title) {
	title = title;
	// Set the window title using SFML library
	//window.setTitle(title);
};
void Window::setSize(int width, int height) {
	this->m_width = width;
	this->m_height = height;
	// Set the window size using SFML library
	//window.setSize(sf::Vector2u(width, height));
	// You can also set the size of the window using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowSize(window, width, height);
};
void Window::setPosition(int x, int y) {
	this->m_mouseCursorPosition[0] = x;
	this->m_mouseCursorPosition[1] = y;
	// Set the window position using SFML library
	//window.setPosition(sf::Vector2i(x, y));
	// You can also set the position of the window using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowPos(window, x, y);
};
void Window::setFullscreen(bool fullscreen) {
	this->m_fullscreen = fullscreen;
	// Set the window to fullscreen mode using SFML library
	//window.create(sf::VideoMode::getFullscreenModes()[0], title, sf::Style::Fullscreen);
	// You can also set the window to fullscreen mode using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowMonitor(window, monitor, x, y, width, height, refreshRate);
};
void Window::setResizable(bool resizable) {
	this->m_resizable = resizable;
	// Set the window to be resizable using SFML library
	//window.setResizable(resizable);
	// You can also set the window to be resizable using other graphics libraries
	// For example, using GLFW:
	// glfwSetWindowAttrib(window, GLFW_RESIZABLE, resizable ? GL_TRUE : GL_FALSE);
};
void Window::setVSync(bool vsync) {
	this->m_vsync = vsync;
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
	this->m_backgroundColor[0] = r;
	this->m_backgroundColor[1] = g;
	this->m_backgroundColor[2] = b;
	this->m_backgroundColor[3] = a;
	// Set the background color using SFML library
	//window.clear(sf::Color(r * 255, g * 255, b * 255, a * 255));
	// You can also set the background color using other graphics libraries
	// For example, using OpenGL:
	// glClearColor(r, g, b, a);
	// glClear(GL_COLOR_BUFFER_BIT);
};
void Window::setMouseCursorVisible(bool visible) {
	this->m_mouseCursorVisible = visible;
	// Set the mouse cursor visibility using SFML library
	//window.setMouseCursorVisible(visible);
	// You can also set the mouse cursor visibility using other graphics libraries
	// For example, using GLFW:
	// glfwSetInputMode(window, GLFW_CURSOR, visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
};
void Window::setMouseCursorPosition(int x, int y) {
	this->m_mouseCursorPosition[0] = x;
	this->m_mouseCursorPosition[1] = y;
	// Set the mouse cursor position using SFML library
	//window.setMouseCursorPosition(sf::Vector2i(x, y));
	// You can also set the mouse cursor position using other graphics libraries
	// For example, using GLFW:
	// glfwSetCursorPos(window, x, y);
};
void Window::setMouseCursorGrabbed(bool grabbed) {
	this->m_mouseCursorGrabbed = grabbed;
	// Set the mouse cursor grab state using SFML library
	//window.setMouseCursorGrabbed(grabbed);
	// You can also set the mouse cursor grab state using other graphics libraries
	// For example, using GLFW:
	// glfwSetInputMode(window, GLFW_CURSOR, grabbed ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
};
void Window::setMouseCursorScale(float scale) {
	this->m_mouseCursorScale = scale;
	// Set the mouse cursor scale using SFML library
	//window.setMouseCursorScale(scale);
	// You can also set the mouse cursor scale using other graphics libraries
	// For example, using GLFW:
	// glfwSetCursorScale(window, scale);
};
void Window::setMouseCursorHidden(bool hidden) {
	this->m_mouseCursorHidden = hidden;
	// Set the mouse cursor hidden state using SFML library
	//window.setMouseCursorHidden(hidden);
	// You can also set the mouse cursor hidden state using other graphics libraries
	// For example, using GLFW:
	// glfwSetInputMode(window, GLFW_CURSOR, hidden ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);
};
