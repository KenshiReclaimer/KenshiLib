#pragma once

#include <kenshi/util/lektor.h>
#include <ogre/OgreMemoryAllocatorConfig.h>

class GameData;

class TradeCulture
{
public:
    void reset();// public RVA = 0x944DD0
    void setupTradeCulture(GameData * dat);// public RVA = 0x7FC740
    lektor<GameData *> forbiddenItems; // 0x0 Member
    std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::GeneralAllocPolicy > > illegalBuildings; // 0x18 Member
    std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::GeneralAllocPolicy > > happyBuildings; // 0x40 Member
    std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::GeneralAllocPolicy > > illegalItems; // 0x68 Member
    std::map<GameData *,float,std::less<GameData *>,Ogre::STLAllocator<std::pair<GameData * const,float>,Ogre::GeneralAllocPolicy > > tradeGoodsMults; // 0x90 Member
    const lektor<GameData *> & getForbiddenItemsList() const;// public RVA = 0x95C910
    bool isItemIllegal(GameData * item) const;// public RVA = 0x71C890
    const std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::GeneralAllocPolicy > > * getAllIllegalItems() const;// public RVA = 0x670B30
    float getTradePriceMultiplier(GameData * item);// public RVA = 0x949930
    bool hasTradePriceMultiplier(GameData * item);// public RVA = 0x9467B0
    // no_addr void TradeCulture(const class TradeCulture & _a1);// public missing arg names
    TradeCulture();// public RVA = 0x80EFA0
    void _CONSTRUCTOR();// public RVA = 0x80EFA0
    ~TradeCulture();// public RVA = 0x80F050
    void _DESTRUCTOR();// public RVA = 0x80F050
    // no_addr class TradeCulture & operator=(const class TradeCulture & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
