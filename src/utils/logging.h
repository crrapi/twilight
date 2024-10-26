// src/utils/logging.h
#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <iostream>

enum LogLevel
{
    INFO,
    WARNING,
    ERROR
};

class Logger
{
public:
    static void log(const std::string &message, LogLevel level = INFO);
};

#endif // LOGGING_H
