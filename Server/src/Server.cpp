#include "../headers/Server.hpp"

Server::Server(int port) : m_port(port), m_socket(-1) {
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
            std::cout << "Failed to acceptn" << std::endl;
            continue;
        }
        std::thread clientThread(&Server::ClientHandling, this, clientSocket);
        clientThread.detach();
    }
}

void Server::ClientHandling(int clientSocket) {
    char buffer[4096];
    int read = recv(clientSocket, buffer, sizeof(buffer), 0);
    
    if (read == -1) {
        std::cout << "Failed to receive data from the client" << std::endl;
    } else if (read == 0) {
        std::cout << "Client disconnected" << std::endl;
    } else {
        buffer[read] = '\0';
        std::cout << "Received: " << buffer << std::endl;

        std::string response = "Hellooo!";

        int sent = send(clientSocket, response.c_str(), response.length(), 0);
        if (sent == -1) {
            std::cout << "Failed to send a response" << std::endl;
        } else {
            std::cout << "Response sent: " << response << std::endl;
        }
    }

    close(clientSocket);
}


void Server::SendingMessages() {
    std::string message = "Server message to client";
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
