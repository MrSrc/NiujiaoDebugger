#pragma once
/*
定义调试引擎的相关结构和处理函数
*/
#include <Windows.h>
#include "ImageInfo.h"
#include "Disasm.h"

static enum {
	BP_System = 0x1,
	BP_ModuleEntry = 0x10,
	BP_WinMain = 0x100,
	BP_CreateThread = 0x1000,
	BP_ExitThread = 0x10000,
	BP_LoadDll = 0x100000,
	BP_UnloadDll = 0x1000000,
	BP_DebugString = 0x10000000,
	BP_BreakPoint = 0x100000000
}BP_TYPE;//断点类型

static enum {
	DBG_NONE,
	DBG_STOP,
	DBG_SUSPEND,
	DBG_RESTART,
	DBG_RUN,
	DBG_STEPINTO,
	DBG_STEPOVER,

	DBG_TRACE,
	DBG_AUTOSTEPINTO,
	DBG_AUTOSTEPOVER,
	DBG_EXETORET,
	DBG_EXETOUSERSPACE,
}DEBUGER_ENVENT;
static enum {
	ST_RUNNING,
	ST_CLOSED,
	ST_BREAKING
}DBG_STATE;//断点事件
class Executor
{
private:
	Executor();
	~Executor();
	Executor(const Executor&) {};
	Executor& operator=(const Executor&) const { };
	static Executor *ExeInstance;  //执行体实例
	SRWLOCK m_srwStateLock; //读写锁
	SRWLOCK m_srwCommandLock; //读写锁

	DWORD m_debuggerState;  //调试器状态  由调试线程写 调用线程读
	DWORD m_controlCommand; //控制命令   调用线程写  调试线程执行完成后清除该状态

	HANDLE m_hDebuggerThread;

	TCHAR m_fileName[1024];
	TCHAR m_parameter[1024];
	TCHAR m_environment[1024];


	HANDLE m_currentThread; //默认为主线程

	DWORD m_debuggedProcessId;

	DWORD m_currentDebuggedProcessId;
	DWORD m_currentDebuggedThreadId;

	bool m_firstBreak; //首次中断


public:
	static Executor* GetInstance();
	bool IsRunning();
	bool DebuggerStart(LPCTSTR FileN = nullptr, LPCTSTR ExecuteP = nullptr, LPCTSTR Env = nullptr);


	void SetDebuggerState(DWORD);  //设置调试器运行状态
	DWORD GetDebuggerState();  //获取调试器运行状态
	void SetControlCommand(DWORD);  //设置控制命令
	DWORD GetControlCommand();  //获取控制命令
	bool DebuggerRestart();
	bool DebuggerClose();
	bool DebuggerSuspend();
	bool DebuggerRun();
	bool DebuggerStepInto();
	bool DebuggerStepOver();

	bool SetSoftBreakPoint(DWORD addr);
	static DWORD WINAPI StartDebugThread(LPVOID lParam);

//以上是调用线程使用的函数
//以下是调试线程使用的函数
	
	void MessageLoop();
	void DbgMessageLoop();
	bool OnExceptionAccessViolationEvent(DEBUG_EVENT*) const;
	bool OnExceptionBreakPointEvent(DEBUG_EVENT*) const;
	bool OnExceptionDataTypeMisalignmentEvent(DEBUG_EVENT*) const;
	bool OnExceptionSingleStepEvent(DEBUG_EVENT*) const;
	bool OnDbgControlCEvent(DEBUG_EVENT*) const;
	bool OnCreateThreadEvent(DEBUG_EVENT*) const;
	bool OnCreateProcessEvent(DEBUG_EVENT*);
	bool OnExitThreadEvent(DEBUG_EVENT*) const;
	bool OnExitProcessEvent(DEBUG_EVENT*) const;
	bool OnLoadDllEvent(DEBUG_EVENT*) const;
	bool OnUnloadDllEvent(DEBUG_EVENT*) const;
	bool OnRipEvent(DEBUG_EVENT*) const;
	

	bool GetFileNameFromHandle(const HANDLE, char*) const;

	bool StopDebugger();
};