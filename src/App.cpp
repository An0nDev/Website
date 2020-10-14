#include "HTStack/src/Response/Response.hpp"
#include "HTStack/src/HTTPUtils/MIMEType.hpp"

#include "App.hpp"

#include <fstream>
#include <iostream>

App::App (HTStack::Server & server, std::map <std::string, std::string> & settings) : HTStack::App (server, settings) {};

void App::handleRequest (HTStack::Request & request) {
    if (request.headers ["Host"] != "an0n.dev") return;
    if (request.path == "/") {
        std::ifstream htmlFileStream ("webroot/index.html", std::ifstream::binary);
        if (!htmlFileStream) return;
        HTStack::MIMEType mimeType ("index.html", true); // guess
        HTStack::Response response (200, &htmlFileStream, &mimeType); // 200 = OK
        response.respondTo (request);
    } else if (request.path == "/logo") {
        std::ifstream logoFileStream ("webroot/logo.png", std::ifstream::binary);
        if (!logoFileStream) return;
        HTStack::MIMEType mimeType ("logo.png", true); // guess
        HTStack::Response response (200, &logoFileStream, &mimeType); // 200 = OK
        response.respondTo (request);
    } else {
        HTStack::Response response (404);
        response.respondTo (request);
    }
};

extern "C" HTStack::App* factory (HTStack::Server & server, std::map <std::string, std::string> & settings) {
    return new App (server, settings);
};
