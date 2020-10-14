#include <HTStack/App/App.hpp>
#include <HTStack/Server/Server.hpp>
#include <HTStack/Request/Request.hpp>

#include <map>
#include <string>

class App : public HTStack::App {
public:
    App (HTStack::Server & server, std::map <std::string, std::string> & settings);
    void handleRequest (HTStack::Request & request);
};

extern "C" HTStack::App* factory (HTStack::Server & server, std::map <std::string, std::string> & settings);
