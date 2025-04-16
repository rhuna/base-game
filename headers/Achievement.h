#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

class Achievement{
public:
	Achievement(int id, const char* name, const char* description, int points)
		: id(id), name(name), description(description), points(points) {
	}
	int getId() const { return id; }
	const char* getName() const { return name; }
	const char* getDescription() const { return description; }
	int getPoints() const { return points; }
private:
	int id;
	const char* name;
	const char* description;
	int points;

};

#endif // !ACHIEVEMENT_H



