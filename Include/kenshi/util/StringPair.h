#pragma once

#include <string>

class StringPair
{
    // no_addr public void StringPair(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float);
    // no_addr public void StringPair(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float);
public:
    StringPair(const std::string& a, const std::string& b);// RVA = 0xAC0A0
    StringPair(const StringPair& a);// RVA = 0x229790
    StringPair(const std::string& a);// RVA = 0xAC790
    StringPair();// RVA = 0xAC710
    virtual ~StringPair();// RVA = 0xAA880// vtable offset = 0x0
    std::string s1; // 0x8 Member
    std::string s2; // 0x30 Member
    float val1; // 0x58 Member
    virtual const StringPair& operator=(const StringPair&);// RVA = 0xAC810// vtable offset = 0x8
    // no_addr public void __local_vftable_ctor_closure();
    // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};