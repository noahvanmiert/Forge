#pragma once


#ifdef FG_PLATFORM_WINDOWS
	// Windows Specific Macros
#else
	#error Forge only supports Windows for now!
#endif


#ifdef FG_DEBUG
	#define FG_ENABLE_ASSERTS
#endif

#ifdef FG_ENABLE_ASSERTS
	#define FG_ASSERT(x, ...)      { if(!(x)) { FG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FG_CORE_ASSERT(x, ...) { if(!(x)) { FG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FG_ASSERT(x, ...)
	#define FG_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
