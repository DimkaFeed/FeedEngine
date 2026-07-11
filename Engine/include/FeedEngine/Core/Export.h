#pragma once

#ifdef FE_ENGINE_EXPORTS
#define FE_API __declspec(dllexport)
#else
#define FE_API __declspec(dllimport)
#endif