#ifndef ENTITY_H
#define ENTITY_H

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



class entity {
public:
	entity(int id, float x, float y, int width, int height, int health, int damage);
	int getId() const;
	float getX() const;
	float getY() const;
	int getWidth() const;
	int getHeight() const;
	int getHealth() const;
	int getDamage() const;
	bool isAlive() const;
	void setPosition(int newX, int newY);
	void takeDamage(int amount);
	float getPreviousX() const { return m_previousX; }
	float getPreviousY() const { return m_previousY; }
	sf::Vector2f getPosition();


private:

	sf::Vector2f m_position;

	float m_previousX;
	float m_previousY;
	int id;
	float m_x, m_y;
	int width, height;
	int health;
	int damage;
	bool alive;


};


#endif // !ENTITY_H



