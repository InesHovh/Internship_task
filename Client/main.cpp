#include <iostream>
#include "headers/Client.hpp"
#include <cstring>

int main() {
    Client client("127.0.0.1", 8080);

    client.Connect();

    while (true) {
        std::string message;
        memset((void*)message.c_str(), 0, sizeof(message));
        std::cout << "Enter a message to send to the server (or 'exit' to quit): ";
        std::getline(std::cin, message);

        if (message == "exit") {
            break;
        }

        client.Send(message);

        std::string response = client.Receive();
        if (!response.empty()) {
            std::cout << "Received from the server: " << response << std::endl;
        }
    }

    client.Close();

    return 0;
}
