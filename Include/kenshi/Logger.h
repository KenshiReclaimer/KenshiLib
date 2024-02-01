#pragma once

#include <string>

class Logger
{
public:
    enum Severity
    {
        Trace = 0x0,
        Debug = 0x1,
        Info = 0x2,
        Warning = 0x3,
        Error = 0x4,
        Fatal = 0x5
    };

    static void init();// RVA = 0x11D2C0
    static void close();// RVA = 0x11CCF0
    static void logMessage(const std::string&, enum Logger::Severity);// RVA = 0x11CD90
    static void logMessageDebug(const std::string&);// RVA = 0x11CCD0
    static void logHeader();// RVA = 0x11CFC0
};
