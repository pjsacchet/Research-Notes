## Chapter 1 - Concepts & Tools
- Newer Windows APIs use Component Object Model (COM)
  - Originally for exchanging data between documents
  - Object Linking & Embedding (OLE)
- COM based on two things:
  - 1. Clients communicate w/ objects through interfaces
    - Well-defined contracts w/ a set of logcially grouped methods grouped under the virtual table dispatch mechanism
  - 2. Component information is loaded dynamically rather than being statically linked to the client
- "COM server" typically refers to the DLL or EXE where the COM classes are implemented
- Windows RunTime built on top of COM
- .NET Framework consists of two major components:
  - 1. Common Langauge Runtime (CLR):
    - Runtime engine for .NET & includes a Just In Time (JIT) compiler that translates Common Intermediate Language (CIL) instructions into machine code
  - 2. .NET Framework Class Library (FCL)
    - Large collection of types that implement functionality needed by client and server applications
### Processes
  - Process is a container for a set of resources used when executing the instance of the program. Comprises the following:
    - Private virtual address space: Set of memory addresses that the process can use
    - Executable program: Defines initial code and data and is mapped into the process's virtual address space 
    - List of open handles: Map to various system resources such as semaphores, synch objects, and files that are accessible to all threads of a process
    - Security context: Access token that identifies the user, security groups, privileges, attributes, claims, capabilities, User Account Control (UAC) virtualization state, session etc.
    - PID
    - At least one thread of execution 
### Threads
  - Entity within a process taht Windows schedules for execution. Contains:
    - Contents of a set of CPU registers
    - Two stacks - one for kernel mode execution and the other for user mode 
    - Private storage area called thread local storage (TLS) for use by subsystems, DLLs, libraries 
    - TID
  - Switching execution from one thread to another is often expensive since it requires the kernel scheduler so Windows offers
    - 1. Fibers (lightweight threads)
    - 2. User Mode Scheduling (UMS) threads 
### Fibers
  - Allow an application to schedule its own threads of execution rather than rely on the kernel scheduler (priority based)
    - "Lightweight threads"
    - Call *ConvertThreadToFiber*()
  - Not usually good to use since they are invisible to the kernel 
#### User Mode Scheduling Threads
  - Available only on 64-bit Windows
  - Similar to fibers, but visible to the kernel
#### Virtual Address Descriptors (VADs)
 - Structures the memory managers uses to keep track of the virtual addresses the process is using
### Jobs
 - Main function is to allow the management and manipulation of groups of processes as a unit
   - Allows control of certain attributes and provides limits for the process or processes associated with the job.
### Virtual Memory
 - Windows provides flat/linear address space for processes (they think they have a lot more than they actually do)
   - By controlling the protection and mapping, Windows can ensure that individual processes don't overwrite one another
 - Since most machines have much less physical memory (RAM) than the memory in use by processes the memory manager pages that memory to disk
   - This allows physical memory to be freed so that it can be used for other processes 
     - If/when a thread accesses a virtual address that has been paged to disk, the virtual memory manager loads the information back into physical memory from disk
     - Page default sizes are 4KB