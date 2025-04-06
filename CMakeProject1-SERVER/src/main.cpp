// CMakeProject1-SERVER.cpp: определяет точку входа для приложения.
#include <boost/asio.hpp>
#include <server.hpp>
#include "iostream"

int main() {
    try {
        boost::asio::io_context io;
        Server server(io, 8080);
        io.run(); 
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
