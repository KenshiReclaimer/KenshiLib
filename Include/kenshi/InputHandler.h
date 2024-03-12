#pragma once

#include "util/lektor.h"

#include <map>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector2.h>
#include <ogre/OgreVector3.h>
#include <ois/OISKeyboard.h>

class InputHandler : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    enum Masks
    {
        SHIFT_MASK = 0x100,
        CTRL_MASK = 0x200,
        ALT_MASK = 0x400,
        ALL_MASK = 0x700,
        NONE_MASK = 0x0
    };

    enum GameMode
    {
        GLOBAL,
        EDITOR
    };

    struct Command
    {
    public:
        Command(const Command&);// RVA = 0x2A8040
        Command();// RVA = 0x2A20A0
        GameMode gameMode; // 0x0 Member
        bool isKey; // 0x4 Member
        int code; // 0x8 Member
        bool* boolean; // 0x10 Member
        std::string name; // 0x18 Member
        int bound; // 0x40 Member
        Masks masks; // 0x44 Member
        ~Command();// RVA = 0x2A20D0
        Command& operator=(const Command&);// RVA = 0x2A8480
        // no_addr public void * __vecDelDtor(unsigned int);
    };
    // Typedef        : EventIterator
    // Typedef        : CommandMap
    std::map<std::string, Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Command>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > commands; // 0x0 Member
    std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > map; // 0x28 Member
    std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > editMap; // 0x50 Member
    std::set<InputHandler::Command*, std::less<InputHandler::Command*>, Ogre::STLAllocator<Command*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > events; // 0x78 Member
    OIS::Keyboard* keyboard; // 0xA0 Member
    std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > keyNameMap; // 0xA8 Member
    std::string getKeyUTF8(int);// RVA = 0x2A3C90
    int parseKey(const std::string&);// RVA = 0x2A4720
    Command* getCommand(const std::string&);// RVA = 0x2A4AE0
    void keyDownEvent(OIS::KeyCode);// RVA = 0x2A36C0
    void keyUpEvent(OIS::KeyCode);// RVA = 0x2A3930
    void clearMessages();// RVA = 0x2A3610
    // no_addr public void InputHandler(const class InputHandler &);
    InputHandler();// RVA = 0x2A7E50
    void initialise();// RVA = 0x2A6250
    void addCommand(const std::string&, int, int, int, Masks, GameMode);// RVA = 0x2A5FD0
    void addCommand(const std::string&, bool&, int, int, Masks, GameMode);// RVA = 0x2A6170
    void addKey(const std::string&, bool&, int, int, GameMode);// RVA = 0x2A61E0
    void bind(const std::string&, int);// RVA = 0x2A4DF0
    void unbind(int, GameMode);// RVA = 0x2A3C00
    void unbind(const std::string&);// RVA = 0x2A4E80
    void unbindAll();// RVA = 0x2A3560
    bool isBound(const std::string&);// RVA = 0x2A4C20
    bool isBound(int);// RVA = 0x2A3B40
    bool isKeyState(const std::string&);// RVA = 0x2A4C50
    GameMode getMode(const std::string&);// RVA = 0x2A4C80
    void sendEvent(const std::string&);// RVA = 0x2A4B70
    void loadConfig();// RVA = 0x2A4FC0
    void saveConfig();// RVA = 0x2A4040
    std::string keyString(int, bool);// RVA = 0x2A3E70
    lektor<int> getBoundKeys(const std::string&);// RVA = 0x2A4CA0
    const std::string& getBoundCommand(int, GameMode);// RVA = 0x2A45D0
    bool controlEnabled; // 0xD0 Member
    GameMode gameMode; // 0xD4 Member
    bool ctrl; // 0xD8 Member
    bool shift; // 0xD9 Member
    bool alt; // 0xDA Member
    bool up; // 0xDB Member
    bool down; // 0xDC Member
    bool left; // 0xDD Member
    bool right; // 0xDE Member
    bool space; // 0xDF Member
    bool pgup; // 0xE0 Member
    bool pgdn; // 0xE1 Member
    bool comma; // 0xE2 Member
    bool period; // 0xE3 Member
    bool f1; // 0xE4 Member
    bool f2; // 0xE5 Member
    bool escape; // 0xE6 Member
    bool del; // 0xE7 Member
    bool escape_msg; // 0xE8 Member
    bool zoomin; // 0xE9 Member
    bool zoomout; // 0xEA Member
    bool buildTiltInc; // 0xEB Member
    bool buildTiltDec; // 0xEC Member
    bool rotate; // 0xED Member
    bool rotRight; // 0xEE Member
    bool rotLeft; // 0xEF Member
    bool tiltDown; // 0xF0 Member
    bool tiltUp; // 0xF1 Member
    bool highlight; // 0xF2 Member
    bool mLeft; // 0xF3 Member
    bool mRight; // 0xF4 Member
    bool lastMLeft; // 0xF5 Member
    bool lastMRight; // 0xF6 Member
    bool mLDown; // 0xF7 Member
    bool mRDown; // 0xF8 Member
    bool mLUp; // 0xF9 Member
    bool mRUp; // 0xFA Member
    bool swapMouseButtons; // 0xFB Member
    Ogre::Vector2 mPos; // 0xFC Member
    Ogre::Vector2 mPosAbs; // 0x104 Member
    Ogre::Vector3 mSpeed; // 0x10C Member
    int mWheel; // 0x118 Member
    ~InputHandler();// RVA = 0x684D30
    // no_addr public class InputHandler & operator=(const class InputHandler &);
    // no_addr public void * __vecDelDtor(unsigned int);
};
