#include <stdafx.h>

#include <kenshi/Root.h>


Kenshi::RootObjectSimple* Kenshi::RootObjectSimple::Instance()
{
    // .text:00007FF7F1006229                 mov     cs:g_rootObjectSimple, rax
    // .text:00007FF7F1006230                 mov     [rbp+57h+var_48], 0Fh
    // .text:00007FF7F1006238                 mov     [rbp+57h+var_50], rdi
    // .text:00007FF7F100623C                 mov     byte ptr [rbp+57h+Src], 0
    // .text:00007FF7F1006240                 mov     r8d, 11h        ; Size
    // .text:00007FF7F1006246                 lea     rdx, aUnloadedNotDea ; "UNLOADED_NOT_DEAD"
    // .text:00007FF7F100624D                 lea     rcx, [rbp+57h+Src] ; void *
    // .text:00007FF7F1006251                 call    std__string__ctor ; #STR: "string too long"
    // .text:00007FF7F1006256                 nop
    // Just look for UNLOADED_NOT_DEAD

    static RVAPtr<RootObjectSimple*> c_inst(0x1AADEC0);
    return *c_inst;
}