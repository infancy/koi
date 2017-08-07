#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef KOI_CORE_PLATFORM_H
#define KOI_CORE_PLATFORM_H

#if defined(_WIN32) || defined(_WIN64)
	#define KOI_IN_WINDOWS
	#if defined(_MSC_VER)
		#define KOI_IN_MSVC
	#elif defined(__MINGW32__)  
		#define KOI_IN_MINGW
	#endif
#elif defined(__linux__)
	#define KOI_IN_LINUX
#elif defined(__APPLE__)
	#define KOI_IN_OSX
#endif

/*
#if defined(_MSC_VER) 
	#if _MSC_VER == 1910
	#define KOI_IN_MSVC2017
	#elif _MSC_VER == 1900
	#define KOI_IN_MSVC2015
	#endif
#endif
*/

//platform features

#if defined(KOI_IN_LINUX) || defined(KOI_IN_WINDOWS)
#define KOI_HAVE_MALLOC_H
#endif

#if defined(KOI_IN_MSVC)
#define KOI_THREAD_LOCAL __declspec(thread)
#else
#define KOI_THREAD_LOCAL __thread
#endif

#if defined(KOI_IN_MSVC)
#define KOI_FORCEINLINE __forceinline
#else
#define KOI_FORCEINLINE __attribute__((always_inline)) inline
#endif

#endif //KOI_CORE_PLATFORM_H



