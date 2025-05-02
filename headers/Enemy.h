#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>


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


#include "Item.h"
#include "entity.h"


class Enemy : public entity
{

public:
	Enemy(int id, int x, int y, int width, int height, int health, int damage, sf::Sprite sprite);
	void attack(entity& target);
	void move(int deltaX, int deltaY);
	void takeDamage(int damage);
	void setHealth(int damage);
	void die();
	void setAggroRange(int range);
	int getAggroRange() const;
	void setLoot(const Item& loot);
	Item getLoot() const;
	void setAIType(const std::string& aiType);
	std::string getAIType() const;
	sf::Sprite getSprite();
	void setTexture(const std::string& texturePath);
	void setPosition(int x, int y);	
	void setScale(float scaleX, float scaleY);
	void setOrigin(float x, float y);
	void setRotation(float angle);
	void setColor(const sf::Color& color);
	void setAlive();
	void setSprite(sf::Sprite& sprite);
	bool isAlive();
	void followTarget(entity& target);
	void setX(int x);
	void setY(int y);

private:

	int m_speed;
	int m_health;
	int m_damage;
	bool alive;
	int m_aggroRange;
	Item m_loot;
	std::string m_aiType;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	
};

#endif // ENEMY_H