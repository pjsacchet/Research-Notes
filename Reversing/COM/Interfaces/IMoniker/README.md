# IMoniker

## IID
0000000F-0000-0000-C000-000000000046

GUID guidObject = {0x0000000f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

## Proxy Definition
```
[Guid("0000000f-0000-0000-c000-000000000046")]
interface IMoniker : IUnknown {
    HRESULT Proc3(/* Stack Offset: 8 */ [Out] GUID* p0);
    HRESULT Proc4();
    HRESULT Proc5(/* Stack Offset: 8 */ [In] IStream* p0);
    HRESULT Proc6(/* Stack Offset: 8 */ [In] IStream* p0, /* Stack Offset: 16 */ [In] int p1);
    HRESULT Proc7(/* Stack Offset: 8 */ [Out] struct Struct_14* p0);
    HRESULT Proc8(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] IMoniker* p1, /* Stack Offset: 24 */ [In] GUID* p2, /* Stack Offset: 32 */ [Out] /* iid_is param offset: 24 */ IUnknown** p3);
    HRESULT Proc9(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] IMoniker* p1, /* Stack Offset: 24 */ [In] GUID* p2, /* Stack Offset: 32 */ [Out] /* iid_is param offset: 24 */ IUnknown** p3);
    HRESULT Proc10(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] int p1, /* Stack Offset: 24 */ [In, Out] /* unique */IMoniker** p2, /* Stack Offset: 32 */ [Out] IMoniker** p3);
    HRESULT Proc11(/* Stack Offset: 8 */ [In] IMoniker* p0, /* Stack Offset: 16 */ [In] int p1, /* Stack Offset: 24 */ [Out] IMoniker** p2);
    HRESULT Proc12(/* Stack Offset: 8 */ [In] int p0, /* Stack Offset: 16 */ [Out] IEnumMoniker** p1);
    HRESULT Proc13(/* Stack Offset: 8 */ [In] IMoniker* p0);
    HRESULT Proc14(/* Stack Offset: 8 */ [Out] int* p0);
    HRESULT Proc15(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] IMoniker* p1, /* Stack Offset: 24 */ [In] IMoniker* p2);
    HRESULT Proc16(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] IMoniker* p1, /* Stack Offset: 24 */ [Out] struct Struct_16* p2);
    HRESULT Proc17(/* Stack Offset: 8 */ [Out] IMoniker** p0);
    HRESULT Proc18(/* Stack Offset: 8 */ [In] IMoniker* p0, /* Stack Offset: 16 */ [Out] IMoniker** p1);
    HRESULT Proc19(/* Stack Offset: 8 */ [In] IMoniker* p0, /* Stack Offset: 16 */ [Out] IMoniker** p1);
    HRESULT Proc20(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] IMoniker* p1, /* Stack Offset: 24 */ [Out] wchar_t** p2);
    HRESULT Proc21(/* Stack Offset: 8 */ [In] IBindCtx* p0, /* Stack Offset: 16 */ [In] IMoniker* p1, /* Stack Offset: 24 */ [In] wchar_t* p2, /* Stack Offset: 32 */ [Out] int* p3, /* Stack Offset: 40 */ [Out] IMoniker** p4);
    HRESULT Proc22(/* Stack Offset: 8 */ [Out] int* p0);
}
```