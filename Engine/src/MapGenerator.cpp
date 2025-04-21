#include "../headers/MapGenerator.h"




MapGenerator::MapGenerator() : map(nullptr), width(0), height(0) {
	std::cout << "Default constructor called." << std::endl;
}
MapGenerator::MapGenerator(int width, int height) : map(nullptr), width(width), height(height) {
	std::cout << "Parameterized constructor called." << std::endl;
	initializeMap();
	generateMap(width, height);
}
MapGenerator::MapGenerator(const MapGenerator& other) : map(nullptr), width(other.width), height(other.height) {
	std::cout << "Copy constructor called." << std::endl;
	initializeMap();
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			map[i][j] = other.map[i][j];
		}
	}
}
MapGenerator& MapGenerator::operator=(const MapGenerator& other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {
		deleteMap();
		width = other.width;
		height = other.height;
		initializeMap();
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				map[i][j] = other.map[i][j];
			}
		}
	}
	return *this;
}
MapGenerator::MapGenerator(MapGenerator&& other) noexcept : map(other.map), width(other.width), height(other.height) {
	std::cout << "Move constructor called." << std::endl;
	other.map = nullptr;
	other.width = 0;
	other.height = 0;
}
MapGenerator::~MapGenerator() {
	std::cout << "Destructor called." << std::endl;
	deleteMap();
}
void MapGenerator::initializeMap() {
	map = new int* [height];
	for (int i = 0; i < height; ++i) {
		map[i] = new int[width];
	}
}
void MapGenerator::deleteMap() {
	if (map) {
		for (int i = 0; i < height; ++i) {
			delete[] map[i];
		}
		delete[] map;
		map = nullptr;
	}
}
void MapGenerator::generateMap(int width, int height) {
	this->width = width;
	this->height = height;
	initializeMap();
	generateTerrain();
	generateObstacles();
	generateItems();
	generateEnemies();
	generateNPCs();
	generateQuests();
	generateEvents();
	generateWeather();
	generateDayNightCycle();
	generateLore();
	generateMusic();
	generateSoundEffects();
	generateGraphics();
	generateAnimations();
	generateUserInterface();
}
void MapGenerator::displayMap() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void MapGenerator::renderMapSFML(sf::RenderWindow& window) {
	//const int tileSize = 10; // Size of each tile in pixels
	//
	//for (int y = 0; y < height; ++y) {
	//	for (int x = 0; x < width; ++x) {
	//		sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
	//		{
	//			sf::Vector2f xy(x * tileSize, y * tileSize);
	//			tile.setPosition(xy);
	//		}
	//
	//		// Set color based on tile value
	//		switch (map[y][x]) {
	//		case 0: tile.setFillColor(sf::Color::Green); break;  // Grass
	//		case 1: tile.setFillColor(sf::Color::Blue); break;   // Water
	//		case 2: tile.setFillColor(sf::Color::Yellow); break; // Items
	//		case 3: tile.setFillColor(sf::Color(139, 69, 19)); break; // Brown for obstacles
	//		case 4: tile.setFillColor(sf::Color::Red); break;    // Enemies
	//			// Add more cases for other tile types
	//		//default: tile.setFillColor(sf::Color::White);
	//		}
	//
	//		window.draw(tile);
	//	}
	//}
	// Define tile size and spacing
	const int tileSize = 8;  // Size of each tile in pixels
	const int tileSpacing = 0;  // Space between tiles

	// Define colors for different tile types
	const sf::Color grassColor(34, 139, 34);       // Green for terrain
	const sf::Color waterColor(30, 144, 255);      // Blue for water
	const sf::Color obstacleColor(139, 69, 19);    // Brown for obstacles
	const sf::Color itemColor(255, 215, 0);        // Gold for items
	const sf::Color enemyColor(220, 20, 60);       // Crimson for enemies
	const sf::Color npcColor(138, 43, 226);        // Purple for NPCs
	const sf::Color defaultColor(200, 200, 200);    // Gray for unknown types

	// Calculate view offset to center the map
	sf::Vector2f viewCenter(width * (tileSize + tileSpacing) / 2.f,
		height * (tileSize + tileSpacing) / 2.f);

	// Create a view to center the map
	sf::View view(viewCenter,
		sf::Vector2f(window.getSize().x, window.getSize().y));
	window.setView(view);

	// Draw each tile
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
			sf::Vector2f xy(x * (tileSize + tileSpacing),
				y * (tileSize + tileSpacing));
			tile.setPosition(xy);

			// Set color based on tile value
			switch (map[y][x]) {
			case 15:  tile.setFillColor(grassColor); break;    // Terrain
			case 10:  tile.setFillColor(waterColor); break;    // Water
			case 11:  tile.setFillColor(itemColor); break;     // Items
			case 9:  tile.setFillColor(obstacleColor); break; // Obstacles
			case 13:  tile.setFillColor(enemyColor); break;    // Enemies
			case 14:  tile.setFillColor(npcColor); break;      // NPCs
				// Add more cases for your other tile types
			case 12: tile.setFillColor(defaultColor);
			}

			// Add outline to make tiles more distinct
			tile.setOutlineThickness(0.5f);
			tile.setOutlineColor(sf::Color(50, 50, 50, 100));

			window.draw(tile);
		}
	}

	// Reset the view to default for UI elements
	window.setView(window.getDefaultView());
}

