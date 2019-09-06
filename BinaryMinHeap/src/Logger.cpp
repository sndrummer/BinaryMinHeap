#include "Logger.h"
#include <iostream>

Logger::Logger() = default;

Logger::~Logger() = default;

void Logger::log_info(const char* message) { std::cout << "LOGGER INFO: " << message << std::endl; }

void Logger::log_info(const std::string& message) { std::cout << "LOGGER INFO: " << message << std::endl; }

void Logger::log_debug(const char* message) { std::cout << "LOGGER DEBUG: " << message << std::endl; }

void Logger::log_debug(const std::string& message) { std::cout << "LOGGER DEBUG: " << message << std::endl; }

void Logger::log_error(const char* message) { std::cout << "LOGGER ERROR: " << message << std::endl; }

void Logger::log_error(const std::string& message) { std::cout << "LOGGER ERROR: " << message << std::endl; }
