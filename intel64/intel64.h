#pragma once
#define MY_INT UINT64
extern  int asm_IsCpuSupportedCPUID();
extern  int asm_IsCpuSupportedVmx();
extern  void asm_BreakPoint();
extern  MY_INT asm_GetCR0();
extern  void asm_SetCR0(MY_INT Cr0);
extern  MY_INT asm_GetCR3();
extern  void asm_SetCR3(MY_INT Cr0);
extern  MY_INT asm_GetCR4();
extern  void asm_SetCR4(MY_INT Cr4);
extern  MY_INT asm_GetCS();
extern  MY_INT asm_GetSS();
extern  MY_INT asm_GetDS();
extern  MY_INT asm_GetES();
extern  MY_INT asm_GetFS();
extern  MY_INT asm_GetGS();
extern  MY_INT asm_GetTR();
extern  MY_INT asm_GetCS();
extern  MY_INT asm_GetCS();
extern  MY_INT asm_GetCS();
extern  void asm_SGDT(void*, void*);
extern  MY_INT asm_SLDT();
extern  void asm_SIDT(void*, void*);
extern  void asm_Vmxon(UINT64*);
extern  void asm_VmVmclear(UINT64* VmcsAddr);
extern  void asm_VmVmptrld(UINT64* VmcsAddr);
extern  void asm_Vmxoff();
extern  void asm_VmVmlaunch();
extern  INT32 asm_VmVmread(MY_INT ReadType);
extern  void asm_VmVmwrite(MY_INT writeType, MY_INT Content);
extern  MY_INT asm_GetRflags();
extern  void asm_GetCpuVendor(MY_INT*, MY_INT*, MY_INT*);
extern void asm_GetMSR(INT64 FuncCode, MY_INT* HighMsrResult, MY_INT* LowMsrResult);
extern void asm_SetMSR(INT64 FuncCode, MY_INT HighMsr, MY_INT LowMsr);

enum reg
{
	vmcs_rax,
	vmcs_rcx,
	vmcs_rbx,
	vmcs_rdx,
	vmcs_rsi,
	vmcs_rdi,
	vmcs_rsp,
	vmcs_rbp
};