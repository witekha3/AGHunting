//
// Created by neko on 04.04.19.
//

#include "GameServer.h"

#define BIND_API(func, ...) std::bind(&GameServer::func, this, __VA_ARGS__)

namespace ah {

    GameServer::GameServer(Host&& h)
        :   _host(h),
            _sock(_host),
            _is_running(false)
    {
        AH_ASSERT(!Instance, "Instance of GameServer already exists.");
        Instance = this;

        _request_handler = AsyncRequestHandler<PayloadHandler>::createInstance();
    }

    GameServer::~GameServer() {
        // --
    }

    void GameServer::update() {
        auto request = _sock.recv_from();

        if (!request) {
            AH_ERROR("Received invalid UDP packet");
        }

        _request_handler->handle(request.value(), {
            BIND_API(api_response, request->addr, std::placeholders::_1, std::placeholders::_2),
            BIND_API(api_sendAll, std::placeholders::_1, std::placeholders::_2),
            BIND_API(api_addNewPlayer, std::placeholders::_1),
            BIND_API(api_getPlayerPtr, std::placeholders::_1)
        });
    }

    void GameServer::start() {
        AH_INFO("Game server is listening on {0}:{1}.", _host.ip.c_str(), _host.port);

        while (_is_running) {
            update();
        }

        deinit();

        AH_INFO("Server is shutting down.");
    }

    void GameServer::deinit() {

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