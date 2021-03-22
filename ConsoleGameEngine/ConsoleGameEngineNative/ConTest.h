#pragma once

#ifdef __cplusplus
#define EXPORT_FUNC extern "C" __declspec(dllexport) bool __stdcall
#else
#define EXPORT_FUNC extern __declspec(dllexport) bool __stdcall
#endif

namespace ConsoleGameEngineNative
{
    EXPORT_FUNC TryToLoadNativeDLL();
}