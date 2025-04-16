#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

class Achievement{
public:
	Achievement(int id, const char* name, const char* description, int points);
	int getId() const;
	const char* getName() const;
	const char* getDescription() const;
	int getPoints() const;
private:
	int id;
	const char* name;
	const char* description;
	int points;

};

#endif // !ACHIEVEMENT_H



