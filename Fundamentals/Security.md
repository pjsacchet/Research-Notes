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

## Key System Components 
The following figure displays a rudimentary overview of some of the core componenets that make up Windows, to include: subsystems, processes, services and applications:

![architecture.jpg](./Images/architecture.jpg?raw=true "Architecture Overview")

### Environment Subsystems
The role of an environment subsystem is to expose some subset of the base Windows executive system services to application programs. Each executable image (exe) is bound to *only* one subsystem, which can be specified with the /SUBSYSTEM flag in Microsoft Visual Studio. When an image is run, the process creation code examines the subsystem type code in the image header so that it can notify the proper subsystem of the new process. 

When an application calls a function in   subsystem DLL one of the following will occur:
- The function is entirely implemented in user mode inside the subsystem DLL. Because of this no message is sent to the environment subsystem process, and no Windows executive subsystem services are called. The function is performed in user mode and the results are returned to the caller. Examples of this include *GetCurrentProcess* (always returns -1) and *GetCurrentProcessId* (process ID is retreived from a cached location, not the kernel). 
- The function requires one or more calls to the Windows executive. Examples include the Windows *ReadFile* and *WriteFile* functions, which underneath call undocumented *NtReadFile* (* \*cough\* http://undocumented.ntinternals.net/index.html?page=UserMode%2FUndocumented%20Functions%2FNT%20Objects%2FFile%2FNtReadFileScatter.html*) and *NtWriteFile* (*\*cough\* http://undocumented.ntinternals.net/index.html?page=UserMode%2FUndocumented%20Functions%2FNT%20Objects%2FFile%2FNtWriteFile.html*) functions.
- The function requires some work to be done in the environment subsystem process. In this case, a client/server request is made to the environment subsystem via an ALPC message sent to the subsystem to perform some operation. The subsystem DLL then waits for a reply before returning to the caller.

Subsystems are started by the session manager (*smss.exe*) process.Subsystem startup information is stored udner the registry key *HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SessionManager\SubSystems*.

#### Windows Subsystem
In an attempt to reduce redunancy and overhead, Windows implements key parts of its operating systems into the Windows subsystem. This subsystem is responsible for critical functionality for the Windows device, to include handling things like display I/O on behalf of processes. This is to include scenarios where a Windows server is running with no interactive users logged on. Because of its role, this process is marked as critical and if for any reason it is stopped the device crashes. The Windows subsystem consists of the following components:

- For each session, an instance of the environment subsystem process (Csrss.exe) loads four DLLs (Baserv.dll, Winsrv.dll, Sxssrv.dll, and Csrsrv.dll) that contain support for:
  - Housekeeping tasks related to creating processes and threads 
  - Shutting down Windows applications
  - Containing the .ini (initialization file) to registry location mappings for backwards compatibility
  - Sending certain kernel notification messages to Windows applications as Window messages
  - Portions of the support for 16-bit virtual DOS machine processes
  - Side-by-side (SxS)/Fusino and manifest cache support
  - Several natural language support functions 
- A kernel-mode device driver (Win32k.sys) that contains the following:


*Important note: The kernel mode code that handles the raw input thread and desktop thread (responsible for the mouse cursor, keyboard input, and handling the desktop window) is hosted inside threads running inside Winsrc.dll. The Csess.exe instances associated with interactive user sessions contain a fifth D:: called the Canonical Display Driver (Cdd.dll). This driver is responsible for communicating with the DirectX support in the kernel on each vertical refresh (VSync) to draw the visible desktop without traditional hardware-accelerated GDI support.*

#### Windows 10 & Win32k.sys