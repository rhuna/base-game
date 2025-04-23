#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
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
	sf::Texture& getTexture(const char* filename, int tileNumber);
	std::unordered_map<int, sf::IntRect> loadTileset(const std::string& filename, int tilesize);
	
private:

	int** map;
	int width;
	int height;
	int tileSize = 32;
	std::map<int, sf::Texture> tileTextures;
	sf::Texture tilesetTexture;
	std::unordered_map<int, sf::Rect<int>> tileRects;
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


