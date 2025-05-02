#include "../headers/GameEngine.h"



GameEngine::GameEngine(sf::VideoMode& vm, sf::RenderWindow& window) 
	: Engine(), m_frameRate(60.0f), m_width(800), m_height(600),
	m_initialized(false), m_window(window), m_vm(vm) // Initialize the window member variable
{
	 // Initialize the window member variable
	// Default constructor implementation
	std::cout << "GameEngine created with default settings." << std::endl;
	m_initialized = false; // Set the initialized flag to false
	m_window.create(vm, "GameEngine Window"); // Create a window with the specified video mode and title
	//m_window = sf::RenderWindow(vm, "GameEngine Window");
	initialize();
	start();
	render();
	// Set default background color
	//m_window.clear(sf::Color(0, 0, 0)); // Black background
	//m_window.display(); // Display the window contents

	 

}


GameEngine::~GameEngine() = default;

void GameEngine::initialize() {

	// Initialize the engine

	// Additional initialization logic if needed
	m_initialized = true; // Set the initialized flag to true
	if (!m_initialized) {
		throw std::runtime_error("GameEngine initialization failed.");
	}else {
		std::cout << "GameEngine initialized successfully." << std::endl;
	}

	m_State = State::RUNNING;

	m_time = 0.0f; // Initialize time
	m_deltaTime = 0.0f; // Initialize delta time
	m_frameTime = 0.0f; // Initialize frame time
	m_frameCount = 0; // Initialize frame count
	m_fps = 0.0f; // Initialize FPS
	m_lastFrameTime = 0.0f; // Initialize last frame time
	m_currentFrameTime = 0.0f; // Initialize current frame time
}
void GameEngine::start(){
	
	// Start the engine, i.e. time 
	// Set the game state to RUNNING
	m_State = State::RUNNING; // Set the game state to RUNNING
	// Initialize the game state
	std::cout << "GameEngine started." << std::endl;
	
	std::time_t t = std::time(nullptr); // Get the current time
	std::tm tm;
	m_time = static_cast<float>(std::difftime(t, 0)); // Calculate time since epoch
    if (localtime_s(&tm, &t) != 0) {
		
        std::cerr << "Failed to convert time to local time." << std::endl;
        return;
    }
	std::cout << "engine time: " << m_time;
	std::cout << "Current time: " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << std::endl; // Print the current time

	
}
void GameEngine::stop(){
	// Stop the engine
	std::cout << "GameEngine stopped." << std::endl;
	// Additional stop logic if needed
	// Example of using the player class with quest class and equipment class
	
}
sf::RenderWindow& GameEngine::getWindow() {
	return m_window;

};

///// ////	////	////	//////	////	///	/	/	/	//////	/////	/////	///


/// <summary>
/// 
/// </summary>
/// <param name="vm"></param>
/// <param name="window"></param>

