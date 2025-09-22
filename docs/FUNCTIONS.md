# libnt5 Functions

For building libnt5 from source, see [BUILDING.md](BUILDING.md).

## List of Redirected Functions

This is a list of functions that are redirected/overridden, "spoofed", whatever you wanna call it, in libnt5. 
They are grouped by when the function was introduced into Windows. 
Click the function name to see the Microsoft documentation link of info about the function. 
There is info on whether the function has an alternative implementation supplied or just returns i.e. `null`.

The default target for the v141_xp Toolchain + Windows 7.1 SDK is XP Service Pack 3. However, there are some 
functions that are only present in XP that we must provide function definitions and .dll imports for, and a 
few functions that were only introduced in service packs as well. Those must also be spoofed to allow applications 
to run on Windows XP RTM (i.e. "Gold Master"), SP1 and SP2.

### Kernel Functions

__Introduced in Windows XP RTM__  
 - Spoofed for Windows 2000 support, the primary goal of this library. Some use [ReactOS](https://reactos.org/) implementations.

[GetModuleHandleEx](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw)
 - Returns `FALSE`.

[GetNumaHighestNodeNumber](https://learn.microsoft.com/en-us/windows/win32/api/systemtopologyapi/nf-systemtopologyapi-getnumahighestnodenumber)
 - Sets HighestNodeNumber to `0` and returns `TRUE`.

[GetVersionEx](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexw)
 - On Windows 2000, returns `dwMajorVersion = 5 dwMinorVersion = 1` (5.1), otherwise uses the real GetVersionExW() function.

[InitializeSListHead](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-initializeslisthead)
 - Uses alternative ReactOS implementation.

[InterlockedFlushSList](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedflushslist)
 - Uses alternative ReactOS implementation.

[InterlockedPopEntrySList](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist)
 - Uses alternative ReactOS implementation.

[InterlockedPushEntrySList](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist)
 - Uses alternative ReactOS implementation.

[QueryDepthSList](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-querydepthslist)
 - Uses alternative ReactOS implementation.

*Added by me:*  
[HeapQueryInformation](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapqueryinformation)
 - Returns `FALSE`.

[HeapSetInformation](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsetinformation)
 - Returns `FALSE`.

*yet to implement*  
[DnsFree](https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsfree)
 - 

[GetNativeSystemInfo](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo)
 - 

[WTSQueryUserToken](https://learn.microsoft.com/en-us/windows/win32/api/wtsapi32/nf-wtsapi32-wtsqueryusertoken)
 - 

__Introduced in Windows XP Service Pack 1__  
 - To allow running on XP RTM.

*yet to implement*  
[SetDllDirectory](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setdlldirectoryw)
 - 

[GetProcessId](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid)
 - 

__Introduced in Windows XP Service Pack 2__  
 - To allow running on XP RTM.

[DecodePointer](https://learn.microsoft.com/en-us/previous-versions/bb432242(v=vs.85))
 - 

[EncodePointer](https://learn.microsoft.com/en-us/previous-versions/bb432254(v=vs.85))
 - 

*yet to implement*  
[DecodeSystemPointer](https://learn.microsoft.com/en-us/previous-versions/bb432243(v=vs.85))
 - Simply returns the original pointer, which is enough.

[EncodeSystemPointer](https://learn.microsoft.com/en-us/previous-versions/bb432255(v=vs.85))
 - Simply returns the original pointer, which is enough.

__Introduced in Windows XP Service Pack 3__  
 - To allow running on XP SP2.

[GetLogicalProcessorInformation](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation)
 - Returns `ERROR_CALL_NOT_IMPLEMENTED`.

### User Functions
[ImmDisableTextFrameService](https://learn.microsoft.com/en-us/windows/win32/api/imm/nf-imm-immdisabletextframeservice) 
was introduced in Windows Server 2003, it is a user mode function.  
New code should use [ImmDisableIME](https://learn.microsoft.com/en-us/windows/win32/api/imm/nf-imm-immdisableime) instead.
