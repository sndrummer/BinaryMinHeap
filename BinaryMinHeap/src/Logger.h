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
};

