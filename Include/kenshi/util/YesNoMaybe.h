#pragma once

class YesNoMaybe
{
public:
    enum ynm
    {
        NO = 0x0,
        YES = 0x1,
        MAYBE = 0x2
    };

    YesNoMaybe(int);// RVA = 0x224E30
    YesNoMaybe(YesNoMaybe&);// RVA = 0x1FB8D0
    YesNoMaybe(YesNoMaybe::ynm);// RVA = 0x109830
    YesNoMaybe();// RVA = 0x491B40
    ynm key; // 0x0 Member
    operator bool();// RVA = 0x224E50
    operator ynm();// RVA = 0x224E60
    // no_addr public bool operator==(class YesNoMaybe);
    bool operator==(YesNoMaybe::ynm);// RVA = 0x594F0
    // no_addr public bool operator==(bool);
    bool operator!=(YesNoMaybe);// RVA = 0x412270
    bool operator!=(YesNoMaybe::ynm);// RVA = 0x1FB8E0
    bool operator!=(bool);// RVA = 0x412250
    int toInt();// RVA = 0x224EA0
};