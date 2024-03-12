#pragma once

#include <stdint.h>
#include <Release_Assert.h>

/* Here's how all this black magic fuckery works
* functions.asm declares an array of pointers to the game's functions
* it also generates a function defintion for every function defined in a header we use, using the function's mangled symbol name
* The function definition is one instruction - a jmp to the corresponding address in the function pointer table
* All function definitions become tightly-packed when assembled, and since each definition consists of one single 
* identical instruction, each function body has the exact same size in bytes.
* Thus, we can get the "index" of a function in the address table by taking the function's address, subtracting 
* the address of the first defined function, and dividing by the length of a jmp instruction.
* You can then use that index in the function pointer table to get the actual address of the function in the game's code.
* The end result is that you can call any function the game defines using it's regular C++ syntax, and the call will be passed on to the .exe
* as we've created a valid statically-linked definition for it, and you can also get the address of the function in the game's code
* in order to hook it by passing the address of the statically-linked function to GetRealAddress()
* As an added bonus, the pointer table is writeable, so we can dynamically load the offsets for the correct game version at runtime.
* Note: The order of pointers in the pointer array and the order functions are defined in inside functions.asm must be
* EXACTLY IDENTICAL else the whole system breaks.
*/

// array containing absolute function addresses - the length here doesn't matter as it's set in functions.asm
extern "C" intptr_t function_pointers[1];
// address of first function definition
extern "C" void FUNC_BEGIN(void);
extern "C" void FUNC_END(void);
extern "C" const uint32_t FUNCTION_SIZE;
extern "C" const uint32_t FUNCTION_BUFF_LENGTH;
// amount of "error" in the compiled function table, this MUST be 0
extern "C" const uint32_t FUNCTION_ERROR;

// NOTE: doesn't work with virtual functions
inline intptr_t GetFunctionSlot(void* ptr)
{
	intptr_t functionsStart = (intptr_t)&FUNC_BEGIN;
	intptr_t functionAddr = (intptr_t)ptr;
	intptr_t slot = (functionAddr - functionsStart) / FUNCTION_SIZE;
	return (functionAddr - functionsStart) / FUNCTION_SIZE;
}

template<typename T>
// NOTE: doesn't work with virtual functions
intptr_t GetFunctionSlotDebug(T fun)
{
	return GetFunctionSlot((void*&)fun); // the cast has to be to a ref to work with member functions in VC++
}

// usage: GetShimAddress(&Class::function)
// returns the address of the JMP instruction corresponding to that function
template<typename T>
// NOTE: doesn't work with virtual functions
intptr_t GetShimAddress(T fun)
{
	return (intptr_t&)fun; // the cast has to be to a ref to work with member functions in VC++
}

// usage: GetRealAddress(&Class::function)
// NOTE: doesn't work with virtual functions
template<typename T>
intptr_t GetRealAddress(T fun)
{
	assert_release((intptr_t&)fun >= (intptr_t)&FUNC_BEGIN && (intptr_t&)fun <= (intptr_t)&FUNC_END);
	return function_pointers[GetFunctionSlot((void*&)fun)]; // the cast has to be to a ref to work with member functions in VC++
}

// NOTE: doesn't work with virtual functions
template<typename T>
T GetRealFunction(T fun)
{
	return (T)GetRealAddress(fun);
}


/*
inline bool CheckFunctionTable()
{
	return FUNCTION_ERROR == 0;
}

template<typename T>
intptr_t GetMemberPointer(T fun)
{
	void* pPtr = (void*&)fun; // the cast has to be to a ref to work with member functions in VC++
	return (intptr_t)pPtr;
}
*/
