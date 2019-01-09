;为 vt_driver 提供64位的函数调用库
.code

EXTERN SetupVm:PROC 
asm_BreakPoint PROC 
	int 3
	ret
asm_BreakPoint ENDP
asm_GetCpuVendor PROC
	;保存参数地址
	push rcx
	push rdx
	push r8
	mov rax,0
	cpuid
	pop rax
	mov qword ptr [rax],rdx
	pop rax
	mov qword ptr [rax],rcx
	pop rax
	mov qword ptr [rax],rbx
	ret
asm_GetCpuVendor ENDP
;intel 手册 780页
asm_IsCpuSupportedVmx PROC
	mov rax,1
	cpuid
	and  ecx,20h
	jz NO_VMX
	mov rax,1
	ret
No_VMX:
	mov rax,0
	ret
asm_IsCpuSupportedVmx ENDP
;80页
asm_IsCpuSupportedCPUID PROC
	pushfq
	pop rax
	mov rbx,rax
	xor rax,00200000h
	push rax
	popfq
	pushfq
	pop rax
	cmp rax,rbx
	jz NO_CPUID
	mov rax,1
	ret
NO_CPUID:
	mov rax,0
	ret
asm_IsCpuSupportedCPUID ENDP
;1654页
asm_GetMSR PROC
	;保存两个参数地址
	push r8
	push rdx
	rdmsr
	pop rbx
	mov qword ptr [rbx],rdx
	pop rbx
	mov qword ptr [rbx],rax
	ret
asm_GetMSR ENDP

;2382页
asm_SetMSR PROC
	mov rax,r8
	wrmsr
	ret
asm_SetMSR ENDP
;1166页
asm_GetCR0 PROC
	mov rax,cr0
	ret
asm_GetCR0 ENDP
asm_SetCR0 PROC
	mov cr0,rcx
	ret
asm_SetCR0 ENDP

asm_GetCR3 PROC
	mov rax,cr3
	ret
asm_GetCR3 ENDP

asm_GetCS PROC
	mov rax,cs
	ret
asm_GetCS ENDP
asm_GetSS PROC
	mov rax,ss
	ret
asm_GetSS ENDP
asm_GetDS PROC
	mov rax,ds
	ret
asm_GetDS ENDP
asm_GetES PROC
	mov rax,es
	ret
asm_GetES ENDP
asm_GetFS PROC
	mov rax,fs
	ret
asm_GetFS ENDP
asm_GetGS PROC
	mov rax,gs
	ret
asm_GetGS ENDP
asm_GetTR PROC
	str rax
	ret
asm_GetTR ENDP
asm_SGDT PROC
	local gdtr[10]:BYTE
	sgdt gdtr
	mov ax,word ptr gdtr[0]
	mov word ptr[rcx],ax
	mov rax,qword ptr gdtr[2]
	mov qword ptr[rdx],rax
	ret
asm_SGDT ENDP
asm_SIDT PROC
	local idtr[10]:BYTE
	sidt idtr
	mov ax,word ptr idtr[0]
	mov word ptr[rcx],ax
	mov rax,qword ptr idtr[2]
	mov qword ptr[rdx],rax
	ret
asm_SIDT ENDP
asm_SLDT PROC
	sldt rax
	ret
asm_SLDT ENDP
asm_SetCR3 PROC
	mov cr3,rcx
	ret
asm_SetCR3 ENDP
asm_GetCR4 PROC
	mov rax,cr4
	ret
asm_GetCR4 ENDP
asm_SetCR4 PROC
	mov cr4,rcx
	ret
asm_SetCR4 ENDP

asm_GetRflags PROC
	pushfq
	pop rax
	ret
asm_GetRflags ENDP
;3933页
asm_Vmxon PROC
	vmxon qword ptr[rcx]
	ret
asm_Vmxon ENDP


;3917页
asm_VmVmclear PROC
	vmclear qword ptr[rcx]
	ret
asm_VmVmclear ENDP

;3922页
asm_VmVmptrld PROC
	vmptrld qword ptr[rcx]
	ret
asm_VmVmptrld ENDP

asm_Vmxoff PROC
	vmxoff
	ret
asm_Vmxoff ENDP

asm_VmVmlaunch PROC
	vmlaunch
	ret
asm_VmVmlaunch ENDP

asm_VmVmwrite PROC
	vmwrite rcx,rdx
	ret
asm_VmVmwrite ENDP

asm_VmVmread PROC
	vmread rax,rcx
	ret
asm_VmVmread ENDP

end