void GameEngine::run()  {
	//open window
	//sf::RenderWindow window(sf::VideoMode(vm.width, vm.height), "GameEngine Window");
	// Set the window properties
	m_window.setFramerateLimit(60); // Set frame rate limit
	m_window.setVerticalSyncEnabled(true); // Enable VSync
	m_window.setMouseCursorVisible(true); // Show mouse cursor
	m_window.setMouseCursorGrabbed(false); // Don't grab mouse cursor

	MapGenerator mapGen(100, 100);//mapgenerator function is called in constructor
	mapGen.displayMap();
	m_maps.push_back(mapGen); // Add the map to the maps vector

	//-load texture to player1 using file and tile number
	
	sf::Sprite player_Sprite = mapGen.getTileSprite(15, 60);
	sf::Sprite wizard_Sprite = mapGen.getTileSprite(0, 60);
	sf::Sprite armored_devil_troll_Sprite = mapGen.getTileSprite(1, 60);
	sf::Sprite yellow_dragon_Sprite = mapGen.getTileSprite(3, 60);
	sf::Sprite Shirtless_baldy_sprite = mapGen.getTileSprite(19,61);
	sf::Sprite minotaur_with_bow = mapGen.getTileSprite(5, 59);
	sf::Sprite rock_with_eyes = mapGen.getTileSprite(16, 61);
	sf::Sprite Frog_sprite = mapGen.getTileSprite(56, 62);

	player player1(1, 50,50,32,32,100,5, player_Sprite);
	player1.setPlayerName("Hero");
	player1.setPlayerClass("Warrior");
	player1.setGold(100);
	player1.setManaPotions(5);
	player1.setHealthPotions(3);
	player1.setExperiencePoints(0);
	player1.setLevel(1);
	player1.setActive(true);


	Enemy minotaur(5, 300, 450, 32, 32, 100, 5, minotaur_with_bow);
	Enemy rockEyes(5, 300, 50, 432, 32, 100, 5, rock_with_eyes);
	Enemy frog(5, 300, 150, 132, 32, 100, 5, Frog_sprite);
	Enemy shirtless_bald_guy(5, 300, 50, 32, 32, 100, 5, Shirtless_baldy_sprite);
	Enemy wizard(1, 50, 50, 32, 32, 100, 5, wizard_Sprite);
	Enemy armored_devil_troll(2, 100, 100, 32, 32, 100, 5, armored_devil_troll_Sprite);
	Enemy yellow_dragon(3, 250, 250, 32, 32, 100, 5, yellow_dragon_Sprite);
	m_enemies.push_back(wizard);
	m_enemies.push_back(armored_devil_troll);
	m_enemies.push_back(yellow_dragon);
	m_enemies.push_back(minotaur);
	m_enemies.push_back(rockEyes);
	m_enemies.push_back(frog);

	GameState currentGameState = {
		0, // ID
		m_clock, // clock
		m_time, // time
		m_deltaTime, // deltaTime
		m_frameTime, // frameTime
		m_fps, // fps
		m_lastFrameTime, // lastFrameTime
		m_currentFrameTime, // currentFrameTime
		m_initialized, // initialized
		m_width, // width
		m_height, // height
		m_frameRate, // frameRate
		m_window, // Initialize window 
		player(0, 0, 0, 32, 32, 100, 10, player1.getSprite()), // player object
		m_enemies, // enemies
		m_maps, // maps 
		m_lootableItems, // lootableItems
		m_obstacles, // obstacles
		m_walls // walls
	};

	// Main loop of the engine
	while (m_window.isOpen()) {
		
		while (m_State == State::RUNNING) {
			currentGameState.currentFrameTime = static_cast<float>(clock()) / CLOCKS_PER_SEC; // Get the current time
			currentGameState.deltaTime = m_currentFrameTime - m_lastFrameTime; // Calculate delta time
			currentGameState.lastFrameTime = m_currentFrameTime; // Update last frame time
			update(m_deltaTime); // Update the game state // Handle user input


			player1.handleInput();

			m_window.clear();

			mapGen.renderMapSFML(m_window);

			m_window.draw(player1.getSprite());
			checkCollision(player1.getSprite(), wizard_Sprite);


			for (auto& enemy : m_enemies) {
				m_window.draw(enemy.getSprite());
				enemy.attack(player1);
			}



			m_window.display();


		}
		
	}
	
}

bool  GameEngine::checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
	// Check if the two sprites are colliding
	if (sprite1.getGlobalBounds() == sprite2.getLocalBounds()) {
		std::cout << "Collision detected!" << std::endl;
		return true; // Collision detected
	}
	std::cout << "No collision detected." << std::endl;
	return false; // No collision
}

void GameEngine::update(float deltaTime) {
	// Update game state
	// Example delta time (60 FPS)
	m_time += deltaTime; // Update time
	m_deltaTime = deltaTime; // Update delta time
	m_frameTime = deltaTime; // Update frame time
	m_frameCount++; // Increment frame count
	if (m_frameCount >= m_frameRate) { // If frame count reaches frame rate
		m_fps = 1.0f / deltaTime; // Calculate FPS
		m_frameCount = 0; // Reset frame count
	}
	// Example update logic
	// Update game objects, physics, etc.
	// For example, update player position, check collisions, etc.


	std::cout << "Updating game state with deltaTime: " << m_time << " seconds." << std::endl;
}
void GameEngine::render() {
	// Render game graphics
	std::cout << "Rendering game graphics..." << std::endl;



}
void GameEngine::handleInput() {
	// Handle user input
	std::cout << "Handling input..." << std::endl;
	// Example input handling logic
	if (!m_initialized) {
		std::cerr << "GameEngine is not initialized. Cannot handle input." << std::endl;
		return;
	}

	// Simulate input handling
	std::cout << "Input handled successfully." << std::endl;
}
void GameEngine::cleanup() {
	// Clean up resources
	std::cout << "Cleaning up GameEngine resources..." << std::endl;


}






/// <summary>////	////	////	/////	/////	//	//	///	////	////	//















float GameEngine::getFrameRate() const  {
	return m_frameRate;
}
void GameEngine::setFrameRate(float frameRate)  {
	m_frameRate = frameRate;
}
void GameEngine::getResolution(int& width, int& height) const  {
	width = m_width;
	height = m_height;
}
void GameEngine::setResolution(int width, int height) {
	m_width = width;
	m_height = height;
}

bool GameEngine::isInitialized() const {
	return m_initialized;
}

int GameEngine::getWidth() const {
	return m_width;
}

int GameEngine::getHeight() const {
	return m_height;
}
