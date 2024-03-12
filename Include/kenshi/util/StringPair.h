#pragma once

#include <string>

class StringPair
{
public:
    // VTable         : (none)
    // no_addr void StringPair(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a2, float _a3);// public missing arg names
    // no_addr void StringPair(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1, float _a2);// public missing arg names
    StringPair(const std::string& a, const std::string& b);// public RVA = 0xAC0A0
    void _CONSTRUCTOR(const std::string& a, const std::string& b);// public RVA = 0xAC0A0
    StringPair(const StringPair& a);// public RVA = 0x229790
    void _CONSTRUCTOR(const StringPair& a);// public RVA = 0x229790
    StringPair(const std::string& a);// public RVA = 0xAC790
    void _CONSTRUCTOR(const std::string& a);// public RVA = 0xAC790
    StringPair();// public RVA = 0xAC710
    void _CONSTRUCTOR();// public RVA = 0xAC710
    virtual ~StringPair();// public RVA = 0xAA880 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0xAA880 vtable offset = 0x0
    std::string s1; // 0x8 Member
    std::string s2; // 0x30 Member
    float val1; // 0x58 Member
    virtual const StringPair& operator=(const StringPair& a);// public RVA = 0xAC810 vtable offset = 0x8
    const StringPair& _NV_operator_assign(const StringPair& a);// public RVA = 0xAC810 vtable offset = 0x8
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};