#ifndef DEBUFF_H
#define DEBUFF_H

class Debuff {
public:
	Debuff(const std::string& name, int duration, int effectStrength);
	const std::string& getName() const;
	int getDuration() const;
	int getEffectStrength() const;
	void reduceDuration(int amount);

private:
	std::string name; // Name of the debuff
	int duration; // Duration in turns or time units
	int effectStrength; // Strength of the debuff effect (e.g., damage reduction, speed reduction)



};



#endif // !DEBUFF_H



