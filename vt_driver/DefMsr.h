#pragma once
/*
定义和msr寄存器相关的结构
*/
#define COMBINE_64(high,low) ((high<<32)+low)
enum MsrFuncCode
{
	IA32_FEATURE_CONTROL=0x3A,
	IA32_SYSENTER_CS=0x174,
	IA32_SYSENTER_ESP=0x175,
	IA32_SYSENTER_EIP=0x176,
	IA32_PAT=0x277,
	IA32_PERF_GLOBAL_CTRL=0x38F,
	IA32_VMX_BASIC = 0x480,
	IA32_VMX_PINBASED_CTLS = 0x481,
	IA32_VMX_PROCBASED_CTLS = 0x482,
	IA32_VMX_EXIT_CTLS = 0x483,
	IA32_VMX_ENTRY_CTLS = 0x484,
	IA32_VMX_MISC = 0x485,
	IA32_VMX_CR0_FIXED0 = 0x486,
	IA32_VMX_CR0_FIXED1 = 0x487,
	IA32_VMX_CR4_FIXED0 = 0x488,
	IA32_VMX_CR4_FIXED1 = 0x489,
	IA32_VMX_VMCS_ENUM = 0x48A,
	IA32_VMX_PROCBASED_CTLS2 = 0x48B,
	IA32_VMX_EPT_VPID_CAP = 0x48C,
	IA32_VMX_TRUE_PINBASED_CTLS = 0x48D,
	IA32_VMX_TRUE_PROCBASED_CTLS = 0x48E,
	IA32_VMX_TRUE_EXIT_CTLS = 0x48F,
	IA32_VMX_TRUE_ENTRY_CTLS = 0x490,
	IA32_VMX_VMFUNC = 0x491,
	IA32_RTIT_CTL = 0x570,
	IA32_EFER= 0xC0000080,
	IA32_FS_BASE=0xC0000100,
	IA32_GS_BASE=0xC0000101

};
//4303页
typedef struct s_ia32_vmx_basic
{
	unsigned int VmcsVersion : 31;  //取1-31位的内容作为 VMCS的版本号
	unsigned int Always0 : 1;
	unsigned int VmxonSize : 13;
	unsigned int Reserved0 : 3;
	unsigned int Is32BitPhysicalAddress : 1; //48位为地址宽度 1 为32位 0为物理地址宽度     64位恒为0
	unsigned int IsSupportDualMonitor : 1; //49位 为1 则逻辑处理器支持双监视器处理系统中断和系统管理模式
	unsigned int MemoryType : 4;
	unsigned int IsReportInsAndOuts:1;
	unsigned int OtherInfo:1;
	unsigned int Reserved1 : 8; /*The values of bits 47:45 and bits 63:56 are reserved and are read as 0.*/
}S_IA32_VMX_BASIC;

typedef struct s_ia32_vmx_pinbased_ctls
{
	unsigned int AllowZeroSettingBits : 32;  //0值
	unsigned int AllowOneSettingBits : 32;  //1值
}S_IA32_VMX_PINBASED_CTLS;
typedef struct s_ia32_vmx_procbased_ctls
{
	unsigned int AllowZeroSettingBits : 32;  //0值
	unsigned int AllowOneSettingBits : 32;  //1值
}S_IA32_VMX_PROCBASED_CTLS;
typedef struct s_ia32_vmx_procbased_ctls2
{
	unsigned int AllowZeroSettingBits : 32;  //0值
	unsigned int AllowOneSettingBits : 32;  //1值
}S_IA32_VMX_PROCBASED_CTLS2;
typedef struct s_ia32_vmx_exit_ctls
{
	unsigned int AllowZeroSettingBits : 32;  //0值
	unsigned int AllowOneSettingBits : 32;  //1值
}S_IA32_VMX_EXIT_CTLS;
typedef struct s_ia32_vmx_entry_ctls
{
	unsigned int AllowZeroSettingBits : 32;  //0值
	unsigned int AllowOneSettingBits : 32;  //1值
}S_IA32_VMX_ENTRY_CTLS;

