#include "Debug.h"
#include <crtdefs.h>

// defines assert_release() without defining assert()
extern "C" {
	_CRTIMP void __cdecl _wassert(_In_z_ const wchar_t* _Message, _In_z_ const wchar_t* _File, _In_ unsigned _Line);
}
#define STRINGIZE(x) STRINGIZE2(x)
#define STRINGIZE2(x) #x
#define LINE_STRING STRINGIZE(__LINE__)
#define assert_release(expression) \
	((!!(expression)) \
	|| (ErrorLog(std::string("Assertion failed: ") + #expression + " in " + __FILE__ + " line: " + LINE_STRING), 0) \
	|| (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0)) /*(throw std::exception("Assert failed"), 0))*/
