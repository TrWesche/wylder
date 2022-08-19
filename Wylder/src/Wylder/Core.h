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


#ifdef WY_ENABLE_ASSERTS
	#ifdef WY_PLATFORM_WINDOWS
		#define WY_ASSERT(x, ...) {if (!(x)) { WY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }} // If an assertion fails in processing break out of processing loop
		#define WY_CORE_ASSERT(x, ...) {if (!(x)) { WY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#endif // WY_PLATFORM_WINDOWS
#else
	#define WY_ASSERT(x,...);
	#define WY_CORE_ASSERT(x,...);
#endif

#define BIT(x) (1 << x)


#define WY_EVENT_FN_BIND(x) std::bind(&x, this, std::placeholders::_1)