#pragma once

#include <stdafx.h>

namespace Kenshi
{
    class hand
    {
    public:
        virtual bool check(bool is11);
        virtual bool isEqual(const hand& compare);
        virtual bool isNotEqual(const hand& compare);

    public:
        uint32_t a, b;
        void* ptr1;
        void* ptr2;
    };
}
