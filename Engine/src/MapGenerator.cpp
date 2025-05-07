#include "../headers/MapGenerator.h"




MapGenerator::MapGenerator() : m_map(nullptr), m_width(100), m_height(100),
m_tileSize(32)
{
	std::cout << "Default constructor called." << std::endl;
}
MapGenerator::MapGenerator(int width, int height) : m_map(nullptr), m_width(width), m_height(height) {
	std::cout << "Parameterized constructor called." << std::endl;
	tileRects = loadTileset("assets/textures/tileset.png", 32); //- works
	m_characters = loadTileset("assets/textures/32rogues/rogues.png", 32);
	//loadTextures();
	initializeMap();
	generateMap(width, height);
}
MapGenerator::MapGenerator(const MapGenerator& other) : m_map(nullptr), m_width(other.m_width), m_height(other.m_height),
tileRects(other.tileRects), m_tileTextures(other.m_tileTextures), m_tileSize(32)  // Copy constructor
{
	std::cout << "Copy constructor called." << std::endl;
	initializeMap();
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			m_map[i][j] = other.m_map[i][j];
		}
	}
}
MapGenerator& MapGenerator::operator=(const MapGenerator& other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {
		deleteMap();
		m_width = other.m_width;
		m_height = other.m_height;
		initializeMap();
		for (int i = 0; i < m_height; ++i) {
			for (int j = 0; j < m_width; ++j) {
				m_map[i][j] = other.m_map[i][j];
			}
		}
	}
	return *this;
}
MapGenerator::MapGenerator(MapGenerator&& other) noexcept : m_map(other.m_map), m_width(other.m_width), m_height(other.m_height),
tileRects(std::move(other.tileRects)), m_tileTextures(std::move(other.m_tileTextures)), m_tileSize(32) {
	// Move constructor
	std::cout << "Move assignment operator called." << std::endl;
	other.m_map = nullptr;
	other.m_width = 0;
	other.m_height = 0;
}
MapGenerator::~MapGenerator() {
	std::cout << "Destructor called." << std::endl;
	deleteMap();
}
void MapGenerator::initializeMap() {
	std::cout << "initialized map\n";
	m_map = new int* [m_height];
	for (int i = 0; i < m_height; ++i) {
		m_map[i] = new int[m_width];
	}
}
void MapGenerator::deleteMap() {
	if (m_map) {
		for (int i = 0; i < m_height; ++i) {
			delete[] m_map[i];
		}
		delete[] m_map;
		m_map = nullptr;
	}
}
void MapGenerator::generateMap(int width, int height) {
	this->m_width = width;
	this->m_height = height;
	initializeMap();
	generateTerrain();
	generateObstacles();
	generateItems();
	generateEnemies();
	generateNPCs();
	//generateQuests();
	//generateEvents();
	//generateWeather();
	//generateDayNightCycle();
	//generateLore();
	//generateMusic();
	//generateSoundEffects();
	//generateGraphics();
	//generateAnimations();
	//generateUserInterface();
}

