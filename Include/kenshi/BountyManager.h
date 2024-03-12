#pragma once

#include <string>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/StringPair.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/hand.h>
#include <kenshi/Bounty.h>

class Faction;
class Character;
class GameData;
class BountyManager
{
public:
    ogre_unordered_map<Faction *,Bounty>::type bounties; // 0x0 Member
    Character * me; // 0x40 Member
    Faction * _getBountyFaction(Faction * f);// private RVA = 0x850A80
    Faction * _getHighestBountyFaction();// private RVA = 0x852150
    Faction * _hasAccessPass; // 0x48 Member
    TimeOfDay accessPassExpirationTime; // 0x50 Member
    // no_addr void BountyManager(const class BountyManager & _a1);// public missing arg names
    BountyManager(Character * c);// public RVA = 0x6405E0
    void _CONSTRUCTOR(Character * c);// public RVA = 0x6405E0
    int getPercievedBounty(Character * whosLooking);// public RVA = 0x852A40
    int getActualBounty(Faction * whosLooking);// public RVA = 0x852AF0
    void notifyPlayerClaimBounty(Faction * whosLooking);// public RVA = 0x852BE0
    bool bountyAlreadyBeenClaimedByPlayer(Faction * whosLooking);// public RVA = 0x852CE0
    void assignBountyForCrimes(Faction * enforcer);// public RVA = 0x852930
    void unfairAddToBounty(Faction * enforcer, int amount);// public RVA = 0x852890
    int getBountyRecognitionThreshold();// public RVA = 0x850B30
    void clearBounty(Faction * enforcer);// public RVA = 0x852460
    int getTotalBounty() const;// public RVA = 0x8521B0
    void update(float frameTime);// public RVA = 0x5CB400
    StringPair getGUIData(lektor<StringPair> & outs);// public RVA = 0x5D2620
    void getGUIDataForAppend(lektor<StringPair> & outs);// public RVA = 0x5D0C80
    std::string getBountyExpiryStringForGUI();// public RVA = 0x5D0990
    void load(GameData * state);// public RVA = 0x6256E0
    void save(GameData * state);// public RVA = 0x625B30
    bool setCrime(CrimeEnum crime, Faction * against, const hand & agnst);// public RVA = 0x8516F0
    void notifyCrimeWitnessed(Faction * against, const hand & againstWho, int expirytime, CrimeEnum what);// public RVA = 0x851880
    void notifyPossibleCrimeWitnessed(float time);// public RVA = 0x8509B0
    CrimeEnum committingCrime; // 0x58 Member
    Faction * crimeAgainstFaction; // 0x60 Member
    Faction * usingTrainingEquipmentOf; // 0x68 Member
    hand crimeAgainst; // 0x70 Member
    float crimeExpiry; // 0x90 Member
    TimeOfDay prisonSentenceBeganTime; // 0x98 Member
    float prisonSentenceToServe; // 0xA0 Member
    bool _hadABountyAssignedForCurrentCrime; // 0xA4 Member
    bool isCommittingCrime() const;// public RVA = 0x850540
    void notifyStartPrisonSentence(Faction * law);// public RVA = 0x8533C0
    bool hasAccessPass(Faction * forFac) const;// public RVA = 0x850550
    void giveAccessPass(Faction * who, float minutes);// public RVA = 0x337770
    static std::string crimeToStr(CrimeEnum c);// public RVA = 0x854FA0
    static int getBountyForCrime(CrimeEnum c);// public RVA = 0x8508B0
    static int getPrisonSentenceInHours(int bounty);// public RVA = 0x850940
    static float getBountyExpirationTime(int bounty);// public RVA = 0x850980
    ~BountyManager();// public RVA = 0x6406F0
    void _DESTRUCTOR();// public RVA = 0x6406F0
    // no_addr class BountyManager & operator=(const class BountyManager & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
