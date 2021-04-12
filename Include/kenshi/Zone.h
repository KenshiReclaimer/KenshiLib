#pragma once


namespace Kenshi
{
    struct ZoneManagerInterfaceT
    {

        virtual ~ZoneManagerInterfaceT();

        virtual void vfn1();
        virtual void vfn2();
        virtual void vfn3();
        virtual void vfn4();
    };


    struct ZoneManager : public ZoneManagerInterfaceT
    {

    };
}