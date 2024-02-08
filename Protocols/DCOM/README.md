# Distributed Component Object Model 

## Client and Server Relationships
Three relationships:
- In-process: Wheh a COM client has loaded an in-proc server and obtains an interface pointer on some object, the two entities talk directly through the acquired interface.
  
  ![In-Proc-Server-Final.png](./Images/In-Proc-Server-Final.png?raw=true "In-Proc Server Example")

- Local (out of process): When a COM client obtains an interface pointer from a coclass residing in a local exe server, the client does not have a 'direct' connection to the acquired interface. COM secretly loads a 'sub/proxy' DLL that contains marshaling code for each custom interface defined in the server's IDL file. 
  - Proxy: A COM object loaded into the client's process, which packages up client requests for any out-of-process (or *out of apartment*) method invocation.
  - Stub: A COM object loaded into the server's process, which receives the client's requests, unpackages them, and hands them off to the 'real' COM object. 
- Remote: If a client and server are communicating across machine boundaries using DCOM, the client is once again really calling a proxy loaded into its memory partition, which communicates with a stub located in the memory partition of the remote process. This call uses 'full-blown' RPC (instead of LRPC).