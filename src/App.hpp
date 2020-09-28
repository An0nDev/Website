#include "HTStack/src/App/App.hpp"
#include "HTStack/src/Server/Server.hpp"
#include "HTStack/src/Request/Request.hpp"

class App : public HTStack::App {
public:
    void onLoad ();
    void onUnload ();
    void onRequest (HTStack::Request & request);
};

extern "C" HTStack::App* factory ();
