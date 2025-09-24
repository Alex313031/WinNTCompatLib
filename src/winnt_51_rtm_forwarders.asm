;
; libnt5 - Let MSVC v141_xp targeted applications run on even older Windows versions
; Copyright (c) 2025 Alex313031
; SPDX-License-Identifier: MIT
;

.model flat

;EXTERN _LibGetDllDirectory@4 : PROC
EXTERN _LibSetDllDirectory@4 : PROC

.data

;PUBLIC __imp__GetDllDirectoryW@4
;__imp__GetDllDirectoryW@4 dd _LibGetDllDirectory@4

PUBLIC __imp__SetDllDirectoryW@4
__imp__SetDllDirectoryW@4 dd _LibSetDllDirectory@4

END
