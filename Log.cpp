#include "Log.hpp"
#include <memory>

namespace Logger
{
    // Global Logging Object.
    std::unique_ptr<Log> g_log;

    // Initalize our logging object.
    void startLog(const std::string &filepath)
    {
        g_log = std::make_unique<Log>(filepath);
        Logger::log(Level::Info, "Started logging system.");
    }

    // Method which logs.
    void log(Level s, const std::string &msg)
    {
        g_log->addLog(s, msg);
    }

    void log_fatal(const std::string &msg)
    {
        g_log->addLog(Fatal, msg);
    }

    void log_error(const std::string &msg)
    {
        g_log->addLog(Error, msg);
    }

    void log_warn(const std::string &msg)
    {
        g_log->addLog(Warning, msg);
    }

    void log_info(const std::string &msg)
    {
        g_log->addLog(Info, msg);
    }

    void log_debug(const std::string &msg)
    {
        g_log->addLog(Debug, msg);
    }

    // Create our global logging object.
    Log::Log(const std::string &filepath) : m_logfile{}
    {
        m_logfile.open(filepath, std::ofstream::app);
    }

    // Add a message to our log.
    void Log::addLog(Level s, const std::string &msg)
    {
        if (m_logfile.is_open())
        {
            m_logfile << levels[static_cast<int>(s)] << ": " << msg << std::endl;
            m_logfile.flush();
        }
    }

    Log::~Log()
    {
        addLog(Level::Info, "Stopped logging system.");
        m_logfile.close();
    }
}