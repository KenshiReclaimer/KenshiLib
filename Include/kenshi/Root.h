#pragma once

#include <ogre/OgreString.h>

namespace Kenshi
{
    struct RootObjectBase
    {

        virtual ~RootObjectBase();

        virtual Ogre::String& GetState();
        virtual void SetState(const Ogre::String& state);
        virtual void GetVirtualProcessorRoot(); // ?GetVirtualProcessorRoot@UMSThreadProxy@details@Concurrency@@QEAAPEAVUMSFreeVirtualProcessorRoot@23@XZ ; Concurrency::details::UMSThreadProxy::GetVirtualProcessorRoot(void)
        virtual void sub_7FF7F0DB6C80();
        virtual void sub_7FF7F09E10C0();
        virtual void sub_7FF7F09E1100();
        virtual void unknown_libname_373(); //; Microsoft VisualC v7/14 64bit runtime
        virtual void sub_7FF7F09E1130();
        virtual void sub_7FF7F09E1150();
        virtual void sub_7FF7F09E1160();
        virtual void sub_7FF7F0DB6FC0(); // ; #STR: "nofac"
        virtual long GetSchedulerId();
        virtual void sub_7FF7F09E1180();
        virtual void sub_7FF7F09E1190();
        virtual void sub_7FF7F09E11A0();
        virtual void sub_7FF7F09E11B0();
        virtual void sub_7FF7F0F15550();
        virtual void sub_7FF7F0F15550_1();
        virtual void sub_7FF7F09E11D0();
        virtual void sub_7FF7F0DB7D90();
    };

    struct RootObject : public RootObjectBase
    {

    };

    struct RootObjectSimple : public RootObject
    {
    public:

        static RootObjectSimple* Instance();
    };
}

