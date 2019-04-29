//
// Created by neko on 4/23/19.
//

#include "PayloadHandler.h"

namespace ah {

    GamePacketParserPtr PayloadHandler::_game_packet_parser = GamePacketParser::createInstance();
}
