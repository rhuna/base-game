#ifndef BUFF_H
#define BUFF_H

class Buff {
public:
	// Default constructor
	Buff();
	// Parameterized constructor
	Buff(int id, const std::string& name, const std::string& description, int duration, int effectValue);
	// Copy constructor
	Buff(const Buff& other);
	// Assignment operator
	Buff& operator=(const Buff& other);
	// Destructor
	~Buff();
	// Getters and setters
	int getId() const;
	void setId(int newId);
	std::string getName() const;
	void setName(const std::string& newName);
	std::string getDescription() const;
	void setDescription(const std::string& newDescription);
	int getDuration() const;
	void setDuration(int newDuration);
	int getEffectValue() const;
	void setEffectValue(int newEffectValue);
private:
	int id; // Unique identifier for the buff
	std::string name; // Name of the buff
	std::string description; // Description of the buff
	int duration; // Duration of the buff in seconds or turns
	int effectValue; // Value of the effect provided by the buff (e.g., stat increase)



};



#endif // !BUFF_H
