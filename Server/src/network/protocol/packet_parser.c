//
// Created by neko on 19.03.19.
//

#include "packet_parser.h"

bool parse_packet_header(Packet* p, char* raw_packet, size_t len) {
    if (len - 1 < RAW_PACKET_HEADER_LEN) {
        log_debug("Packet is too short");
        return false;
    }
    // to do error checking
    p->length = (unsigned char)raw_packet[0];

    char checksum[2];
    memcpy(checksum, raw_packet + 1, 2);

    p->checksum  = *((unsigned short*)&raw_packet[1]);
    p->player_id = (unsigned char)raw_packet[3];
    p->method    = (unsigned char)raw_packet[4];

    memset(p->data, 0, RAW_DATA_LEN);
    memcpy(p->data, &raw_packet[5], len - RAW_PACKET_HEADER_LEN);

    return true;
}

void print_packet(const Packet* const p) {
    log_info("Packet --> length: %d, checksum: %d, player-id: %d, method: %d, raw data: ", p->length, p->checksum, p->player_id, p->method);
}