void MapGenerator::saveMapToFile(const std::string& filename) {
	std::ofstream file(filename);
	if (file.is_open()) {
		file << width << " " << height << std::endl;
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				file << map[i][j] << " ";
			}
			file << std::endl;
		}
		file.close();
	}
	else {
		std::cerr << "Unable to open file for writing." << std::endl;
	}
}
void MapGenerator::loadMapFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (file.is_open()) {
		file >> width >> height;
		deleteMap();
		initializeMap();
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				file >> map[i][j];
			}
		}
		file.close();
	}
	else {
		std::cerr << "Unable to open file for reading." << std::endl;
	}
}
void MapGenerator::setMapSize(int width, int height) {
	deleteMap();
	this->width = width;
	this->height = height;
	initializeMap();
}
void MapGenerator::setMapTile(int x, int y, int value) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		map[y][x] = value;
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
	}
}
int MapGenerator::getMapTile(int x, int y) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		return map[y][x];
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
		return -1; // or some other error value
	}
}
void MapGenerator::setMapTileType(int x, int y, const std::string& type) {
	// Implementation for setting tile type
	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Set the tile type here
		std::cout << "Tile type set to: " << type << std::endl;

		// Example: map[y][x] = type; // Assuming map is a 2D array of strings
		

		// For example, if you have a separate data structure for tile types,
		// you would set the type in that structure instead of the map array.
		// Example: tileTypes[y][x] = type; // Assuming tileTypes is a 2D array of strings
	

		// You can also add error handling or validation here if needed.
		// For example, check if the type is valid or if the coordinates are within bounds.
		// Example: if (type is valid) { ... } else { std::cerr << "Invalid tile type." << std::endl; }

	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
	}
}
std::string MapGenerator::getMapTileType(int x, int y) {
	// Implementation for getting tile type

	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Get the tile type here
		std::string type = "Grass"; // Example: return the tile type
		return type;
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
		return ""; // or some other error value
	}
	// Example: return tileTypes[y][x]; // Assuming tileTypes is a 2D array of strings

}
void MapGenerator::setMapTileProperties(int x, int y, const std::string& properties) {
	// Implementation for setting tile properties

	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Set the tile properties here
		std::cout << "Tile properties set to: " << properties << std::endl;
		// Example: map[y][x] = properties; // Assuming map is a 2D array of strings

		// For example, if you have a separate data structure for tile properties,
		// you would set the properties in that structure instead of the map array.
		// Example: tileProperties[y][x] = properties; // Assuming tileProperties is a 2D array of strings

		// You can also add error handling or validation here if needed.
		// For example, check if the properties are valid or if the coordinates are within bounds.
		// Example: if (properties are valid) { ... } else { std::cerr << "Invalid tile properties." << std::endl; }
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
	}
	// Example: return tileProperties[y][x]; // Assuming tileProperties is a 2D array of strings
}
std::string MapGenerator::getMapTileProperties(int x, int y) {
	// Implementation for getting tile properties

	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Get the tile properties here
		std::string properties = "None"; // Example: return the tile properties
		return properties;
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
		return ""; // or some other error value
	}
	// Example: return tileProperties[y][x]; // Assuming tileProperties is a 2D array of strings

};
void MapGenerator::setMapTileEvent(int x, int y, const std::string& event) {
	// Implementation for setting tile event
	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Set the tile event here
		std::cout << "Tile event set to: " << event << std::endl;
		// Example: map[y][x] = event; // Assuming map is a 2D array of strings
		// For example, if you have a separate data structure for tile events,
		// you would set the event in that structure instead of the map array.
		// Example: tileEvents[y][x] = event; // Assuming tileEvents is a 2D array of strings
		// You can also add error handling or validation here if needed.
		// For example, check if the event is valid or if the coordinates are within bounds.
		// Example: if (event is valid) { ... } else { std::cerr << "Invalid tile event." << std::endl; }
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
	}
	// Example: return tileEvents[y][x]; // Assuming tileEvents is a 2D array of strings
}
std::string MapGenerator::getMapTileEvent(int x, int y) {
	// Implementation for getting tile event
	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Get the tile event here
		std::string event = "None"; // Example: return the tile event
		return event;
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
		return ""; // or some other error value
	}
	// Example: return tileEvents[y][x]; // Assuming tileEvents is a 2D array of strings
	
}
void MapGenerator::setMapTileNPC(int x, int y, const std::string& npc) {
	// Implementation for setting tile NPC
	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Set the tile NPC here
		std::cout << "Tile NPC set to: " << npc << std::endl;
		// Example: map[y][x] = npc; // Assuming map is a 2D array of strings
		// For example, if you have a separate data structure for tile NPCs,
		// you would set the NPC in that structure instead of the map array.
		// Example: tileNPCs[y][x] = npc; // Assuming tileNPCs is a 2D array of strings
		// You can also add error handling or validation here if needed.
		// For example, check if the NPC is valid or if the coordinates are within bounds.
		// Example: if (npc is valid) { ... } else { std::cerr << "Invalid tile NPC." << std::endl; }
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
	}
	// Example: return tileNPCs[y][x]; // Assuming tileNPCs is a 2D array of strings
}
std::string MapGenerator::getMapTileNPC(int x, int y) {
	// Implementation for getting tile NPC
	if (x >= 0 && x < width && y >= 0 && y < height) {
		// Get the tile NPC here
		std::string npc = "None"; // Example: return the tile NPC
		return npc;
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
		return ""; // or some other error value
	}
	// Example: return tileNPCs[y][x]; // Assuming tileNPCs is a 2D array of strings
	
}
void MapGenerator::generateTerrain() {
	// Implementation for generating terrain
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			map[i][j] = rand() % 2; // Randomly assign terrain type (0 or 1)
		}
	}
	std::cout << "Terrain generated." << std::endl;
	// Example: 0 for grass, 1 for water
}
void MapGenerator::generateObstacles() {
	// Implementation for generating obstacles
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 2) { // 20% chance to place an obstacle
				map[i][j] = 3; // Assign obstacle type
			}
		}
	}
	std::cout << "Obstacles generated." << std::endl;
}
void MapGenerator::generateItems() {
	// Implementation for generating items
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 3) { // 30% chance to place an item
				map[i][j] = 2; // Assign item type
			}
		}
	}
	std::cout << "Items generated." << std::endl;
}
void MapGenerator::generateEnemies() {
	// Implementation for generating enemies
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 5) { // 50% chance to place an enemy
				map[i][j] = 4; // Assign enemy type
			}
		}
	}
	std::cout << "Enemies generated." << std::endl;
}
void MapGenerator::generateNPCs() {
	// Implementation for generating NPCs
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 4) { // 40% chance to place an NPC
				map[i][j] = 5; // Assign NPC type
			}
		}
	}
	std::cout << "NPCs generated." << std::endl;
}
void MapGenerator::generateQuests() {
	// Implementation for generating quests
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 6) { // 60% chance to place a quest
				map[i][j] = 6; // Assign quest type
			}
		}
	}
	std::cout << "Quests generated." << std::endl;
}
void MapGenerator::generateEvents() {
	// Implementation for generating events
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 7) { // 70% chance to place an event
				map[i][j] = 7; // Assign event type
			}
		}
	}
	std::cout << "Events generated." << std::endl;
}
void MapGenerator::generateWeather() {
	// Implementation for generating weather
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 8) { // 80% chance to place a weather effect
				map[i][j] = 8; // Assign weather type
			}
		}
	}
	std::cout << "Weather generated." << std::endl;
	
}
void MapGenerator::generateDayNightCycle() {
	// Implementation for generating day/night cycle
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 9) { // 90% chance to place a day/night cycle
				map[i][j] = 9; // Assign day/night type
			}
		}
	}
	std::cout << "Day/Night cycle generated." << std::endl;
}
void MapGenerator::generateLore() {
	// Implementation for generating lore
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 1) { // 10% chance to place lore
				map[i][j] = 10; // Assign lore type
			}
		}
	}
	std::cout << "Lore generated." << std::endl;
}
void MapGenerator::generateMusic() {
	// Implementation for generating music
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 2) { // 20% chance to place music
				map[i][j] = 11; // Assign music type
			}
		}
	}
	std::cout << "Music generated." << std::endl;
}
void MapGenerator::generateSoundEffects() {
	// Implementation for generating sound effects
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 3) { // 30% chance to place sound effects
				map[i][j] = 12; // Assign sound effect type
			}
		}
	}
	std::cout << "Sound effects generated." << std::endl;
}
void MapGenerator::generateGraphics() {
	// Implementation for generating graphics
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 4) { // 40% chance to place graphics
				map[i][j] = 13; // Assign graphic type
			}
		}
	}
	std::cout << "Graphics generated." << std::endl;
}
void MapGenerator::generateAnimations() {
	// Implementation for generating animations
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 5) { // 50% chance to place animations
				map[i][j] = 14; // Assign animation type
			}
		}
	}
	std::cout << "Animations generated." << std::endl;
}
void MapGenerator::generateUserInterface() {
	// Implementation for generating user interface
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (rand() % 10 < 6) { // 60% chance to place user interface
				map[i][j] = 15; // Assign UI type
			}
		}
	}
	std::cout << "User interface generated." << std::endl;
}
