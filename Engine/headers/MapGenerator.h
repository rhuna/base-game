#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H


#if defined(_WIN64)  
	#include <SFML/Graphics.hpp>  // Adjusted to use the default include path for Windows 64-bit
	//#include <../../../SFML/x64/include/SFML/Graphics.hpp>  
#elif defined(__APPLE__) || defined(__MACH__)  
	#include <SFML/Graphics.hpp> // Adjusted to use the default include path for macOS  
#elif defined(__linux__)  
	#include <../../../SFML/x86_64-unknown-linux-gnu/include/SFML/Graphics.hpp>  
#elif defined(_WIN32)  
	#include <SFML/Graphics.hpp>	
	//#include <../../../SFML/x86/include/SFML/Graphics.hpp>
#else
	#error "Unsupported platform. Please adjust the include paths for your system."
#endif



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class MapGenerator{



public:
	MapGenerator();
	MapGenerator(int width, int height);
	MapGenerator(const MapGenerator& other);
	MapGenerator& operator=(const MapGenerator& other);
	MapGenerator(MapGenerator&& other) noexcept;
	~MapGenerator();
	void generateMap(int width, int height);
	void renderMapSFML(sf::RenderWindow& window);
	void displayMap();
	void saveMapToFile(const std::string& filename);
	void loadMapFromFile(const std::string& filename);
	void setMapSize(int width, int height);
	void setMapTile(int x, int y, int value);
	int getMapTile(int x, int y);
	void setMapTileType(int x, int y, const std::string& type);
	std::string getMapTileType(int x, int y);
	void setMapTileProperties(int x, int y, const std::string& properties);
	std::string getMapTileProperties(int x, int y);
	void setMapTileEvent(int x, int y, const std::string& event);
	std::string getMapTileEvent(int x, int y);
	void setMapTileNPC(int x, int y, const std::string& npc);
	std::string getMapTileNPC(int x, int y);
	void loadTextures();
	sf::Sprite getTileSprite(int tileX, int tileY);
	std::unordered_map<int, sf::Rect<int>> getCharacters() const;
	std::unordered_map<int, sf::Rect<int>> loadTileset(const std::string& filename, int tilesize);
	//void loadTileset(const std::string& filename, int tilesize);
	std::unordered_map<int, sf::Rect<int>> tileRects;
	
	
private:

	int** map;
	int width;
	int height;
	int tileSize;
	std::map<int, sf::Texture> tileTextures;
	sf::Texture tilesetTexture;
	std::unordered_map<int, sf::Rect<int>> characters;
	void initializeMap();
	void deleteMap();
	void generateTerrain();
	void generateObstacles();
	void generateItems();
	void generateEnemies();
	void generateNPCs();
	void generateQuests();
	void generateEvents();
	void generateWeather();
	void generateDayNightCycle();
	void generateLore();
	void generateMusic();
	void generateSoundEffects();
	void generateGraphics();
	void generateAnimations();
	void generateUserInterface();
};



#endif // !MAPGENERATOR_H


