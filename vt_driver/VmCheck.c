/*
实现驱动调用的相关函数
*/
#include "VmCheck.h"
#include "VmcsFields.h"

UINT64 StartVmm()
{
	// 0、检查处理器是否支持CPUID指令
	if (asm_IsCpuSupportedCPUID() == 0)
	{
		DbgPrint(("当前处理器不支持cpuid 指令!\n"));
		return 0;
	}
	// 1、检查处理器是否支持vmx
	if (asm_IsCpuSupportedVmx() == 0)
	{
		DbgPrint(("当前处理器不支持vmx 操作!\n"));
		return 0;
	}
	// 2、申请VMCS内存区域 Vmxon 最多为4096字节，函数需要不小于一页才会进行页面对齐
	PVOID Vmxon = ExAllocatePoolWithTag(NonPagedPoolNx, PAGE_SIZE, 0x766d6f6e); //"vmon"

	if (Vmxon == NULL)
	{
		DbgPrint(("ExAllocatePoolWithTag 申请内存失败!\n"));
		return 0;
	}
	RtlZeroMemory(Vmxon, PAGE_SIZE);

	// 3、初始化vmxon区域
	S_VMCS* Vmcs = Vmxon;
	MY_INT  HighMsrResult, LowMsrResult;
	asm_GetMSR(IA32_VMX_BASIC, &HighMsrResult, &LowMsrResult);
	UINT64 Ia32VmxBasicValue = COMBINE_64(HighMsrResult, LowMsrResult);
	S_IA32_VMX_BASIC* Ia32VmxBasic = (S_IA32_VMX_BASIC*)&Ia32VmxBasicValue;

	Vmcs->VmcsVersion = Ia32VmxBasic->VmcsVersion;
	Vmcs->ShadowVmcsIndicator = 0; //设置隐藏时需要检测处理器是否支持隐藏VMCS
	Vmcs->VMXAbortIndicator = 0;

	// 4、检测和设置 CR0
	MY_INT  Cr0 = asm_GetCR0();
	S_CR0* sCr0 = (S_CR0*)&Cr0;
	if (sCr0->pe == 0)
	{
		DbgPrint(("vmx操作需要运行在处理器保护模式下，处理器当前模式不符合要求!\n"));
		ExFreePoolWithTag(Vmxon, 0x766d6f6e);
		return 0;
	}
	if (sCr0->pg == 0)
	{
		DbgPrint(("vmx操作需要运行在处理器开启分页模式，处理器当前模式不符合要求!\n"));
		ExFreePoolWithTag(Vmxon, 0x766d6f6e);
		return 0;
	}
	MY_INT  HighCrFixed0 = 0, LowCrFixed0 = 0;
	asm_GetMSR(IA32_VMX_CR0_FIXED0, &HighCrFixed0, &LowCrFixed0);
	MY_INT  HighCrFixed1 = 0, LowCrFixed1 = 0;
	asm_GetMSR(IA32_VMX_CR0_FIXED1, &HighCrFixed1, &LowCrFixed1);
	SetRegDefaultValue(&Cr0, LowCrFixed0, LowCrFixed1); //64位模式下才有高位 不过并不使用它
	asm_SetCR0(Cr0);
	// 5、设置CR4 开vmx操作
	MY_INT Cr4 = asm_GetCR4();
	S_CR4* sCr4 = (S_CR4*)&Cr4;
	asm_GetMSR(IA32_VMX_CR4_FIXED0, &HighCrFixed0, &LowCrFixed0);
	asm_GetMSR(IA32_VMX_CR4_FIXED1, &HighCrFixed1, &LowCrFixed1);
	SetRegDefaultValue(&Cr4, LowCrFixed0, LowCrFixed1); //64位模式下才有高位 不过并不使用它
	sCr4->vmxe = 1; //设置vmxe位
	asm_SetCR4(Cr4);
	// 6、设置msr
	asm_GetMSR(IA32_FEATURE_CONTROL, &HighMsrResult, &LowMsrResult);
	S_IA32_FEATURE_CONTROL* Ia32FeatureControlValue = (S_IA32_FEATURE_CONTROL*)&LowMsrResult; //高位不使用

	Ia32FeatureControlValue->EnableVmxInsideSMX = 1;
	Ia32FeatureControlValue->EnableVmxOutsideSMX = 1;
	Ia32FeatureControlValue->LockBit = 1;
	asm_SetMSR(IA32_FEATURE_CONTROL, 0, LowMsrResult);  //一旦执行设置  需要关机重启才能重新配置
	// 7、执行vmxon指令 

	PHYSICAL_ADDRESS PhysicalAddr = MmGetPhysicalAddress(Vmxon);
	UINT64 Addr = PhysicalAddr.QuadPart;
	asm_Vmxon(&Addr);

	// 8、检测 vmxon执行结果
	MY_INT Rflags = asm_GetRflags();
	S_RFLAGS* sRflags = (S_RFLAGS*)&Rflags;
	if (sRflags->cf == 1) //失败
	{
		DbgPrint("开启 vmxon失败!\n");
		ExFreePoolWithTag(Vmxon, 0x766d6f6e);
		return 0;
	}
	DbgPrint("开启 vmxon成功!\n");

	/*开始执行 VM操作*/
	SetupVm();
	// 9、执行vmxoff 指令
	//asm_Vmxoff();
	__vmx_off();
	// 10、检测vmxoff 执行结果
	Rflags = asm_GetRflags();
	if (sRflags->cf == 0 && sRflags->zf == 0)
		DbgPrint(("Vmxoff 执行成功！！！！！\n"));
	else
		DbgPrint(("Vmxoff 执行失败********\n"));
	// 11、释放内存
	ExFreePoolWithTag(Vmxon, 0x766d6f6e);
	return 0;
}

