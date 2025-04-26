#include "client.h"
#include <iostream>


client::client() 
	: m_connected(false), m_serverPort(0), m_State(State::STOPPED),
	m_serverAddress(sf::IpAddress::Any)
{
	m_socket.setBlocking(false);
	m_serverPort = 0;
	m_connected = false;
	m_State = State::STOPPED;


};
client::~client() {
	if (m_connected) {
		disconnect();
	}
	m_socket.disconnect();
	m_socket.setBlocking(false);
	m_serverPort = 0;
	m_connected = false;
	m_State = State::STOPPED;
};
bool client::connect(const sf::IpAddress& serverAddress, unsigned short port){
	m_serverAddress = serverAddress;
	m_serverPort = port;
	if (m_socket.connect(serverAddress, port) != sf::Socket::Done) {
		std::cerr << "Failed to connect to server at "
			<< serverAddress.toString() << ":" << port << std::endl;
		m_connected = false;
		return false;
	}
	m_socket.setBlocking(false);
	m_connected = true;
	std::cout << "Connected to server at "
		<< serverAddress.toString() << ":" << port << std::endl;
	return true;
};
void client::disconnect() {
	if (m_connected) {
		m_socket.disconnect();
		m_connected = false;
		std::cout << "Disconnected from server." << std::endl;
	}
	else {
		std::cerr << "Already disconnected from server." << std::endl;
	}
};
bool client::isConnected() const {
	return m_connected;
};
void client::sendPacket(sf::Packet& packet) {

	if (m_connected) {
		if (m_socket.send(packet) != sf::Socket::Status::Done) {
			std::cerr << "Failed to send packet to server" << std::endl;
		}
	}
};
void client::receivePackets() {
	if (!m_connected) return;

	sf::Packet packet;
	while (m_socket.receive(packet) == sf::Socket::Status::Done) {
		// Process received packet
		handlePacket(packet);
	}
};

void client::handlePacket(sf::Packet& packet) {
	std::uint8_t packetType;
	if (!(packet >> packetType)) {
		std::cerr << "Failed to read packet type" << std::endl;
		return;
	}

	switch (static_cast<PacketType>(packetType)) {
	case PacketType::GameState:
		handleGameStatePacket(packet);
		break;
		// Handle other packet types...
	default:
		std::cerr << "Unknown packet type: " << static_cast<int>(packetType) << std::endl;
	}
}

void client::handleGameStatePacket(sf::Packet& packet) {
	// Deserialize game state from packet
	// Update local game state with server's authoritative state

};

auto client::processLocalInput(const GameEngine& engine) {
	// Process local input and update the input state
	InputState input;

	// Reset input state
	input.moveUp = false;
	input.moveDown = false;
	input.moveLeft = false;
	input.moveRight = false;
	input.jump = false;
	input.attack = false;
	input.special = false;

	// Keyboard input (WASD or Arrow keys)
	input.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	input.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	input.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	input.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);

	// Action buttons
	input.jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	input.attack = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J);  // Example attack button
	input.special = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K); // Example special ability

	// Mouse input
	input.fire = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	input.altFire = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

	// Get mouse position relative to the window
	sf::Vector2i mousePos = sf::Mouse::getPosition(engine.getWindow()); // Assuming you have a window pointer
	input.aimX = mousePos.x;
	input.aimY = mousePos.y;

	// Joystick support (optional)
	if (sf::Joystick::isConnected(0)) { // Check first joystick
		// Movement (left stick)
		float axisX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float axisY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

		// Apply deadzone
		const float deadzone = 25.f;
		if (std::abs(axisX) > deadzone) {
			if (axisX < -deadzone) input.moveLeft = true;
			if (axisX > deadzone) input.moveRight = true;
		}
		if (std::abs(axisY) > deadzone) {
			if (axisY < -deadzone) input.moveUp = true;
			if (axisY > deadzone) input.moveDown = true;
		}

		// Buttons
		input.jump = input.jump || sf::Joystick::isButtonPressed(0, 0); // A button
		input.attack = input.attack || sf::Joystick::isButtonPressed(0, 2); // X button
		input.special = input.special || sf::Joystick::isButtonPressed(0, 3); // Y button
	}

	return input;
}


client::PlayerState client::predictMovement(const PlayerState& state, const InputState& input) {
	PlayerState predictedState = state;
	// Apply input to predicted state (pseudo-code)
	if (input.moveUp) {
		predictedState.y -= 1.0f; // Move up
	}
	if (input.moveDown) {
		predictedState.y += 1.0f; // Move down
	}
	if (input.moveLeft) {
		predictedState.x -= 1.0f; // Move left
	}
	if (input.moveRight) {
		predictedState.x += 1.0f; // Move right
	}
	return predictedState;
};
void client::reconcileStates() {
	// Compare predicted state with server state and reconcile
	// Example: If the server state is different, adjust the local state
	if (m_serverPlayerStateReceived) {
		// Reconcile logic here
	}
};
void client::sendInputToServer(const InputState& input) {
	sf::Packet packet;
	packet << static_cast<std::uint8_t>(PacketType::PlayerInput);
	packet << input.moveUp << input.moveDown << input.moveLeft << input.moveRight;
	sendPacket(packet);
};

void client::update(const GameEngine& engine) {
	// 1. Process local input
	InputState input = processLocalInput(engine);

	// 2. Apply input to local player (prediction)
	m_localPlayerState = predictMovement(m_localPlayerState, input);

	// 3. Send input to server
	sendInputToServer(input);

	// 4. Receive and apply server updates
	receivePackets();

	// 5. Reconcile predicted state with server state
	if (m_serverPlayerStateReceived) {
		reconcileStates();
	}
}