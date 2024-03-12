#pragma once


class YesNoMaybe
{
public:
    enum ynm
    {
        NO,
        YES,
        MAYBE    
    };

    YesNoMaybe(int a);// public RVA = 0x2C4510
    void _CONSTRUCTOR(int a);// public RVA = 0x2C4510
    YesNoMaybe(YesNoMaybe & k);// public RVA = 0x2914B0
    void _CONSTRUCTOR(YesNoMaybe & k);// public RVA = 0x2914B0
    YesNoMaybe(YesNoMaybe::ynm k);// public RVA = 0x167DF0
    void _CONSTRUCTOR(YesNoMaybe::ynm k);// public RVA = 0x167DF0
    YesNoMaybe();// public RVA = 0x5C0360
    void _CONSTRUCTOR();// public RVA = 0x5C0360
    YesNoMaybe::ynm key; // 0x0 Member
    operator bool() const;// public RVA = 0x2C4530
    operator YesNoMaybe::ynm() const;// public RVA = 0x2C4540
    // no_addr bool operator==(class YesNoMaybe _a1);// public missing arg names
    bool operator==(YesNoMaybe::ynm a) const;// public RVA = 0x88D40
    // no_addr bool operator==(bool _a1);// public missing arg names
    bool operator!=(YesNoMaybe a) const;// public RVA = 0x522BF0
    bool operator!=(YesNoMaybe::ynm a) const;// public RVA = 0x2914C0
    bool operator!=(bool a) const;// public RVA = 0x522BD0
    int toInt();// public RVA = 0x2C4570
};
