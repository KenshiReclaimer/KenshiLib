#pragma once

#include <map>
 
#include <ogre/OgreMemoryAllocatorConfig.h>

// RVAs from FitnessSelector<CombatTechniqueData*>
template<typename T>
class FitnessSelector
{
public:
    // no_addr void FitnessSelector<CombatTechniqueData *>(const class FitnessSelector<CombatTechniqueData *> &);// public
    // no_addr void FitnessSelector<CombatTechniqueData *>();// public
    // no_addr void reset();// public
    // no_addr void deleteAll();// public
    // no_addr int size();// public
    // no_addr bool hasItem(class CombatTechniqueData * const);// public
    // no_addr bool empty();// public
    // no_addr float getItemScore(class CombatTechniqueData * const);// public
    // no_addr void addItem(class CombatTechniqueData *, const float);// public
    // no_addr bool removeItem(class CombatTechniqueData * const);// public
    // no_addr class CombatTechniqueData * chooseAnItem(class boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253> &);// public
    // no_addr class CombatTechniqueData * chooseAnItem();// public
    // no_addr class CombatTechniqueData * chooseAnItem_absoluteScore();// public
    // no_addr class CombatTechniqueData * chooseHighest();// public
    // no_addr class CombatTechniqueData * takeHighest();// public
    // no_addr class CombatTechniqueData * takeRandom();// public
    std::map<float, T, std::less<float>, Ogre::STLAllocator<std::pair<float const, T>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > list; // 0x0 Member
    std::map<T, float, std::less<T>, Ogre::STLAllocator<std::pair<T const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > itemsScores; // 0x28 Member
    float totalScore; // 0x50 Member
    float highestScore; // 0x54 Member
    T highestItem; // 0x58 Member
    // no_addr void ~FitnessSelector<CombatTechniqueData *>();// public
    // no_addr class FitnessSelector<CombatTechniqueData *> & operator=(const class FitnessSelector<CombatTechniqueData *> &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};
