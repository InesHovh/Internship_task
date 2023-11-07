#include "../headers/HTTP.hpp"

using boost::asio::ip::tcp;

void HTTP::Create() const{
    boost::asio::io_context io_context;

    tcp::socket socket(io_context);

    tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 5432);
    socket.connect(endpoint);

    std::cout << "Connection..." << std::endl;

    socket.close();
}

void HTTP::Read() const{
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("https://example.com:/resource", "8080");
    
    boost::asio::connect(socket, endpoints);

    std::string req = "GET /data HTTP/1.1\r\nHost: https://example.com/resource\r\n\r\n";

    std::cout << boost::asio::write(socket, boost::asio::buffer(req)) << std::endl;

    socket.close();
}

void HTTP::Update() const{
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("https://example.com/resource", "8080");

    boost::asio::connect(socket, endpoints);

    std::string req = "PUT HTTP/1.1\r\nHost: api.example.com\r\n\r\n";

    boost::asio::write(socket, boost::asio::buffer(req));

    socket.close();
}

void HTTP::Delete() const{
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("https://example.com/resource", "8080");

    boost::asio::connect(socket, endpoints);

    std::string req = "DELETE HTTP/1.1\r\nHost: https://example.com/resource\r\n\r\n";

    boost::asio::write(socket, boost::asio::buffer(req));
    socket.close();
}


int main(){

    HTTP http;

    http.Create();
    http.Read();
    http.Update();
    http.Delete();

    std::cout << "Hello" << std::endl;
}