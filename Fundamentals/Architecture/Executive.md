# Executive
Executive serves as the upper layer of ntoskrnl.exe (kernel is the lower layer). The executive layer includes:
- Function exports callable from user mode
  - Called system services
  - Exported via ntdll.dll
- Device driver functions
- Functions that can only be called from kernel mode

Major components of the Executive layer include:
- Configuration manager
  - Responsible for managing registry
- Process manager
  - Creates and terminates processes and threads
  - Technically underlying support for these are in kernel
- Security Reference Monitor (SRM)
  - Enforces security policies on the local computer. Guards OS resources, performing run-time object protection and auditing. 
- I/O Manager
  - Implements device-independent I/O and is responsible for dispatching to the appropriate device drivers for further processing. 
- Plug and play (PnP) Manager
  - Determines which drivers are required to support a particular device and loads those drivers
- Power Manager
  - Coordinates power events, puts CPU asleep when system is idle
- Windows Driver Model (WDM) Windows Management Instrumentation (WMI) Routines
  - These routines enable device drivers to publish performance and configuration information 
- Memory Manager
  - Implements virtual memory for process address spaces
- Cache Manager
  - Improves the performance of file-based I/O by causing recently reference disk data to reside in main memory for quick access
  - Also defers disk writes by holding updates in memory for a short time before sending them to disk