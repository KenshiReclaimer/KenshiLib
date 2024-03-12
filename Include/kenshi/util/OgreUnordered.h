#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>

#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

// TODO can this be done with typedefs?
template<typename T1, typename T2>
struct ogre_unordered_map
{
	typedef boost::unordered::unordered_map<T1, T2, boost::hash<T1>, std::equal_to<T1>, Ogre::STLAllocator<std::pair<T1 const, T2>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > type;
};

template<typename T>
struct ogre_unordered_set
{
	typedef boost::unordered::unordered_set<T, boost::hash<T>, std::equal_to<T>, Ogre::STLAllocator<T, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > type;
};