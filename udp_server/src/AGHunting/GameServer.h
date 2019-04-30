//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_GAMESERVER_H
#define UDP_SERVER_GAMESERVER_H

#include <map>
#include <vector>
#include <functional>
#include <future>

#include <AGHunting/Core.h>
#include <AGHunting/network/SocketUDP.h>
#include <AGHunting/network/AsyncRequestHandler.h>
#include <AGHunting/network/RequestHandler.h>

#include <AGHunting/game/PayloadHandler.h>
#include <AGHunting/game/Player.h>

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

        std::vector<Player> _players;

        // server api
        inline void api_response(UDP_Addr addr, char* buff, size_t len) {
            _sock.send_to(addr, buff, len);
        }

        inline void api_sendAll(char* buff, size_t len) {
            for (auto& p : _players) {
                _sock.send_to(p.addr, buff, len);
            }
        }

        inline void api_addNewPlayer(Player p) {
            _players.push_back(p);
        }

        inline Player* api_getPlayerPtr(AH_USHORT id) {
            for (auto& p : _players) {
                if (p.id == id) {
                    return &p;
                }
            }
            return nullptr;
        }

        RequestHandlerPtr _request_handler;
    };

    static GameServer* Instance = nullptr;
}

#endif //UDP_SERVER_GAMESERVER_H
