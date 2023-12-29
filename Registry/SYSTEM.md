# The SYSTEM Hive

## ProductType
Key - *HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ProductOptions* <br>
Type - REG_SZ <br>
Values - ProductType - Used to distinguish whether the system is a client system or a server system. Read on system boot to make decisions regarding optimizations for that system type. Examples include high-performance factors for servers, whereas for clients, optimized response times for interactive desktop use. Could include OS heaps, number of internal system worker threads, size of the system data cache etc. <br>
Examples:
- Windows client - WinNT
- Windows server (domain controller) - LanmanNT
- Windows server (server only) - ServerNT

## ProductPolicy
Key - *HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ProductOptions* <br>
Type - REG_BINARY <br>
Values - ProductPolicy - Contains cached copy of data inside the tokens.dat file (help differentiate between the editions of Windows and the features they enable)
Examples
- N/A
