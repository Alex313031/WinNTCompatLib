# libnt5 Functions

For building libnt5 from source, see [BUILDING.md](BUILDING.md).

## List of Redirected Functions

This is a list of functions that are redirected/overridden, "spoofed", whatever you wanna call it, in libnt5, 
as well as other information such ase when the function was introduced into Windows, info about the function, 
and whether the function has an alternative implementation supplied or just returns `null`.

The default target for the v141_xp Toolchain + Windows 7.1 SDK is XP Service Pack 3. However, there are some 
functions that are only present in XP that we must provide function definitions and .dll imports for, and a 
few functions that were only introduced in service packs as well. Those must also be spoofed to allow applications 
to run on Windows XP RTM (i.e. "Gold Master"), SP1 and SP2.

### Kernel Functions

__Introduced in Windows XP RTM__  
 - Spoofed for Windows 2000 support, the primary goal of this library.

GetModuleHandleEx  
GetNumaHighestNodeNumber  
GetVersionEx  
InitializeSListHead  
InterlockedFlushSList  
InterlockedPopEntrySList  
InterlockedPushEntrySList  
QueryDepthSList  

*added by me*  
HeapQueryInformation  
HeapSetInformation  

*yet to implement*  
DnsFree  
GetNativeSystemInfo  
WTSQueryUserToken  

__Introduced in Windows XP Service Pack 1__  
*yet to implement*  
SetDllDirectory  
GetProcessId  

__Introduced in Windows XP Service Pack 2__  
DecodePointer  
EncodePointer  
EncodeSystemPointer (redirect to above)  
DecodeSystemPointer (redirect to above)  

__Introduced in Windows XP Service Pack 3__  
GetLogicalProcessorInformation

### User Functions
[none]
