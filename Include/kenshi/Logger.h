#pragma once

#include <string>

class Logger
{
public:
    enum Severity
    {
        Tracw,
        Debug,
        Info,
        Warning,
        Error,
        Fatal
    };

    static void init();// RVA = 0x11D2C0
    static void close();// RVA = 0x11CCF0
    static void logMessage(const std::string&, enum Logger::Severity);// RVA = 0x11CD90
    static void logMessageDebug(const std::string&);// RVA = 0x11CCD0
    static void logHeader();// RVA = 0x11CFC0
};