//4307页
typedef struct s_ia32_vmx_misc
{
	unsigned int TscRateOfTimer : 5;  //
	unsigned int IsStoreIa32Efer : 1;  //
	unsigned int HLT : 1;
	unsigned int ShutDown : 1;
	unsigned int WaitForSIPI : 1;
	unsigned int Reserved0 : 5;
	unsigned int IsUsedIntelPT : 1;
	unsigned int IsUsedRDMSR : 1;
	unsigned int CR3TargetValue : 9;
	unsigned int MaxMsrNum : 3;
	unsigned int IsUnblockSMI : 1;
	unsigned int IsCanUsedVmwrite : 1;
	unsigned int IsEnjectException : 1;
	unsigned int Reserved1 : 1;
	unsigned int MsegVersion : 32;
}S_IA32_VMX_MISC;
typedef struct s_ia32_vmx_vmcs_enum
{
	unsigned int AccessType : 1;
	unsigned int IndexField : 9;
	unsigned int FieldType : 2;
	unsigned int Reserved0 : 1;
	unsigned int FieldWidth : 2;
	unsigned int Reserved1 : 17;
}S_IA32_VMX_VMCS_ENUM;
typedef struct s_ia32_vmx_ept_vpid_cap
{
	unsigned int IsEptExecuteOnly : 1;  
	unsigned int Reserved0 : 5;  
	unsigned int IsSupportPageWalkLenOf4 : 1;
	unsigned int Reserved1 : 1;
	unsigned int IsEptUncacheable : 1;
	unsigned int Reserved2 : 5;
	unsigned int IsEptWriteBack : 1;
	unsigned int Reserved3 : 1;
	unsigned int IsEptPdeMapTo2M : 1;
	unsigned int IsEptPdeMapTo1G : 1;
	unsigned int Reserved4 : 2;
	unsigned int IsSupportINVEPT : 1;
	unsigned int IsSupportDirtyFlagsOfEPT : 1;
	unsigned int IsReportAdvancedInforOfEPTViolations : 1;
	unsigned int Reserved5 : 2;
	unsigned int IsSupportSingleContextINVEPT : 1;
	unsigned int IsSupportAllContextINVEPT : 1;
	unsigned int Reserved6 : 5;
	unsigned int IsSupportINVVPID : 1;
	unsigned int Reserved7 : 7;
	unsigned int IsSupportIndividualAddressINVVPID : 1;
	unsigned int IsSupportSingleContextINVVPID : 1;
	unsigned int IsSupportAllContextINVVPID : 1;
	unsigned int IsSupportSingleContextRetainGlobalINVVPID : 1;
	unsigned int Reserved8 : 20;
}S_IA32_VMX_EPT_VPID_CAP;

typedef struct def_vmx_pinbased_execution_ctls
{
	unsigned int ExternalInterruptExting : 1;
	unsigned int Reserved0 : 2;
	unsigned int NMIExiting : 1;
	unsigned int Reserved1 : 1;
	unsigned int VirtualNMIs : 1;
	unsigned int ActivateVMXPreemptionTimer : 1;
	unsigned int ProcessPostedInterrupts : 1;
	unsigned int Reserved2 : 24;

}DEF_VMX_PINBASED_EXECUTION_CTLS;


typedef struct def_vmx_procbased_execution_ctls
{
	unsigned int Reserved0 : 2;
	unsigned int InterruptWindowExiting : 1;
	unsigned int UseTSCOffsetting : 1;
	unsigned int Reserved1 : 3;
	unsigned int HLTExiting : 1;
	unsigned int Reserved2 : 1;
	unsigned int INVLPGExiting : 1;
	unsigned int MWAITExiting : 1;
	unsigned int RDPMCExiting : 1;
	unsigned int RDTSCExiting : 1;
	unsigned int Reserved3 : 2;
	unsigned int CR3LoadExiting : 1;
	unsigned int CR3StoreExiting : 1;
	unsigned int Reserved4 : 2;
	unsigned int CR8LoadExiting : 1;
	unsigned int CR8StoreExiting : 1;
	unsigned int UseTPRShadow : 1;
	unsigned int NMIWindowExiting : 1;
	unsigned int MovDRExiting : 1;
	unsigned int UncondiitionalIOExiting : 1;
	unsigned int UseIOBitmaps : 1;
	unsigned int Reserved5 : 1;
	unsigned int MonitorTrapFlag : 1;
	unsigned int UseMSRBitmaps : 1;
	unsigned int MonitorExiting : 1;
	unsigned int PauseExiting : 1;
	unsigned int ActiveSecondaryControls : 1;
}DEF_VMX_PROCBASED_EXECUTION_CTLS;

