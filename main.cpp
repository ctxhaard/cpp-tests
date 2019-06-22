
#include <spdlog/spdlog.h>
#include <spdlog/sinks/syslog_sink.h>


int main(int argc, const char *argv[]) {
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_default_logger(spdlog::syslog_logger_mt("syslog", "test", LOG_PID));
    spdlog::trace("{} starting", argv[0]);
}