#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

class Achievement{
public:
	Achievement(int id, const char* name, const char* description, int points);
	int getId() const;
	const char* getName() const;
	const char* getDescription() const;
	int getPoints() const;

	bool operator==(const Achievement& other) const {
		//logic for == operator
		return (id == other.id &&
			name == other.name &&
			description == other.description &&
			points == other.points);
	}

	bool operator!=(const Achievement& other) const {
		return !(*this == other);
	}

private:
	int id;
	const char* name;
	const char* description;
	int points;

};

#endif // !ACHIEVEMENT_H