typedef struct def_vmx_secondary_Procbased_execution_ctls
{
	unsigned int VirtualizeAPICAccesses : 1;
	unsigned int EnableEPT : 1;
	unsigned int DescriptorTableExiting : 1;
	unsigned int EnableRDTSCP : 1;
	unsigned int Virtualizex2APICMode : 1;
	unsigned int EnableVPID : 1;
	unsigned int WBINVDExiting : 1;
	unsigned int UnrestrictedGuest : 1;
	unsigned int APICRegisterVirtualization : 1;
	unsigned int VirtualInterruptDelivery : 1;
	unsigned int PAUSELoopExiting : 1;
	unsigned int RDRANDExiting : 1;
	unsigned int EnableINVPCID : 1;
	unsigned int EnableVMFunctions : 1;
	unsigned int VMCSShadowing : 1;
	unsigned int EnableENCLSExiting : 1;
	unsigned int RDSEEDExiting : 1;
	unsigned int EnablePML : 1;
	unsigned int EPTViolation : 1;
	unsigned int ConcealVMXFromPT : 1;
	unsigned int EnableXSAVESAndXRSTORS : 1;
	unsigned int Reserved0 : 1;
	unsigned int ModebasedExecuteControlForEPT : 1;
	unsigned int Reserved1 : 2;
	unsigned int UseTSCScaling : 1;
	unsigned int Reserved2 : 6;
}DEF_VMX_SECONDARY_PROCBASED_EXECUTION_CTLS;

typedef struct def_vmx_exit_ctls
{
	unsigned int Reserved0 : 2;
	unsigned int SaveDebugControls : 1;
	unsigned int Reserved1: 6;
	unsigned int HostAddressSpaceSize : 1;
	unsigned int Reserved2 : 2;
	unsigned int LoadIA32_PERF_GLOBAL_CTRL : 1;
	unsigned int Reserved3 : 2;
	unsigned int AcknowledgeInterruptOnExit : 1;
	unsigned int Reserved4 : 2;
	unsigned int SaveIA32_PAT : 1;
	unsigned int LoadIA32_PAT : 1;
	unsigned int SaveIA32_EFER : 1;
	unsigned int LoadIA32_EFER : 1;
	unsigned int SaveVMXPreemptionTimerValue : 1;
	unsigned int ClearIA32_BNDCFGS : 1;
	unsigned int ConcealVMXFromPT : 1;
	unsigned int Reserved5 : 7;
}DEF_VMX_EXIT_CTLS;
typedef struct def_vmx_entry_ctls
{
	unsigned int Reserved0 : 2;
	unsigned int LoadDebugControls : 1;
	unsigned int Reserved1 : 6;
	unsigned int IA32eModeGuest : 1;
	unsigned int EntryToSMM : 1;
	unsigned int DeactivateDualmonitorTreatment : 1;
	unsigned int Reserved2 : 1;
	unsigned int LoadIA32_PERF_GLOBAL_CTRL : 1;
	unsigned int LoadIA32_PAT : 1;
	unsigned int LoadIA32_EFER : 1;
	unsigned int LoadIA32_BNDCFGS : 1;
	unsigned int ConcealVMXFromPT : 1;
	unsigned int Reserved3 : 14;
}DEF_VMX_ENTRY_CTLS;

//2438页
typedef struct s_ia32_feature_control
{
	unsigned int LockBit : 1;  //
	unsigned int EnableVmxInsideSMX : 1;  //
	unsigned int EnableVmxOutsideSMX : 1;
	unsigned int Reserved0 : 5;
	unsigned int SENTERLocalFuncEnable : 7;
	unsigned int SENTERGlobalEnable : 1;
	unsigned int Reserved1 : 16;
	unsigned int Reserved2 : 32;
}S_IA32_FEATURE_CONTROL;


//;2745页
typedef struct s_ia32_efer
{
	unsigned int sce : 1;
	unsigned int reserved0 : 7;
	unsigned int lme : 1;
	unsigned int reserved1 : 1;
	unsigned int lma : 1;
	unsigned int nxe : 1;
	unsigned int reserved2 : 20;
	unsigned int reserved3 : 32;
}S_IA_32_EFER;

//4372页
typedef struct s_ia32_rtit_ctl
{
	unsigned int TraceEn : 1;
	unsigned int CYCEn : 1;
	unsigned int OS : 1;
	unsigned int User : 1;
	unsigned int PwrEvtEn : 1;
	unsigned int FUPonPTW : 1;
	unsigned int FabricEn : 1;
	unsigned int CR3Filter : 1;
	unsigned int ToPA : 1;
	unsigned int MTCEn : 1;
	unsigned int TSCEn : 1;
	unsigned int DisRETC : 1;
	unsigned int PTWEn : 1;
	unsigned int BranchEn : 1;
	unsigned int MTCFreq : 4;
	unsigned int Reserved0 : 1;
	unsigned int CYCThresh : 4;
	unsigned int Reserved1 : 1;
	unsigned int PSBFreq : 4;
	unsigned int Reserved2 : 4;
	unsigned int ADDR0_CFG : 4;
	unsigned int ADDR1_CFG : 4;
	unsigned int ADDR2_CFG : 4;
	unsigned int ADDR3_CFG : 4;
	unsigned int Reserved3 : 16;

}S_IA32_RTIT_CTL;