void MapGenerator::displayMap() {
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			std::cout << m_map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
std::unordered_map<int, sf::Rect<int>> MapGenerator::loadTileset(const std::string& filename, int tileSize) {
   this->m_tileSize = tileSize;

   std::unordered_map<int, sf::Rect<int>> p_tileRects;
   p_tileRects.clear();
   p_tileRects.reserve(1000); // Reserve space for 256 tile types
   // Create a texture object to hold the tileset image
   sf::Texture p_tilesetTexture;
   p_tilesetTexture.bind(nullptr); // Unbind any previously bound texture

   std::cout << filename;
   // Check the return value of loadFromFile and handle errors properly
   if (!p_tilesetTexture.loadFromFile(filename)) {
       throw std::runtime_error("Failed to load texture: " + filename);
   } else {
       std::cout << "Loaded texture: " << filename << "\n";
   }
   // Calculate how many tiles we have in the tileset
   int tilesetWidth = p_tilesetTexture.getSize().x / tileSize;
   int tilesetHeight = p_tilesetTexture.getSize().y / tileSize;

   // Automatically map tile types to texture rects
   for (int y = 0; y < tilesetHeight; y++) {
       for (int x = 0; x < tilesetWidth; x++) {
           int tileType = y * tilesetWidth + x;

           // Create the rectangle using the constructor
           p_tileRects[tileType] = sf::IntRect(
               sf::Vector2i(x * tileSize, y * tileSize),
               sf::Vector2i(tileSize, tileSize)
           );
       }
   }

   // Assign the loaded texture and tile rects to the class members
   tileRects = p_tileRects;
   m_tilesetTexture = std::move(p_tilesetTexture);

   return p_tileRects;
}

sf::Sprite MapGenerator::getTileSprite(int tileX, int tileY) {
	// Validate tile coordinates against tilesheet dimensions
	int tilesheetWidth = m_tilesetTexture.getSize().x / m_tileSize;
	int tilesheetHeight = m_tilesetTexture.getSize().y / m_tileSize;

	if (tileX < 0 || tileX >= tilesheetWidth ||
		tileY < 0 || tileY >= tilesheetHeight) {
		std::cerr << "Invalid tile coordinates (" << tileX << "," << tileY << ")\n";
		sf::Texture texture;
		return sf::Sprite(texture); // Return empty sprite
	}

	sf::Sprite tileSprite(m_tilesetTexture);
	tileSprite.setTextureRect(sf::IntRect(
		sf::Vector2i(tileX * m_tileSize, tileY * m_tileSize),
		sf::Vector2i(m_tileSize, m_tileSize)
	));

	return tileSprite;
}


std::unordered_map<int, sf::Rect<int>> MapGenerator::getCharacters() const {
	return m_characters;
}

// not using at the moment... do not need it currently
void MapGenerator::loadTextures() {
	// Define which texture corresponds to which tile type
		std::map<int, std::string> texturePaths = {
			{0, "assets/textures/grass.png"},
			{1, "assets/textures/water.png"},
			{2, "assets/textures/item.png"},
			{3, "assets/textures/obstacle.png"},
			{4, "assets/textures/enemy.png"},
			{5, "assets/textures/npc.png"}
			// Add more as needed
	};

	for (const auto& pair : texturePaths) {
		sf::Texture texture;
		if (texture.loadFromFile(pair.second)) {
			m_tileTextures[pair.first] = texture;
		}
		else {
			std::cerr << "Failed to load texture: " << pair.second << std::endl;
			// Fallback: create a colored placeholder texture
			//sf::Image placeholder;
			//placeholder.create(32, 32, sf::Color::Magenta); // Magenta = obviously missing
			//tileTextures[pair.first].loadFromImage(placeholder);
		}
	}
}



void MapGenerator::renderMapSFML(sf::RenderWindow& window) {
	// Define tile size and spacing

	//const int tileSize = 8;  // Size of each tile in pixels
	//const int tileSpacing = 0;  // Space between tiles
	//
	//// Define colors for different tile types
	//const sf::Color grassColor(34, 139, 34);       // Green for terrain
	//const sf::Color waterColor(30, 144, 255);      // Blue for water
	//const sf::Color obstacleColor(139, 69, 19);    // Brown for obstacles
	//const sf::Color itemColor(255, 215, 0);        // Gold for items
	//const sf::Color enemyColor(220, 20, 60);       // Crimson for enemies
	//const sf::Color npcColor(138, 43, 226);        // Purple for NPCs
	//const sf::Color defaultColor(200, 200, 200);    // Gray for unknown types
	//
	//// Calculate view offset to center the map
	//sf::Vector2f viewCenter(width * (tileSize + tileSpacing) / 2.f,
	//	height * (tileSize + tileSpacing) / 2.f);
	//
	//// Create a view to center the map
	//sf::View view(viewCenter,
	//	sf::Vector2f(window.getSize().x, window.getSize().y));
	//window.setView(view);
	//
	//// Draw each tile
	//for (int y = 0; y < height; ++y) {
	//	for (int x = 0; x < width; ++x) {
	//		sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
	//		sf::Vector2f xy(x * (tileSize + tileSpacing),
	//			y * (tileSize + tileSpacing));
	//		tile.setPosition(xy);
	//
	//		// Set color based on tile value
	//		switch (map[y][x]) {
	//		case 15:  tile.setFillColor(grassColor); break;    // Terrain
	//		case 10:  tile.setFillColor(waterColor); break;    // Water
	//		case 11:  tile.setFillColor(itemColor); break;     // Items
	//		case 9:  tile.setFillColor(obstacleColor); break; // Obstacles
	//		case 13:  tile.setFillColor(enemyColor); break;    // Enemies
	//		case 14:  tile.setFillColor(npcColor); break;      // NPCs
	//			// Add more cases for your other tile types
	//		case 12: tile.setFillColor(defaultColor);
	//		}
	//
	//		// Add outline to make tiles more distinct
	//		tile.setOutlineThickness(0.5f);
	//		tile.setOutlineColor(sf::Color(50, 50, 50, 100));
	//
	//		window.draw(tile);
	//	}
	//}
	//
	//// Reset the view to default for UI elements
	//window.setView(window.getDefaultView());
	//________________________________________________________________//
	// Calculate view offset to center the map
	const int tileSize = 32;
	const int tileSpacing = 0;

	sf::Vector2f viewCenter(m_width * tileSize / 2.f, m_height * tileSize / 2.f);
	sf::View view(viewCenter, sf::Vector2f( static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y) ));
	window.setView(view);

	// Draw each tile
	sf::Sprite tileSprite(m_tilesetTexture);
	tileSprite.setTexture(m_tilesetTexture);

	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {
			int tileType = m_map[y][x];

			if (tileRects.empty()) {
				std::cerr << "Error: tileRects is empty in renderMapSFML()\n";
				return;
			}
			else if (!m_tilesetTexture.getSize().x) {
				std::cerr << "Error: tilesetTexture not loaded properly\n";
				return;
			}

			// Check if the tile type exists in the map
			

			// Set the texture rectangle for this tile type
			if (tileRects.find(tileType) != tileRects.end()) {
				tileSprite.setTextureRect(tileRects[tileType]);
				//std::cout << tileType;
			}
			else {
				// Default to first tile if type not found
				tileSprite.setTextureRect(tileRects.begin()->second);
				std::cerr << "Tile type not found: " << tileType << std::endl;
			}

			// Position the sprite
			tileSprite.setPosition({ static_cast<float>(x * tileSize), static_cast<float>(y * tileSize )});
			window.draw(tileSprite);
			
		}
	}

	window.setView(window.getDefaultView());
}



