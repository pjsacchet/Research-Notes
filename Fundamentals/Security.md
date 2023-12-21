# Security

## Kernel vs. User Mode
Windows operates primarily in two modes: kernel mode and user mode. The primary purpose for this split is for security. This is so user and third party applications cannot make direct calls to core 'kernel' libraries and functions. Most calls end up going to NTDLL.dll, or other subsystem DLLs. From this point calls cross over into kernel mode, touching the Executive, Device Drivers, the Hardward Abstraction Layer (HAL), GUI or the kernel itself. There is additionally the Hyper-V Hypervisor, which runs in its own hypervisor context. 

### Core Windows System Files
- Ntoskrnl.exe - Executive and kernel
- Hal.dll - HAL
- Win32k.sys - Kernel-mode part of the Windows subsystem (GUI)
- Hvix64.exe (Intel)/Hvax64.exe (AMD) - Hypervisor
- Sys files in \SystemRoot\System32\Drivers - Core driver files, such as Direct X, Volume Manager, TCP/IP, TPM, and ACPI support
- Ntdll.dll - Internal support functions and system service dispatch stubs to executive functions 
- Kernel32.dll, Advapi32.dll, User32.dll, Gdi32.dll - Core Windows subsystem DLLs