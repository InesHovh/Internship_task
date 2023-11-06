#include "../headers/Server.hpp"

Server::Server(int port) : m_port(port), m_socket(-1) {
    // m_driver = sql::mysql::get_mysql_driver_instance();

    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket == -1) {
        std::cout << "Failed to create a socket" << std::endl;
        exit(1);
    }
    
    m_sockaddr.sin_family = AF_INET;
    m_sockaddr.sin_port = htons(port);
    m_sockaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(m_socket, (const sockaddr*)&m_sockaddr, sizeof(sockaddr)) == -1) {
        std::cout << "Failed to bind" << std::endl;
        close(m_socket);
        exit(1);
    }
    
    if (listen(m_socket, 5) == -1) {
        std::cout << "Failed to listen" << std::endl;
        close(m_socket);
        exit(1);
    }
    else {
        std::cout << "Server is listening " << port << std::endl;
    }
}

void Server::Start() {
    while (1) {
        int clientSocket;
        sockaddr_in clientAddr;
        socklen_t clientAddrSize = sizeof(clientAddr);

        clientSocket = accept(m_socket, (sockaddr*)&clientAddr, &clientAddrSize);
        if (clientSocket == -1) {
            std::cout << "Failed to accept" << std::endl;
            continue;
        }

        std::cout << "Client connected." << std::endl;

        m_clients.push_back(clientSocket);
        std::thread clientThread(&Server::ClientHandling, this, clientSocket);
        clientThread.detach();
    }
}


void Server::ClientHandling(int clientSocket) {
    char buffer[4096];
    
    while (true) {
        int rec = recv(clientSocket, buffer, sizeof(buffer), 0);
        
        if (rec == -1) {
            std::cout << "Failed to receive data from the client" << std::endl;
            break;
        } else if (rec == 0) {
            std::cout << "Client disconnected" << std::endl;
            break;
        } else {
            buffer[rec] = '\0';
            std::cout << "Received: " << buffer << std::endl;

            std::string response = "Hello, client!";

            int sent = send(clientSocket, response.c_str(), response.length(), 0);
            if (sent == -1) {
                std::cout << "Failed to send a response" << std::endl;
            } else {
                std::cout << "Response sent: " << response << std::endl;
            }
        }
    }

    close(clientSocket);
}


void Server::SendingMessages(const std::string& message) {
    std::lock_guard<std::mutex> lock(m_mutex);

    for (int clientSocket : m_clients) {
        int sent = send(clientSocket, message.c_str(), message.length(), 0);
        if (sent == -1) {
            std::cout << "Failed to send a message to a client" << std::endl;
        } else {
            std::cout << "Message sent to a client: " << message << std::endl;
        }
    }
}


void Server::Close()
{
    if (m_socket != -1){
        close(m_socket);
        m_socket = -1;
    }
}


Server::~Server() {
    Close();
}

void Server::ServerCommandListener() {
    while (true) {
        std::string command;
        std::getline(std::cin, command);
        SendingMessages(command);
    }
}

int main() {
    Server server(8080);

    std::thread serverThread(&Server::Start, &server);
    serverThread.detach();

    std::thread commandListener(&Server::ServerCommandListener, &server);
    commandListener.detach();

    while (true) {
        std::string message;
        std::cout << "Enter a message to send to client: " << std::endl;;
        std::getline(std::cin, message);
        server.SendingMessages(message);
    }

    server.Close();

    return 0;
}