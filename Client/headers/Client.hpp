#pragma once

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>

class Client
{
private:
    int m_socket;
    struct sockaddr_in m_serverAddr;
public:
    Client(const std::string& serverAddress, int serverPort);
    void Connect();
    void Send(const std::string& message);
    std::string Receive();
    void Close();

    ~Client();
};
