#include "../headers/Achievement.h"


Achievement::Achievement(int id, const char* name, const char* description, int points)
	: id(id), name(name), description(description), points(points) {
}
int Achievement::getId() const { return id; }
const char* Achievement::getName() const { return name; }
const char* Achievement::getDescription() const { return description; }
int Achievement::getPoints() const { return points; }