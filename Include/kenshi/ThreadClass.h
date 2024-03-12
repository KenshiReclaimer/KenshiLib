#pragma once

#include <string>
#include <boost/thread/shared_mutex.hpp>

class ThreadClass
{
public:
    // VTable         : (none)
    void * threadHandle; // 0x8 Member
    unsigned int threadID; // 0x10 Member
    bool _running; // 0x14 Member
    std::string name; // 0x18 Member
    float frameTime; // 0x40 Member
    bool infiniteMode; // 0x44 Member
    bool pretendThread; // 0x45 Member
    boost::shared_mutex runMute; // 0x48 Member
    boost::shared_mutex lockedWhileRunningMute; // 0x68 Member
    void stopRunning();// protected RVA = 0x25F450
    bool canIRun();// protected RVA = 0x25F790
    bool startRunning(float time);// public RVA = 0x3BE990
    bool isRunning();// public RVA = 0x25C220
    // no_addr bool waitForRunningStop_SleepWhileWait();// public
    bool waitForRunningStop_Blocking();// public RVA = 0x7899B0
    // no_addr void ThreadClass(const class ThreadClass & _a1);// public missing arg names
    ThreadClass(const std::string & _name);// public RVA = 0x25F0E0
    void _CONSTRUCTOR(const std::string & _name);// public RVA = 0x25F0E0
    virtual ~ThreadClass();// public RVA = 0x25F550 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x25F550 vtable offset = 0x0
    void setup(float _frameTime, bool infinite, bool _pretendThread);// public RVA = 0x877260
    bool beginThread(float _frameTime, bool infinite, int priority);// public RVA = 0x3BEBE0
    void setThreadName(const char * threadName);// public RVA = 0x3B2790
    void endThread();// public RVA = 0x25F4B0
    // no_addr bool endThreadTry();// public
    void setName(const char * name);// public RVA = 0x3B27F0
    virtual unsigned long threadProc() = 0;// public vtable offset = 0x8
    // no_addr class ThreadClass & operator=(const class ThreadClass & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
