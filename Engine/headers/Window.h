#ifndef WINDOW_H  
#define WINDOW_H  

#if defined(_WIN64)  
#include <SFML/Graphics.hpp>  // Adjusted to use the default include path for Windows 64-bit
	#include <../../../SFML/x64/include/SFML/Graphics.hpp>  
#elif defined(__APPLE__) || defined(__MACH__)  
   #include <SFML/Graphics.hpp> // Adjusted to use the default include path for macOS  
#elif defined(__linux__)  
   #include <../../../SFML/x86_64-unknown-linux-gnu/include/SFML/Graphics.hpp>  
#elif defined(_WIN32)  
	#include <../../../SFML/x86/include/SFML/Graphics.hpp>
#else
	#error "Unsupported platform. Please adjust the include paths for your system."
#endif  


#include <iostream>  
class Window {  
public:  
   Window();  
   Window(int width, int height, std::string title, sf::RenderWindow& window);  
   ~Window();  
   sf::RenderWindow& createWindow(int width, int height, std::string title, sf::RenderWindow& window);  
   void setTitle(std::string title);  
   void setSize(int width, int height);  
   void setPosition(int x, int y);  
   void setFullscreen(bool fullscreen);  
   void setResizable(bool resizable);  
   void setVSync(bool vsync);  
   void setIcon(const char* iconPath);  
   void setBackgroundColor(float r, float g, float b, float a);  
   void setMouseCursorVisible(bool visible);  
   void setMouseCursorPosition(int x, int y);  
   void setMouseCursorGrabbed(bool grabbed);  
   void setMouseCursorScale(float scale);  
   void setMouseCursorHidden(bool hidden);  

private:  
   int m_width;  
   int m_height;  
   sf::RenderWindow& m_window;  
   std::string m_title;  
   bool m_fullscreen;  
   bool m_resizable;  
   bool m_vsync;  
   float m_backgroundColor[4];  
   bool m_mouseCursorVisible;  
   int m_mouseCursorPosition[2];  
   bool m_mouseCursorGrabbed;  
   float m_mouseCursorScale;  
   bool m_mouseCursorHidden;  
   // Add any other necessary private members or methods here  
};  

#endif // !WINDOW_H
