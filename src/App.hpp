#include "HTStack/src/App/App.hpp"
#include "HTStack/src/Server/Server.hpp"
#include "HTStack/src/Request/Request.hpp"

#include <map>
#include <string>

class App : public HTStack::App {
public:
    App (HTStack::Server & server, std::map <std::string, std::string> & settings);
    void handleRequest (HTStack::Request & request);
};

extern "C" HTStack::App* factory (HTStack::Server & server, std::map <std::string, std::string> & settings);
