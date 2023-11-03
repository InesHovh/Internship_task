#include <iostream>
#include "headers/Server.hpp"
#include <thread>
#include <chrono>

int main() {
    Server server(8080);

    std::thread serverThread(&Server::Start, &server);
    serverThread.detach();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        server.SendingMessages();
    }

    return 0;
}
