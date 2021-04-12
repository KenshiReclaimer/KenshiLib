
#if 0
#include <UI.h>

#include <stdio.h>

// NOTE(KAOS): not really needed I dont think, but here since i didnt think about it lol
MyGUI::Gui* Kenshi::getGuiInstance()
{
    // 48 8B D0 48 8D 45 C7 48 89 44 24 48
    static RVAPtr<MyGUI::Gui*> c_inst(0x1AAD858);
    printf("getGuiInstance() = %p\n", c_inst.GetUIntPtr());
    return *c_inst;
}
#endif