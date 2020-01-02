#include <stdio.h>
#include <cpprest/uri.h>
#include <cpprest/http_listener.h>
#include <cpprest/asyncrt_utils.h>
#pragma comment(lib, "cpprest_2_10.lib")
#pragma comment(lib, "bcrypt.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "httpapi.lib")
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;
class CommandHandler
{
public:
	CommandHandler() {}
	CommandHandler(utility::string_t url);
	pplx::task<void> open() { return m_listener.open(); }
	pplx::task<void> close() { return m_listener.close(); }
private:
	void handle_get_or_post(http_request message);
	http_listener m_listener;
};
CommandHandler::CommandHandler(utility::string_t url) : m_listener(url)
{
	m_listener.support(methods::GET, std::bind(&CommandHandler::handle_get_or_post, this, std::placeholders::_1));
	m_listener.support(methods::POST, std::bind(&CommandHandler::handle_get_or_post, this, std::placeholders::_1));
}
void CommandHandler::handle_get_or_post(http_request message)
{
	ucout << "Method: " << message.method() << std::endl;
	ucout << "URI: " << http::uri::decode(message.relative_uri().path()) << std::endl;
	ucout << "Query: " << http::uri::decode(message.relative_uri().query()) << std::endl << std::endl;
	message.reply(status_codes::OK, "ACCEPTED");
};
int main(int argc, char argv[])
{
	try
	{
		utility::string_t address = U("http://*:8080");
		uri_builder uri(address);
		auto addr = uri.to_uri().to_string();
		CommandHandler handler(addr);
		handler.open().wait();
		ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;
		ucout << U("Press ENTER key to quit...") << std::endl;
		std::string line;
		std::getline(std::cin, line);
		handler.close().wait();
	}
	catch (std::exception & ex)
	{
		ucout << U("Exception: ") << ex.what() << std::endl;
		ucout << U("Press ENTER key to quit...") << std::endl;
		std::string line;
		std::getline(std::cin, line);
	}
	return 0;
}