#include "Server.h"
#include <iostream>

Server::Server(unsigned short port)
	: m_port(port), m_running(false), m_listener()  // Initialize listener
{
    if (m_listener.listen(port) != sf::Socket::Done) {
        std::cerr << "Failed to bind to port " << port << std::endl;
    }
}

Server::~Server() {
    stop();
    for (auto client : m_clients) {
        delete client;
    }
}

void Server::run() {
    m_running = true;
    m_connectionThread = std::thread(&Server::handleConnections, this);
    m_packetThread = std::thread(&Server::processPackets, this);

    std::cout << "Server running on port " << m_port << std::endl;
}

void Server::stop() {
    m_running = false;
    if (m_connectionThread.joinable()) m_connectionThread.join();
    if (m_packetThread.joinable()) m_packetThread.join();
    m_listener.close();
}

void Server::handleConnections() {
    while (m_running) {
        sf::TcpSocket* client = new sf::TcpSocket;
        if (m_listener.accept(*client) == sf::Socket::Done) {
            m_clients.push_back(client);
            std::cout << "New client connected: "
                << client->getRemoteAddress() << std::endl;

            // Send initial game state to new client
            sf::Packet welcomePacket;
            welcomePacket << "Welcome to the game server!";
            client->send(welcomePacket);
        }
        else {
            delete client;
        }
    }
}

void Server::processPackets() {
    while (m_running) {
        for (size_t i = 0; i < m_clients.size(); ++i) {
            sf::TcpSocket& client = *m_clients[i];
            sf::Packet packet;

            if (client.receive(packet) == sf::Socket::Done) {
                // Handle client input
                std::string message;
                if (packet >> message) {
                    std::cout << "Received: " << message << std::endl;

                    // Broadcast to all clients
                    for (auto& otherClient : m_clients) {
                        otherClient->send(packet);
                    }
                }
            }
            else if (client.receive(packet) == sf::Socket::Disconnected) {
                std::cout << "Client disconnected: "
                    << client.getRemoteAddress() << std::endl;
                delete m_clients[i];
                m_clients.erase(m_clients.begin() + i);
                --i;
            }
        }

        // Broadcast game state periodically
        broadcastGameState();
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60fps
    }
}

void Server::broadcastGameState() {
    // Create a packet with current game state
    sf::Packet gameStatePacket;
    // gameStatePacket << playerPositions << enemyStates << etc...

    for (auto& client : m_clients) {
        client->send(gameStatePacket);
    }
}