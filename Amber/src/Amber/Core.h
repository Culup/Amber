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
