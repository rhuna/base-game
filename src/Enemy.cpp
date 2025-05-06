#include "../headers/Enemy.h"



Enemy::Enemy(int id, int x, int y, int width, int height, int health, int damage, sf::Sprite sprite)
	: entity(id, x, y, width, height, health, damage), m_aggroRange(100), m_loot(), m_aiType("default"), m_sprite(sprite),
	m_texture(), m_health(health), m_damage(damage), alive(true), m_speed(5) // Initialize other member variables
{
	m_sprite.setPosition({ static_cast<float>(x), static_cast<float>(y) });
};

void Enemy::followTarget(entity& target, float deltaTime) {
	if (!isAlive() || !target.isAlive()) return;

	// 1. Get positions
	float enemyX = getX();
	float enemyY = getY();
	float targetX = target.getX();
	float targetY = target.getY();

	// 2. Calculate direction vector
	float dx = targetX - enemyX;
	float dy = targetY - enemyY;

	// 3. Normalize the direction (convert to unit vector)
	float length = sqrt(dx * dx + dy * dy);
	if (length > 0) {
		dx /= length;
		dy /= length;
	}
	deltaTime = 2;// Assuming a fixed time step for simplicity
	// 4. Move toward target
	float moveDistance = m_speed * deltaTime;
	setPosition(enemyX + dx * moveDistance,
			enemyY + dy * moveDistance);
	
}
void Enemy::attack(entity& target, float deltaTime) {
	if (isAlive() && target.isAlive()) {
		target.takeDamage(getDamage());
	}
	else {
		std::cout << "Target is not alive." << std::endl;
	}
	
}
void Enemy::move(float deltaX, float deltaY) {
	setPosition(getX() + deltaX, getY() + deltaY );
};
void Enemy::takeDamage(int damage) {

	if (isAlive()) {
		setHealth(getHealth() - damage);
		std::cout << "Enemy took " << damage << " damage. Remaining health: " << getHealth() << std::endl;
		if (getHealth() <= 0) {
			die();
		}
	}
	else {
		std::cout << "Enemy is already dead." << std::endl;
	}
};
void Enemy::setAlive() {


	alive = true;
	std::cout << "Enemy is now alive." << std::endl;
}
bool Enemy::isAlive() {

	return getHealth() > 0;
};
void Enemy::setHealth(int damage) {


	m_health = getHealth() - damage;
	std::cout << "Enemy health set to: " << getHealth() << std::endl;
};
void Enemy::die() {

	std::cout << "Enemy has died." << std::endl;

	setHealth(0); // Set health to 0 to indicate death
	alive = false;

};
void Enemy::setAggroRange(int range) {
	
	m_aggroRange = range;

	std::cout << "Enemy aggro range set to: " << m_aggroRange << std::endl;
	
};
int Enemy::getAggroRange() const {
	// Logic to get the aggro range
	// This could involve returning the enemy's aggro range, checking for nearby entities, etc.
	// For example:
	return m_aggroRange;
	std::cout << "Enemy aggro range: " << m_aggroRange << std::endl;
};
void Enemy::setLoot(const Item& loot) {
	// Logic to set the loot
	// This could involve updating the enemy's loot table, dropping items, etc.
	// For example:
	m_loot = loot;
	std::cout << "Enemy loot set to: " << loot.getName() << std::endl;
	// Assuming Item has a method to get its name or description
	//std::cout << "Loot: " << loot.getName() << " - " << loot.getDescription() << std::endl;
	
};
Item Enemy::getLoot() const {
	// Logic to get the loot
	// This could involve returning the enemy's loot, checking for drops, etc.
	// For example:
	std::cout << "Enemy loot: " << m_loot.getName() << std::endl;
	return m_loot;
	// Assuming Item has a method to get its name or description
	//std::cout << "Loot: " << loot.getName() << " - " << loot.getDescription() << std::endl;
};
void Enemy::setAIType(const std::string& aiType) {
	// Logic to set the AI type
	// This could involve updating the enemy's behavior, AI, etc.
	// For example:
	m_aiType = aiType;
	std::cout << "Enemy AI type set to: " << m_aiType << std::endl;
	// Assuming AIType is a string representing the type of AI
	//std::cout << "AI Type: " << aiType << std::endl;
};
std::string Enemy::getAIType() const {
	// Logic to get the AI type
	// This could involve returning the enemy's AI type, checking for behavior, etc.
	// For example:
	std::cout << "Enemy AI type: " << m_aiType << std::endl;
	return m_aiType;
	// Assuming AIType is a string representing the type of AI
	//std::cout << "AI Type: " << aiType << std::endl;
};

void Enemy::setTexture(const std::string& texturePath) {
	// Logic to set the texture
	// This could involve loading a texture from a file, applying it to the sprite, etc.
	// For example:
	if (!m_texture.loadFromFile(texturePath)) {
		std::cerr << "Error loading texture from: " << texturePath << std::endl;
	}
	else {
		m_sprite.setTexture(m_texture);
		std::cout << "Enemy texture set to: " << texturePath << std::endl;
	}
};
void Enemy::setX(int x) {
	// Logic to set the x-coordinate
	// This could involve updating the enemy's position, checking for collisions, etc.
	// For example:
	std::cout << "Enemy x-coordinate set to: " << x << std::endl;
	// Assuming m_sprite is a member variable of type sf::Sprite
	m_sprite.setPosition({ static_cast<float>(x), m_sprite.getPosition().y });
};
void Enemy::setY(int y) {
	// Logic to set the y-coordinate
	// This could involve updating the enemy's position, checking for collisions, etc.
	// For example:
	std::cout << "Enemy y-coordinate set to: " << y << std::endl;
	// Assuming m_sprite is a member variable of type sf::Sprite
	m_sprite.setPosition({ m_sprite.getPosition().x, static_cast<float>(y) });
};
void Enemy::setSprite(sf::Sprite& sprite) {
	m_sprite = sprite;
}
sf::Sprite Enemy::getSprite() {
	return m_sprite;
}
void Enemy::setPosition(int x, int y) {
	// Logic to set the position
	// This could involve updating the enemy's position, checking for collisions, etc.
	// For example:
	setX(x);
	setY(y);
	std::cout << "Enemy position set to: (" << getX() << ", " << getY() << ")" << std::endl;
	m_sprite.setPosition({ static_cast<float>(x), static_cast<float>(y) });
};
void Enemy::setScale(float scaleX, float scaleY) {
	// Logic to set the scale
	// This could involve updating the enemy's size, checking for collisions, etc.
	// For example:
	m_sprite.setScale({ scaleX, scaleY });
	std::cout << "Enemy scale set to: (" << scaleX << ", " << scaleY << ")" << std::endl;

};
void Enemy::setOrigin(float x, float y) {
	// Logic to set the origin
	// This could involve updating the enemy's origin point, checking for rotations, etc.
	// For example:
	m_sprite.setOrigin({ x, y });
	std::cout << "Enemy origin set to: (" << x << ", " << y << ")" << std::endl;
};
void Enemy::setRotation(float angle) {
	// Logic to set the rotation
	// This could involve updating the enemy's rotation, checking for collisions, etc.
	// For example:
	m_sprite.setRotation(sf::degrees(angle));
	std::cout << "Enemy rotation set to: " << angle << " degrees" << std::endl;
};
void Enemy::setColor(const sf::Color& color) {
	// Logic to set the color
	// This could involve updating the enemy's color, checking for effects, etc.
	// For example:
	m_sprite.setColor(color);
	std::cout << "Enemy color set to: (" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ")" << std::endl;
	
};
