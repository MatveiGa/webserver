#pragma once
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include "iostream"
class Session : public std::enable_shared_from_this<Session>
{
public:

	Session(boost::asio::ip::tcp::socket socket);
	void start();

private:
	void read_request();
	void process_request(size_t length);
	void send_response();
	boost::asio::ip::tcp::socket socket_;
	std::array<char, 1024 > buffer_;
	std::string request_;

};

