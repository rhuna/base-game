#ifndef QUEST_H
#define QUEST_H

class Quest{
public:
	Quest() = default;
	virtual ~Quest() = default;
	// Method to start the quest
	virtual void start() = 0;
	// Method to complete the quest
	virtual void complete() = 0;
	// Method to get the name of the quest
	virtual const char* getName() const = 0;
	// Method to get the description of the quest
	virtual const char* getDescription() const = 0;
	// Method to check if the quest is active
	virtual bool isActive() const = 0;
	// Method to get the reward for completing the quest
	virtual int getReward() const = 0;
private:
	// Private members can be added here if needed
	// For example, you might want to store the quest's name, description, reward, etc.
	std::string name;
	std::string description;
	int reward;
	bool active;

};


#endif // !QUEST_H


