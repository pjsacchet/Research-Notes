/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

HRESULT MkParseDisplayName(LPBC pbc,LPCOLESTR szUserName,ULONG *pchEaten,LPMONIKER *ppmk)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  LPBC pIVar4;
  ulonglong uVar5;
  LPCOLESTR pOVar6;
  ulonglong uVar7;
  uint local_res10 [2];
  LPMONIKER local_48;
  longlong *local_40;
  LPMONIKER local_38;
  
                    /* 0xeec0  1144  MkParseDisplayName */
  uVar7 = 0;
  local_res10[0] = 0;
  local_48 = (LPMONIKER)0x0;
  if ((szUserName == (LPCOLESTR)0x0) || (*szUserName == L'\0')) {
    return -0x7ff8ffa9;
  }
  pIVar4 = pbc;
  uVar2 = IsValidInterface((longlong)pbc);
  if ((((int)uVar2 == 0) || (pchEaten == (ULONG *)0x0)) || (ppmk == (LPMONIKER *)0x0)) {
    return -0x7ff8ffa9;
  }
  *ppmk = (LPMONIKER)0x0;
  *pchEaten = 0;
  puVar3 = FUN_18000f08c(pIVar4,(longlong)szUserName,(int *)local_res10,&local_48);
  uVar5 = (ulonglong)puVar3 & 0xffffffff;
  if ((int)puVar3 == -0x7ffbfe1d) {
    puVar3 = FUN_18000f85c((short *)pIVar4,(longlong)szUserName,(int *)local_res10,&local_48);
    uVar5 = (ulonglong)puVar3 & 0xffffffff;
    if ((int)puVar3 == -0x7ffbfe1d) {
      uVar1 = FUN_18000fa18(pbc,szUserName,local_res10,&local_48);
      uVar5 = (ulonglong)uVar1;
      if (uVar1 == 0x800401e3) {
        uVar1 = FUN_180045a58((longlong *)pbc,(longlong)szUserName,local_res10,&local_48);
        uVar5 = (ulonglong)uVar1;
      }
    }
  }
  if ((int)uVar5 < 0) {
    if (*szUserName == L'@') {
      uVar1 = FUN_180045bec(pbc,szUserName,local_res10,&local_48);
      uVar5 = (ulonglong)uVar1;
    }
    uVar1 = (uint)uVar5;
    pOVar6 = szUserName;
    if ((int)uVar1 < 0) goto LAB_18000efb6;
  }
  pOVar6 = szUserName + local_res10[0];
  if (pOVar6 != (LPCOLESTR)0x0) {
    uVar7 = 0xffffffffffffffff;
    do {
      uVar7 = uVar7 + 1;
    } while (pOVar6[uVar7] != L'\0');
  }
  while ((uVar1 = (uint)uVar5, -1 < (int)uVar1 && (0 < (int)uVar7))) {
    local_res10[0] = 0;
    uVar1 = (*local_48->lpVtbl->ParseDisplayName)();
    uVar5 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) break;
    if (local_40 != (longlong *)0x0) {
      uVar1 = (*local_48->lpVtbl->ComposeWith)();
      uVar5 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        (*local_48->lpVtbl->Release)();
        uVar7 = (ulonglong)((int)uVar7 - local_res10[0]);
        local_48 = local_38;
        pOVar6 = pOVar6 + local_res10[0];
      }
      (**(code **)(*local_40 + 0x10))();
    }
  }
LAB_18000efb6:
  *ppmk = local_48;
  *pchEaten = (ULONG)((longlong)((longlong)pOVar6 - (longlong)szUserName) >> 1);
  return (HRESULT)uVar1;
}