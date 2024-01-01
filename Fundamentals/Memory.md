# Memory 

## Virtualization Trust Layers (VTLs)
An additional mechanism of security Windows employs involves Virtualization Based Security (VBS), which extend the processors natural privilege-based separation through VTLs. VTLS are just one mechanism Windows employs in their virtualization 'arsenal' in an attempt to prevent malicious code from executing or performing privilege escalation. In an attempt to understand VTLs as simply as possible, one could think of VTLs as enforcing *isolation* while privilege levels (user versus kernel) enforce *power*. The following graphic shows a breakdown of the various components found in VTL 0 and VTL 1 to include their shared use of the Hyper-V Hypervisor:

![vbs-vtl.png.png](./Images/vbs-vtl.png?raw=true "VBS Overview")

We can see above with VTL 1 it has its own version of the kernel, the *secure kernel*, which runs in the privileged processor mode (ring 0). Additionally with VTL 1 we also see a run-time user environment mode called the Isolated User Mode (IUM) now exists which runs in unprivileged mode (ring 3). The secure kernel in this instance is its own binary which is found as *securekernel.exe* on disk. IUM is both an environment that restricts the allowed system calls that regular user-mode DLLs can make (which limits the  number of DLLs that can be loaded) and a framework that ads special secure system calls that can <ins>*only execute under VTL 1*</ins>. These system calls are exposed internally through a system library named *lumdll.dll* (essentially the VTL 1 version of Ntdll.dll) and a Windows subsystem-facing library called *lumbase.dll* (VTL 1 version of Kernelbase.dll). Copy on-write mechanisms prevent VTL 0 applications from making changes to binaries used by VTL 1.

Some fun considerations one could make could include the following:
- Kernel mode running at VTL 0 cannot touch user-mode running at VTL 1 because VTL 1 is more privileged. 
- User-mode running at VTL 1 cannot touch kernel mode running at VTL 0 because user (ring 3) cannot touch kernel (ring 0).
- VTL 1 user-mode applications must still go through their regular Windows system calls and their respective access checks if they want ot access system resources. 

Some parts of VTL seem a bit confusing as we notice VTL 1 is not considered to be more powerful than VTL 0, to the point where it could even be considered the opposite. This is due to the way that the secure kernel picks and chooses certain OS calls to forward to VTL 0, in addition to the fact the secure kernel already has a more narrow variety when it comes to system call access. This also means it never handles any kind of I/O, file, network, registry-based operations in addition to graphics and any driver interaction. The secure kernel however by both running at VTL 1 and being in kernel mode does have complete access to VTL 0 memory and resources. It can use the hypervisor to limit the VTL 0 access to certain memory locations by leveraging CPU hardware support known as *Second Level Address Translation (SLAT)*. SLAT is the basis of Microsoft's Credential Guard technology, which can store secrets in such locations. Similarly, the secure kernel can use SLAT to control the execution of memory locations. 

To prevent normal device drivers from leveraging hardware devices to directly access memory the system uses another piece of hardware referred to as the *I/O Memory Management Unit (MMU)* which effectively virtualizes memory access for devices. This is often used to prevent device drivers from using Direct Memory Access (DMA) to directly access the hypervisor or secure kernel's physical regions of memory. This would bypass SLAT because no virtual memory is involved. 

On boot, the hypervisor is the first component to be launched by the boot loader. Because of this the hypervisor is able to program the SLAT and I/O MMU as it desires, defining the VTL 0 and 1 execution environments. When in VTL 1, the boot loader runs again which loads the secure kernel at which point the VTL is dropped, leaving the 'normal' kernel in its VTL 0 'jail' unable to escape. 

Since user-mode processes running in VTL 1 are isolated malicious code could potentially make secure system calls to sign/seal its own secrets and potentially cause bad interactions with other VTL1 processes or the smart kernel. Due to this only a special class of specially signed binaries called *Trustlets* are allowed to execute in VTL 1.



## References
- https://learn.microsoft.com/en-us/windows/win32/procthread/isolated-user-mode--ium--processes
- https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/tlfs/vsm