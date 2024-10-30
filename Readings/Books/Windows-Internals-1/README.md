# Windows Internals Volume 1

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

### Fibers