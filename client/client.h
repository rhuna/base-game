#ifndef CLIENT_H
#define CLIENT_H
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>


// Forward declaration
class GameEngine;

struct InputState {
    bool moveUp;
    bool moveDown;
    bool moveLeft;
    bool moveRight;
    bool jump;
    bool attack;
    bool special;
    bool fire;
    bool altFire;
    int aimX;
    int aimY;
    // Add other input states
};

struct PlayerState {
    float x, y;
    // Other player properties
};

class client{
private:
    sf::TcpSocket m_socket;
    sf::IpAddress m_serverAddress;
    unsigned short m_serverPort;
    bool m_connected;
	sf::Packet m_packet;
    bool m_serverPlayerStateReceived;
    PlayerState m_serverPlayerState;

public:
    enum class PacketType : std::uint8_t {
        GameState,
        PlayerInput,
        ChatMessage,
        // Add more as needed
    };

    
    PlayerState m_localPlayerState;

	client();
	~client();
	float lerp(float a, float b, float t);
    void update(GameEngine& engine);
    bool connect(const sf::IpAddress& serverAddress, unsigned short port);
    void disconnect();
    bool isConnected() const;
    void sendPacket(sf::Packet& packet);
    void receivePackets();
	void handlePacket(sf::Packet& packet);
	void handleGameStatePacket(sf::Packet& packet);
    InputState processLocalInput(GameEngine& engine);
	void reconcileStates();
    void sendInputToServer(const InputState& input);

    PlayerState predictMovement(const PlayerState& state, const InputState& input);

	enum class State {
		STOPPED,
		RUNNING,
		INITIALIZING,
		RENDERING
	};
	State m_State;
	
};



#endif // !CLIENT_H


