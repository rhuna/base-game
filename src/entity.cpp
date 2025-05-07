//#pragma warning(disable: 4275)
#include "../headers/entity.h"




entity::entity(int id, float x, float y, int width, int height, int health, int damage)
	: id(id), x(x), y(y), width(width), height(height), health(health), damage(damage), alive(true),
	m_previousX(x), m_previousY(y) // Initialize previous position
{// Constructor implementation
	// Initialize other member variables if needed
	// For example, you can set default values for alive, m_previousX, m_previousY, etc.
	alive = true; // Set alive to true by default
	m_previousX = x; // Initialize previous X position
	m_previousY = y; // Initialize previous Y position
	//std::cout << "Entity created with ID: " << id << std::endl;
}
int entity::getId() const { return id; }
float entity::getX() const { return x; }
float entity::getY() const { return y; }
int entity::getWidth() const { return width; }
int entity::getHeight() const { return height; }
int entity::getHealth() const { return health; }
int entity::getDamage() const { return damage; }
bool entity::isAlive() const { return alive; }

void entity::takeDamage(int amount) {
	if (alive) {
		health -= amount;
		if (health <= 0) {
			alive = false;
		}
	}
}

void entity::setPosition(int newX, int newY) {
	m_previousX = x;
	m_previousY = y;
	x = newX;
	y = newY;
	m_position = { static_cast<float>(x), static_cast<float>(y) };
}
sf::Vector2f entity::getPosition() {
	return m_position;
}