//__________________________________________________________________________//
//__________________________________________________________________________//
//__________________________________________________________________________//

void MapGenerator::generateTerrain() {
	// Implementation for generating terrain
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			//assign terrain based on the appropriate tile
			m_map[i][j] = 608;
			//map[i][j] = rand() % 2; // Randomly assign terrain type (0 or 1)
		}
	}
	std::cout << "Terrain generated." << std::endl;
	// Example: 0 for grass, 1 for water
}
void MapGenerator::generateObstacles() {
	// Implementation for generating obstacles
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 2) { // 20% chance to place an obstacle
				m_map[i][j] = 609; // Assign obstacle type
			}
		}
	}
	std::cout << "Obstacles generated." << std::endl;
}
void MapGenerator::generateItems() {
	// Implementation for generating items
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 3) { // 30% chance to place an item
				m_map[i][j] = 610; // Assign item type
			}
		}
	}
	std::cout << "Items generated." << std::endl;
}
void MapGenerator::generateEnemies() {
	// Implementation for generating enemies
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 5) { // 50% chance to place an enemy
				m_map[i][j] = 612; // Assign enemy type
			}
		}
	}
	std::cout << "Enemies generated." << std::endl;
}
void MapGenerator::generateNPCs() {
	// Implementation for generating NPCs
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 4) { // 40% chance to place an NPC
				m_map[i][j] = 611; // Assign NPC type
			}
		}
	}
	std::cout << "NPCs generated." << std::endl;
}
void MapGenerator::generateQuests() {
	// Implementation for generating quests
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 6) { // 60% chance to place a quest
				m_map[i][j] = 6; // Assign quest type
			}
		}
	}
	std::cout << "Quests generated." << std::endl;
}
void MapGenerator::generateEvents() {
	// Implementation for generating events
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 7) { // 70% chance to place an event
				m_map[i][j] = 7; // Assign event type
			}
		}
	}
	std::cout << "Events generated." << std::endl;
}
void MapGenerator::generateWeather() {
	// Implementation for generating weather
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 8) { // 80% chance to place a weather effect
				m_map[i][j] = 8; // Assign weather type
			}
		}
	}
	std::cout << "Weather generated." << std::endl;
	
}
void MapGenerator::generateDayNightCycle() {
	// Implementation for generating day/night cycle
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 9) { // 90% chance to place a day/night cycle
				m_map[i][j] = 9; // Assign day/night type
			}
		}
	}
	std::cout << "Day/Night cycle generated." << std::endl;
}
void MapGenerator::generateLore() {
	// Implementation for generating lore
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 1) { // 10% chance to place lore
				m_map[i][j] = 10; // Assign lore type
			}
		}
	}
	std::cout << "Lore generated." << std::endl;
}
void MapGenerator::generateMusic() {
	// Implementation for generating music
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 2) { // 20% chance to place music
				m_map[i][j] = 11; // Assign music type
			}
		}
	}
	std::cout << "Music generated." << std::endl;
}
void MapGenerator::generateSoundEffects() {
	// Implementation for generating sound effects
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 3) { // 30% chance to place sound effects
				m_map[i][j] = 12; // Assign sound effect type
			}
		}
	}
	std::cout << "Sound effects generated." << std::endl;
}
void MapGenerator::generateGraphics() {
	// Implementation for generating graphics
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 4) { // 40% chance to place graphics
				m_map[i][j] = 13; // Assign graphic type
			}
		}
	}
	std::cout << "Graphics generated." << std::endl;
}
void MapGenerator::generateAnimations() {
	// Implementation for generating animations
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 5) { // 50% chance to place animations
				m_map[i][j] = 14; // Assign animation type
			}
		}
	}
	std::cout << "Animations generated." << std::endl;
}
void MapGenerator::generateUserInterface() {
	// Implementation for generating user interface
	for (int i = 0; i < m_height; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (rand() % 10 < 6) { // 60% chance to place user interface
				m_map[i][j] = 15; // Assign UI type
			}
		}
	}
	std::cout << "User interface generated." << std::endl;
}



//_______________________________________________________________________//
//_______________________________________________________________________//
//_______________________________________________________________________//



void MapGenerator::saveMapToFile(const std::string& filename) {
	std::ofstream file(filename);
	if (file.is_open()) {
		file << m_width << " " << m_height << std::endl;
		for (int i = 0; i < m_height; ++i) {
			for (int j = 0; j < m_width; ++j) {
				file << m_map[i][j] << " ";
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
		file >> m_width >> m_height;
		deleteMap();
		initializeMap();
		for (int i = 0; i < m_height; ++i) {
			for (int j = 0; j < m_width; ++j) {
				file >> m_map[i][j];
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
	this->m_width = width;
	this->m_height = height;
	initializeMap();
}
void MapGenerator::setMapTile(int x, int y, int value) {
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
		m_map[y][x] = value;
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
	}
}
int MapGenerator::getMapTile(int x, int y) {
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
		return m_map[y][x];
	}
	else {
		std::cerr << "Invalid tile coordinates." << std::endl;
		return -1; // or some other error value
	}
}
void MapGenerator::setMapTileType(int x, int y, const std::string& type) {
	// Implementation for setting tile type
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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

	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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

	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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

	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
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
