#ifndef QUEST_H
#define QUEST_H
#include <iostream>
class Quest {
public:
    Quest() = default;
    Quest(int id, const std::string& name, const std::string& description, bool active)
        : id(id), name(name), description(description), active(active) {
    }
    virtual ~Quest() = default;

    // Method to start the quest
    virtual void start() = 0;
    // Method to complete the quest
    virtual void complete() = 0;
    // Method to get the name of the quest
    virtual std::string getName() const = 0;
    // Method to get the description of the quest
    virtual std::string getDescription() const = 0;
    // Method to check if the quest is active
    virtual bool isActive() const = 0;
    // Method to get the reward for completing the quest
    virtual int getReward() const = 0;
    virtual bool markAsCompleted() = 0;

    enum QuestStatus {
        NOT_STARTED,
        IN_PROGRESS,
        COMPLETED,
        FAILED
    };
    enum questType {
        MAIN_QUEST,
        SIDE_QUEST,
        DAILY_QUEST,
        EVENT_QUEST
    };
    enum questDifficulty {
        EASY,
        MEDIUM,
        HARD,
        VERY_HARD
    };
    enum questRewardType {
        GOLD,
        ITEM,
        EXPERIENCE,
        SKILL_POINTS
    };

    enum questObjectiveType {
        DEFEAT_ENEMY,
        COLLECT_ITEM,
        DELIVER_ITEM,
        EXPLORE_AREA,
        SOLVE_PUZZLE,
        COMPLETE_TASK,
        INTERACT_WITH_NPC,
        DEFEAT_BOSS
    };

    bool operator==(const Quest& other) const {
        //logic for == operator
        return this->name == other.name &&
            this->description == other.description &&
            this->id == other.id && this->active == other.active;
             
    }

    bool operator!=(const Quest& other) const {
        return !(*this == other);
    }

private:
    int id; // Added id to match constructor arguments
    std::string name;
    std::string description;
    int reward =0;
    bool active;
};


#endif // !QUEST_H



