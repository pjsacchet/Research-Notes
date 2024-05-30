# Ntdll.dll
Ntdll.dll serves as the fundamental system support library for Windows. This library contains many functions that transition from user mode to kernel mode. Typically, parameters are verified prior to invoking the *System Service Dispatcher* which calls the actual kernel-mode system service (code is typically contained in ntoskrnl.exe).

## Contents
Some of the things that can be found inside Ntdll.dll:
- Image loader (functions that start with Ldr)
- Heap manager
- Windows subsystem process communication functions (functions that start with Csr)
- General run-time library functions (functions that start with Rtl)
- Functions that support user-mode debugging (functions that start with Dbgui)
- Event tracing for windows functions (functions that start with Etw)
- User mode asynchronous procedure calls (APC)
- Small set of C Run Time (CRT) routines 