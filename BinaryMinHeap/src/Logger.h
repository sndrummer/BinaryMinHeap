#pragma once
#include <string>

class Logger
{
public:
	Logger();
	~Logger();
	static void log_info(const char* message);
	static void log_info(const std::string& message);

	static void log_debug(const char* message);
	static void log_debug(const std::string& message);

	static void log_error(const char* message);
	static void log_error(const std::string& message);


	




#ifdef _DEBUG
#define LOG_DBG(x) (Logger::log_debug(x))
#else
#define LOG_DBG(x)
#endif

#define LOG_ERR(x) (Logger::log_error(x))
#define LOG_INFO(x) (Logger::log_info(x))
};

