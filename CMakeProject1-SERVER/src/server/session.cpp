#include <session.hpp>
#include <server.hpp>

Session::Session(boost::asio::ip::tcp::socket socket)
	:socket_(std::move(socket)) {}

void Session::start() {
	read_request();
}
void Session::read_request() {
	auto self(shared_from_this());
	socket_.async_read_some(boost::asio::buffer(buffer_),
		[this, self](boost::system::error_code ec, std::size_t length) {
		if (!ec) {
			process_request(length);
			send_response();
		}
	});
}
void Session::process_request(size_t length) {
	request_ = std::string(buffer_.data(), length);
	std::cout << "Received: " << request_ << std::endl;
}
void Session::send_response() {
	auto self(shared_from_this());
	std::string response =
		"HTTP/1.1 200 OK\r\n"
		"Content-Length: 13\r\n"
		"\r\n"
		"Hello, World!";
	boost::asio::async_write(socket_, boost::asio::buffer(response),
		[this, self](boost::system::error_code ec, std::size_t) {
		if (!ec) {
			socket_.close();
			}
		});
}