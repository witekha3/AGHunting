//
// Created by neko on 04.04.19.
//

#include "SocketUDP.h"

namespace ah {
    SocketUDP::SocketUDP(const Host& host)
        :   _host(host),
            _sock(0)
    {
    }

    SocketUDP::~SocketUDP() {
        if (_sock != 0) {
            close(_sock);
        }
    }

    bool SocketUDP::bind() {
        _sock = socket(AF_INET, SOCK_DGRAM, 0);

        if (_sock < 0) {
            AH_FATAL("Cannot created UDP socket.");
            return false;
        }

        _addr.sin_family = AF_INET;
        _addr.sin_port   = htons(_host.port);

        if (inet_pton(AF_INET, _host.ip.c_str(), &_addr.sin_addr) <= 0) {
            AH_FATAL("IP address is invalid.");
            return false;
        }

        socklen_t len = sizeof(_addr);

        if (::bind(_sock, (sockaddr*)&_addr, len) < 0) {
            AH_FATAL("Cannot bind socket.");
            return false;
        }

        return true;
    }

    std::optional<UDP_Packet> SocketUDP::recv_from() {
        sockaddr_in client;
        socklen_t   slen;

        UDP_Packet p;

        size_t received = ::recvfrom(_sock, p.payload.data, PAYLOAD_BUFF_LEN, 0, (sockaddr*)&client, &slen);

        if (received < 0 ) {
            AH_ERROR("Recvfrom error.");
            return std::nullopt;
        }

        p.payload.len   = received;
        p.addr.saddr    = client;
        p.addr.len      = slen;

        p.addr.host.ip   = std::string(inet_ntop(AF_INET, &client.sin_addr, p.addr.ip_buff, IP_BUFF_LEN));
        p.addr.host.port = ntohs(client.sin_port);

        return p;
    }

    size_t SocketUDP::send_to(UDP_Addr addr, char* buff, size_t len) {
        return sendto(_sock, buff, len, 0, (sockaddr*)&addr.saddr, addr.len);
    }
}
