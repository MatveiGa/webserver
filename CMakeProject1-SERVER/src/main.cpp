// CMakeProject1-SERVER.cpp: определяет точку входа для приложения.
#include <iostream>
#include <boost/asio.hpp>
#include "server1.h"

using namespace boost::asio;
using ip::tcp;

int main()
{
	std::cout << "Hello CMake." << std::endl;
	io_context io;// ввод/вывод 
	
		tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));//создал приемник входящих TCP соединений
		while (true) {
		tcp::socket socket1(io);// создал сокет для чтения запросов
		acceptor.accept(socket1);// ожидание подключения
		std::string response =
			"HTTP/1.1 200 OK\r\n"
			"Content-Length:  12\r\n"
			"\r\n"
			"Hello world!";
		write(socket1, buffer(response));
	}
	std::cout << "Hello CMake." << std::endl;

	return 0;
}
