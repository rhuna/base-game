#include "../headers/GameEngine.h"



GameEngine::GameEngine(sf::RenderWindow& window) 
	: Engine(), m_frameRate(60.0f), m_width(800), m_height(600),
	m_initialized(false), m_window(window) // Initialize the window member variable
{
	 // Initialize the window member variable
	// Default constructor implementation
	std::cout << "GameEngine created with default settings." << std::endl;
	m_initialized = false; // Set the initialized flag to false
	sf::VideoMode vm({ static_cast<unsigned int>(m_width), static_cast<unsigned int>(m_height) });
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

	m_gameState = GameState::RUNNING;
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
	m_gameState = GameState::RUNNING; // Set the game state to RUNNING
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

	//-load texture to player1 using file and tile number
	
	sf::Sprite player_Sprite = mapGen.getTileSprite(4, 60);
	sf::Sprite wizard_Sprite = mapGen.getTileSprite(0, 60);
	sf::Sprite armored_devil_troll_Sprite = mapGen.getTileSprite(1, 60);
	sf::Sprite yellow_dragon_Sprite = mapGen.getTileSprite(3, 60);


	player player1(1, 50,50,32,32,100,5, player_Sprite);
	player1.setPlayerName("Hero");
	player1.setPlayerClass("Warrior");
	player1.setGold(100);
	player1.setManaPotions(5);
	player1.setHealthPotions(3);
	player1.setExperiencePoints(0);
	player1.setLevel(1);
	player1.setActive(true);

	Enemy wizard(1, 50, 50, 32, 32, 100, 5, wizard_Sprite);
	Enemy armored_devil_troll(2, 100, 100, 32, 32, 100, 5, armored_devil_troll_Sprite);
	Enemy yellow_dragon(3, 250, 250, 32, 32, 100, 5, yellow_dragon_Sprite);

	//sf::RectangleShape playerShape(sf::Vector2f(static_cast<float>(player1.getWidth()), static_cast<float>(player1.getHeight())));
	//playerShape.setPosition({ static_cast<float>(player1.getX()), static_cast<float>(player1.getY())});
	//playerShape.setFillColor(sf::Color::Red); // Set player color

	// Main loop of the engine
	while (m_window.isOpen()) {
	
		

		while (m_gameState == GameState::RUNNING) {
			m_currentFrameTime = static_cast<float>(clock()) / CLOCKS_PER_SEC; // Get the current time
			m_deltaTime = m_currentFrameTime - m_lastFrameTime; // Calculate delta time
			m_lastFrameTime = m_currentFrameTime; // Update last frame time
			update(m_deltaTime); // Update the game state
			//render(); // Render the game state
			//handleInput(); // Handle user input
			//cleanup(); // Clean up resources






			wizard.attack(player1); // Attack the player
			armored_devil_troll.attack(player1); // Attack the player
			yellow_dragon.attack(player1); // Attack the player

			player1.handleInput();
			m_window.clear();



			mapGen.renderMapSFML(m_window);

			m_window.draw(player1.getSprite());
			m_window.draw(wizard.getSprite()); // Draw the wizard sprite -- works
			m_window.draw(armored_devil_troll.getSprite()); // Draw the armored devil troll sprite
			m_window.draw(yellow_dragon.getSprite()); // Draw the yellow dragon sprite



			m_window.display();


		}
		
	}
	
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
