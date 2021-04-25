#pragma once



namespace KenshiLib {

	class HookManager
	{
	public:

		template<typename _Src, typename _Dst>
		union Translator
		{
			_Src src;
			_Dst dst;

			constexpr Translator(_Src _src) : src(_src) {}
		};


		HookManager() {}
		HookManager(const char* module_name);

		bool WriteCallBase(void* src, void* dst);
		bool WriteJumpBase(void* src, void* dst);
		bool WriteDetourBase(void* src, void* dst);

		template<typename _Src, typename _Dst>
		bool WriteCall(_Src src, _Dst dst)
		{
			return WriteCallBase(
				Translator<_Src, void*>(src).dst,
				Translator<_Dst, void*>(dst).dst
			);
		}

		template<typename _Src, typename _Dst>
		bool WriteJump(_Src src, _Dst dst)
		{
			return WriteJumpBase(
				Translator<_Src, void*>(src).dst,
				Translator<_Dst, void*>(dst).dst
			);
		}

		template<typename _Src, typename _Dst>
		bool WriteDetour(_Src src, _Dst dst)
		{
			return WriteDetourBase(
				Translator<_Src, void*>(src).dst,
				Translator<_Dst, void*>(dst).dst
			);
		}


		template<typename _Src, typename _Dst>
		_Dst Getx86BranchOriginal(_Src source)
		{
			uintptr_t p = Translator<_Src, uintptr_t>(source).dst;
			p += *(uint32_t*)(p + 1) + 5;
			return Translator<uintptr_t, _Dst>(p).dst;
		}

	private:

		void* Allocate(size_t size);

		void* m_base;
		void* m_end;
		void* m_seek;
	};

	extern HookManager g_mainHookManager;
}