#include "Server.hpp"

#include "HTStack/src/ServerConfiguration/ServerConfiguration.hpp"
#include "HTStack/src/Server/Server.hpp"
#include "HTStack/src/SSL/SSLSetupVars.hpp"
#include "HTStack/src/CInteropUtils/CInteropUtils.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <signal.h>
#include <openssl/ssl.h>

int main () {
    std::string appLocation ("App.so");
    std::vector <std::string> appLocations;
    appLocations.push_back (appLocation);
    HTStack::ServerConfiguration serverConfiguration (
        appLocations,
        true, // autoStart
        "192.168.1.95", // ip
        443, // port
        1024, // backlog
        std::thread::hardware_concurrency (), // clientThreadPoolSize
        65535, // maxRecvSize
        true, // sloppySocketRestart
        1024, // streamedResponseBufferSize
        HTStack::SSLSetupVars ( // use empty constructor to disable
            "cert.pem", // certChainFilePath
            "key.pem", // keyFilePath
            SSL_FILETYPE_PEM // keyFileType
        ) // ssl
    );
    {
        HTStack::Server server (serverConfiguration);
        server.start ();
        HTStack::CInteropUtils::waitForSignal (SIGINT);
        server.shutdown ();
    }
};
