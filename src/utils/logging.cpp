// src/utils/logging.cpp
#include "logging.h"

void Logger::log(const std::string &message, LogLevel level)
{
    switch (level)
    {
    case INFO:
        std::cout << "[INFO]: " << message << std::endl;
        break;
    case WARNING:
        std::cout << "[WARNING]: " << message << std::endl;
        break;
    case ERROR:
        std::cerr << "[ERROR]: " << message << std::endl;
        break;
    }
}
