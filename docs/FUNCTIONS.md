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

## Kernel Functions
Some of these functions use [ReactOS](https://reactos.org/) implementations.  
See also > [Here](https://betawiki.net/wiki/User:Uncle_Captain/Drafts/Kernel_functions_introduced_in_Windows) for more historical info on these.

### Introduced in Windows XP RTM
 __*- Spoofed to allow running on Windows 2000.*__

[GetModuleHandleEx()](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw) - Returns `FALSE`.

[GetNumaHighestNodeNumber()](https://learn.microsoft.com/en-us/windows/win32/api/systemtopologyapi/nf-systemtopologyapi-getnumahighestnodenumber) - Sets *HighestNodeNumber* to `0` and returns `TRUE`.

[GetVersionEx()](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexw) - On Windows 2000, returns `dwMajorVersion = 5 dwMinorVersion = 1` (5.1), otherwise it uses the real *GetVersionExW()* function.

[InitializeSListHead()](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-initializeslisthead) - Uses alternative ReactOS implementation.

[InterlockedFlushSList()](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedflushslist) - Uses alternative ReactOS implementation.

[InterlockedPopEntrySList()](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist) - Uses alternative ReactOS implementation.

[InterlockedPushEntrySList()](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist) - Uses alternative ReactOS implementation.

[QueryDepthSList()](https://learn.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-querydepthslist) - Uses alternative ReactOS implementation.

[HeapQueryInformation()](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapqueryinformation) - Returns `FALSE`. *Added by me.*

[HeapSetInformation()](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsetinformation) - Returns `FALSE`. *Added by me.*
 
[DnsFree()](https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsfree) - *yet to implement* 

[GetNativeSystemInfo()](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo) - On Windows 2000, uses the `GetSystemInfo()` function, otherwise it uses the real *GetSystemInfo()* function. *Added by me.*

[WTSQueryUserToken()](https://learn.microsoft.com/en-us/windows/win32/api/wtsapi32/nf-wtsapi32-wtsqueryusertoken) - *yet to implement* 

### Introduced in Windows XP Service Pack 1
 __*- Spoofed to allow running on XP RTM.*__

[SetDllDirectory()](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setdlldirectoryw) - *yet to implement* 

[GetProcessId()](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid) - *yet to implement* 

### Introduced in Windows XP Service Pack 2
 __*- Spoofed to allow running on XP RTM - SP1.*__

[DecodePointer()](https://learn.microsoft.com/en-us/previous-versions/bb432242(v=vs.85)) - Simply returns the original pointer, which is enough.

[EncodePointer()](https://learn.microsoft.com/en-us/previous-versions/bb432254(v=vs.85)) - Simply returns the original pointer, which is enough.

[DecodeSystemPointer()](https://learn.microsoft.com/en-us/previous-versions/bb432243(v=vs.85)) - *yet to implement* 

[EncodeSystemPointer()](https://learn.microsoft.com/en-us/previous-versions/bb432255(v=vs.85)) - *yet to implement* 

[IsWow64Process()](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo) - *yet to implement* 

### Introduced in Windows XP Service Pack 3
 __*- Spoofed to allow running on XP RTM - XP SP2.*__

[GetLogicalProcessorInformation()](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation) - Returns `ERROR_CALL_NOT_IMPLEMENTED`.

### User Functions
The user mode function [ImmDisableTextFrameService()](https://learn.microsoft.com/en-us/windows/win32/api/imm/nf-imm-immdisabletextframeservice) 
was introduced in Windows Server 2003, however new code should use [ImmDisableIME()](https://learn.microsoft.com/en-us/windows/win32/api/imm/nf-imm-immdisableime) instead.
