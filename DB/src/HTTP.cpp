#include "../headers/HTTP.hpp"

using boost::asio::ip::tcp;

void HTTP::Create() const{
    try
    {
        boost::asio::io_context io_context;

        tcp::socket socket(io_context);

        tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 5432);
        // std::cout << "***********************" << std::endl;
        socket.connect(endpoint);
        std::cout << "Connection..." << std::endl;

        socket.close();
    } catch(const boost::wrapexcept<boost::system::system_error>& e)
    {
        std::cerr << "Boost.Asio system error in Create: " << e.what() << std::endl;
        std::cerr << "Error code: " << e.code() << std::endl;
    }
}

void HTTP::Read() const{
    try
    {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("www.google.com", "443");
        
        boost::asio::connect(socket, endpoints);

        std::string req = "GET /data HTTP/1.1\r\nHost: www.google.com\r\n\r\n";

        std::cout << boost::asio::write(socket, boost::asio::buffer(req)) << std::endl;

        socket.close();
    } catch(const boost::wrapexcept<boost::system::system_error>& e)
    {
        std::cerr << "Boost.Asio system error in Read: " << e.what() << std::endl;
        std::cerr << "Error code: " << e.code() << std::endl;
    }
}

void HTTP::Update() const{
    try
    {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("www.google.com", "443");

        boost::asio::connect(socket, endpoints);

        std::string req = "PUT HTTP/1.1\r\nHost: api.example.com\r\n\r\n" ;

        std::cout <<  boost::asio::write(socket, boost::asio::buffer(req)) << std::endl;

        socket.close();
    } catch(const boost::wrapexcept<boost::system::system_error>& e)
    {
        std::cerr << "Boost.Asio system error in Update: " << e.what() << std::endl;
        std::cerr << "Error code: " << e.code() << std::endl;
    }
}

void HTTP::Delete() const{
    try
    {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        // std::cout << "Helloo " << std::endl;
        tcp::resolver resolver(io_context);
        // std::cout << "Helloo 11111 " << std::endl;

        tcp::resolver::results_type endpoints = resolver.resolve("www.google.com", "443");
        // std::cout << "Helloo******************** " << std::endl;


        boost::asio::connect(socket, endpoints);

        std::string req = "DELETE HTTP/1.1\r\nHost: www.google.com\r\n\r\n";

        std::cout << boost::asio::write(socket, boost::asio::buffer(req)) << std::endl;
        socket.close();
    } catch(const boost::wrapexcept<boost::system::system_error>& e)
    {
        std::cerr << "Boost.Asio system error in Delete: " << e.what() << std::endl;
        std::cerr << "Error code: " << e.code() << std::endl;
    }
}


int main(){

    HTTP http;

    http.Create();
    http.Read();
    http.Update();
    http.Delete();
}