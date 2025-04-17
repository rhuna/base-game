#include "../headers/MainQuest.h"



MainQuest::MainQuest(int id, const std::string& name, const std::string& description, bool active)
	: Quest(id, name, description, active), id(id), name(name), description(description), active(active) {
}
MainQuest::~MainQuest() {};
// Override methods from the Quest class
void MainQuest::start(){
	// Implementation for starting the main quest
}
void MainQuest::complete() {
	// Implementation for completing the main quest
}
const char* MainQuest::getName() const {
	return "Main Quest Name"; // Replace with actual name
}
const char* MainQuest::getDescription() const {
	return "Main Quest Description"; // Replace with actual description
}
bool MainQuest::isActive() const{
	return true; // Replace with actual logic to check if the quest is active
}
int MainQuest::getReward() const{
	return 100; // Replace with actual reward logic
}
bool MainQuest::markAsCompleted() {
	return true; // Replace with actual logic to mark the quest as completed
}
// Additional methods specific to MainQuest can be added here
bool MainQuest::operator==(std::unique_ptr<Quest>& other) const {
		// Compare based on all attributes
	return this->name == other->getName() &&
		this->description == other->getDescription();
}
bool MainQuest::operator!=(std::unique_ptr<Quest>& other) const {
	return !(*this == other);
}