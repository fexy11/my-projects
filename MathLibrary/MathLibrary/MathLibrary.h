#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern MATHLIBRARY_API void fibonacci_init(
    const unsigned long long a, const unsigned long long b);

extern MATHLIBRARY_API bool fibonacci_next();

extern MATHLIBRARY_API unsigned long long fibonacci_current();

extern MATHLIBRARY_API unsigned fibonacci_index();