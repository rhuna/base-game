#include "../headers/Debuff.h"

#include <string>


Debuff::Debuff(const std::string& name, int duration, int effectStrength)
	: name(name), duration(duration), effectStrength(effectStrength) {
}
const std::string& Debuff::getName() const { return name; }
const std::string& Debuff::getDescription() const { return description; }
int Debuff::getDuration() const { return duration; }
int Debuff::getEffectStrength() const { return effectStrength; }
void Debuff::reduceDuration(int amount) {
	if (duration > amount) {
		duration -= amount;
	}
	else {
		duration = 0; // Debuff ends
	}
}