UINT64 SetupVm()
{

	DbgPrint(("开始 setupvm\n"));
	//1、创建vmcs区域
	PVOID Vmcs = ExAllocatePoolWithTag(NonPagedPoolNx, PAGE_SIZE, 0x766d3030); //"vm00"
	if (Vmcs == NULL)
	{
		DbgPrint(("vmcs ExAllocatePoolWithTag 申请内存失败!\n"));
		return 0;
	}
	RtlZeroMemory(Vmcs, PAGE_SIZE);
	//2、初始化vmcs区域头

	S_VMCS* sVmcs = (S_VMCS*)Vmcs;

	MY_INT  HighMsrResult, LowMsrResult;
	asm_GetMSR(IA32_VMX_BASIC, &HighMsrResult, &LowMsrResult);
	UINT64 Ia32VmxBasic = COMBINE_64(HighMsrResult, LowMsrResult);
	S_IA32_VMX_BASIC* sIa32VmxBasic = (S_IA32_VMX_BASIC*)&Ia32VmxBasic;

	sVmcs->VmcsVersion = sIa32VmxBasic->VmcsVersion;
	sVmcs->ShadowVmcsIndicator = 0; //设置隐藏时需要检测处理器是否支持隐藏VMCS
	sVmcs->VMXAbortIndicator = 0;
	//3、使用vmclear指令初始化VMCS区域 并设置状态为 clear

	PHYSICAL_ADDRESS PhysicalAddr = MmGetPhysicalAddress(Vmcs);
	UINT64 Addr = PhysicalAddr.QuadPart;
	__try {
		asm_VmVmclear(&Addr);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		DbgPrint("vmclear失败，错误码:<%X>\n", GetExceptionCode());
		ExFreePoolWithTag(Vmcs, 0x766d3030);
		return 0;
	}
	size_t ret = __vmx_vmclear(&Addr);
	DbgPrint("执行 vmclear <%d>\n", ret);
	MY_INT Rflags = asm_GetRflags();
	S_RFLAGS* sRflags = (S_RFLAGS*)&Rflags;
	if (sRflags->cf == 1 || sRflags->zf == 1) //失败
	{
		DbgPrint("VmClear 失败!\n");
		ExFreePoolWithTag(Vmcs, 0x766d3030);
		return 0;
	}
	//4、使用VMPTRLD指令初始化vmcs指针寄存器

	__try {
		asm_VmVmptrld(&Addr);
		Rflags = asm_GetRflags();
		sRflags = (S_RFLAGS*)&Rflags;
		if (sRflags->cf == 1 || sRflags->zf == 1) //失败
		{
			DbgPrint("Vmptrld 失败!\n");
			ExFreePoolWithTag(Vmcs, 0x766d3030);
			return 0;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		DbgPrint("vmptrld失败，错误码:<%X>\n", GetExceptionCode());
		ExFreePoolWithTag(Vmcs, 0x766d3030);
		return 0;
	}
	//5、发起多个vmwrite指令初始化有效vmcs上面的相关域
	__try {
		VmVmwrite();
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		DbgPrint("vmptrld失败，错误码:<%X>\n", GetExceptionCode());
		ExFreePoolWithTag(Vmcs, 0x766d3030);
		return 0;
	}
	//6、使用vmlaunch指令启动vm
	__try {
		asm_VmVmlaunch();
		Rflags = asm_GetRflags();
		sRflags = (S_RFLAGS*)&Rflags;

		DbgPrint("sRflags->cf %d sRflags->zf %d\n", sRflags->cf, sRflags->zf);
		if (sRflags->cf == 1)
		{
			DbgPrint("Vmlaunch 失败!!!!!!!!!\n");
			ExFreePoolWithTag(Vmcs, 0x766d3030);
			return 0;
		}
		if (sRflags->zf == 1) //失败
		{
			DbgPrint("Vmlaunch 失败!\n");
			ExFreePoolWithTag(Vmcs, 0x766d3030);
			size_t ErrorCode = asm_VmVmread(vmcs_VMEntryExceptionErrorCode);
			DbgPrint("VmEntryErrorCode <%X>\n", ErrorCode);
			ErrorCode = asm_VmVmread(vmcs_VMInstructionError);
			DbgPrint("ErrorCode <%X>\n", ErrorCode);
			ErrorCode = asm_VmVmread(vmcs_ExitReason);
			DbgPrint("ErrorReason <%X>\n", ErrorCode);
			ErrorCode = asm_VmVmread(vmcs_VMEntryExceptionErrorCode);
			DbgPrint("vmcs_VMEntryExceptionErrorCode <%X>\n", ErrorCode);
			ErrorCode = asm_VmVmread(vmcs_VMExitInstructionInformation);
			DbgPrint("vmcs_VMExitInstructionInformation <%X>\n", ErrorCode);
			DbgPrint("vmcs <%X>\n", sVmcs->VMXAbortIndicator);
			return 0;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		DbgPrint("vmlaunch失败，错误码:<%X>\n", GetExceptionCode());
		ExFreePoolWithTag(Vmcs, 0x766d3030);
		return 0;
	}

	//__vmx_vmresume();
	ExFreePoolWithTag(Vmcs, 0x766d3030);
	DbgPrint(("结束 setupvm\n"));
	return 0;
}


BOOLEAN InitialVmExecutiveCtrls()
{
	//3814页
	//1、pin-based VM-execution controls
	MY_INT  HighFixed0 = 0, LowFixed1 = 0;
	MY_INT VmxBaseValue = 0;
	MY_INT VmxPinBasedValue = 0x16;
	MY_INT FirstProcBasedValue = 0x401E172;
	MY_INT VmxExitValue = 0x36DFF;
	MY_INT VmxEntryValue = 0x11FF;

	asm_GetMSR(IA32_VMX_BASIC, &HighFixed0, &LowFixed1);
	VmxBaseValue = (HighFixed0 << 32) + LowFixed1;
	S_IA32_VMX_BASIC* sIa32VmxBasic = (S_IA32_VMX_BASIC*)&VmxBaseValue;
	if (sIa32VmxBasic->OtherInfo == 1)
	{
		DbgPrint("sIa32VmxBasic->OtherInfo\n");
		asm_GetMSR(IA32_VMX_TRUE_PINBASED_CTLS, &HighFixed0, &LowFixed1);
		//SetRegDefaultValue(&VmxPinBasedValue, HighFixed0, LowFixed1);
		VmxPinBasedValue = HighFixed0 | LowFixed1;
		DbgPrint("VmxPinBasedValue %X %X %X\n", VmxPinBasedValue, HighFixed0, LowFixed1);

		asm_GetMSR(IA32_VMX_TRUE_PROCBASED_CTLS, &HighFixed0, &LowFixed1);
		//SetRegDefaultValue(&FirstProcBasedValue, HighFixed0, LowFixed1);
		FirstProcBasedValue = HighFixed0 | LowFixed1;
		DbgPrint("FirstProcBasedValue %X %X %X\n", FirstProcBasedValue, HighFixed0, LowFixed1);

		asm_GetMSR(IA32_VMX_TRUE_EXIT_CTLS, &HighFixed0, &LowFixed1);
		//SetRegDefaultValue(&VmxExitValue, HighFixed0, LowFixed1);
		VmxExitValue = HighFixed0 | LowFixed1;
		DbgPrint("VmxExitValue %X %X %X\n", VmxExitValue, HighFixed0, LowFixed1);

		asm_GetMSR(IA32_VMX_TRUE_ENTRY_CTLS, &HighFixed0, &LowFixed1);
		//SetRegDefaultValue(&VmxEntryValue, HighFixed0, LowFixed1);
		VmxEntryValue = HighFixed0 | LowFixed1;
		DbgPrint("VmxEntryValue %X %X %X\n", VmxEntryValue, HighFixed0, LowFixed1);
	}

	//	DEF_VMX_PINBASED_EXECUTION_CTLS* PinBasedExeCtrls = (DEF_VMX_PINBASED_EXECUTION_CTLS*)&VmxPinBasedValue;
	//	DEF_VMX_PROCBASED_EXECUTION_CTLS* FirstProcBasedExeCtls = (DEF_VMX_PROCBASED_EXECUTION_CTLS*)&FirstProcBasedValue;
	//	DEF_VMX_SECONDARY_PROCBASED_EXECUTION_CTLS* SecondProcbasedExeCtls = (DEF_VMX_SECONDARY_PROCBASED_EXECUTION_CTLS*)&SecondProcBasedValue;
	//	DEF_VMX_EXIT_CTLS * VmxExitCtls = (DEF_VMX_EXIT_CTLS*)&VmxExitValue;
	//	DEF_VMX_ENTRY_CTLS* VmxEntryCtls = (DEF_VMX_ENTRY_CTLS*)&VmxEntryValue;


		//3、设置CR3计数值
		asm_GetMSR(IA32_VMX_MISC, &HighFixed0, &LowFixed1);
		MY_INT MiscValue = (HighFixed0 << 32) + LowFixed1;
		S_IA32_VMX_MISC* sIa32VmxMisc = (S_IA32_VMX_MISC*)&MiscValue;


	vmwrite(vmcs_CR3TargetCount, sIa32VmxMisc->CR3TargetValue);
	vmwrite(vmcs_CR3TargetValue0, 0);
	vmwrite(vmcs_CR3TargetValue1, 0);
	vmwrite(vmcs_CR3TargetValue2, 0);
	vmwrite(vmcs_CR3TargetValue3, 0);
	vmwrite(vmcs_PinBasedVMExecutionControls, VmxPinBasedValue);
	vmwrite(vmcs_PrimaryProcessorBasedVMExecutionControls, FirstProcBasedValue);
	vmwrite(vmcs_VMExitControls, VmxExitValue);
	vmwrite(vmcs_VMEntryControls, VmxEntryValue);
	vmwrite(vmcs_VMEntryMSRLoadCount, 0);
	vmwrite(vmcs_VMEntryInterruptionInformationField, 0);
	vmwrite(vmcs_VMExitMSRLoadCount, 0);
	vmwrite(vmcs_VMExitMSRStoreCount, 0);

	return TRUE;
}

BOOLEAN InitialVmHostState()
{
	//1、填充控制寄存器 和 msr
	MY_INT Cr0 = asm_GetCR0();
	MY_INT  HighCrFixed0 = 0, LowCrFixed0 = 0;
	asm_GetMSR(IA32_VMX_CR0_FIXED0, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("Cr0 %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	MY_INT  HighCrFixed1 = 0, LowCrFixed1 = 0;
	asm_GetMSR(IA32_VMX_CR0_FIXED1, &HighCrFixed1, &LowCrFixed1);
	DbgPrint("Cr0 %llX  %llX\n", HighCrFixed1, LowCrFixed1);
	DbgPrint("Cr0前 %llX  \n", Cr0);
	SetRegDefaultValue(&Cr0, LowCrFixed0, LowCrFixed1); //64位模式下才有高位 不过并不使用它
	DbgPrint("Cr0后 %llX  \n", Cr0);
	vmwrite(vmcs_HostCR0, asm_GetCR0());


	MY_INT Cr4 = asm_GetCR4();
	//S_CR4* sCr4 = (S_CR4*)&Cr4;
	asm_GetMSR(IA32_VMX_CR4_FIXED0, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("Cr4 %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	asm_GetMSR(IA32_VMX_CR4_FIXED1, &HighCrFixed1, &LowCrFixed1);
	DbgPrint("Cr4 %llX  %llX\n", HighCrFixed1, LowCrFixed1);
	DbgPrint("Cr4前 %llX  \n", Cr4);
	SetRegDefaultValue(&Cr4, LowCrFixed0, LowCrFixed1); //64位模式下才有高位 不过并不使用它
	//sCr4->vmxe = 1; //设置vmxe位
	vmwrite(vmcs_HostCR4, asm_GetCR4());
	MY_INT Cr3 = asm_GetCR3(); 
	DbgPrint("Cr4 %llX %llx  %llX\n", Cr0, Cr3,Cr4);
	vmwrite(vmcs_HostCR3, Cr3);

	//填充段寄存器和描述符表寄存器  3819页
	vmwrite(vmcs_HostCSSelector, asm_GetCS() & 0xFFF8);
	vmwrite(vmcs_HostSSSelector, asm_GetSS() & 0xFFF8);
	vmwrite(vmcs_HostDSSelector, asm_GetDS() & 0xFFF8);
	vmwrite(vmcs_HostESSelector, asm_GetES() & 0xFFF8);
	vmwrite(vmcs_HostFSSelector, asm_GetFS() & 0xFFF8);
	vmwrite(vmcs_HostGSSelector, asm_GetGS() & 0xFFF8);
	vmwrite(vmcs_HostTRSelector, asm_GetTR() & 0xFFF8);

	//MY_INT GdtLimit=0,GdtBase=0;
	S_GPT_TABLE_64 GdtTable = { 0 };
	asm_SGDT(&(GdtTable.Limit), &(GdtTable.Base));
	DbgPrint("GdtTable limit %X base %llX \n", GdtTable.Limit, GdtTable.Base);
	vmwrite(vmcs_HostGDTRBase, GdtTable.Base);
	S_GPT_TABLE_64 IdtTable = { 0 };
	asm_SIDT(&(IdtTable.Limit), &(IdtTable.Base));
	DbgPrint("GdtTable limit %X base %llX \n", IdtTable.Limit, IdtTable.Base);
	vmwrite(vmcs_HostIDTRBase, IdtTable.Base);

	DbgPrint("GDT %llx GS %X FS %X TR %X\n", GdtTable.Base,asm_GetGS(),asm_GetFS(),asm_GetTR());
	MY_INT Base = CalculateSegmentBase(asm_GetFS(), GdtTable.Base);
	vmwrite(vmcs_HostFSBase, Base);
	DbgPrint("开始计算 FS 基址 %llX\n",Base); 
	Base = CalculateSegmentBase(asm_GetGS(), GdtTable.Base);
	DbgPrint("开始计算 GS 基址 %llX\n",Base);
	vmwrite(vmcs_HostGSBase, Base);
	Base = CalculateSegmentBase(asm_GetTR(), GdtTable.Base);
	DbgPrint("开始计算 TR 基址 %llX\n",Base);
	vmwrite(vmcs_HostTRBase, Base);


	
	asm_GetMSR(IA32_SYSENTER_CS, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("vmcs_HostIA32_SYSENTER_CS %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	vmwrite(vmcs_HostIA32_SYSENTER_CS,  (HighCrFixed0<<32)+LowCrFixed0);

	asm_GetMSR(IA32_SYSENTER_ESP, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("vmcs_HostIA32_SYSENTER_ESP %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	vmwrite(vmcs_HostIA32_SYSENTER_ESP, (HighCrFixed0 << 32) + LowCrFixed0);

	asm_GetMSR(IA32_SYSENTER_EIP, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("vmcs_HostIA32_SYSENTER_EIP %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	vmwrite(vmcs_HostIA32_SYSENTER_EIP, (HighCrFixed0 << 32) + LowCrFixed0);

	asm_GetMSR(IA32_PAT, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("IA32_PAT %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	vmwrite(vmcs_HostIA32_PATFull, (HighCrFixed0 << 32) + LowCrFixed0);
	vmwrite(vmcs_HostIA32_PATHigh, (HighCrFixed0 << 32) + LowCrFixed0);

	asm_GetMSR(IA32_EFER, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("IA32_EFER %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	vmwrite(vmcs_HostIA32_EFERFull, (HighCrFixed0 << 32) + LowCrFixed0);
	vmwrite(vmcs_HostIA32_EFERHigh, (HighCrFixed0 << 32) + LowCrFixed0);

	asm_GetMSR(IA32_PERF_GLOBAL_CTRL, &HighCrFixed0, &LowCrFixed0);
	DbgPrint("IA32_PERF_GLOBAL_CTRL %llX  %llX\n", HighCrFixed0, LowCrFixed0);
	vmwrite(vmcs_HostIA32_PERF_GLOBAL_CTRLFull, (HighCrFixed0 << 32) + LowCrFixed0);
	vmwrite(vmcs_HostIA32_PERF_GLOBAL_CTRLHigh, (HighCrFixed0 << 32) + LowCrFixed0);


	PVOID Vrsp = ExAllocatePoolWithTag(NonPagedPoolNx, 2*PAGE_SIZE, 0x766d3031); //"vm00"
	vmwrite(vmcs_HostRSP, (ULONGLONG)((ULONGLONG)Vrsp+0x1FFF));

	vmwrite(vmcs_HostRIP, (ULONGLONG)&VmEntry);
	ExFreePoolWithTag(Vrsp, 0x766d3031);
	return TRUE;
}



UINT64 VmVmwrite()
{
	//a 初始化vmx control控制域
	//InitialVmExecutiveCtrls();
	//b 初始化vm host-state域
	//InitialVmHostState();

	return 0;
}

void vmwrite(MY_INT writeType, MY_INT Content)
{
	asm_VmVmwrite(writeType, Content);
	MY_INT Rflags = asm_GetRflags();
	S_RFLAGS* sRflags = (S_RFLAGS*)&Rflags;
	if (sRflags->cf == 1||sRflags->zf==1) //失败
	{
		DbgPrint("vmwrite 失败 %llX!\n",writeType);
	}

}

void VmEntry()
{
}

void SetRegDefaultValue(MY_INT* Target, MY_INT Factor1, MY_INT Factor2)
{
	(*Target) &= (Factor1 | Factor2);  //设置0位
	(*Target) |= (Factor1 & Factor2);  //设置1位
}

INT64 CalculateSegmentBase( MY_INT Selector, MY_INT Base)
{
	//1、清除选择子低位
	Selector &= (~0x7);
	//2、获取GDT表中的地址
	Base += Selector;
	//3、读取LDT项内容
	MY_INT LdtContent = *(MY_INT*)Base;
	S_SEGMENT_DESCRIPTOR* sSegDesc = (S_SEGMENT_DESCRIPTOR*)&LdtContent;
	INT64 ret = sSegDesc->BaseAddress + (sSegDesc->Base0 << 16) + (sSegDesc->Base1 << 24);
	if (ret & 0x80000000)
		ret |= 0xFFFFFFFF00000000;
	return ret;
}

