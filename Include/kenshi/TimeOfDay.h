#pragma once

#include <string>

class TimeOfDay
{
public:
    TimeOfDay(double);// RVA = 0x1D9970
    TimeOfDay();// RVA = 0x8D1A0
    void setNull();// RVA = 0x1F59E0
    bool isUnset();// RVA = 0x8D1B0
    void setTime(double);// RVA = 0x8D1D0
    void addHours(double);// RVA = 0x8D1E0
    void addMinutes(double);// RVA = 0x1D9980
    bool operator>(const TimeOfDay&);// RVA = 0x104E80
    bool operator>=(const TimeOfDay&);// RVA = 0x104E90
    bool operator<(const TimeOfDay&);// RVA = 0x1089D0
    bool operator<=(const TimeOfDay&);// RVA = 0x1089E0
    bool operator==(const TimeOfDay&);// RVA = 0x280120
    const TimeOfDay& operator=(const TimeOfDay&);// RVA = 0x8D1F0
    double getTotalHours();// RVA = 0x8D200
    double getTotalMinutes();// RVA = 0x232C60
    double getTotalSeconds();// RVA = 0x6A5440
    double getRealLifeSeconds();// RVA = 0x6A5460
    double getRealLifeSecondsPassed();// RVA = 0x2842B0
    double getTotalDays();// RVA = 0x46F840
    void stampTime();// RVA = 0x60A1C0
    double getHoursPassed();// RVA = 0x60A1F0
    double getMinutesPassed();// RVA = 0x1F59F0
    double getSecondsPassed();// RVA = 0x27D420
    bool timeOfDayHasPassed(double);// RVA = 0x60A220
    double timePassed();// RVA = 0x60A2A0
    std::string getTimePassedString();// RVA = 0x624E00
    std::string getTimeRemainingString();// RVA = 0x624E60
    std::string getTotalTimeString();// RVA = 0x61EF40
    double time; // 0x0 Member
};