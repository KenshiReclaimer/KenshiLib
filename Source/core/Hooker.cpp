#include <stdafx.h>

#include <core\Hooker.h>
#include <cassert>


namespace KenshiLib {

	constexpr BYTE X86_OP_JMP = 0xE9;
	constexpr BYTE X86_OP_CALL = 0xE8;


	bool Writex86Rel(BYTE op, uintptr_t source, uintptr_t dest)
	{
#pragma pack(push, 1)
		struct {
			BYTE op;
			DWORD jump;
		} payload;
#pragma pack(pop)
		SIZE_T bytesWritten;

		payload.op = op;
		payload.jump = dest - source - 5;


		return WriteProcessMemory(GetCurrentProcess(), (LPVOID)source, &payload, sizeof(payload), &bytesWritten) > 0;
	}


HookManager::HookManager(const char* module_name)
	: m_base(nullptr), m_end(nullptr), m_seek(nullptr)
{
	size_t len = 1024 * 128;

	uintptr_t moduleBase = (uintptr_t)GetModuleHandleA(module_name);
	uintptr_t addr = moduleBase;
	uintptr_t lowestOKAddress = moduleBase - 0x80000000 + (1024 * 1024 * 128);	// largest 32-bit displacement with 128MB scratch space
	addr--;

	while (!m_base)
	{
		MEMORY_BASIC_INFORMATION info;

		if (!VirtualQuery((void*)addr, &info, sizeof(info)))
		{
			break;
		}

		if (info.State == MEM_FREE)
		{
			// free block, big enough?
			if (info.RegionSize >= len)
			{
				// try to allocate it
				addr = ((uintptr_t)info.BaseAddress) + info.RegionSize - len;

				m_base = (void*)VirtualAlloc((void*)addr, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
				if (m_base)
				{
					m_end = (void*)((uintptr_t)m_base + len);
					m_seek = m_base;
				}
				else
				{
				}
			}
		}

		// move back and try again
		if (!m_base)
		{
			addr = ((uintptr_t)info.BaseAddress) - info.RegionSize;
		}

		if (addr < lowestOKAddress)
		{
			break;
		}
	}

	assert(m_base != nullptr);
}

void* HookManager::Allocate(size_t size)
{

	void* result = m_seek;

	m_seek = (void*)((uintptr_t)m_seek + size);
	assert(m_seek < m_end);

	return result;
}

bool HookManager::WriteCallBase(void* src, void* dst)
{
	return false;
}

bool HookManager::WriteJumpBase(void* vsrc, void* vdst)
{
	bool result = false;
	uintptr_t src = (uintptr_t)vsrc;
	uintptr_t dst = (uintptr_t)vdst;
	ptrdiff_t off = dst - src;

	if (off < INT32_MAX && off > INT32_MIN) {
		return Writex86Rel(X86_OP_JMP, src, dst);
	}
		

#pragma pack(push, 1)
	// code placed in trampoline
	struct TrampolineCode
	{
		// jmp [rip]
		uint8_t	escape;	// FF
		uint8_t	modrm;	// 25
		uint32_t	displ;	// 00000000
		// rip points here
		uint64_t	dst;	// target

		void Init(uintptr_t _dst)
		{
			escape = 0xFF;
			modrm = 0x25;
			displ = 0;
			dst = _dst;
		}
	};

	struct HookCode
	{
		// jmp disp32
		uint8_t	op;		// E9 for jmp, E8 for call
		int32_t	displ;	// 

		void Init(int32_t _displ, uint8_t _op)
		{
			op = _op;
			displ = _displ;
		}
	};
#pragma pack(pop)


	TrampolineCode* trampolineCode = (TrampolineCode*)Allocate(sizeof(TrampolineCode));
	if (trampolineCode)
	{
		trampolineCode->Init(dst);

		HookCode hookCode;

		uintptr_t	trampolineAddr = uintptr_t(trampolineCode);
		uintptr_t	nextInstr = src + sizeof(hookCode);
		ptrdiff_t	trampolineDispl = trampolineAddr - nextInstr;

		// should never fail because we're branching in to the trampoline
		assert((trampolineDispl >= _I32_MIN) && (trampolineDispl <= _I32_MAX));

		hookCode.Init(trampolineDispl, 0xE9);
		SIZE_T bytesWritten;
		WriteProcessMemory(GetCurrentProcess(), (LPVOID)src, &hookCode, sizeof(hookCode), &bytesWritten);

		result = true;
	}

	// do this for now so it's obvious when something goes wrong
	assert(result);

	return result;
}

bool HookManager::WriteDetourBase(void* src, void* dst)
{
	return false;
}

HookManager g_mainHookManager;

}