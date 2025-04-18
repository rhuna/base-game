#ifndef DEBUFF_H
#define DEBUFF_H
#include <iostream>

class Debuff {
public:
	Debuff(const std::string& name, int duration, int effectStrength);
	const std::string& getName() const;
	const std::string& getDescription() const;
	int getDuration() const;
	int getEffectStrength() const;
	void reduceDuration(int amount);

	bool operator==(const Debuff& other) const {
		//logic for == operator
		return (name == other.name &&
			duration == other.duration &&
			effectStrength == other.effectStrength);
	}

	bool operator!=(const Debuff& other) const {
		return !(*this == other);
	}

private:
	std::string name; // Name of the debuff
	int duration; // Duration in turns or time units
	int effectStrength; // Strength of the debuff effect (e.g., damage reduction, speed reduction)
	std::string description;


};



#endif // !DEBUFF_H



