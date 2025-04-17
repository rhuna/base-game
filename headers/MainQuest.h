#ifndef MAINQUEST_H
#define MAINQUEST_H

#include "Quest.h"
// MainQuest.h
// This file defines the MainQuest class, which inherits from the Quest class.
// It represents a main quest in the game, which is a specific type of quest.


class MainQuest : public Quest {
public:
	MainQuest(int id, const std::string& name, const std::string& description, bool active)
		: Quest(id, name, description, active), id(id), name(name), description(description), active(active) {
	}
	// Override methods from the Quest class
	void start() override {
		// Implementation for starting the main quest
	}
	void complete() override {
		// Implementation for completing the main quest
	}
	const char* getName() const override {
		return "Main Quest Name"; // Replace with actual name
	}
	const char* getDescription() const override {
		return "Main Quest Description"; // Replace with actual description
	}
	bool isActive() const override {
		return true; // Replace with actual logic to check if the quest is active
	}
	int getReward() const override {
		return 100; // Replace with actual reward logic
	}
	bool markAsCompleted() override {
		return true; // Replace with actual logic to mark the quest as completed
	}
	// Additional methods specific to MainQuest can be added here
	bool operator==(const MainQuest& other) const {
		return id == other.id &&
			name == other.name &&
			description == other.description &&
			active == other.active; // Compare based on all attributes
	}
	bool operator!=(const MainQuest& other) const {
		return !(*this == other);
	}
private:
	int id; // Unique identifier for the main quest
	std::string name; // Name of the main quest
	std::string description; // Description of the main quest
	bool active; // Whether the main quest is currently active
	// Additional attributes specific to MainQuest can be added here
	
};

#endif // !MAINQUEST_H



