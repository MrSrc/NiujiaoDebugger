#pragma once
#define MY_INT int32

extern  int asm_IsCpuSupportedCPUID();
extern  void asm_BreakPoint();
extern  void asm_GetCpuVendor(MY_INT*, MY_INT*, MY_INT*);
extern void asm_GetMSR(MY_INT FuncCode, MY_INT* HighMsrResult, MY_INT* LowMsrResult);
