#pragma once
/*
定义汇编引擎的相关处理函数
*/
#include <Windows.h>
#include "define.h"
#include "PubLib/StrTrie.h"

#define MAX_ASM_STR_LENGTH 16
class CAsm
{
	static CStrTrie *m_strTrie;
public:
	CAsm();
	static int AsmFromStr(LPCTSTR asmStr, SAsmResultSet* asmResultSet);
	static bool StripStr(char* str); //去除字符串首尾的空白字符
	static bool RemoveSpace(char* str); //去除字符串首尾的空白字符
	static bool SplitStr(char*, SAsmStr*); //分割汇编语句的助记符和各个操作数
	static bool IsImmValue(char* tmpStr, int* immValue=NULL); //判断字符串是否为立即数  ****
	static bool IsReg(char* tmpStr, int base,int* Reg=NULL); //判断字符串是否为寄存器
	static bool IsMemAddressing(char* tmpStr); //判断字符串是否为内存寻址
	static UINT64 GetOpcode(UINT Opcode);


	static bool Asm_None(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static int Asm_SIB(char* AsmStr, char** SIBByte); //解析 SIB 字节
	static int Asm_ModRm(char* AsmStr,char** ModeRmByte,int base); //解析ModRM字节 返回解析后的长度
	static bool Asm_Imm(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);  //汇编操作数为立即数的汇编语句  ****
	static bool Asm_Grp_80_81_82_83(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format); //汇编操作码为 0x80 81 82 83 的分组指令
	static bool Asm_Grp_8F(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_C0_C1_D0_D1_D2_D3(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_C6(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_C7(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_F6_F7(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_FE(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_FF(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0F00(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0F01(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0F18(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0F71(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0F72(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0F73(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0FAE(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0FB9(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0FBA(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
	static bool Asm_Grp_0FC7(SAsmStr* asmStr, SAsmResult* asmResult, SInstructFmt* format);
};