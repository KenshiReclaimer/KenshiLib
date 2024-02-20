#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>

#include <vector>

// RVAs are for Array2d<Item>
template<typename T>
class Array2d
{
public:
    // no_addr void Array2d<Item>();// public
    // no_addr void Array2d<Item>();// public
    Array2d<T>(unsigned int nRows, unsigned int nCols);// public RVA = 0x5DECD0
    void resize(unsigned int nrows, unsigned int ncols, bool clear);// public RVA = 0x5DF300
    void setToZeros();// public RVA = 0x5DA4E0
    class BadSize
    {
    };
    const T* operator()(unsigned int row, unsigned int col) const;// public RVA = 0x5D5FC0
    T*& operator()(unsigned int row, unsigned int col);// public RVA = 0x5D6000
    class BoundsViolation
    {
    };
    // no_addr unsigned int numRows();// public
    // no_addr unsigned int numCols();// public
    unsigned int nRows; // 0x0 Member
    unsigned int nCols; // 0x4 Member
    // Ogre::vector<T*>::type is throwing mad errors
    std::vector<T*, Ogre::STLAllocator<T*, Ogre::GeneralAllocPolicy > > data; // 0x8 Member
    ~Array2d<T>();// public RVA = 0x5DCBA0
    // no_addr class Array2d<Item> & operator=(const class Array2d<Item> &);// public
    // no_addr void * __vecDelDtor();// public
};
