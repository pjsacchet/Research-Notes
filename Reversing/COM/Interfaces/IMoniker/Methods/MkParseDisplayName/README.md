# MkParseDisplayName
https://learn.microsoft.com/en-us/windows/win32/api/objbase/nf-objbase-mkparsedisplayname

## Overview
Header - objbase.h
Library - Ole32.lib
DLL - Ole32.dll

## Declaration
```
HRESULT MkParseDisplayName(
  [in]  LPBC      pbc,
  [in]  LPCOLESTR szUserName,
  [out] ULONG     *pchEaten,
  [out] LPMONIKER *ppmk
);
```

## Parameters
[in] pbc

A pointer to the IBindCtx interface on the bind context object to be used in this binding operation.

[in] szUserName

A pointer to the display name to be parsed.

[out] pchEaten

A pointer to the number of characters of szUserName that were consumed. If the function is successful, *pchEaten is the length of szUserName; otherwise, it is the number of characters successfully parsed.

[out] ppmk

The address of the IMoniker* pointer variable that receives the interface pointer to the moniker that was built from szUserName. When successful, the function has called AddRef on the moniker and the caller is responsible for calling Release. If an error occurs, the specified interface pointer will contain as much of the moniker that the method was able to create before the error occurred.

## Remarks
The MkParseDisplayName function parses a human-readable name into a moniker that can be used to identify a link source. The resulting moniker can be a simple moniker (such as a file moniker), or it can be a generic composite made up of the component moniker pieces. For example, the display name "c:\mydir\somefile!item 1"

could be parsed into the following generic composite moniker: FileMoniker based on "c:\mydir\somefile") + (ItemMoniker based on "item 1").

The most common use of MkParseDisplayName is in the implementation of the standard Links dialog box, which allows an end user to specify the source of a linked object by typing in a string. You may also need to call MkParseDisplayName if your application supports a macro language that permits remote references (reference to elements outside of the document).

Parsing a display name often requires activating the same objects that would be activated during a binding operation, so it can be just as expensive (in terms of performance) as binding. Objects that are bound during the parsing operation are cached in the bind context passed to the function. If you plan to bind the moniker returned by MkParseDisplayName, it is best to do so immediately after the function returns, using the same bind context, which removes the need to activate objects a second time.

MkParseDisplayName parses as much of the display name as it understands into a moniker. The function then calls IMoniker::ParseDisplayName on the newly created moniker, passing the remainder of the display name. The moniker returned by ParseDisplayName is composed onto the end of the existing moniker and, if any of the display name remains unparsed, ParseDisplayName is called on the result of the composition. This process is repeated until the entire display name has been parsed.

MkParseDisplayName attempts the following strategies to parse the beginning of the display name, using the first one that succeeds:

The function looks in the Running Object Table for file monikers corresponding to all prefixes of the display name that consist solely of valid file name characters. This strategy can identify documents that are as yet unsaved.
The function checks the maximal prefix of the display name, which consists solely of valid file name characters, to see if an OLE 1 document is registered by that name. In this case, the returned moniker is an internal moniker provided by the OLE 1 compatibility layer of OLE 2.
The function consults the file system to check whether a prefix of the display name matches an existing file. The file name can be drive-absolute, drive-relative, working-directory relative, or begin with an explicit network share name. This is the common case.
If the initial character of the display name is '@', the function finds the longest string immediately following it that conforms to the legal ProgID syntax. The function converts this string to a CLSID using the CLSIDFromProgID function. If the CLSID represents an OLE 2 class, the function loads the corresponding class object and asks for an IParseDisplayName interface pointer. The resulting IParseDisplayName interface is then given the whole string to parse, starting with the '@'. If the CLSID represents an OLE 1 class, then the function treats the string following the ProgID as an OLE1/DDE link designator having filename|item syntax.