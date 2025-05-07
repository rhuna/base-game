//#pragma warning(disable: 4275)
#include "../headers/entity.h"




entity::entity(int id, float x, float y, int width, int height, int health, int damage)
	: id(id), m_x(x), m_y(y), width(width), height(height), health(health), damage(damage), alive(true),
	m_previousX(x), m_previousY(y) // Initialize previous position
{
	
	alive = true; // Set alive to true by default
	m_x = x; // Initialize previous X position
	m_y = y; // Initialize previous Y position
	//std::cout << "Entity created with ID: " << id << std::endl;
}
int entity::getId() const { return id; }
float entity::getX() const { return m_x; }
float entity::getY() const { return m_y; }
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
	m_previousX = m_x;
	m_previousY = m_y;
	m_x = newX;
	m_y = newY;
	m_position = { static_cast<float>(m_x), static_cast<float>(m_y) };
}

sf::Vector2f entity::getPosition() {
	return m_position;
}