#pragma once

#include <assert.h>
#include <ogre/OgreMemorySTLAllocator.h>
#include <stdint.h>

template <typename T>
class lektor : Ogre::STLAllocator<T, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
    // Ogre::STLAllocator<int,Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x8
public:

        typedef       T* iterator;
        typedef const T* const_iterator;

        iterator       begin()       { return stuff; }
        const_iterator begin() const { return stuff; }
        iterator       end()         { return stuff + count; }
        const_iterator end()   const { return stuff + count; }

        T& at(uint32_t index) {
            assert(stuff && index < count);
            return stuff[index];
        }

        T& operator[](uint32_t index) {
            return at(index);
        }

        const T& operator[](uint32_t index) const {
            assert(stuff && index < count);
            return stuff[index];
        }

        bool valid() const { return stuff != nullptr; }
        void clear() { count = 0; }

        uint32_t size()     const { return count; }
        uint32_t capacity() const { return maxSize; }

        T& find_first(bool* found, bool(*cmpfn)(T&))
        {
            for (uint32_t i = 0; i < maxSize; ++i) {
                if (cmpfn(stuff[i])) {
                    return stuff[i];
                }
            }
        }


private:
    uint32_t count;
    uint32_t maxSize;
    T* stuff;
};
