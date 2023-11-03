#include "../headers/Client.hpp"

Client::Client(const std::string& serverAddress, int serverPort) : m_socket(-1)
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket == -1) {
        std::cout << "Failed to create a socket" << std::endl;
        exit(1);
    }

    m_serverAddr.sin_family = AF_INET;
    m_serverAddr.sin_port = htons(serverPort);
    m_serverAddr.sin_addr.s_addr = inet_addr(serverAddress.c_str());
}

void Client::Connect()
{
    if (connect(m_socket, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) == -1) {
        std::cout << "Failed to connect to the server" << std::endl;
        close(m_socket);
        exit(1);
    }
    else {
        std::cout << "Connected to the server" << std::endl;
    }
}

void Client::Send(const std::string& message)
{
    int sent = send(m_socket, message.c_str(), message.length(), 0);
    if (sent == -1) {
        std::cout << "Failed to send data" << std::endl;
    }
}

std::string Client::Receive()
{
    char buffer[4096];
    int rec = recv(m_socket, buffer, sizeof(buffer), 0);

    if (rec == -1) {
        std::cout << "Failed to receive data from the server" << std::endl;
        return "";
    } else if (rec == 0) {
        std::cout << "Server disconnected" << std::endl;
        return "";
    } else {
        buffer[rec] = '\0';
        return std::string(buffer);
    }
}

void Client::Close()
{
    if (m_socket != -1) {
        close(m_socket);
        m_socket = -1;
    }
}

Client::~Client()
{
    Close();
}

