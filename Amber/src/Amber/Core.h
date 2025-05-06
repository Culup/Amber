#pragma once

#ifdef AB_PLATFORM_WINDOWS
	#ifdef AB_BUILD_DLL
		#define AMBER_API __declspec(dllexport)
	#else
		#define AMBER_API __declspec(dllimport)
	#endif
#else
	#error Amber only supports Windows Operating Systems!
#endif

#ifdef AB_ENABLE_ASSERTS
	#define AB_ASSERT(x, ...) { if(!(x)) { AB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AB_CORE_ASSERT(x, ...) { if(!(x)) { AB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AB_ASSERT(x, ...)
	#define AB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)