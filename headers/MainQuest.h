#ifndef MAINQUEST_H
#define MAINQUEST_H

#include "Quest.h"
// MainQuest.h
// This file defines the MainQuest class, which inherits from the Quest class.
// It represents a main quest in the game, which is a specific type of quest.


class MainQuest : public Quest {
public:
	MainQuest(int id, const std::string& name, const std::string& description, bool active);
	~MainQuest();
	// Override methods from the Quest class
	void start() override;
	void complete() override;
	const char* getName() const override;
	const char* getDescription() const override;
	bool isActive() const override;
	int getReward() const override;
	bool markAsCompleted() override;
	// Additional methods specific to MainQuest can be added here
	bool operator==(std::unique_ptr<Quest>& other) const;
	bool operator!=(std::unique_ptr<Quest>& other) const;
private:
	int id; // Unique identifier for the main quest
	std::string name; // Name of the main quest
	std::string description; // Description of the main quest
	bool active; // Whether the main quest is currently active
	// Additional attributes specific to MainQuest can be added here
	
};

#endif // !MAINQUEST_H



