#pragma once

#include <string>
#include <kenshi/GameData.h>

class InstanceID
{
public:
    std::string uid; // 0x0 Member
    short baseIndex; // 0x28 Member
    short modIndex; // 0x2A Member
    bool modified; // 0x2C Member
    int getModIndex() const;// public RVA = 0x459CA0
    static short getModIndex(const std::string & s);// private RVA = 0x6BB650
    InstanceID(const InstanceID & __that);// public RVA = 0x46D060
    void _CONSTRUCTOR(const InstanceID & __that);// public RVA = 0x46D060
    InstanceID(const std::string & uid, GameData::ObjectInstance & inst);// public RVA = 0x3846A0
    void _CONSTRUCTOR(const std::string & uid, GameData::ObjectInstance & inst);// public RVA = 0x3846A0
    InstanceID();// public RVA = 0x382110
    void _CONSTRUCTOR();// public RVA = 0x382110
    void assign(const std::string & id);// public RVA = 0x3851E0
    void clear();// public RVA = 0x571F30
    bool needsSaving(const std::string & mod) const;// public RVA = 0x37F170
    void notifyChange();// public RVA = 0x459C20
    bool hasChanges() const;// public RVA = 0x459C30
    void notifySaved(const std::string & mod);// public RVA = 0x459C40
    bool empty() const;// public RVA = 0x37F1E0
    // no_addr const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & operator const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &();// public
    bool operator==(const std::string & s) const;// public RVA = 0x468A10
    int getBaseIndex() const;// public RVA = 0x459C90
    ~InstanceID();// public RVA = 0x382140
    void _DESTRUCTOR();// public RVA = 0x382140
    InstanceID & operator=(const InstanceID & __that);// public RVA = 0x46DF10
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
