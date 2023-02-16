#include <string>
#include <iostream>
#include <fstream>

#ifndef CUSTOM_LOGGING
#define CUSTOM_LOGGING

namespace Logger
{
    // Severity level enum.
    enum Level
    {
        Fatal,
        Error,
        Warning,
        Info,
        Debug
    };

    // Initialize the log.
    void startLog(const std::string &filepath);

    // Log a message.
    void log(Level s, const std::string &msg);
    void log_fatal(const std::string &msg);
    void log_error(const std::string &msg);
    void log_warn(const std::string &msg);
    void log_info(const std::string &msg);
    void log_debug(const std::string &msg);

    // Logging class.
    class Log
    {
    public:
        Log(const std::string &filepath);
        void addLog(Level s, const std::string &msg);
        ~Log();

    private:
        // File for logging.
        std::ofstream m_logfile;
        std::string levels[5] = {"Fatal", "Error", "Warning", "Info", "Debug"};
    };
}

#endif