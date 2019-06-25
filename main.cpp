
#include <spdlog/spdlog.h>
#include <spdlog/sinks/syslog_sink.h>

#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

int main(int argc, const char *argv[]) {
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_default_logger(spdlog::syslog_logger_mt("syslog", "test", LOG_PID));
    spdlog::trace("{} starting", argv[0]);

    fs::path p { argv[1] };

    for (auto item: fs::recursive_directory_iterator( p )) {
        std::cout << item.path() << (fs::is_character_file(item.path()) ? " C" : " R") << std::endl;

    }

}