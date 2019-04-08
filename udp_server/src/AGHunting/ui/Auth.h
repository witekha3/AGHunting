//
// Created by neko on 07.04.19.
//

#ifndef UDP_SERVER_AUTH_H
#define UDP_SERVER_AUTH_H

#include <cstring>
#include <cstdlib>

#include <vector>
#include <array>

#include <bcrypt/BCrypt.hpp>

#include <AGHunting/Core.h>

namespace ah {
    class AH_API Auth {
    public:
        Auth() = delete;


    private:
        BCrypt _bcrypt;

    };
}

#endif //UDP_SERVER_AUTH_H
