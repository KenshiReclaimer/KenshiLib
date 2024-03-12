#pragma once

#include <string>

class TimeOfDay
{
public:
    TimeOfDay(double hrs);// public RVA = 0x268060
    void _CONSTRUCTOR(double hrs);// public RVA = 0x268060
    TimeOfDay();// public RVA = 0xCCF50
    void _CONSTRUCTOR();// public RVA = 0xCCF50
    void setNull();// public RVA = 0x28A160
    bool isUnset() const;// public RVA = 0xCCF60
    void setTime(double hrs);// public RVA = 0xCCF80
    void addHours(double hours);// public RVA = 0xCCF90
    void addMinutes(double mins);// public RVA = 0x268070
    bool operator>(const TimeOfDay & a) const;// public RVA = 0x1623A0
    bool operator>=(const TimeOfDay & a) const;// public RVA = 0x1623C0
    bool operator<(const TimeOfDay & a) const;// public RVA = 0x166DE0
    bool operator<=(const TimeOfDay & a) const;// public RVA = 0x166E00
    bool operator==(const TimeOfDay & a) const;// public RVA = 0x334FA0
    const TimeOfDay & operator=(const TimeOfDay & a);// public RVA = 0xCCFA0
    double getTotalHours() const;// public RVA = 0xCCFB0
    double getTotalMinutes() const;// public RVA = 0x2D53A0
    double getTotalSeconds() const;// public RVA = 0x850480
    double getRealLifeSeconds() const;// public RVA = 0x8504A0
    double getRealLifeSecondsPassed() const;// public RVA = 0x339CC0
    double getTotalDays() const;// public RVA = 0x595CA0
    void stampTime();// public RVA = 0x790960
    double getHoursPassed() const;// public RVA = 0x790990
    double getMinutesPassed() const;// public RVA = 0x28A170
    double getSecondsPassed() const;// public RVA = 0x3319B0
    bool timeOfDayHasPassed(double additionalHours) const;// public RVA = 0x7909C0
    double timePassed() const;// public RVA = 0x790A40
    std::string getTimePassedString() const;// public RVA = 0x7AB5A0
    std::string getTimeRemainingString() const;// public RVA = 0x7AB600
    std::string getTotalTimeString() const;// public RVA = 0x7A56E0
    double time; // 0x0 Member
};
