# Memory 

## Virtualization Trust Layers (VTLs)
An additional mechanism of security Windows employs involves Virtualization Based Security (VBS), which extend the processors natural privilege-based separation through VTLs. VTLS are just one mechanism Windows employs in their virtualization 'arsenal' in an attempt to prevent malicious code from executing or performing privilege escalation. In an attempt to understand VTLs as simply as possible, one could think of VTLs as enforcing *isolation* while privilege levels (user versus kernel) enforce *power*. The following graphic shows a breakdown of the various components found in VTL 0 and VTL 1 to include their shared use of the Hyper-V Hypervisor:

![vbs-vtl.png.png](./Images/vbs-vtl.png?raw=true "VBS Overview")

We can see above with VTL 1 it has its own version of the kernel, the *secure kernel*, which runs in the privileged processor mode (ring 0). Additionally with VTL 1 we also see a run-time user environment mode called the Isolated User Mode (IUM) now exists which runs in unprivileged mode (ring 3). The secure kernel in this instance is its own binary which is found as *securekernel.exe* on disk. IUM is both an environment that restricts the allowed system calls that regular user-mode DLLs can make (which limits the  number of DLLs that can be loaded) and a framework that ads special secure system calls that can <ins>*only execute under VTL 1*</ins>. These system calls are exposed internally through a system library named *lumdll.dll* (essentially the VTL 1 version of Ntdll.dll) and a Windows subsystem-facing library called *lumbase.dll* (VTL 1 version of Kernelbase.dll).



## References
- https://learn.microsoft.com/en-us/windows/win32/procthread/isolated-user-mode--ium--processes
- https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/tlfs/vsm