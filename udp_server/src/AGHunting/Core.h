//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_CORE_H
#define UDP_SERVER_CORE_H

#include <stack>
#include <future>
#include <string>
#include <cstdint>

// macros/defines

#define AH_API
#define RUN_ASYNC(func, ...) std::async(std::launch::async, func, __VA_ARGS__);

#define PORT   uint16_t
#define IP     std::string
#define SOCKET int

#define AH_SHORT  short
#define AH_USHORT unsigned short


// constants

constexpr PORT DEFAULT_PORT = 15001;
const IP       DEFAULT_IP   = "127.0.0.1";


template<class T>
class AH_Stack : protected std::stack <T> {
public:
    inline T Pop() {
        T tmp = this->top();
        this->pop();

        return tmp;
    }

    inline void Push(T value) {
        this->push(value);
    }


};

#endif //UDP_SERVER_CORE_H
