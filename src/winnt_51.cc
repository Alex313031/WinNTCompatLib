//
// EnlyzeWinCompatLib - Let MSVC v141_xp targeted applications run on even older Windows versions
// Copyright (c) 2021 Colin Finck, ENLYZE GmbH <c.finck@enlyze.com>
// SPDX-License-Identifier: MIT
//

// This file implements required APIs not available in Windows XP RTM (NT 5.1).
#include "libnt5_internal.h"

typedef PVOID (WINAPI *PFN_DECODEPOINTER)(PVOID Ptr);
typedef PVOID (WINAPI *PFN_ENCODEPOINTER)(PVOID Ptr);

typedef BOOL (WINAPI *PFN_HEAPQUERYINFORMATION)(HANDLE hHeap, HEAP_INFORMATION_CLASS heapClass, PVOID heapInfo, SIZE_T heapLength, PSIZE_T returnLength);
typedef BOOL (WINAPI *PFN_HEAPSETINFORMATION)(HANDLE hHeap, HEAP_INFORMATION_CLASS heapClass, PVOID heapInfo, SIZE_T heapLength);

static PFN_DECODEPOINTER pfnDecodePointer = nullptr;
static PFN_ENCODEPOINTER pfnEncodePointer = nullptr;

static PFN_HEAPQUERYINFORMATION pfnHeapQueryInformation = nullptr;
static PFN_HEAPSETINFORMATION pfnHeapSetInformation = nullptr;

static PVOID WINAPI
_CompatDecodePointer(PVOID Ptr)
{
    // Just return the input pointer without any decoding.
    return Ptr;
}

static PVOID WINAPI
_CompatEncodePointer(PVOID Ptr)
{
    // Just return the input pointer without any encoding.
    return Ptr;
}

static BOOL WINAPI
_CompatHeapQueryInformation(HANDLE HeapHandle,
                            HEAP_INFORMATION_CLASS HeapInformationClass,
                            PVOID HeapInformation,
                            SIZE_T HeapInformationLength,
                            PSIZE_T ReturnLength) {
  UNREFERENCED_PARAMETER(HeapHandle);
  UNREFERENCED_PARAMETER(HeapInformationClass);
  UNREFERENCED_PARAMETER(HeapInformation);
  UNREFERENCED_PARAMETER(HeapInformationLength);
  UNREFERENCED_PARAMETER(ReturnLength);
  return FALSE;
}

static BOOL WINAPI
_CompatHeapSetInformation(HANDLE HeapHandle,
                          HEAP_INFORMATION_CLASS HeapInformationClass,
                          PVOID HeapInformation,
                          SIZE_T HeapInformationLength) {
  UNREFERENCED_PARAMETER(HeapHandle);
  UNREFERENCED_PARAMETER(HeapInformationClass);
  UNREFERENCED_PARAMETER(HeapInformation);
  UNREFERENCED_PARAMETER(HeapInformationLength);
  return FALSE;
}

extern "C" PVOID WINAPI
LibDecodePointer(PVOID Ptr)
{
    if (!pfnDecodePointer)
    {
        // Check if the API is provided by kernel32, otherwise fall back to our implementation.
        HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
        pfnDecodePointer = reinterpret_cast<PFN_DECODEPOINTER>(GetProcAddress(hKernel32, "DecodePointer"));
        if (!pfnDecodePointer)
        {
            pfnDecodePointer = _CompatDecodePointer;
        }
    }

    return pfnDecodePointer(Ptr);
}

extern "C" PVOID WINAPI
LibEncodePointer(PVOID Ptr)
{
    if (!pfnEncodePointer)
    {
        // Check if the API is provided by kernel32, otherwise fall back to our implementation.
        HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
        pfnEncodePointer = reinterpret_cast<PFN_ENCODEPOINTER>(GetProcAddress(hKernel32, "EncodePointer"));
        if (!pfnEncodePointer)
        {
            pfnEncodePointer = _CompatEncodePointer;
        }
    }

    return pfnEncodePointer(Ptr);
}


extern "C" BOOL WINAPI
LibHeapQueryInformation(HANDLE hHeap,
                        HEAP_INFORMATION_CLASS heapClass,
                        PVOID heapInfo,
                        SIZE_T heapLength,
                        PSIZE_T returnLength) {
    if (!pfnHeapQueryInformation)
    {
        // Check if the API is provided by kernel32, otherwise fall back to our implementation.
        HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
        pfnHeapQueryInformation = reinterpret_cast<PFN_HEAPQUERYINFORMATION>(GetProcAddress(hKernel32, "HeapQueryInformation"));
        if (!pfnHeapQueryInformation)
        {
            pfnHeapQueryInformation = _CompatHeapQueryInformation;
        }
    }

    return pfnHeapQueryInformation(hHeap, heapClass, heapInfo, heapLength, returnLength);
}

extern "C" BOOL WINAPI
LibHeapSetInformation(HANDLE hHeap,
                      HEAP_INFORMATION_CLASS heapClass,
                      PVOID heapInfo,
                      SIZE_T heapLength) {
    if (!pfnHeapSetInformation)
    {
        // Check if the API is provided by kernel32, otherwise fall back to our implementation.
        HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
        pfnHeapSetInformation = reinterpret_cast<PFN_HEAPSETINFORMATION>(GetProcAddress(hKernel32, "HeapSetInformation"));
        if (!pfnHeapSetInformation)
        {
            pfnHeapSetInformation = _CompatHeapSetInformation;
        }
    }

    return pfnHeapSetInformation(hHeap, heapClass, heapInfo, heapLength);
}
