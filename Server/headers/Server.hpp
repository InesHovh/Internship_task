#pragma once

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <vector>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <chrono>
// #include <mysql_driver.h>
// #include <mysql_connection.h>


class Server
{
private:
    int m_port;
    int m_socket;
    struct sockaddr_in m_sockaddr;
    std::vector<int> m_clients;
    std::mutex m_mutex;

    // sql::mysql::MySQL_Driver *m_driver;

public:
    // Server();
    Server(int port);

    void Start();
    void ClientHandling(int clientSocket);
    void SendingMessages(const std::string& message);
    void ServerCommandListener();
    void Close();

    ~Server();
};

