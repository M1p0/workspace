#ifndef __BASE_ENGINE_KG_MODULEEXPORT_H__
#define __BASE_ENGINE_KG_MODULEEXPORT_H__

#ifdef __GNUC__     // linux

#ifdef ENGINE_EXPORTS               // 动态库使用
#define ENGINE_API   __attribute__((visibility("default")))
#define C_ENGINE_API extern "C" __attribute__((visibility("default")))
#else                               // 静态库使用
#define ENGINE_API
#define C_ENGINE_API extern "C"
#endif

#else               // WIN32

#if defined(ENGINE_EXPORTS)         // 动态库使用
#define ENGINE_API   __declspec(dllexport)
#define C_ENGINE_API extern "C" __declspec(dllexport)
#elif defined(ENGINE_STATIC)        // 静态库使用
#define ENGINE_API
#define C_ENGINE_API extern "C"
#else                               // 动态库使用
#define ENGINE_API   __declspec(dllimport)
#define C_ENGINE_API extern "C" __declspec(dllimport)
#endif

#endif

C_ENGINE_API int Sum(int a, int b);

#endif  // __BASE_ENGINE_KG_MODULEEXPORT_H__
