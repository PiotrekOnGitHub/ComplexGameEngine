#pragma once

#ifdef CE_PLATFORM_WINDOWS
	#ifdef CE_BUILD_DLL
		#define COMPLEX_API __declspec(dllexport)
	#else
		#define COMPLEX_API __declspec(dllimport)
	#endif
#else
	#error Complex Engine only supports Windows!
#endif
