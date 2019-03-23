//
// Created by neko on 19.03.19.
//

#ifndef SERVER_PACKET_H
#define SERVER_PACKET_H

#define U_CHAR unsigned char

#define RAW_PACKET_LEN 64
#define RAW_PACKET_HEADER_LEN 5
#define RAW_DATA_LEN (RAW_PACKET_LEN - RAW_PACKET_HEADER_LEN)

typedef enum {
    MT_SEND_PLAYER_POS = 0,
    MT_GET_PLAYERS_POS = 1,
    MT_EMIT_EVENT = 2
} Method;

typedef struct {
    U_CHAR         length;
    unsigned short checksum;
    U_CHAR         player_id;
    Method         method;
    char           data[RAW_DATA_LEN];
} Packet;

#endif //SERVER_PACKET_H
