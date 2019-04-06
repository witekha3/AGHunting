//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_GAMESERVER_H
#define UDP_SERVER_GAMESERVER_H

#include <map>
#include <functional>
#include <future>

#include <AGHunting/Core.h>
#include <AGHunting/network/SocketUDP.h>
#include <AGHunting/misc/Log.h>

namespace ah {
    class AH_API GameServer {
        friend class ServerController;

    public:
        explicit GameServer(Host&&);
        ~GameServer();

        bool init();
        void start();

    private:
        void update();
        void deinit();

        Host      _host;
        SocketUDP _sock;

        bool _is_running;

    };

    static GameServer* Instance = nullptr;
}

#endif //UDP_SERVER_GAMESERVER_H
