#include "HTStack/src/Response/Response.hpp"
#include "HTStack/src/HTTPUtils/MIMEType.hpp"

#include "App.hpp"

#include <fstream>

void App::onLoad () {};
void App::onUnload () {};

void App::onRequest (HTStack::Request & request) {
    if (request.path == "/") {
        std::ifstream htmlFileStream ("webroot/index.html", std::ifstream::binary);
        HTStack::MIMEType mimeType ("index.html", true); // guess
        HTStack::Response response (200, &htmlFileStream, &mimeType); // 200 = OK
        response.respondTo (request);
    } else if (request.path == "/logo") {
        std::ifstream logoFileStream ("webroot/logo.png", std::ifstream::binary);
        HTStack::MIMEType mimeType ("logo.png", true); // guess
        HTStack::Response response (200, &logoFileStream, &mimeType); // 200 = OK
        response.respondTo (request);
    } else {
        HTStack::Response response (404);
        response.respondTo (request);
    }
};

extern "C" HTStack::App* factory () {
    return new App ();
};
