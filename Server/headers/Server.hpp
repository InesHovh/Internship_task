#pragma once

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <vector>
#include <mutex>
#include <thread>
#include <unistd.h>

class Server
{
private:
    int m_port;
    int m_socket;
    struct sockaddr_in m_sockaddr;
    std::vector<int> m_clients;
    std::mutex m_mutex;
public:
    // Server();
    Server(int port);

    void Start();
    void ClientHandling(int clientSocket);
    void SendingMessages();
    void Close();

    ~Server();
};

