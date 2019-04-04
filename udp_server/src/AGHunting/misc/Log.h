
//
// Created by neko on 11.03.19.
//

#ifndef AH_API_LOG_H
#define AH_API_LOG_H

#include <memory>
#include <type_traits>

#include <signal.h>

#include <AGHunting/Core.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/ostream_sink.h>
#include <spdlog/fmt/ostr.h>


namespace ah {
    class AH_API Log {
    public:
        static void init();

        inline static auto getCoreLogger() -> std::shared_ptr<spdlog::logger>& {
            return _core_logger;
        }

        inline static auto getAppLogger() -> std::shared_ptr<spdlog::logger>& {
            return _app_logger;
        }

    private:
        static std::shared_ptr<spdlog::logger> _core_logger;
        static std::shared_ptr<spdlog::logger> _app_logger;
    };
}

#define AH_FATAL(...) ah::Log::getAppLogger()->critical(__VA_ARGS__);
#define AH_ERROR(...) ah::Log::getAppLogger()->error(__VA_ARGS__);
#define AH_WARN(...) ah::Log::getAppLogger()->warn(__VA_ARGS__)
#define AH_INFO(...) ah::Log::getAppLogger()->info(__VA_ARGS__)
#define AH_TRACE(...) ah::Log::getAppLogger()->trace(__VA_ARGS__)

#define AH_ASSERT(x, ...) if (!(x)) { AH_FATAL(__VA_ARGS__); raise(SIGTRAP); }

#endif //TEMPEST_API_LOG_H
