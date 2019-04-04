//
// Created by neko on 11.03.19.
//

#include "Log.h"

namespace ah {

    std::shared_ptr<spdlog::logger> Log::_core_logger;
    std::shared_ptr<spdlog::logger> Log::_app_logger;

    void Log::init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        _core_logger = spdlog::stdout_color_mt("TEMPEST");
        _core_logger->set_level(spdlog::level::trace);

        _app_logger = spdlog::stdout_color_mt("APP");
        _app_logger->set_level(spdlog::level::trace);
    }
}