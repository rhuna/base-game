#include "../headers/Enemy.h"



Enemy::Enemy(int id, float x, float y, int width, int height, int health, int damage, sf::Sprite sprite)
	: entity(id, x, y, width, height, health, damage), m_aggroRange(100), m_loot(), m_aiType("default"), m_sprite(sprite),
	m_texture(), m_health(health), m_damage(damage), alive(true), m_speed(5)
{
	m_sprite.setPosition({ x, y });
	setPosition(x, y);
};





void Enemy::followTarget(entity& target, float deltaTime) {

	

	if (!isAlive() || !target.isAlive()) return;

	// Get target position (convert to float if needed)
	sf::Vector2f targetPos(static_cast<float>(target.getX()),
		static_cast<float>(target.getY()));
	sf::Vector2f enemyPos(static_cast<float>(getX()),
		static_cast<float>(getY()));

	

	// Calculate direction vector
	sf::Vector2f direction = targetPos - enemyPos;
	std::cout << "direction: {" << direction.x << ", " << direction.y << "}s\n";
	std::cout << "player: {" << targetPos.x << ", " << targetPos.y << "}s\n";
	std::cout << "enemy: {" << enemyPos.x << ", " << enemyPos.y << "}s\n";
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	

	// Normalize direction and scale by speed
	if (distance > 0) {

		//example info direction = direction / distance(-100,-50);
		direction /= distance;
		deltaTime = 0.05f;


		// Move toward target (frame-rate independent)
		float moveDistance = m_speed * deltaTime;

		

		move(direction.x, direction.y);
		m_position = { getX() + direction.x * moveDistance, getY() + direction.y * moveDistance };
		m_sprite.setPosition(m_position);



	}

}
void Enemy::attack(entity& target, float deltaTime) {
	if (isAlive() && target.isAlive()) {
		target.takeDamage(getDamage());
		std::cout << "player damage taken: " << getDamage() << "\n";
	}
	else {
		std::cout << "Target is not alive." << std::endl;
	}
	
}
void Enemy::move(float deltaX, float deltaY) {
	setPosition(getX() + deltaX, getY() + deltaY );
};
void Enemy::takeDamage(float damage) {

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
	//std::cout << "Enemy aggro range: " << m_aggroRange << std::endl;
	return m_aggroRange;
};
void Enemy::setLoot(const Item& loot) {

	m_loot = loot;
	std::cout << "Enemy loot set to: " << loot.getName() << std::endl;

	//std::cout << "Loot: " << loot.getName() << " - " << loot.getDescription() << std::endl;
	
};
Item Enemy::getLoot() const {
	
	std::cout << "Enemy loot: " << m_loot.getName() << std::endl;
	return m_loot;

	//std::cout << "Loot: " << loot.getName() << " - " << loot.getDescription() << std::endl;
};
void Enemy::setAIType(const std::string& aiType) {
	
	m_aiType = aiType;
	std::cout << "Enemy AI type set to: " << m_aiType << std::endl;
	
	//std::cout << "AI Type: " << aiType << std::endl;
};
std::string Enemy::getAIType() const {
	
	std::cout << "Enemy AI type: " << m_aiType << std::endl;
	return m_aiType;
	
	//std::cout << "AI Type: " << aiType << std::endl;
};

void Enemy::setTexture(const std::string& texturePath) {
	
	if (!m_texture.loadFromFile(texturePath)) {
		std::cerr << "Error loading texture from: " << texturePath << std::endl;
	}
	else {
		m_sprite.setTexture(m_texture);
		std::cout << "Enemy texture set to: " << texturePath << std::endl;
	}
};
void Enemy::setX(int x) {
	m_sprite.setPosition({ static_cast<float>(x), m_sprite.getPosition().y });
};
void Enemy::setY(int y) {
	m_sprite.setPosition({ m_sprite.getPosition().x, static_cast<float>(y) });
};
void Enemy::setSprite(sf::Sprite& sprite) {
	m_sprite = sprite;
}
sf::Sprite Enemy::getSprite() {
	return m_sprite;
}

void Enemy::setScale(float scaleX, float scaleY) {
	
	m_sprite.setScale({ scaleX, scaleY });
	std::cout << "Enemy scale set to: (" << scaleX << ", " << scaleY << ")" << std::endl;

};
void Enemy::setOrigin(float x, float y) {
	
	m_sprite.setOrigin({ x, y });
	std::cout << "Enemy origin set to: (" << x << ", " << y << ")" << std::endl;
};
void Enemy::setRotation(float angle) {
	
	m_sprite.setRotation(sf::degrees(angle));
	std::cout << "Enemy rotation set to: " << angle << " degrees" << std::endl;
};
void Enemy::setColor(const sf::Color& color) {
	
	m_sprite.setColor(color);
	std::cout << "Enemy color set to: (" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ")" << std::endl;
	
};
