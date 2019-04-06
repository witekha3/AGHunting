//
// Created by neko on 04.04.19.
//

#include "GameServer.h"

namespace ah {

    GameServer::GameServer(Host&& h)
        :   _host(h),
            _sock(_host),
            _is_running(false)
    {
        AH_ASSERT(!Instance, "Instance of GameServer already exists.");
        Instance = this;
    }

    GameServer::~GameServer() {
        // --
    }

    void GameServer::update() {

    }

    void GameServer::start() {
        AH_INFO("Server is listening on {0}:{1}", _host.ip.c_str(), _host.port);

        while (_is_running) {
            update();
        }
    }

    bool GameServer::init() {
        if (!_sock.bind()) {
            AH_ERROR("Failed to bind server socket.");
            return false;
        }

        _is_running = true;
        return true;
    }
}