#pragma once
/*
定义反汇编引擎的部分结构体和相关处理函数
*/
#include <Windows.h>
#include <stdio.h>
#include "ImageInfo.h"
#include "define.h"

//反汇编结果结构体
enum {
	PLATFORM_8BIT,
	PLATFORM_16BIT,
	PLATFORM_32BIT,
	PLATFORM_64BIT
};
typedef struct disasm_result
{
	int* CodeMap;
	DWORD CurrentAddr;
	BYTE  MachineCode[16];
	bool IsData; //可能是数据
	int SIB_Prefix;
	DWORD PrefixState;
	char Opcode[15];
	int CurrentLen;
	int OperandNum;
	char FirstOperand[64];
	char SecondOperand[64];
	char ThirdOperand[64];
	char ForthOperand[64];
	char  Memo[32];

}DISASM_RESULT;
typedef struct disasm_point
{
	int PlatForm;
	DWORD BaseOfCode;  //内存代码基址
	DWORD BaseOfCodeInFile;  //文件代码基址
	DWORD BaseOfImage; //内存映像基址 
	DWORD EntryOfCode; //代码入口位置
	DWORD FileStartOfCode; //文件中代码段开始位置
	DWORD FileEndOfCode; //文件中代码段结束位置
	DWORD LenOfCode;//代码段长度
	DWORD CurrentAddr;
	DWORD TotalDisasmRecord;
	DWORD MapFileAddr; //文件映射内存地址
}DISASM_POINT;  //由于静态函数的缘故  使用额外一份独立的imageinfo 

typedef struct str_map_code
{
	BYTE Num;  //操作码序号 没有用到，只为前期检索方便设置的
	char OpStr[15];  //操作码伪指令字符串
	DWORD64 Operand;  //操作数，最多四个。前三位为操作数数量，最大为四；后面每个地址类型与其操作数类型各占五位。总的有效位为43位。
	bool(*DisasmFunc)(DISASM_RESULT*, DISASM_POINT*,int* IsFinished); //操作码对应的处理函数指针
}STR_MAP_CODE;

typedef struct func_list
{
	DWORD Addr;
	struct func_list* next;
} FUNC_LIST;


class Disasm
{
private:
	DISASM_RESULT* DisasmResult; //基于地址索引的反汇编结果
	DWORD *DisasmResultBySeq; //基于序号的反汇编结果

	DISASM_POINT* DisasmPoint;
	CImageInfo* ImageInfo;


public:
	//反汇编单条指令
	Disasm();
	Disasm(HANDLE hFile);
	Disasm(char* FileName);
	~Disasm();
	DISASM_RESULT* GetDisasmResult(DWORD) const;

	DISASM_RESULT* GetDisasmResult() const;
	DWORD* GetDisasmResultBySeq() const;
	CImageInfo* GetImageInfo() const;
	DWORD GetTotalDisasmRecord() const;
	void IndexResultBySeq(DISASM_POINT* ImageInfo); //根据序号建立反汇编结果索引

	/*链表操作函数 */
	static bool FuncAdd(DWORD Addr);
	static DWORD FuncPop();
	static int GetFuncPoolSize();
	/*链表操作函数 */

	bool DisasmFile();
	bool TestPrintToFile() const;
	static bool SetDataType(DISASM_POINT*  DisasmPoint, DWORD addr, int size);

	static bool GernelDisasm(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static char* GetNumbericType(DISASM_RESULT*DisasmResult,int base,int seg=0);
	static bool Disasm_reg_or_imm(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished); // 任意个寄存器或者任意个编码在指令中的操作数
	static bool Disasm_ModRM(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_SIB(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, PDWORD Len, char*);
	static bool Disasm_grp_80_83(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_grp_ff(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_RexPrefix(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ret(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_set_prefix(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_grp_c6_c7(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_grp_shift(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_no_else(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_pusha(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_popa(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_pushf(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_popf(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_grp_f6_f7(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_grp_fe(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_int(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_reserve(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_bound(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_0x63(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_imul(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_grp_8f(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_0x90(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xd8(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xd9(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xda(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xdb(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xdc(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xdd(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xde(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_ESC_0xdf(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_two_opcode(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);


	//二字节操作码
	static bool Disasm_TWO_grp_0x00(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_grp_0x01(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_grp_0xae(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xbx(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x6x_0xdx_0xex_0xfx(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_three_opcode38(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_three_opcode3A(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x10(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x11(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x12(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x13(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x14(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x15(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x16(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x17(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_grp_16(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x1a(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x1b(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x28(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x29(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x2a(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x2b(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x2c(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x2d(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x2e_0x2f(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x50(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x51(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x52_0x53(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x54_0x55_0x56_0x57(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x58_0x59_0x5c_0x5d_0x5e_0x5f(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x5a(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x5b(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x70(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_grp12_grp13_grp14(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x74_0x75_0x76(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x77(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x7c_0x7d(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x7e(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0x7f(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xc0_0xc1_0xc3(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xc2(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xc4(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xc5(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xc6(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_grp9(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_TWO_0xc8_0xcf(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);

	//三字节操作码38
	static bool Disasm_THREE38_0x0x(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_gernel(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0x1c_0x1d_0x1e(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0xf0(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0xf1(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0xf2(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_grp17(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0xf5(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0xf6(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE38_0xf7(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	//三字节操作码3a
	static bool Disasm_THREE3A_gernel(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
	static bool Disasm_THREE3A_0x0f(DISASM_RESULT*DisasmResult, DISASM_POINT*  DisasmPoint, int* IsFinished);
};
