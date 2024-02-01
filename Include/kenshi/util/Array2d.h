#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>

#include <vector>

// RVAs are for Array2d<Item>
template<typename T>
class Array2d
{
public:
    // no_addr public void Array2d<Item>(const class Array2d<Item> &);
    // no_addr public void Array2d<Item>();
    Array2d<T>(unsigned int, unsigned int);// RVA = 0x5DECD0
    void resize(unsigned int, unsigned int, bool);// RVA = 0x5DF300
    void setToZeros();// RVA = 0x5DA4E0
    class BadSize
    {
    };
    const T* operator()(unsigned int, unsigned int) const;// RVA = 0x5D5FC0
    T*& operator()(unsigned int, unsigned int);// RVA = 0x5D6000
    class BoundsViolation
    {
    };
    // no_addr public unsigned int numRows();
    // no_addr public unsigned int numCols();
    unsigned int nRows; // 0x0 Member
    unsigned int nCols; // 0x4 Member
    std::vector<T*, Ogre::STLAllocator<T*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > data; // 0x8 Member
    ~Array2d<T>();// RVA = 0x5DCBA0
    // no_addr public class Array2d<Item> & operator=(const class Array2d<Item> &);
    // no_addr public void * __vecDelDtor(unsigned int);
};
