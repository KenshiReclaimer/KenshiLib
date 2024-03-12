# pragma once

#include <kenshi/util/TimeOfDay.h>

// TODO move?
enum CrimeEnum
{
    CRIME_NONE,
    CRIME_ENSLAVING,
    CRIME_LOCKPICKING,
    CRIME_STEALING,
    CRIME_MURDER,
    CRIME_ASSAULT,
    CRIME_ASSAULT_VIP,
    CRIME_SLAVE_FREEING,
    CRIME_SMUGGLING,
    CRIME_TERRORISM,
    CRIME_LOOTING,
    CRIME_TRESSPASSING,
    CRIME_ESCAPE_PRISON,
    CRIME_FENCING,
    CRIME_FARM_EATING,
    CRIME_KIDNAPPING,
    CRIME_UNIFORM_THEFT,
    CRIME_END
};

class Bounty
{
public:
    Bounty();// public RVA = 0x850A40
    void _CONSTRUCTOR();// public RVA = 0x850A40
    int amount; // 0x0 Member
    unsigned int crimes; // 0x4 Member
    bool bountyHasBeenClaimedOnce; // 0x8 Member
    TimeOfDay bountyAssignmentStartedTime; // 0x10 Member
    void addCrime(CrimeEnum what);// public RVA = 0x850520
    bool hasCrime(CrimeEnum t) const;// public RVA = 0x5C7040
    // no_addr class Bounty & operator=(const class Bounty & _a1);// public missing arg names
};
