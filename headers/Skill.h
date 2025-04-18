#ifndef SKILL_H
#define SKILL_H

class Skill {
public:
	Skill() = default;
	virtual ~Skill() = default;
	// Method to execute the skill
	virtual void execute() = 0;
	// Method to get the name of the skill
	virtual const char* getName() const = 0;
	// Method to get the description of the skill
	virtual const char* getDescription() const = 0;
	// Method to check if the skill is available
	virtual bool isAvailable() const = 0;
	// Method to get the cooldown time of the skill
	virtual int getCooldown() const = 0;

	bool operator==(const Skill& other) const {
		//logic for == operator
		return (name == other.name && description == other.description && cooldownTime == other.cooldownTime);
	}

	bool operator!=(const Skill& other) const {
		return !(*this == other);
	}


private:
	// Private members can be added here if needed
	// For example, you might want to store the skill's name, description, cooldown time, etc.
	std::string name;
	std::string description;
	int cooldownTime;
};

#endif // !SKILL_H



