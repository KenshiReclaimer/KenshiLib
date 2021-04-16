#pragma once

#include <stdafx.h>

/*
	Class that implements RVA resolution at runtime. Mostly like how F4SE/SKSE64 implement it.
*/

typedef size_t offset_t;

class RVACore
{
public:

    RVACore(offset_t rva);
	/* TODO FIX COMPILER
	RVACore(
		const std::string& pattern, 
		uintptr_t(*onFound)(uintptr_t) = [](uintptr_t addr) { return addr; },
		const char* moduleName = nullptr
		);
	*/

    uintptr_t GetUIntPtr() const
	{
		return m_addr;
	}
	
protected:

    static uintptr_t c_base;
	static size_t c_size;

    uintptr_t m_addr;

	/* TODO FIX COMPILER
    RVACore() = delete;
    RVACore(RVACore & rhs) = delete;
	RVACore & operator=(RVACore & rhs) = delete;
	*/
};

template <typename T>
class RVAPtr : public RVACore
{
public:
	using RVACore::RVACore;

	// HACK temporary fix for RVA compilation
	RVAPtr(offset_t ptr) : RVACore(ptr) {};

	operator T *() const
	{
		return GetPtr();
	}

	T * operator->() const
	{
		return GetPtr();
	}

	T * GetPtr() const
	{
		return reinterpret_cast <T *>(m_addr);
	}

	const T * GetConst() const
	{
		return reinterpret_cast <T *>(m_addr);
	}

private:
	/* TODO FIX COMPILER
	RVAPtr(RVAPtr& rhs) = delete;
	*/
};

/* TODO FIX COMPILER
template <typename _Ret, typename... _Args>
class RVAFn : public RVACore
{
public:
	using Type = _Ret(*)(_Args...);

	_Ret operator()(_Args... e)
	{
		return reinterpret_cast<Type>(m_addr)(e);
	}

private:
};
*/

uintptr_t ProtectedDeref(uintptr_t addr);

uintptr_t ProtectedDerefRel(uintptr_t addr);
// Addr expected from start of instruction, not from the offset
// makes it easier to work with in ida