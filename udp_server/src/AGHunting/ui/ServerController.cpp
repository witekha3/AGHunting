//
// Created by neko on 06.04.19.
//

#include "ServerController.h"

namespace ah {

    ServerController::ServerController(GameServer& server, Host&& host)
        :   _server(server),
            _host(host),
            _sock(0)
    {
    }

    ServerController::~ServerController() {
        if (_sock) {
            close(_sock);
        }
    }

    void ServerController::_threadWorker() {
        while (_server._is_running) {
            AH_INFO("Server controller is waiting for connection on {0}:{1}.", _host.ip, _host.port);
            auto controller_sock = accept(_sock, nullptr, nullptr);

            if (controller_sock < 0) {
                AH_ERROR("Controller received empty connection.");
                continue;
            }

            // to do some auth!

            AH_INFO("Controller connected.");

            char buff[CONTROLLER_BUF_SIZE];

            while (true) {
                std::memset(buff, 0, CONTROLLER_BUF_SIZE);

                size_t received = recv(controller_sock, buff, CONTROLLER_BUF_SIZE, 0);

                if (received <= 0 && _server._is_running) {
                    AH_INFO("Connection with controller lost.");
                    break;
                }

                switch (parseRequest(buff, received)) {
                    case Request::SHUTDOWN: {
                        _server._is_running = false;
                        _server._sock.close();
                        break;
                    }

                    case Request::UNKNOWN:
                    default:
                        AH_INFO("Received unknown request from controller.");
                        break;
                }

            }
        }
    }

    bool ServerController::start() {
        _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (_sock < 0) {
            AH_ERROR("Cannot create server controller socket.");
            return false;
        }

        sockaddr_in addr = {};

        addr.sin_family = AF_INET;
        addr.sin_port   = htons(_host.port);

        if (inet_pton(AF_INET, _host.ip.c_str(), &addr.sin_addr) <= 0) {
            AH_ERROR("Invalid ip address of server controller socket.");
            return false;
        }

        if (::bind(_sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
            AH_ERROR("Failed to bind server controller socket.");
            return false;
        }

        listen(_sock, 1);

        _thread = std::make_unique<std::thread>(&ServerController::_threadWorker, this);
        _thread->detach();

        return true;
    }

    ServerController::Request ServerController::parseRequest(char* buff, size_t len) {
        if (strncmp(buff, "shutdown", strlen("shutdown")) == 0) {
            return Request::SHUTDOWN;
        }

        return Request::UNKNOWN;
    }
}