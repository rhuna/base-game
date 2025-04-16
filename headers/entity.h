#ifndef ENTITY_H
#define ENTITY_H

class entity {
public:
	entity(int id, int x, int y, int width, int height, int health, int damage);
	int getId() const;
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	int getHealth() const;
	int getDamage() const;
	bool isAlive() const;
	void setPosition(int newX, int newY);
	void takeDamage(int amount);


private:
	int id;
	int x, y;
	int width, height;
	int health;
	int damage;
	bool alive;


};


#endif // !ENTITY_H



