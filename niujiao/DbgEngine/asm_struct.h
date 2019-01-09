#pragma once
/*
定义汇编引擎的相关结构  -- SAsmInstruct 结构由脚本读取intel手册 Volume 2 (2A, 2B, 2C & 2D):Instruction Set Reference, A-Z中的内容自动生成
*/
#include <Windows.h>
#include "define.h"
#include "asm.h"

enum asm_error_code
{
	ASM_ERROR_INCORRECT_OPERANDNUM,
};

enum e_opcode_supported_mode
{
	SUPPORT_UNDEF,
	SUPPORT64_BIT_V,
	SUPPORT32_BIT_V,
	SUPPORT_CL_V,
	SUPPORT64_BIT_I,
	SUPPORT32_BIT_I,
	SUPPORT_CL_I,
	SUPPORT64_BIT_NE,
	SUPPORT32_BIT_NE,
	SUPPORT_CL_NE,
	SUPPORT64_BIT_NP,
	SUPPORT32_BIT_NP,
	SUPPORT64_BIT_NI,
	SUPPORT32_BIT_NI,
	SUPPORT64_BIT_NS,
	SUPPORT32_BIT_NS,
};


// 1125页  LZCNT 三条记录
// 2328页 VREDUCESD 
// 2332页 VREDUCESS 
static SAsmInstruct gAsmInstruct[] =
{
{"aaa"             ,0x37        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"aad"             ,0xd50a      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd5        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                     ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm },
{"aam"             ,0xd40a      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd4        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                     ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm },
{"aas"             ,0x3f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"adc"             ,0x14        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x15        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x15        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x15        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x10        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x10        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x11        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x11        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x11        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x12        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x12        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x13        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x13        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x13        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"adcx"            ,0x660f38f6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //ADX
					0x660f38f6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //ADX
{"add"             ,0x4         ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x5         ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x5         ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x5         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x1         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x2         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x3         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"addpd"           ,0x660f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vaddpd"          ,0x660f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"addps"           ,0xf58       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vaddps"          ,0xf58       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf58       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf58       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf58       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf58       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"addsd"           ,0xf20f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vaddsd"          ,0xf20f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"addss"           ,0xf30f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vaddss"          ,0xf30f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f58    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"addsubpd"        ,0x660fd0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vaddsubpd"       ,0x660fd0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"addsubps"        ,0xf20fd0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vaddsubps"       ,0xf20fd0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20fd0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"adox"            ,0xf30f38f6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //ADX
					0xf30f38f6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //ADX
{"aesdec"          ,0x660f38de  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AES
{"vaesdec"         ,0x660f38de  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both AES and AVX flags
{"aesdeclast"      ,0x660f38df  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AES
{"vaesdeclast"     ,0x660f38df  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both AES and AVX flags
{"aesenc"          ,0x660f38dc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AES
{"vaesenc"         ,0x660f38dc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both AES and AVX flags
{"aesenclast"      ,0x660f38dd  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AES
{"vaesenclast"     ,0x660f38dd  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both AES and AVX flags
{"aesimc"          ,0x660f38db  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AES
{"vaesimc"         ,0x660f38db  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both AES and AVX flags
{"aeskeygenassist" ,0x660f3adf  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AES
{"vaeskeygenassist",0x660f3adf  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both AES and AVX flags
{"and"             ,0x24        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x25        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x25        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x25        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x20        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x20        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x21        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x21        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x21        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x22        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x22        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x23        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x23        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x23        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"andn"            ,0xf38f2     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //BMI1
{"0f38"            ,0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI1
{"andpd"           ,0x660f54    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vandpd"          ,0x660f54    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f54    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f54    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f54    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f54    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"andps"           ,0xf54       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vandps"          ,0xf54       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf54       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf54       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf54       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf54       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"andnpd"          ,0x660f55    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vandnpd"         ,0x660f55    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f55    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f55    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f55    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"andnps"          ,0xf55       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vandnps"         ,0xf55       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf55       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf55       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf55       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf55       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"arpl"            ,0x63        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"blendpd"         ,0x660f3a0d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vblendpd"        ,0x660f3a0d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a0d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"bextr"           ,0xf38f7     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI1
					0xf38f7     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI1
{"blendps"         ,0x660f3a0c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vblendps"        ,0x660f3a0c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a0c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"blendvpd"        ,0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vblendvpd"       ,0x660f3a4b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a4b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"blendvps"        ,0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vblendvps"       ,0x660f3a4a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a4a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"blsi"            ,0xf38f3     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None ,  //BMI1
					0xf38f3     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,3    ,CAsm::Asm_None },  //BMI1
{"blsmsk"          ,0xf38f3     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None ,  //BMI1
					0xf38f3     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,2    ,CAsm::Asm_None },  //BMI1
{"blsr"            ,0xf38f3     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None ,  //BMI1
					0xf38f3     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,1    ,CAsm::Asm_None },  //BMI1
{"bndcl"           ,0xf30f1a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0xf30f1a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bndcu"           ,0xf20f1a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0xf20f1a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bndcn"           ,0xf20f1b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0xf20f1b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bndldx"          ,0xf1a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bndmk"           ,0xf30f1b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0xf30f1b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bndmov"          ,0x660f1a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0x660f1a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0x660f1b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MPX
					0x660f1b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bndstx"          ,0xf1b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //MPX
{"bound"           ,0x62        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x62        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"bsf"             ,0xfbc       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbc       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbc       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"bsr"             ,0xfbd       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbd       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbd       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"bswap"           ,0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"bt"              ,0xfa3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_0FBA },
{"btc"             ,0xfbb       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbb       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbb       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_0FBA },
{"btr"             ,0xfb3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_0FBA },
{"bts"             ,0xfab       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfab       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfab       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_0FBA ,
					0xfba       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_0FBA },
{"bzhi"            ,0xf38f5     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf38f5     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"call"            ,0xe8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_FF ,
					0x9a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x9a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_FF },
{"cbw"             ,0x98        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cwde"            ,0x98        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cdqe"            ,0x98        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"clac"            ,0xf01ca     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SMAP
{"clc"             ,0xf8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cld"             ,0xfc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"clflush"         ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_0FAE },
{"clflushopt"      ,0x660fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None },
{"cli"             ,0xfa        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"clts"            ,0xf06       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"clwb"            ,0x660fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //CLWB
{"cmc"             ,0xf5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cmova"           ,0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovae"          ,0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovb"           ,0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovbe"          ,0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovc"           ,0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmove"           ,0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovg"           ,0xf4f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //NA
{"cmovge"          ,0xf4d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovl"           ,0xf4c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovle"          ,0xf4e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovna"          ,0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnae"         ,0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnb"          ,0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnbe"         ,0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnc"          ,0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf43       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovne"          ,0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovng"          ,0xf4e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnge"         ,0xf4c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnl"          ,0xf4d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnle"         ,0xf4f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovno"          ,0xf41       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf41       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf41       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnp"          ,0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovns"          ,0xf49       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf49       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf49       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovnz"          ,0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovo"           ,0xf40       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf40       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf40       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovp"           ,0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovpe"          ,0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovpo"          ,0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovs"           ,0xf48       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf48       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf48       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmovz"           ,0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmp"             ,0x3c        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3d        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3d        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x38        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x38        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x39        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x39        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x39        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x3a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x3b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x3b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmppd"           ,0x660fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcmppd"          ,0x660fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cmpps"           ,0xfc2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vcmpps"          ,0xfc2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xfc2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xfc2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xfc2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xfc2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cmps"            ,0xa6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmpsb"           ,0xa6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cmpsw"           ,0xa7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cmpsd"           ,0xa7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf20fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"cmpsq"           ,0xa7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"vcmpsd"          ,0xf20fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cmpss"           ,0xf30fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vcmpss"          ,0xf30fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30fc2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cmpxchg"         ,0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmpxchg8b"       ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_0FC7 },
{"cmpxchg16b"      ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_0FC7 },
{"comisd"          ,0x660f2f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcomisd"         ,0x660f2f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f2f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"comiss"          ,0xf2f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vcomiss"         ,0xf2f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf2f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cpuid"           ,0xfa2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"crc32"           ,0xf20f38f0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf20f38f0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf20f38f1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf20f38f1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf20f38f0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf20f38f1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cvtdq2pd"        ,0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtdq2pd"       ,0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtdq2ps"        ,0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtdq2ps"       ,0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtpd2dq"        ,0xf20fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtpd2dq"       ,0xf20fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf20fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf20fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtpd2pi"        ,0x660f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cvtpd2ps"        ,0x660f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtpd2ps"       ,0x660f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtpi2pd"        ,0x660f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cvtpi2ps"        ,0xf2a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cvtps2dq"        ,0x660f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtps2dq"       ,0x660f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtps2pd"        ,0xf5a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtps2pd"       ,0xf5a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL
					0xf5a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtps2pi"        ,0xf2d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cvtsd2si"        ,0xf20f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf20f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtsd2si"       ,0xf20f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtsd2ss"        ,0xf20f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtsd2ss"       ,0xf20f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtsi2sd"        ,0xf20f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf20f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtsi2sd"       ,0xf20f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtsi2ss"        ,0xf30f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf30f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vcvtsi2ss"       ,0xf30f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f2a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtss2sd"        ,0xf30f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvtss2sd"       ,0xf30f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvtss2si"        ,0xf30f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf30f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vcvtss2si"       ,0xf30f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f2d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvttpd2dq"       ,0x660fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvttpd2dq"      ,0x660fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvttpd2pi"       ,0x660f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cvttps2dq"       ,0xf30f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvttps2dq"      ,0xf30f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f5b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvttps2pi"       ,0xf2c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cvttsd2si"       ,0xf20f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf20f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vcvttsd2si"      ,0xf20f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cvttss2si"       ,0xf30f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf30f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vcvttss2si"      ,0xf30f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f2c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"cwd"             ,0x99        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cdq"             ,0x99        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cqo"             ,0x99        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"daa"             ,0x27        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"das"             ,0x2f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"dec"             ,0xfe        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_FE ,
					0xfe        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_FE ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_FF ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"div"             ,0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_F6_F7 ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_F6_F7 },
{"divpd"           ,0x660f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vdivpd"          ,0x660f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"divps"           ,0xf5e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vdivps"          ,0xf5e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"divsd"           ,0xf20f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vdivsd"          ,0xf20f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"divss"           ,0xf30f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vdivss"          ,0xf30f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"dppd"            ,0x660f3a41  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vdppd"           ,0x660f3a41  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"dpps"            ,0x660f3a40  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vdpps"           ,0x660f3a40  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a40  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"emms"            ,0xf77       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"enter"           ,0xc800      ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__w,AT__I,OT_zero,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc801      ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__w,AT__I,OT_one,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc8        ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__w,AT__I,OT__b,0,0,0,0)             ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"extractps"       ,0x660f3a17  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vextractps"      ,0x660f3a17  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a17  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"f2xm1"           ,0xd9f0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fabs"            ,0xd9e1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fadd"            ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xd8c0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdcc0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"faddp"           ,0xdec0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdec1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fiadd"           ,0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None },
{"fbld"            ,0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None },
{"fbstp"           ,0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None },
{"fchs"            ,0xd9e0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fclex"           ,0x9bdbe2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fnclex"          ,0xdbe2      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovb"          ,0xdac0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmove"          ,0xdac8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovbe"         ,0xdad0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovu"          ,0xdad8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovnb"         ,0xdbc0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovne"         ,0xdbc8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovnbe"        ,0xdbd0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcmovnu"         ,0xdbd8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcom"            ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None ,
					0xd8d0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd8d1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcomp"           ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xd8d8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd8d9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcompp"          ,0xded9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcomi"           ,0xdbf0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcomip"          ,0xdff0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fucomi"          ,0xdbe8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fucomip"         ,0xdfe8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fcos"            ,0xd9ff      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fdecstp"         ,0xd9f6      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fdiv"            ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None ,
					0xd8f0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdcf8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fdivp"           ,0xdef8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdef9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fidiv"           ,0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None ,
					0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None },
{"fdivr"           ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None ,
					0xd8f8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdcf0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fdivrp"          ,0xdef0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdef1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fidivr"          ,0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None ,
					0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None },
{"ffree"           ,0xddc0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ficom"           ,0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None ,
					0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None },
{"ficomp"          ,0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None },
{"fild"            ,0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xdb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None },
{"fincstp"         ,0xd9f7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"finit"           ,0x9bdbe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fninit"          ,0xdbe3      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fist"            ,0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None ,
					0xdb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None },
{"fistp"           ,0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xdb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None },
{"fisttp"          ,0xdf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None ,
					0xdb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None ,
					0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None },
{"fld"             ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xdb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None ,
					0xd9c0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fld1"            ,0xd9e8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldl2t"          ,0xd9e9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldl2e"          ,0xd9ea      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldpi"           ,0xd9eb      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldlg2"          ,0xd9ec      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldln2"          ,0xd9ed      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldz"            ,0xd9ee      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fldcw"           ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None },
{"fldenv"          ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None },
{"fmul"            ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None ,
					0xd8c8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdcc8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fmulp"           ,0xdec8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdec9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fimul"           ,0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None ,
					0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_None },
{"fnop"            ,0xd9d0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fpatan"          ,0xd9f3      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fprem"           ,0xd9f8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fprem1"          ,0xd9f5      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fptan"           ,0xd9f2      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"frndint"         ,0xd9fc      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"frstor"          ,0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None },
{"fsave"           ,0x9bdd      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None },
{"fnsave"          ,0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None },
{"fscale"          ,0xd9fd      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fsin"            ,0xd9fe      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fsincos"         ,0xd9fb      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fsqrt"           ,0xd9fa      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fst"             ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None ,
					0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_None ,
					0xddd0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fstp"            ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_None ,
					0xdb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None ,
					0xddd8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fstcw"           ,0x9bd9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None },
{"fnstcw"          ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None },
{"fstenv"          ,0x9bd9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None },
{"fnstenv"         ,0xd9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_None },
{"fstsw"           ,0x9bdd      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None ,
					0x9bdfe0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fnstsw"          ,0xdd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_None ,
					0xdfe0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fsub"            ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None ,
					0xd8e0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdce8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fsubp"           ,0xdee8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdee9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fisub"           ,0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None ,
					0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_None },
{"fsubr"           ,0xd8        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None ,
					0xdc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None ,
					0xd8e8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdce0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fsubrp"          ,0xdee0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdee1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fisubr"          ,0xda        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None ,
					0xde        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_None },
{"ftst"            ,0xd9e4      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fucom"           ,0xdde0      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdde1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fucomp"          ,0xdde8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xdde9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fucompp"         ,0xdae9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fxam"            ,0xd9e5      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fxch"            ,0xd9c8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd9c9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fxrstor"         ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_0FAE },
{"fxrstor64"       ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_0FAE },
{"fxsave"          ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_0FAE },
{"fxsave64"        ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_0FAE },
{"fyl2x"           ,0xd9f1      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fyl2xp1"         ,0xd9f9      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"haddpd"          ,0x660f7c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vhaddpd"         ,0x660f7c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f7c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"haddps"          ,0xf20f7c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vhaddps"         ,0xf20f7c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f7c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"hlt"             ,0xf4        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"hsubpd"          ,0x660f7d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vhsubpd"         ,0x660f7d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f7d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"hsubps"          ,0xf20f7d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vhsubps"         ,0xf20f7d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f7d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"idiv"            ,0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_F6_F7 ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_F6_F7 },
{"imul"            ,0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_F6_F7 ,
					0xfaf       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfaf       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfaf       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x6b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x69        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x69        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x69        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"in"              ,0xe4        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe5        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__b,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe5        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__b,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xec        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT_XX,RG__DX,0,0,0,0)       ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xed        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT_XX,RG__DX,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xed        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__G,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"inc"             ,0xfe        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_FE ,
					0xfe        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_FE ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_FF ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ins"             ,0x6c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"insb"            ,0x6c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"insw"            ,0x6d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"insd"            ,0x6d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"insertps"        ,0x660f3a21  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vinsertps"       ,0x660f3a21  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a21  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"int3"            ,0xcc        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"int"             ,0xcd        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                     ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm },
{"into"            ,0xce        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"int1"            ,0xf1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"invd"            ,0xf08       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"invlpg"          ,0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"invpcid"         ,0x660f3882  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //INVPCID
					0x660f3882  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //INVPCID
{"iret"            ,0xcf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"iretd"           ,0xcf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"iretq"           ,0xcf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"ja"              ,0x77        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf87       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf87       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jae"             ,0x73        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf83       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf83       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jb"              ,0x72        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf82       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf82       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jbe"             ,0x76        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf86       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf86       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jc"              ,0x72        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf82       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf82       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jcxz"            ,0xe3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jecxz"           ,0xe3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jrcxz"           ,0xe3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"je"              ,0x74        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf84       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf84       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jg"              ,0x7f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jge"             ,0x7d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jl"              ,0x7c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jle"             ,0x7e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jna"             ,0x76        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf86       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf86       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnae"            ,0x72        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf82       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf82       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnb"             ,0x73        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf83       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf83       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnbe"            ,0x77        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf87       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf87       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnc"             ,0x73        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf83       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf83       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jne"             ,0x75        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf85       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf85       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jng"             ,0x7e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnge"            ,0x7c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnl"             ,0x7d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnle"            ,0x7f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jno"             ,0x71        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf81       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf81       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnp"             ,0x7b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jns"             ,0x79        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf89       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf89       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jnz"             ,0x75        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf85       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf85       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jo"              ,0x70        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf80       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf80       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jp"              ,0x7a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jpe"             ,0x7a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jpo"             ,0x7b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf8b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"js"              ,0x78        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf88       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf88       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jz"              ,0x74        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf84       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf84       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf84       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf84       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"jmp"             ,0xeb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NS    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_FF ,
					0xea        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xea        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_FF },
{"kaddw"           ,0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kaddb"           ,0x660f4a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kaddq"           ,0xf4a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kaddd"           ,0x660f4a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kandw"           ,0xf41       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kandb"           ,0x660f41    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kandq"           ,0xf41       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kandd"           ,0x660f41    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kandnw"          ,0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kandnb"          ,0x660f42    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kandnq"          ,0xf42       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kandnd"          ,0x660f42    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kmovw"           ,0xf90       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf91       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kmovb"           ,0x660f90    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512DQ
					0x660f91    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512DQ
					0x660f92    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512DQ
					0x660f93    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kmovq"           ,0xf90       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf91       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf20f92    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf20f93    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kmovd"           ,0x660f90    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0x660f91    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf20f92    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf20f93    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"knotw"           ,0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"knotb"           ,0x660f44    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"knotq"           ,0xf44       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"knotd"           ,0x660f44    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"korw"            ,0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"korb"            ,0x660f45    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"korq"            ,0xf45       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kord"            ,0x660f45    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kortestw"        ,0xf98       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kortestb"        ,0x660f98    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kortestq"        ,0xf98       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kortestd"        ,0x660f98    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kshiftlw"        ,0x660f3a32  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kshiftlb"        ,0x660f3a32  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kshiftlq"        ,0x660f3a33  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kshiftld"        ,0x660f3a33  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kshiftrw"        ,0x660f3a30  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kshiftrb"        ,0x660f3a30  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kshiftrq"        ,0x660f3a31  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kshiftrd"        ,0x660f3a31  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"ktestw"          ,0xf99       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"ktestb"          ,0x660f99    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"ktestq"          ,0xf99       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"ktestd"          ,0x660f99    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kunpckbw"        ,0x660f4b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kunpckwd"        ,0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kunpckdq"        ,0xf4b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kxnorw"          ,0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kxnorb"          ,0x660f46    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kxnorq"          ,0xf46       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kxnord"          ,0x660f46    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kxorw"           ,0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"kxorb"           ,0x660f47    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"kxorq"           ,0xf47       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"kxord"           ,0x660f47    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"lahf"            ,0x9f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lar"             ,0xf02       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf02       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lddqu"           ,0xf20ff0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vlddqu"          ,0xf20ff0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20ff0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"ldmxcsr"         ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_Grp_0FAE },  //SSE
{"vldmxcsr"        ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_Grp_0FAE },  //AVX
{"lds"             ,0xc5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lss"             ,0xfb2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"les"             ,0xc4        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc4        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lfs"             ,0xfb4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"lgs"             ,0xfb5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"lea"             ,0x8d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"leave"           ,0xc9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"lfence"          ,0xfaee8     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lgdt"            ,0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_0F01 ,
					0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_0F01 },
{"lidt"            ,0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_0F01 ,
					0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_0F01 },
{"lldt"            ,0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_0F00 },
{"lmsw"            ,0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_0F01 },
{"lock"            ,0xf0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lods"            ,0xac        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xad        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xad        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xad        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"lodsb"           ,0xac        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lodsw"           ,0xad        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lodsd"           ,0xad        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lodsq"           ,0xad        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"loop"            ,0xe2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"loope"           ,0xe1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"loopne"          ,0xe0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lsl"             ,0xf03       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf03       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf03       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ltr"             ,0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_0F00 },
{"maskmovdqu"      ,0x660ff7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmaskmovdqu"     ,0x660ff7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"maskmovq"        ,0xff7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"maxpd"           ,0x660f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmaxpd"          ,0x660f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"maxps"           ,0xf5f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmaxps"          ,0xf5f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"maxsd"           ,0xf20f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmaxsd"          ,0xf20f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"maxss"           ,0xf30f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmaxss"          ,0xf30f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"minpd"           ,0x660f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vminpd"          ,0x660f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"minps"           ,0xf5d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vminps"          ,0xf5d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"minsd"           ,0xf20f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vminsd"          ,0xf20f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"minss"           ,0xf30f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vminss"          ,0xf30f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"mov"             ,0x88        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x88        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x89        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x89        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x89        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x8a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x8b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x8c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xa1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xa2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xa3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xc6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C6 ,
					0xc6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C6 ,
					0xc7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C7 ,
					0xc7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C7 ,
					0xc7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C7 ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf20       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_None ,
					0xf22       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf22       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf22       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf23       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf23       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movapd"          ,0x660f28    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f29    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovapd"         ,0x660f28    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f29    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f28    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f29    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f28    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f28    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f28    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f29    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f29    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f29    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movaps"          ,0xf28       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf29       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovaps"         ,0xf28       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf29       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf28       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf29       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf28       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf28       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf28       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf29       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf29       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf29       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movd"            ,0xf6e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0xf7e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f6e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"movq"            ,0xf6e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0xf7e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f6e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf6f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0xf7f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0xf30f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660fd6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovd"           ,0x660f6e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vmovq"           ,0x660f6e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f7e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660fd6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movddup"         ,0xf20f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vmovddup"        ,0xf20f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf20f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf20f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movdqa"          ,0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovdqa"         ,0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vmovdqa32"       ,0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vmovdqa64"       ,0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movdqu"          ,0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovdqu"         ,0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vmovdqu8"        ,0xf20f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf20f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vmovdqu16"       ,0xf20f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0xf20f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vmovdqu32"       ,0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vmovdqu64"       ,0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f6f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f7f    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movhlps"         ,0xf12       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovhlps"        ,0xf12       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf12       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movhpd"          ,0x660f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f17    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovhpd"         ,0x660f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f17    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f17    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movhps"          ,0xf16       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf17       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovhps"         ,0xf16       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf16       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf17       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf17       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movlhps"         ,0xf16       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovlhps"        ,0xf16       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf16       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movlpd"          ,0x660f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovlpd"         ,0x660f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movlps"          ,0xf12       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovlps"         ,0xf12       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf12       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movmskpd"        ,0x660f50    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovmskpd"       ,0x660f50    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f50    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"movmskps"        ,0xf50       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovmskps"       ,0xf50       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf50       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"movntdqa"        ,0x660f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vmovntdqa"       ,0x660f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movntdq"         ,0x660fe7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovntdq"        ,0x660fe7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fe7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fe7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movnti"          ,0xfc3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfc3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movntpd"         ,0x660f2b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovntpd"        ,0x660f2b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f2b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f2b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f2b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f2b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movntps"         ,0xf2b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovntps"        ,0xf2b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf2b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf2b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf2b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf2b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movntq"          ,0xfe7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"movq2dq"         ,0xf30fd6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"movs"            ,0xa4        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movsb"           ,0xa4        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"movsw"           ,0xa5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"movsd"           ,0xa5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf20f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf20f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf20f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"movsq"           ,0xa5        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"vmovsd"          ,0xf20f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movshdup"        ,0xf30f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vmovshdup"       ,0xf30f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f16    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movsldup"        ,0xf30f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE3
{"vmovsldup"       ,0xf30f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f12    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movss"           ,0xf30f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf30f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf30f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovss"          ,0xf30f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movsx"           ,0xfbe       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbe       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbe       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfbf       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfbf       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movsxd"          ,0x63        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x63        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x63        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movupd"          ,0x660f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmovupd"         ,0x660f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f10    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f11    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movups"          ,0xf10       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0xf11       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmovups"         ,0xf10       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf11       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf10       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf11       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf10       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf10       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf10       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf11       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf11       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf11       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"movzx"           ,0xfb6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfb7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfb7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"mpsadbw"         ,0x660f3a42  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vmpsadbw"        ,0x660f3a42  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a42  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"mul"             ,0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_F6_F7 ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_F6_F7 },
{"mulpd"           ,0x660f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmulpd"          ,0x660f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"mulps"           ,0xf59       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmulps"          ,0xf59       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf59       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf59       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf59       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf59       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"mulsd"           ,0xf20f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vmulsd"          ,0xf20f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"mulss"           ,0xf30f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vmulss"          ,0xf30f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f59    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"mulx"            ,0xf20f38f6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf20f38f6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"mwait"           ,0xf01c9     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"neg"             ,0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_F6_F7 ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_F6_F7 },
{"nop"             ,0x90        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf1f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None ,
					0xf1f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_None },
{"not"             ,0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_F6_F7 ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_F6_F7 },
{"or"              ,0xc         ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd         ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd         ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x8         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x8         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x9         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x9         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x9         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xa         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xb         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xb         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xb         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"orpd"            ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vorpd"           ,0x660f56    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f56    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f56    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f56    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f56    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"orps"            ,0xf56       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vorps"           ,0xf56       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf56       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf56       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf56       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf56       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"out"             ,0xe6        ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__b,AT__REG8,RG8__AL,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe7        ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__b,AT_XX,RG__AX,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xe7        ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__b,AT_eXX,RG__AX,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xee        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT__REG8,RG8__AL,0,0,0,0)       ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xef        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT_XX,RG__AX,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xef        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT_eXX,RG__AX,0,0,0,0)          ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"outs"            ,0x6e        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT__M,OT__b,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6f        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT__M,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6f        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT__M,OT__d,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"outsb"           ,0x6e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"outsw"           ,0x6f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"outsd"           ,0x6f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pabsb"           ,0xf381c     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f381c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"pabsw"           ,0xf381d     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f381d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"pabsd"           ,0xf381e     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f381e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vpabsb"          ,0x660f381c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f381c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f381c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f381c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f381c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpabsw"          ,0x660f381d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f381d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f381d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpabsd"          ,0x660f381e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f381e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"packsswb"        ,0xf63       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f63    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"packssdw"        ,0xf6b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f6b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpacksswb"       ,0x660f63    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f63    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f63    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f63    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f63    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpackssdw"       ,0x660f6b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f6b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"packusdw"        ,0x660f382b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpackusdw"       ,0x660f382b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f382b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f382b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f382b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"packuswb"        ,0xf67       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f67    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpackuswb"       ,0x660f67    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f67    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f67    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f67    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f67    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"paddb"           ,0xffc       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ffc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"paddw"           ,0xffd       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ffd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"paddd"           ,0xffe       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ffe    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"paddq"           ,0xfd4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpaddb"          ,0x660ffc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ffc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ffc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ffc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ffc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpaddw"          ,0x660ffd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ffd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ffd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ffd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ffd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpaddd"          ,0x660ffe    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ffe    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ffe    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660ffe    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660ffe    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpaddq"          ,0x660fd4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fd4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fd4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fd4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"paddsb"          ,0xfec       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fec    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"paddsw"          ,0xfed       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fed    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpaddsb"         ,0x660fec    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fec    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fec    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fec    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fec    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpaddsw"         ,0x660fed    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fed    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fed    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fed    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fed    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"paddusb"         ,0xfdc       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fdc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"paddusw"         ,0xfdd       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fdd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpaddusb"        ,0x660fdc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fdc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fdc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fdc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fdc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpaddusw"        ,0x660fdd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fdd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fdd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fdd    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"palignr"         ,0xf3a0f     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3a0f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vpalignr"        ,0x660f3a0f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a0f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3a0f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a0f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a0f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pand"            ,0xfdb       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpand"           ,0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpandd"          ,0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpandq"          ,0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pandn"           ,0xfdf       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpandn"          ,0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpandnd"         ,0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpandnq"         ,0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fdf    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pause"           ,0xf390      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pavgb"           ,0xfe0       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pavgw"           ,0xfe3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpavgb"          ,0x660fe0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fe0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe0    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpavgw"          ,0x660fe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pblendvb"        ,0x660f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpblendvb"       ,0x660f3a4c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a4c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"pblendw"         ,0x660f3a0e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpblendw"        ,0x660f3a0e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a0e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"pclmulqdq"       ,0x660f3a44  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //PCLMUL- QDQ
{"vpclmulqdq"      ,0x660f3a44  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //Both PCL- MULQDQ and AVX flags
{"pcmpeqb"         ,0xf74       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f74    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pcmpeqw"         ,0xf75       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f75    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pcmpeqd"         ,0xf76       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f76    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpcmpeqb"        ,0x660f74    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f74    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f74    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpcmpeqw"        ,0x660f75    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f75    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpcmpeqd"        ,0x660f76    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f76    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f76    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f76    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f76    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pcmpeqq"         ,0x660f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpcmpeqq"        ,0x660f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pcmpestri"       ,0x660f3a61  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_2
{"vpcmpestri"      ,0x660f3a61  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"pcmpestrm"       ,0x660f3a60  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_2
{"vpcmpestrm"      ,0x660f3a60  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"pcmpgtb"         ,0xf64       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f64    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pcmpgtw"         ,0xf65       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f65    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pcmpgtd"         ,0xf66       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f66    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpcmpgtb"        ,0x660f64    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f64    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f64    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f64    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpcmpgtw"        ,0x660f65    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f65    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpcmpgtd"        ,0x660f66    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f66    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f66    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f66    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f66    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pcmpgtq"         ,0x660f3837  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_2
{"vpcmpgtq"        ,0x660f3837  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3837  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3837  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3837  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3837  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pcmpistri"       ,0x660f3a63  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_2
{"vpcmpistri"      ,0x660f3a63  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"pcmpistrm"       ,0x660f3a62  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_2
{"vpcmpistrm"      ,0x660f3a62  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"pdep"            ,0xf20f38f5  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf20f38f5  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"pext"            ,0xf30f38f5  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf30f38f5  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"pextrb"          ,0x660f3a14  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pextrd"          ,0x660f3a16  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pextrq"          ,0x660f3a16  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpextrb"         ,0x660f3a14  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a14  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpextrd"         ,0x660f3a16  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a16  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vpextrq"         ,0x660f3a16  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a16  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"pextrw"          ,0xfc5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fc5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660f3a15  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpextrw"         ,0x660fc5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a15  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fc5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512B W
					0x660f3a15  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512B W
{"phaddw"          ,0xf3801     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3801  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"phaddd"          ,0xf3802     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3802  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vphaddw"         ,0x660f3801  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3801  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vphaddd"         ,0x660f3802  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3802  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"phaddsw"         ,0xf3803     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3803  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vphaddsw"        ,0x660f3803  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3803  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"phminposuw"      ,0x660f3841  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vphminposuw"     ,0x660f3841  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"phsubw"          ,0xf3805     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3805  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"phsubd"          ,0xf3806     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3806  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vphsubw"         ,0x660f3805  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3805  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vphsubd"         ,0x660f3806  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3806  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"phsubsw"         ,0xf3807     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3807  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vphsubsw"        ,0x660f3807  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3807  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"pinsrb"          ,0x660f3a20  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pinsrd"          ,0x660f3a22  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pinsrq"          ,0x660f3a22  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpinsrb"         ,0x660f3a20  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a20  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpinsrd"         ,0x660f3a22  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a22  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vpinsrq"         ,0x660f3a22  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a22  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"pinsrw"          ,0xfc4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fc4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpinsrw"         ,0x660fc4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fc4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmaddubsw"       ,0xf3804     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3804  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vpmaddubsw"      ,0x660f3804  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3804  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3804  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3804  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3804  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmaddwd"         ,0xff5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ff5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpmaddwd"        ,0x660ff5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ff5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ff5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmaxsw"          ,0xfee       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fee    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pmaxsb"          ,0x660f383c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmaxsd"          ,0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmaxsb"         ,0x660f383c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f383c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f383c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f383c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f383c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmaxsw"         ,0x660fee    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fee    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fee    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fee    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fee    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmaxsd"         ,0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmaxsq"         ,0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pmaxub"          ,0xfde       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fde    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pmaxuw"          ,0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmaxub"         ,0x660fde    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fde    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fde    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fde    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fde    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmaxuw"         ,0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f383e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f383e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f383e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmaxud"          ,0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmaxud"         ,0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmaxuq"         ,0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pminsw"          ,0xfea       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fea    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pminsb"          ,0x660f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpminsb"         ,0x660f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpminsw"         ,0x660fea    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fea    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fea    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fea    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fea    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pminsd"          ,0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpminsd"         ,0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpminsq"         ,0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pminub"          ,0xfda       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fda    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"pminuw"          ,0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpminub"         ,0x660fda    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fda    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fda    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fda    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fda    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpminuw"         ,0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pminud"          ,0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpminud"         ,0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpminuq"         ,0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f383b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pmovmskb"        ,0xfd7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fd7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpmovmskb"       ,0x660fd7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"pmovsxbw"        ,0x660f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovsxbd"        ,0x660f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovsxbq"        ,0x660f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovsxwd"        ,0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovsxwq"        ,0x660f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovsxdq"        ,0x660f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmovsxbw"       ,0x660f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovsxbd"       ,0x660f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsxbq"       ,0x660f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsxwd"       ,0x660f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsxwq"       ,0x660f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsxdq"       ,0x660f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pmovzxbw"        ,0x660f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovzxbd"        ,0x660f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovzxbq"        ,0x660f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovzxwd"        ,0x660f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovzxwq"        ,0x660f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"pmovzxdq"        ,0x660f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmovzxbw"       ,0x660f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovzxbd"       ,0x660f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovzxbq"       ,0x660f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovzxwd"       ,0x660f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovzxwq"       ,0x660f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovzxdq"       ,0x660f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pmuldq"          ,0x660f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmuldq"         ,0x660f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pmulhrsw"        ,0xf380b     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f380b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vpmulhrsw"       ,0x660f380b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f380b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f380b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f380b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmulhuw"         ,0xfe4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660fe4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpmulhuw"        ,0x660fe4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fe4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmulhw"          ,0xfe5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fe5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpmulhw"         ,0x660fe5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fe5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmulld"          ,0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vpmulld"         ,0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmullq"         ,0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3840  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"pmullw"          ,0xfd5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpmullw"         ,0x660fd5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fd5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fd5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fd5    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pmuludq"         ,0xff4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660ff4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpmuludq"        ,0x660ff4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ff4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ff4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660ff4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660ff4    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pop"             ,0x8f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_8F ,
					0x8f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_8F ,
					0x8f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_8F ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x1f        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x7         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x17        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfa9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"popa"            ,0x61        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"popad"           ,0x61        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"popcnt"          ,0xf30fb8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf30fb8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf30fb8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"popf"            ,0x9d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"popfd"           ,0x9d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"popfq"           ,0x9d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"por"             ,0xfeb       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpor"            ,0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpord"           ,0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vporq"           ,0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660feb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"prefetcht0"      ,0xf18       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_0F18 },
{"prefetcht1"      ,0xf18       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_0F18 },
{"prefetcht2"      ,0xf18       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_0F18 },
{"prefetchnta"     ,0xf18       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_0F18 },
{"prefetchw"       ,0xf0d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None },  //PRFCHW
{"psadbw"          ,0xff6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE
					0x660ff6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpsadbw"         ,0x660ff6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ff6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ff6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pshufb"          ,0xf3800     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3800  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vpshufb"         ,0x660f3800  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3800  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3800  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3800  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3800  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pshufd"          ,0x660f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpshufd"         ,0x660f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"pshufhw"         ,0xf30f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpshufhw"        ,0xf30f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0xf30f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pshuflw"         ,0xf20f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpshuflw"        ,0xf20f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0xf20f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf20f70    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"pshufw"          ,0xf70       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"psignb"          ,0xf3808     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3808  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"psignw"          ,0xf3809     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f3809  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"psignd"          ,0xf380a     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSSE3
					0x660f380a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSSE3
{"vpsignb"         ,0x660f3808  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3808  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpsignw"         ,0x660f3809  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3809  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpsignd"         ,0x660f380a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"pslldq"          ,0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None },  //SSE2
{"vpslldq"         ,0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None ,  //AVX
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None ,  //AVX2
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None },  //AVX512BW
{"psllw"           ,0xff1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ff1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf71       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0F71 ,  //MMX
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //SSE2
{"pslld"           ,0xff2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ff2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf72       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0F72 ,  //MMX
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //SSE2
{"psllq"           ,0xff3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ff3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf73       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0F73 ,  //MMX
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //SSE2
{"vpsllw"          ,0x660ff1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None ,  //AVX
					0x660ff1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //AVX2
{"vpslld"          ,0x660ff2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //AVX
{"vpsllq"          ,0x660ff3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_None },  //AVX
{"psraw"           ,0xfe1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fe1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf71       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_Grp_0F71 ,  //MMX
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None },  //SSE2
{"psrad"           ,0xfe2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fe2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf72       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_Grp_0F72 ,  //MMX
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None },  //SSE2
{"vpsraw"          ,0x660fe1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None ,  //AVX
					0x660fe1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None ,  //AVX2
					0x660fe1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsrad"          ,0x660fe2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None ,  //AVX
					0x660fe2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None },  //AVX2
{"psrldq"          ,0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None },  //SSE2
{"vpsrldq"         ,0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None ,  //AVX
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None ,  //AVX2
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_None },  //AVX512BW
{"psrlw"           ,0xfd1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf71       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_Grp_0F71 ,  //MMX
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None },  //SSE2
{"psrld"           ,0xfd2       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf72       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_Grp_0F72 ,  //MMX
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None },  //SSE2
{"psrlq"           ,0xfd3       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0xf73       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_Grp_0F73 ,  //MMX
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None },  //SSE2
{"vpsrlw"          ,0x660fd1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None ,  //AVX
					0x660fd1    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f71    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None },  //AVX2
{"vpsrld"          ,0x660fd2    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None },  //AVX
{"vpsrlq"          ,0x660fd3    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f73    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,2    ,CAsm::Asm_None },  //AVX
{"psubb"           ,0xff8       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ff8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"psubw"           ,0xff9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ff9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"psubd"           ,0xffa       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660ffa    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpsubb"          ,0x660ff8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ff8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ff8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsubw"          ,0x660ff9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ff9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ff9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660ff9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsubd"          ,0x660ffa    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ffa    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"psubq"           ,0xffb       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //SSE2
					0x660ffb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpsubq"          ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660ffb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660ffb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660ffb    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"psubsb"          ,0xfe8       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fe8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"psubsw"          ,0xfe9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fe9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpsubsb"         ,0x660fe8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fe8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsubsw"         ,0x660fe9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fe9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fe9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fe9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"psubusb"         ,0xfd8       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"psubusw"         ,0xfd9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fd9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpsubusb"        ,0x660fd8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fd8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fd8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fd8    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsubusw"        ,0x660fd9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fd9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660fd9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660fd9    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"ptest"           ,0x660f3817  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vptest"          ,0x660f3817  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3817  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"ptwrite"         ,0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,4    ,CAsm::Asm_None ,
					0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_None },
{"punpckhbw"       ,0xf68       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f68    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"punpckhwd"       ,0xf69       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f69    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"punpckhdq"       ,0xf6a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f6a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"punpckhqdq"      ,0x660f6d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpunpckhbw"      ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f68    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f68    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpunpckhwd"      ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f69    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f69    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpunpckhdq"      ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f6a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vpunpckhqdq"     ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f6d    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"punpcklbw"       ,0xf60       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f60    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"punpcklwd"       ,0xf61       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f61    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"punpckldq"       ,0xf62       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660f62    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"punpcklqdq"      ,0x660f6c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpunpcklbw"      ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f60    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f60    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpunpcklwd"      ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f61    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f61    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512BW
{"vpunpckldq"      ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f62    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f62    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vpunpcklqdq"     ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f6c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f6c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"push"            ,0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_FF ,
					0xff        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_FF ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x6a        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                     ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm ,
					0x68        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__w,0,0,0,0,0,0)                     ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm ,
					0x68        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__d,0,0,0,0,0,0)                     ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm ,
					0xe         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x16        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x6         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa0       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa8       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pusha"           ,0x60        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pushad"          ,0x60        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pushf"           ,0x9c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pushfd"          ,0x9c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"pushfq"          ,0x9c        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"pxor"            ,0xfef       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //MMX
					0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vpxor"           ,0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpxord"          ,0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpxorq"          ,0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fef    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"rcl"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,2    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"rcr"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"rol"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"ror"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,1    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"rcpps"           ,0xf53       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vrcpps"          ,0xf53       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf53       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"rcpss"           ,0xf30f53    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vrcpss"          ,0xf30f53    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"rdfsbase"        ,0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,0    ,CAsm::Asm_None ,  //FSGSBASE
					0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,0    ,CAsm::Asm_None },  //FSGSBASE
{"rdgsbase"        ,0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,1    ,CAsm::Asm_None },  //FSGSBASE
{"rdmsr"           ,0xf32       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"rdpid"           ,0xf30fc7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NE    ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_None ,  //RDPID
					0xf30fc7    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,7    ,CAsm::Asm_None },  //RDPID
{"rdpkru"          ,0xf01ee     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },
{"rdpmc"           ,0xf33       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"rdrand"          ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0FC7 ,  //RDRAND
					0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0FC7 ,  //RDRAND
					0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,6    ,CAsm::Asm_Grp_0FC7 },  //RDRAND
{"rdseed"          ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_Grp_0FC7 ,  //RDSEED
					0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,7    ,CAsm::Asm_Grp_0FC7 ,  //RDSEED
					0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,7    ,CAsm::Asm_Grp_0FC7 },  //RDSEED
{"rdtsc"           ,0xf31       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"rdtscp"          ,0xf01f9     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ins m8, dx"      ,0xf36c      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf36c      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"ins m16, dx"     ,0xf36d      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ins m32, dx"     ,0xf36d      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ins r/m32, dx"   ,0xf36d      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movs m8, m8"     ,0xf3a4      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf3a4      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"movs m16, m16"   ,0xf3a5      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"movs m32, m32"   ,0xf3a5      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"movs m64, m64"   ,0xf3a5      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"outs dx, r/m8"   ,0xf36e      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"outs dx, r/m8*"  ,0xf36e      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"outs dx, r/m16"  ,0xf36f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"outs dx, r/m32"  ,0xf36f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf36f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"lods al"         ,0xf3ac      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf3ac      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"lods ax"         ,0xf3ad      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lods eax"        ,0xf3ad      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"lods rax"        ,0xf3ad      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"stos m8"         ,0xf3aa      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf3aa      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"stos m16"        ,0xf3ab      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"stos m32"        ,0xf3ab      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"stos m64"        ,0xf3ab      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmps m8, m8"     ,0xf3a6      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf3a6      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf2a6      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf2a6      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"cmps m16, m16"   ,0xf3a7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf2a7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cmps m32, m32"   ,0xf3a7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf2a7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"cmps m64, m64"   ,0xf3a7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf2a7      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"scas m8"         ,0xf3ae      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf3ae      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf2ae      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf2ae      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"scas m16"        ,0xf3af      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf2af      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"scas m32"        ,0xf3af      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf2af      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"scas m64"        ,0xf3af      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf2af      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"ret"             ,0xc3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xcb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xc2        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__w,0,0,0,0,0,0)                     ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm ,
					0xca        ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__w,0,0,0,0,0,0)                     ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_Imm },
{"rorx"            ,0xf20f3af0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf20f3af0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"roundpd"         ,0x660f3a09  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vroundpd"        ,0x660f3a09  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a09  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"roundps"         ,0x660f3a08  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vroundps"        ,0x660f3a08  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a08  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"roundsd"         ,0x660f3a0b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vroundsd"        ,0x660f3a0b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"roundss"         ,0x660f3a0a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE4_1
{"vroundss"        ,0x660f3a0a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"rsm"             ,0xfaa       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"rsqrtps"         ,0xf52       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vrsqrtps"        ,0xf52       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf52       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"rsqrtss"         ,0xf30f52    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vrsqrtss"        ,0xf30f52    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"sahf"            ,0x9e        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_I     ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"sal"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"sar"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,7    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"shl"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,4    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"shr"             ,0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd2        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc0        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xd3        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 ,
					0xc1        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_C0_C1_D0_D1_D2_D3 },
{"sarx"            ,0xf30f38f7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf30f38f7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"shlx"            ,0x660f38f7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0x660f38f7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"shrx"            ,0xf20f38f7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI2
					0xf20f38f7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI2
{"sbb"             ,0x1c        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1d        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1d        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,3    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x18        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x18        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x19        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x19        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x19        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x1a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x1b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x1b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"scas"            ,0xae        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xaf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xaf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xaf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"scasb"           ,0xae        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"scasw"           ,0xaf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"scasd"           ,0xaf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"scasq"           ,0xaf        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"seta"            ,0xf97       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf97       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setae"           ,0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setb"            ,0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setbe"           ,0xf96       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf96       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setc"            ,0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"sete"            ,0xf94       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf94       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setg"            ,0xf9f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setge"           ,0xf9d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setl"            ,0xf9c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setle"           ,0xf9e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setna"           ,0xf96       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf96       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnae"          ,0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf92       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnb"           ,0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnbe"          ,0xf97       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf97       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnc"           ,0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf93       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setne"           ,0xf95       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf95       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setng"           ,0xf9e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnge"          ,0xf9c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnl"           ,0xf9d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9d       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnle"          ,0xf9f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9f       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setno"           ,0xf91       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf91       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnp"           ,0xf9b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setns"           ,0xf99       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf99       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setnz"           ,0xf95       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf95       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"seto"            ,0xf90       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf90       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setp"            ,0xf9a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setpe"           ,0xf9a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9a       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setpo"           ,0xf9b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf9b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"sets"            ,0xf98       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf98       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"setz"            ,0xf94       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf94       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"sfence"          ,0xfaef8     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"sgdt"            ,0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_0F01 },
{"sha1rnds4"       ,0xf3acc     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"sha1nexte"       ,0xf38c8     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"sha1msg1"        ,0xf38c9     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"sha1msg2"        ,0xf38ca     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"sha256rnds2"     ,0xf38cb     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"sha256msg1"      ,0xf38cc     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"sha256msg2"      ,0xf38cd     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SHA
{"shld"            ,0xfa4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa4       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfa5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfa5       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"shrd"            ,0xfac       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfad       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfac       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfac       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfad       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfad       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"shufpd"          ,0x660fc6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vshufpd"         ,0x660fc6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fc6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660fc6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fc6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660fc6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"shufps"          ,0xfc6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vshufps"         ,0xfc6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xfc6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xfc6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xfc6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xfc6       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"sidt"            ,0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_0F01 },
{"sldt"            ,0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_0F00 ,
					0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_0F00 },
{"smsw"            ,0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_0F01 ,
					0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_0F01 ,
					0xf01       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_0F01 },
{"sqrtpd"          ,0x660f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vsqrtpd"         ,0x660f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"sqrtps"          ,0xf51       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vsqrtps"         ,0xf51       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf51       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf51       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"sqrtsd"          ,0xf20f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vsqrtsd"         ,0xf20f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"sqrtss"          ,0xf30f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vsqrtss"         ,0xf30f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f51    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"stac"            ,0xf01cb     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SMAP
{"stc"             ,0xf9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"std"             ,0xfd        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"sti"             ,0xfb        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"stmxcsr"         ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_Grp_0FAE },  //SSE
{"vstmxcsr"        ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_Grp_0FAE },  //AVX
{"stos"            ,0xaa        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xab        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xab        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xab        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"stosb"           ,0xaa        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"stosw"           ,0xab        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"stosd"           ,0xab        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"stosq"           ,0xab        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"str"             ,0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,1    ,CAsm::Asm_Grp_0F00 },
{"sub"             ,0x2c        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2d        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2d        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2d        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,5    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x28        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x28        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x29        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x29        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x29        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x2a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2a        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x2b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x2b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"subpd"           ,0x660f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vsubpd"          ,0x660f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"subps"           ,0xf5c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vsubps"          ,0xf5c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf5c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf5c       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"subsd"           ,0xf20f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vsubsd"          ,0xf20f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf20f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"subss"           ,0xf30f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vsubss"          ,0xf30f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf30f5c    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"swapgs"          ,0xf01f8     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_I        ,-1   ,CAsm::Asm_None },
{"syscall"         ,0xf05       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_I        ,-1   ,CAsm::Asm_None },
{"sysenter"        ,0xf34       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"sysexit"         ,0xf35       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xf35       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"sysret"          ,0xf07       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_I        ,-1   ,CAsm::Asm_None ,
					0xf07       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_I        ,-1   ,CAsm::Asm_None },
{"test"            ,0xa8        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa9        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa9        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xa9        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_F6_F7 ,
					0xf6        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,0    ,CAsm::Asm_Grp_F6_F7 ,
					0xf7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,0    ,CAsm::Asm_Grp_F6_F7 ,
					0x84        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x84        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x85        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x85        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x85        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"tzcnt"           ,0xf30fbc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI1
					0xf30fbc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //BMI1
					0xf30fbc    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //BMI1
{"ucomisd"         ,0x660f2e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vucomisd"        ,0x660f2e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f2e    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"ucomiss"         ,0xf2e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vucomiss"        ,0xf2e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf2e       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"ud01"            ,0xfff       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ud1"             ,0xfb9       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"ud2"             ,0xf0b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"unpckhpd"        ,0x660f15    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vunpckhpd"       ,0x660f15    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f15    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f15    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f15    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f15    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"unpckhps"        ,0xf15       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vunpckhps"       ,0xf15       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf15       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf15       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf15       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf15       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"unpcklpd"        ,0x660f14    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vunpcklpd"       ,0x660f14    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f14    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f14    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f14    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f14    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"unpcklps"        ,0xf14       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vunpcklps"       ,0xf14       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf14       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf14       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf14       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf14       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"valignd"         ,0x660f3a03  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a03  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a03  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"valignq"         ,0x660f3a03  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a03  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a03  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vblendmpd"       ,0x660f3865  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3865  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3865  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vblendmps"       ,0x660f3865  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3865  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3865  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vbroadcastss"    ,0x660f3818  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3818  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f38    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3818  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3818  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3818  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3818  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vbroadcastsd"    ,0x660f3819  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3819  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3819  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3819  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vbroadcastf128"  ,0x660f381a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vbroadcastf32x2" ,0x660f3819  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3819  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vbroadcastf32x4" ,0x660f381a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f381a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vbroadcastf64x2" ,0x660f381a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f381a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vbroadcastf32x8" ,0x660f381b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vbroadcastf64x4" ,0x660f381b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcompresspd"     ,0x660f388a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcompressps"     ,0x660f388a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtpd2qq"       ,0x660f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtpd2udq"      ,0xf79       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf79       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf79       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtpd2uqq"      ,0x660f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtph2ps"       ,0x660f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //F16C
					0x660f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //F16C
					0x660f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtps2ph"       ,0x660f3a1d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //F16C
					0x660f3a1d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //F16C
					0x660f3a1d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtps2udq"      ,0xf79       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf79       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf79       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtps2qq"       ,0x660f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtps2uqq"      ,0x660f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtqq2pd"       ,0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30fe6    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtqq2ps"       ,0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf5b       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtsd2usi"      ,0xf20f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtss2usi"      ,0xf30f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f79    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvttpd2qq"      ,0x660f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvttpd2udq"     ,0xf78       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf7802     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf78       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvttpd2uqq"     ,0x660f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvttps2udq"     ,0xf78       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf78       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf78       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvttps2qq"      ,0x660f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvttps2uqq"     ,0x660f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvttsd2usi"     ,0xf20f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvttss2usi"     ,0xf30f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f78    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtudq2pd"      ,0xf30f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtudq2ps"      ,0xf20f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf20f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf20f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtuqq2pd"      ,0xf30f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtuqq2ps"      ,0xf20f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf20f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf20f7a    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vcvtusi2sd"      ,0xf20f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf20f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vcvtusi2ss"      ,0xf30f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0xf30f7b    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vdbpsadbw"       ,0x660f3a42  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a42  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a42  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vexpandpd"       ,0x660f3888  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3888  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3888  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vexpandps"       ,0x660f3888  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3888  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3888  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"verr"            ,0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,4    ,CAsm::Asm_Grp_0F00 },
{"verw"            ,0xf00       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,5    ,CAsm::Asm_Grp_0F00 },
{"vextractf128"    ,0x660f3a19  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vextractf32x4"   ,0x660f3a19  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vextractf32x"    ,0x660f3a19  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vextractf64x2"   ,0x660f3a19  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a19  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vextractf32x8"   ,0x660f3a1b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vextractf64x"    ,0x660f3a1b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vextracti128"    ,0x660f3a39  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vextracti32x4"   ,0x660f3a39  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vextracti32x"    ,0x660f3a39  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vextracti64x2"   ,0x660f3a39  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a39  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vextracti32x8"   ,0x660f3a3b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vextracti64x"    ,0x660f3a3b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfixupimmpd"     ,0x660f3a54  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a54  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a54  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfixupimmps"     ,0x660f3a54  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a54  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a54  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfixupimmsd"     ,0x660f3a55  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfixupimmss"     ,0x660f3a55  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd132pd"     ,0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd213pd"     ,0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd231pd"     ,0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd132ps"     ,0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3898  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd213ps"     ,0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd231ps"     ,0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b8  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd132sd"     ,0x660f3899  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3899  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd213sd"     ,0x660f38a9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd231sd"     ,0x660f38b9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd132ss"     ,0x660f3899  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3899  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd213ss"     ,0x660f38a9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmadd231ss"     ,0x660f38b9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b9  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmaddsub132pd"  ,0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmaddsub213pd"  ,0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmaddsub231pd"  ,0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmaddsub132ps"  ,0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3896  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmaddsub213ps"  ,0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmaddsub231ps"  ,0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b6  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsubadd132pd"  ,0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsubadd213pd"  ,0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsubadd231pd"  ,0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsubadd132ps"  ,0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3897  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsubadd213ps"  ,0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsubadd231ps"  ,0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38b7  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub132pd"     ,0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub213pd"     ,0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub231pd"     ,0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub132ps"     ,0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub213ps"     ,0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38aa  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub231ps"     ,0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ba  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub132sd"     ,0x660f389b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub213sd"     ,0x660f38ab  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ab  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub231sd"     ,0x660f38bb  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bb  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub132ss"     ,0x660f389b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub213ss"     ,0x660f38ab  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ab  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfmsub231ss"     ,0x660f38bb  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bb  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd132pd"    ,0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd213pd"    ,0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd231pd"    ,0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd132ps"    ,0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vfnmadd213ps"    ,0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ac  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd231ps"    ,0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38bc  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd132sd"    ,0x660f389d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd213sd"    ,0x660f38ad  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ad  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd231sd"    ,0x660f38bd  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bd  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd132ss"    ,0x660f389d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd213ss"    ,0x660f38ad  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ad  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmadd231ss"    ,0x660f38bd  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bd  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub132pd"    ,0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub213pd"    ,0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub231pd"    ,0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub132ps"    ,0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f389e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub213ps"    ,0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38ae  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub231ps"    ,0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38be  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub132sd"    ,0x660f389f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub213sd"    ,0x660f38af  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38af  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub231sd"    ,0x660f38bf  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bf  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub132ss"    ,0x660f389f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f389f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub213ss"    ,0x660f38af  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38af  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfnmsub231ss"    ,0x660f38bf  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //FMA
					0x660f38bf  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vfpclasspd"      ,0x660f3a66  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a66  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a66  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vfpclassps"      ,0x660f3a66  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a66  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a66  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vfpclasssd"      ,0x660f3a67  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vfpclassss"      ,0x660f3a67  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vgatherdpd"      ,0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgatherqpd"      ,0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgatherdps"      ,0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3892  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgatherqps"      ,0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3893  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetexppd"       ,0x660f3842  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3842  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3842  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetexpps"       ,0x660f3842  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3842  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3842  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetexpsd"       ,0x660f3843  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetexpss"       ,0x660f3843  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetmantpd"      ,0x660f3a26  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a26  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a26  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetmantps"      ,0x660f3a26  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a26  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a26  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetmantsd"      ,0x660f3a27  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vgetmantss"      ,0x660f3a27  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vinsertf128"     ,0x660f3a18  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vinsertf32x4"    ,0x660f3a18  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a18  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vinsertf64x2"    ,0x660f3a18  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a18  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vinsertf32x8"    ,0x660f3a1a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vinsertf64x4"    ,0x660f3a1a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vinserti128"     ,0x660f3a38  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vinserti32x4"    ,0x660f3a38  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a38  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vinserti64x2"    ,0x660f3a38  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a38  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vinserti32x8"    ,0x660f3a3a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vinserti64x4"    ,0x660f3a3a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vmaskmovps"      ,0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vmaskmovpd"      ,0x660f382d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f382f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vpblendd"        ,0x660f3a02  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3a02  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpblendmb"       ,0x660f3866  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3866  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3866  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpblendmw"       ,0x660f3866  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3866  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3866  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpblendmd"       ,0x660f3864  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3864  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3864  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpblendmq"       ,0x660f3864  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3864  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3864  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpbroadcastb"    ,0x660f387a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f387a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f387a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0x660f3878  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3878  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3878  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3878  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3878  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpbroadcastw"    ,0x660f387b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f387b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f387b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512BW
					0x660f3879  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3879  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3879  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3879  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3879  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpbroadcastd"    ,0x660f387c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3858  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3858  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3858  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3858  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3858  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpbroadcastq"    ,0x660f387c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vbroadcasti32x"  ,0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3859  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vbroadcasti128"  ,0x660f385a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vbroadcasti32x4" ,0x660f385a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f385a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vbroadcasti64x2" ,0x660f385a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f385a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vbroadcasti32x8" ,0x660f385b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vbroadcasti64x4" ,0x660f385b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpbroadcastmb2q" ,0xf30f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0xf30f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0xf30f382a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512CD
{"vpbroadcastmw2d" ,0xf30f383a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0xf30f383a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0xf30f383a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512CD
{"vpcmpb"          ,0x660f3a3f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpcmpub"         ,0x660f3a3e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpcmpd"          ,0x660f3a1f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpcmpud"         ,0x660f3a1e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpcmpq"          ,0x660f3a1f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpcmpuq"         ,0x660f3a1e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a1e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpcmpw"          ,0x660f3a3f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpcmpuw"         ,0x660f3a3e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3a3e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpcompressd"     ,0x660f388b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpcompressq"     ,0x660f388b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f388b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpconflictd"     ,0x660f38c4  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f38c4  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f38c4  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512CD
{"vpconflictq"     ,0x660f38c4  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f38c4  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f38c4  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512CD
{"vperm2f128"      ,0x660f3a06  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vperm2i128"      ,0x660f3a46  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpermb"          ,0x660f388d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512_VBMI
					0x660f388d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512_VBMI
					0x660f388d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512_VBMI
{"vpermd"          ,0x660f3836  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3836  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3836  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermw"          ,0x660f388d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f388d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f388d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpermi2b"        ,0x660f3875  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512_VBMI
					0x660f3875  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512_VBMI
					0x660f3875  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512_VBMI
{"vpermi2w"        ,0x660f3875  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3875  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3875  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpermi2d"        ,0x660f3876  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3876  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3876  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermi2q"        ,0x660f3876  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3876  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3876  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermi2ps"       ,0x660f3877  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3877  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3877  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermi2pd"       ,0x660f3877  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3877  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3877  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermilpd"       ,0x660f380d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f380d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f380d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3a05  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a05  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a05  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a05  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a05  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermilps"       ,0x660f380c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a04  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f3a04  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f380c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f380c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3a04  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a04  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a04  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermpd"         ,0x660f3a01  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3a01  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a01  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3816  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3816  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermps"         ,0x660f3816  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3816  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3816  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermq"          ,0x660f3a00  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3a00  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a00  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3836  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3836  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermt2b"        ,0x660f387d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512_VBMI
					0x660f387d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512_VBMI
					0x660f387d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512_VBMI
{"vpermt2w"        ,0x660f387d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f387d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f387d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpermt2d"        ,0x660f387e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermt2q"        ,0x660f387e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermt2ps"       ,0x660f387f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpermt2pd"       ,0x660f387f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f387f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpexpandd"       ,0x660f3889  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3889  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3889  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpexpandq"       ,0x660f3889  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3889  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3889  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpgatherdd"      ,0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpgatherqd"      ,0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpgatherdq"      ,0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512F
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3890  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpgatherqq"      ,0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3891  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vplzcntd"        ,0x660f3844  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f3844  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f3844  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512CD
{"vplzcntq"        ,0x660f3844  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f3844  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512CD
					0x660f3844  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512CD
{"vpmaskmovd"      ,0x660f388c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f388c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f388e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f388e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpmaskmovq"      ,0x660f388c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f388c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f388e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f388e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX2
{"vpmovb2m"        ,0xf30f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovw2m"        ,0xf30f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3829  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovd2m"        ,0xf30f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vpmovq2m"        ,0xf30f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3839  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vpmovdb"         ,0xf30f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3831  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsdb"        ,0xf30f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3821  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovusdb"       ,0xf30f3811  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3811  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3811  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovdw"         ,0xf30f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3833  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsdw"        ,0xf30f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3823  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovusdw"       ,0xf30f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3813  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovm2b"        ,0xf30f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovm2w"        ,0xf30f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3828  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovm2d"        ,0xf30f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vpmovm2q"        ,0xf30f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf30f3838  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vpmovqb"         ,0xf30f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3832  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsqb"        ,0xf30f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3822  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovusqb"       ,0xf30f3812  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3812  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3812  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovqd"         ,0xf30f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3835  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsqd"        ,0xf30f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3825  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovusqd"       ,0xf30f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovqw"         ,0xf30f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3834  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovsqw"        ,0xf30f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3824  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovusqw"       ,0xf30f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpmovwb"         ,0xf30f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3830  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovswb"        ,0xf30f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3820  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmovuswb"       ,0xf30f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpmultishiftqb"  ,0x660f3883  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512_VBMI AVX512VL
					0x660f3883  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512_VBMI AVX512VL
					0x660f3883  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512_VBMI
{"vprolvd"         ,0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vprold"          ,0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None },  //AVX512F
{"vprolvq"         ,0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3815  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vprolq"          ,0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,1    ,CAsm::Asm_None },  //AVX512F
{"vprorvd"         ,0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vprord"          ,0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,0    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,0    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,0    ,CAsm::Asm_None },  //AVX512F
{"vprorvq"         ,0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3814  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vprorq"          ,0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,0    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,0    ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f72    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,0    ,CAsm::Asm_None },  //AVX512F
{"vpscatterdd"     ,0x660f38a0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpscatterdq"     ,0x660f38a0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a0  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpscatterqd"     ,0x660f38a1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpscatterqq"     ,0x660f38a1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a1  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsllvd"         ,0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsllvq"         ,0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3847  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsllvw"         ,0x660f3812  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3812  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3812  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsravd"         ,0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsravw"         ,0x660f3811  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3811  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3811  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpsravq"         ,0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3846  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsrlvd"         ,0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsrlvq"         ,0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX2
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3845  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpsrlvw"         ,0x660f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3810  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vpternlogd"      ,0x660f3a25  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a25  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a25  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vpternlogq"      ,0x660f3a25  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a25  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a25  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vptestmb"        ,0x660f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vptestmw"        ,0x660f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0x660f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512BW
{"vptestmd"        ,0x660f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vptestmq"        ,0x660f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vptestnmb"       ,0xf30f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F AVX512BW
{"vptestnmw"       ,0xf30f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512BW
					0xf30f3826  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F AVX512BW
{"vptestnmd"       ,0xf30f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vptestnmq"       ,0xf30f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0xf30f3827  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrangepd"        ,0x660f3a50  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a50  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a50  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vrangeps"        ,0x660f3a50  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a50  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a50  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vrangesd"        ,0x660f3a51  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vrangess"        ,0x660f3a51  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vrcp14pd"        ,0x660f384c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrcp14sd"        ,0x660f384d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrcp14ps"        ,0x660f384c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrcp14ss"        ,0x660f384d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vreducepd"       ,0x660f3a56  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a56  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a56  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vreduceps"       ,0x660f3a56  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a56  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f3a56  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"vrndscalepd"     ,0x660f3a09  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a09  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a09  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrndscalesd"     ,0x660f3a0b  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrndscaleps"     ,0x660f3a08  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a08  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f3a08  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrndscaless"     ,0x660f3a0a  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrsqrt14pd"      ,0x660f384e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrsqrt14sd"      ,0x660f384f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrsqrt14ps"      ,0x660f384e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f384e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vrsqrt14ss"      ,0x660f384f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscalefpd"       ,0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscalefsd"       ,0x660f382d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscalefps"       ,0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f382c  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscalefss"       ,0x660f382d  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscatterdps"     ,0x660f38a2  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a2  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a2  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscatterdpd"     ,0x660f38a2  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a2  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a2  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscatterqps"     ,0x660f38a3  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a3  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a3  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vscatterqpd"     ,0x660f38a3  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a3  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512F
					0x660f38a3  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vshuff32x4"      ,0x660f3a23  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vshuff32x"       ,0x660f3a23  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vshuff64x2"      ,0x660f3a23  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vshuff64x"       ,0x660f3a23  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vshufi32x4"      ,0x660f3a43  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vshufi32x"       ,0x660f3a43  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vshufi64x2"      ,0x660f3a43  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512VL AVX512F
{"vshufi64x"       ,0x660f3a43  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512F
{"vtestps"         ,0x660f380e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380e  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vtestpd"         ,0x660f380f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f380f  ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vzeroall"        ,0xf77       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"vzeroupper"      ,0xf77       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX
{"wait"            ,0x9b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"fwait"           ,0x9b        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"wbinvd"          ,0xf09       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"wrfsbase"        ,0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,2    ,CAsm::Asm_None ,  //FSGSBASE
					0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,2    ,CAsm::Asm_None },  //FSGSBASE
{"wrgsbase"        ,0xf30fae    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_I     ,0                   ,3    ,CAsm::Asm_None },  //FSGSBASE
{"wrmsr"           ,0xf30       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"wrpkru"          ,0xf01ef     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },
{"xabort"          ,0xc6f8      ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                     ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_Imm },  //RTM
{"xadd"            ,0xfc0       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfc0       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0xfc1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfc1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xfc1       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"xbegin"          ,0xc7f8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //RTM
					0xc7f8      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //RTM
{"xchg"            ,0x0         ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__G,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__G,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x0         ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x86        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x86        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x86        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x86        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x87        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x87        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x87        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x87        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x87        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x87        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"xend"            ,0xf01d5     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //RTM
{"xgetbv"          ,0xf01d0     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"xlat"            ,0xd7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"xlatb"           ,0xd7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0xd7        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"xor"             ,0x34        ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x35        ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__AX,AT__I,OT__w,0,0,0,0)            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x35        ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__DX,AT__I,OT__d,0,0,0,0)           ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x35        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x80        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x81        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x83        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,6    ,CAsm::Asm_Grp_80_81_82_83 ,
					0x30        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x30        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x31        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x31        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x31        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x32        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x32        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None ,
					0x33        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x33        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None ,
					0x33        ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_NE       ,-1   ,CAsm::Asm_None },
{"xorpd"           ,0x660f      ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE2
{"vxorpd"          ,0x660f57    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f57    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0x660f57    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f57    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0x660f57    ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"xorps"           ,0xf57       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //SSE
{"vxorps"          ,0xf57       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf57       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX
					0xf57       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf57       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None ,  //AVX512VL AVX512DQ
					0xf57       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //AVX512DQ
{"xrstor"          ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,5    ,CAsm::Asm_Grp_0FAE },  //XSAVE
{"xrstor64"        ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,5    ,CAsm::Asm_Grp_0FAE },  //XSAVE
{"xrstors"         ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,3    ,CAsm::Asm_Grp_0FC7 },  //XSS
{"xrstors64"       ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,3    ,CAsm::Asm_Grp_0FC7 },  //XSS
{"xsave"           ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_Grp_0FAE },  //XSAVE
{"xsave64"         ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,4    ,CAsm::Asm_Grp_0FAE },  //XSAVE
{"xsavec"          ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,4    ,CAsm::Asm_Grp_0FC7 },  //XSAVEC
{"xsavec64"        ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,4    ,CAsm::Asm_Grp_0FC7 },  //XSAVEC
{"xsaveopt"        ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0FAE },  //XSAVEOPT
{"xsaveopt64"      ,0xfae       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,6    ,CAsm::Asm_Grp_0FAE },  //XSAVEOPT
{"xsaves"          ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,5    ,CAsm::Asm_Grp_0FC7 },  //XSS
{"xsaves64"        ,0xfc7       ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_NE    ,0                   ,5    ,CAsm::Asm_Grp_0FC7 },  //XSS
{"xsetbv"          ,0xf01d1     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_NI    ,0                   ,SUPPORT_CL_V        ,-1   ,CAsm::Asm_None },
{"xtest"           ,0xf01d6     ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                            ,SUPPORT64_BIT_V     ,SUPPORT32_BIT_V     ,0                   ,-1   ,CAsm::Asm_None },  //HLE or RTM
};