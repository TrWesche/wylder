#pragma once

// .dll import & export only applies to Windows builds. The constants WY_PLATFORM_WINDOWS & WY_BUILD_DLL are defined in the Preprocessor definitions of the Wylder Solution & Applications Using the Wylder Engine (ex. Sandbox)
// Configuration Properties\ C/C++\ Preprocessor
#ifdef WY_PLATFORM_WINDOWS
	// WY_BUILD_DLL will only be defined for the Wylder Engine Library, this will automatically setup the __declspec with the correct behavior depending on the use case.
	#ifdef WY_BUILD_DLL
		#define WYLDER_API __declspec(dllexport)
	#else
		#define WYLDER_API __declspec(dllimport)
	#endif
#else
	#error Wylder currently only supports Windows
#endif