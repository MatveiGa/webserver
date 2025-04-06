#pragma once 
#include <boost/asio.hpp>


class Server
{
public:
	Server(boost::asio::io_context& io, short port);
	

private:
	void accept_connection();
	boost::asio::ip::tcp::acceptor acceptor_;


};

