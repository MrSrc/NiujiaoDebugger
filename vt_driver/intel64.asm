
.code

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

end
