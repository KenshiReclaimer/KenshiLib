#pragma once

namespace Kenshi 
{

    struct Tasker // TBD, still working
    {
        virtual ~Tasker();

        virtual void Start(Tasker* task, /* CharBody* usually */ void* owner);
        virtual void Update(Tasker* task, /* CharBody* usually */ void* owner);
        virtual void Complete(Tasker* task, /* CharBody* usually */ void* owner);

        virtual bool IsComplete(Tasker* task);

    };

}