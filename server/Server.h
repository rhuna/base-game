#ifndef SERVER_H
#define SERVER_H

#if defined(_WIN64)  
#include <SFML/Graphics.hpp>  // Adjusted to use the default include path for Windows 64-bit
#include <SFML/Network.hpp>
//#include <../../../SFML/x64/include/SFML/Graphics.hpp>  
#elif defined(__APPLE__) || defined(__MACH__)  
#include <SFML/Graphics.hpp> // Adjusted to use the default include path for macOS  
#elif defined(__linux__)  
#include <../../../SFML/x86_64-unknown-linux-gnu/include/SFML/Graphics.hpp>  
#elif defined(_WIN32) 
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
//#include <../../../SFML/x86/include/SFML/Graphics.hpp>
#else
#error "Unsupported platform. Please adjust the include paths for your system."
#endif

#include <vector>
#include <thread>
#include <atomic>

class Server{
public:

    Server(unsigned short port);
    ~Server();

    void run();
    void stop();

private:
    void handleConnections();
    void processPackets();
    void broadcastGameState();

    sf::TcpListener m_listener;
    std::vector<sf::TcpSocket*> m_clients;
    std::thread m_connectionThread;
    std::thread m_packetThread;
    std::atomic<bool> m_running;
    unsigned short m_port;

};



#endif // !SERVER_H



