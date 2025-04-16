#include "../headers/entity.h"


entity::entity(int id, int x, int y, int width, int height, int health, int damage)
	: id(id), x(x), y(y), width(width), height(height), health(health), damage(damage), alive(true) {
}
int entity::getId() const { return id; }
int entity::getX() const { return x; }
int entity::getY() const { return y; }
int entity::getWidth() const { return width; }
int entity::getHeight() const { return height; }
int entity::getHealth() const { return health; }
int entity::getDamage() const { return damage; }
bool entity::isAlive() const { return alive; }
void entity::setPosition(int newX, int newY) {
	x = newX;
	y = newY;
}
void entity::takeDamage(int amount) {
	if (alive) {
		health -= amount;
		if (health <= 0) {
			alive = false;
		}
	}
}