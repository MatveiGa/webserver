#include <session.hpp>
#include <server.hpp>


Server::Server(boost::asio::io_context& io, short port)
	: acceptor_(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
	accept_connection();
}


void Server::accept_connection() {
	acceptor_.async_accept(
		[this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
			if (!ec) {
				std::make_shared<Session>(std::move(socket))->start();
			}
			accept_connection();
		}
	);
}

