#pragma once
#include <Ntddk.h>
#include "DefMsr.h"
#ifdef _WIN64
#include "../intel64/intel64.h"
#else
#include "../intel32/intel32.h"
#endif
typedef struct s_vmcs
{
	unsigned int VmcsVersion : 31;
	unsigned int ShadowVmcsIndicator : 1;
	unsigned int VMXAbortIndicator : 32;
}S_VMCS;
typedef struct s_access_type
{
	unsigned int SegmentType : 4;
	unsigned int DescriptorType : 1;
	unsigned int DescriptorPrivilegeLevel : 2;
	unsigned int SegmentPresent : 1;
	unsigned int Reserved0 : 4;
	unsigned int AvailableForUseBySystemSoftware : 1;
	unsigned int Reserved1 : 1;
	unsigned int DefaultOperandSize : 1;
	unsigned int Granularity : 1;
	unsigned int IsSegmentUnusable : 1;
	unsigned int Reserved2 : 15;

}S_ACCESS_TYPE;
typedef struct s_register
{
	UINT16 Selector;
	UINT64 BaseAddress;
	UINT32 SegmentLimit;
	S_ACCESS_TYPE AccessRight;
}S_REGISTER;
typedef struct s_guest_register_state
{
	UINT64 CR0;
	UINT64 CR3;
	UINT64 CR4;
	UINT64 DR7;
	UINT64 RSP;
	UINT64 RIP;
	UINT64 RFLAGS;
	S_REGISTER CS;
	S_REGISTER SS;
	S_REGISTER DS;
	S_REGISTER ES;
	S_REGISTER FS;
	S_REGISTER GS;
	S_REGISTER LDTR;
	S_REGISTER TR;
	UINT64 GDTRBaseAddress;
	UINT32 GDTRBaseLimit;
	UINT64 IDTRBaseAddress;
	UINT32 IDTRBaseLimit;
	UINT64 IA32_DEBUGCTL;
	UINT32 IA32_SYSENTER_CS;
	UINT64 IA32_SYSENTER_ESP;
	UINT64 IA32_SYSENTER_EIP;
	UINT64 IA32_PERF_GLOBAL_CTRL;
	UINT64 IA32_PAT;
	UINT64 IA32_EFER;
	UINT64 IA32_BNDCFGS;
	UINT32 SMBASE;
}S_GUEST_REGISTER_STATE;

typedef struct s_guest_nonregister_state
{

	UINT32 ActivityState;
	UINT32 InterruptibilityState;
	UINT64 PendingDebugExceptions;
	UINT64 VMCSLinkPointer;
	UINT32 VMXPreemptionTimerValue;
	UINT64 PageDirectoryPointerTableEntries[4];
	UINT16 GuestInterruptStatus;
	UINT16 PMLIndex;
}S_GUEST_NONREGISTER_STATE;
typedef struct s_host_state
{

	UINT64 CR0;
	UINT64 CR3;
	UINT64 CR4;
	UINT64 RSP;
	UINT64 RIP;
	UINT16 CSSelector;
	UINT16 SSSelector;
	UINT16 DSSelector;
	UINT16 ESSelector;
	UINT16 FSSelector;
	UINT16 GSSelector;
	UINT16 TRSelector;
	UINT64 FSBaseAddress;
	UINT64 GSBaseAddress;
	UINT64 TRBaseAddress;
	UINT64 GDTRBaseAddress;
	UINT64 IDTRBaseAddress;
	UINT32 IA32_SYSENTER_CS;
	UINT64 IA32_SYSENTER_ESP;
	UINT64 IA32_SYSENTER_EIP;
	UINT64 IA32_PERF_GLOBAL_CTRL;
	UINT64 IA32_PAT;
	UINT64 IA32_EFER;
}S_HOST_STATE;

//intel �ֲ� 2750ҳ
typedef struct s_cr0
{
	unsigned int pe : 1;  //protection enable
	unsigned int mp : 1;  //monitor coprocessor
	unsigned int em : 1;  //emulation
	unsigned int ts : 1;  //task switched
	unsigned int et : 1;  //extension type
	unsigned int ne : 1;  //numberic error
	unsigned int reserved0 : 10;
	unsigned int wp : 1;  //write proctect
	unsigned int reserved1 : 1;
	unsigned int am : 1;  //alignment mask
	unsigned int reserved2 : 10;
	unsigned int nw : 1;  //not write
	unsigned int cd : 1;  //cached isable
	unsigned int pg : 1;  //paging
}S_CR0;

