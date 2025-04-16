

#include <iostream>
#include "./headers/player.h"


int main() {
	// a practical use for all the classes
	player player(1, 5, 5, 20, 20, 100, 0);
	player.setPosition(10, 10);
	std::cout << "Player Position: (" << player.getX() << ", " << player.getY() << ")\n";
	player.move(5, -3);
	std::cout << "Player moved to: (" << player.getX() << ", " << player.getY() << ")\n";
	player.attack(player); // Attacking itself for demonstration
	std::cout << "Player attacked itself, health now: " << player.getHealth() << "\n";
	player.addItemToInventory(Item(0, "health potion", "potion for health reasons", 1, 5, 0.5f));
	std::cout << "Added item to inventory: Health Potion\n";
	player.removeItemFromInventory(Item(0, "health potion", "potion for health reasons", 1, 5, 0.5f));
	std::cout << "Removed item from inventory: Health Potion\n";
	player.levelUp();
	std::cout << "Player leveled up to level: " << player.getLevel() << "\n";
	player.setScore(100);
	std::cout << "Player score set to: " << player.getScore() << "\n";
	std::cout << "Player experience points: " << player.getExperiencePoints() << "\n";
	std::cout << "Player inventory size: " << player.getInventorySize() << "\n";
	for (const auto& item : player.getInventory()) {
		std::cout << "Item in inventory: " << item.getName() << "\n";
	}
	std::cout << "Player is " << (player.isAlive() ? "alive" : "dead") << "\n";
	// Additional game logic can be added here
	std::cout << "Game simulation complete.\n";

	return 0;
}