typedef struct s_cr3
{
	unsigned int reserved0 : 3;
	unsigned int pwt : 1;  //page level write through
	unsigned int pcd : 1;  //paged-level cache disable
	unsigned int reserved1 : 7;
	unsigned int PageDirectoryBase : 20;
}S_CR3;
typedef struct s_cr4
{
	unsigned int vme : 1;  //virtual 8086 mode extensions
	unsigned int pvi : 1;  //proctected mode virtual interrupts
	unsigned int tsd : 1;  //time stamp disable
	unsigned int de : 1;  //debugging extensions
	unsigned int pse : 1;  //page size extension
	unsigned int pae : 1;  //physical address extension
	unsigned int mce : 1;  //machine check enable
	unsigned int pge : 1;  //page global enable
	unsigned int pce : 1;  //performance monitor counter enable
	unsigned int  osfxsr : 1;  //operating system support for fxsave and fxstore instructions
	unsigned int  osxmmexcpt : 1;  //operating system support for unmasked simd floating-point exceptions
	unsigned int umip : 1;  //user mode instruction prevention
	unsigned int reserved2 : 1;  
	unsigned int vmxe : 1;  //vmx-enable
	unsigned int smxe : 1;  //smx enable
	unsigned int reserved3 : 1;
	unsigned int fsgsbase : 1;  //fsgsbase enable
	unsigned int pcide : 1;  //pcid enable
	unsigned int osxsave : 1;  //xsave and processor extened states enable
	unsigned int reserved4 : 1;
	unsigned int smep : 1;  //smep enable
	unsigned int smap : 1;  //smap enable
	unsigned int pke : 1;   //proctorection key enable
	unsigned int tpl : 1;   //task priority level
	unsigned int reserved5 : 7;
}S_CR4;
// 80ҳ
typedef struct s_rflags
{
	unsigned int cf : 1;
	unsigned int AlwaysOne : 1;
	unsigned int pf : 1;
	unsigned int AlwaysZero : 1;
	unsigned int af : 1;
	unsigned int AlwaysZero2 : 1;
	unsigned int zf : 1;
	unsigned int sf : 1;
	unsigned int tf : 1;
	unsigned int If : 1;
	unsigned int df : 1;
	unsigned int of : 1;
	unsigned int iopl : 1;
	unsigned int nt : 1;
	unsigned int AlwaysZero3 : 1;
	unsigned int rf : 1;
	unsigned int vm : 1;
	unsigned int ac : 1;
	unsigned int vif : 1;
	unsigned int vip : 1;
	unsigned int id : 1;
	unsigned int Reserved0 : 10;
	unsigned int Reserved1 : 32;
}S_RFLAGS;
//3791ҳ
typedef struct s_vmcs_encoding
{
	unsigned int AccessType : 1; //0 full 1 high
	unsigned int Index : 9;
	unsigned int Type : 2;  //0 control 1 vm-exit information 2guest state 3 host state
	unsigned int Reserved0 : 1;
	unsigned int Width : 2; //0 16; 1 64; 2 32 ;3 natural width
	unsigned int Reserved1 : 17;
}S_VMCS_ENCODING;
//3786ҳ
typedef  struct s_vm_entry_controls
{
	unsigned int Vector : 8;
	unsigned int InterruptionType : 3;
	unsigned int DeliverErrorCode : 1;
	unsigned int Reserved : 19;
	unsigned int Valid : 1;
}S_VM_ENTRY_CONTROLS;
typedef struct s_gpt_table_64
{
	USHORT Limit;
	UINT64 Base;
}S_GPT_TABLE_64;
typedef struct s_segment_selector
{
	unsigned int ReqPrivLevel : 2;
	unsigned int TabIndicator : 1;
	unsigned int Index : 13;
}S_SEGMENT_SELECTOR;
typedef struct s_segment_descriptor
{
	unsigned int SegmentLimit : 16;
	unsigned int BaseAddress : 16;
	unsigned int  Base0 : 8;
	unsigned int Type : 4;
	unsigned int S : 1;
	unsigned int DPL : 2;
	unsigned int P : 1;
	unsigned int SegLimit : 4;
	unsigned int AVL : 1;
	unsigned int L : 1;
	unsigned int D_B : 1;
	unsigned int G : 1;
	unsigned int Base1 : 8;
}S_SEGMENT_DESCRIPTOR;

int CheckVmxCapabilities();
UINT64 CreateVMCS();
UINT64 StartVmm();
UINT64 SetupVm();
BOOLEAN InitialVmExecutiveCtrls();
BOOLEAN InitialVmHostState();
UINT64 VmClear(PVOID Vmcs);
UINT64 VmVmptrld(PVOID Vmcs);
UINT64 CheckVmResult(PVOID Vmcs);
UINT64 VmVmwrite();
void vmwrite(MY_INT writeType, MY_INT Content);
void VmEntry();
int FillVmxGuestRegisterState(S_GUEST_REGISTER_STATE* VmxGuestRegisterState);
int FillVmxNonGuestRegisterState(S_GUEST_NONREGISTER_STATE* VmxGuestNonRegisterState);
int FillVmxHostState(S_HOST_STATE* VmxHostState);
int FillVmxExecutionCtls(int FillType);

int FillVmxPinBasedExecutionCtls();
int FillVmxTruePinBasedExecutionCtls();
int FillVmxProcBasedExecutionCtls();
int FillVmxTrueProcBasedExecutionCtls();
int FillVmxExceptionMapExecutionCtls();
int FillVmxIOBitmapExecutionCtls();
int FillTSCOffsetExecutionCtls();
int FillRegsiterAccessMaskExecutionCtls();
int FillR3targetCtlsExecutionCtls();
int FillCtlsForAPICVirtualizationExecutionCtls();
int FillMSRBitMapAddrExecutionCtls();
int FillExecutiveVMCSPointerExecutionCtls();
int FillEPTPExecutionCtls();
int FillVPIDExecutionCtls();
int FillPauseLoopExittingCtlsExecutionCtls();
int FillVMFuncCtlsExecutionCtls();
void SetRegDefaultValue(MY_INT* Target, MY_INT Factor1, MY_INT Factor2);
INT64 CalculateSegmentBase(MY_INT Selector, MY_INT Base);