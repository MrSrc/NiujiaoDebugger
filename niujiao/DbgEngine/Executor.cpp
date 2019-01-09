/*
实现调试引擎
*/
#include "stdafx.h"
#include "Executor.h"
#include <atlbase.h>
#include <atlconv.h>
#include <stdio.h>
#include "niujiao.h"

extern CPubWnd* gWndPtr[100];

Executor* Executor::ExeInstance = nullptr;

Executor::Executor(): m_fileName{0}, m_parameter{0}, m_environment{0}, m_currentThread(nullptr), m_debuggedProcessId(0),
                      m_currentDebuggedProcessId(0),
                      m_currentDebuggedThreadId(0), m_debuggerState(ST_CLOSED), m_controlCommand(DBG_NONE),
                      m_firstBreak(false)
{
	InitializeSRWLock(&m_srwStateLock);
	InitializeSRWLock(&m_srwCommandLock);
}

Executor * Executor::GetInstance()
{
	if (ExeInstance == nullptr)
	{
		ExeInstance = new Executor();
	}
	return ExeInstance;
}


void Executor::SetDebuggerState(DWORD state)
{
	AcquireSRWLockExclusive(&m_srwStateLock);
	m_debuggerState = state;
	ReleaseSRWLockExclusive(&m_srwStateLock);
}

DWORD Executor::GetDebuggerState()
{
	DWORD Ret = 0;
	AcquireSRWLockShared(&m_srwStateLock);
	Ret=m_debuggerState;
	ReleaseSRWLockShared(&m_srwStateLock);
	return Ret;
}

void Executor::SetControlCommand(DWORD command)
{
	AcquireSRWLockExclusive(&m_srwCommandLock);
	m_controlCommand = command;
	ReleaseSRWLockExclusive(&m_srwCommandLock);
}

DWORD Executor::GetControlCommand()
{
	DWORD Ret = 0;
	AcquireSRWLockShared(&m_srwCommandLock);
	Ret = m_controlCommand;
	ReleaseSRWLockShared(&m_srwCommandLock);
	return Ret;
}


bool Executor::IsRunning()
{
	return GetDebuggerState() == ST_RUNNING;
}

bool Executor::DebuggerStart(LPCTSTR FileN, LPCTSTR ExecuteP, LPCTSTR Env)
{
	if (FileN)
		lstrcpy(m_fileName, FileN);
	if (ExecuteP)
		lstrcpy(m_parameter, ExecuteP);
	if (Env)
		lstrcpy(m_environment, Env);
	m_hDebuggerThread = CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(StartDebugThread), LPVOID(this), NULL, nullptr);

	return m_hDebuggerThread != INVALID_HANDLE_VALUE;
}

bool Executor::DebuggerRestart()
{
	SetControlCommand(DBG_STOP);
	WaitForSingleObject(m_hDebuggerThread, INFINITE);
	CloseHandle(m_hDebuggerThread);
	return DebuggerStart();;
}

bool Executor::DebuggerClose()
{
	SetControlCommand(DBG_STOP);
	WaitForSingleObject(m_hDebuggerThread, INFINITE);
	CloseHandle(m_hDebuggerThread);
	return true;
}

bool Executor::DebuggerSuspend()
{
	if(GetDebuggerState()==ST_RUNNING)
		SetControlCommand(DBG_SUSPEND);	
	return true;
}

bool Executor::DebuggerRun()
{
	SetControlCommand(DBG_RUN);
	return true;
}

bool Executor::DebuggerStepInto()
{
	SetControlCommand(DBG_STEPINTO);
	return true;
}

bool Executor::DebuggerStepOver()
{
	SetControlCommand(DBG_STEPOVER);
	return true;
}


DWORD WINAPI Executor::StartDebugThread(LPVOID lParam)
{
	Executor* pThis = static_cast<Executor*>(lParam);
	//运行前环境检查
	//执行程序
	STARTUPINFO StartupInfo = { 0 };
	StartupInfo.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION ProcessInformation = { nullptr };
	DWORD ThreadId = 0;

	if (!CreateProcess(pThis->m_fileName, pThis->m_parameter, nullptr, nullptr, false, 
		DEBUG_ONLY_THIS_PROCESS|NORMAL_PRIORITY_CLASS|CREATE_DEFAULT_ERROR_MODE, nullptr, nullptr, &StartupInfo, &ProcessInformation))
	{
		MessageBox(NULL,_T("创建进程失败"), _T("错误提示"), MB_OK);
		return 0;
	}
	pThis->MessageLoop();
	return 0;
}
void Executor::MessageLoop()
{
	//入口处设置断点
	m_firstBreak = false;
	SetDebuggerState(ST_RUNNING);
	gWndPtr[0]->UpdateLogData();
	while (true)
	{
		switch (GetControlCommand())
		{
		case DBG_STOP:
		case DBG_RESTART: //相对于调试线程这两个状态的行为表现一致
			switch(GetDebuggerState())
			{
			case ST_RUNNING:
				//停止目标进程运行
			case ST_BREAKING:
				//杀掉进程
				//清理残留信息
				break;
			default:break;
			}
			//StopDebugger();
			SetDebuggerState(ST_CLOSED);
			break;
		case DBG_STEPINTO: //执行每一条指令
			if (GetDebuggerState() == ST_BREAKING) //只对已经中断下的调试器有效
			{
				ContinueDebugEvent(m_debuggedProcessId, m_currentDebuggedThreadId, DBG_CONTINUE);
			}
			break;
		case DBG_STEPOVER: //跳过call 指令
			if(GetDebuggerState()==ST_BREAKING) //只对已经中断下的调试器有效
			{
				ContinueDebugEvent(m_debuggedProcessId, m_currentDebuggedThreadId, DBG_CONTINUE);
			}
			break;
		case DBG_SUSPEND: //设置断点 
			if(GetDebuggerState()==ST_RUNNING) //只对运行状态下的调试器有效
			{
				SetDebuggerState(ST_BREAKING);
			}
			break;
		case DBG_RUN:
			if(GetDebuggerState()==ST_BREAKING)
			{
				SetDebuggerState(ST_RUNNING);
				ContinueDebugEvent(m_debuggedProcessId, m_currentDebuggedThreadId, DBG_EXCEPTION_NOT_HANDLED);		
			}
			break;
		case DBG_TRACE:
			if (GetDebuggerState() == ST_BREAKING)
			{
				SetDebuggerState(ST_RUNNING);
				ContinueDebugEvent(m_debuggedProcessId, m_currentDebuggedThreadId, DBG_EXCEPTION_NOT_HANDLED);
			}
			break;
		default: break;
		}
		DbgMessageLoop();
		SetControlCommand(DBG_NONE);
	}
}
void Executor::DbgMessageLoop()
{
	DEBUG_EVENT DebugEvent = { 0 };
	while (WaitForDebugEvent(&DebugEvent, 50))
	{
		m_currentDebuggedProcessId = DebugEvent.dwProcessId;
		m_currentDebuggedThreadId = DebugEvent.dwThreadId;
		switch (DebugEvent.dwDebugEventCode)
		{
		case EXCEPTION_DEBUG_EVENT:
			switch (DebugEvent.u.Exception.ExceptionRecord.ExceptionCode)
			{
			case EXCEPTION_ACCESS_VIOLATION:OnExceptionAccessViolationEvent(&DebugEvent);break;
			case EXCEPTION_BREAKPOINT:OnExceptionBreakPointEvent(&DebugEvent);break;
			case EXCEPTION_DATATYPE_MISALIGNMENT:OnExceptionDataTypeMisalignmentEvent(&DebugEvent);break;
			case EXCEPTION_SINGLE_STEP:OnExceptionSingleStepEvent(&DebugEvent);break;
			case DBG_CONTROL_C:OnDbgControlCEvent(&DebugEvent);break;
			}
			break;
		case CREATE_THREAD_DEBUG_EVENT:OnCreateThreadEvent(&DebugEvent);break;  //创建线程
		case CREATE_PROCESS_DEBUG_EVENT:OnCreateProcessEvent(&DebugEvent);break;//创建进程
		case EXIT_THREAD_DEBUG_EVENT:OnExitThreadEvent(&DebugEvent);break; //退出线程
		case EXIT_PROCESS_DEBUG_EVENT:OnExitProcessEvent(&DebugEvent);break; //退出进程
		case LOAD_DLL_DEBUG_EVENT:OnLoadDllEvent(&DebugEvent);break; //加载DLL
		case UNLOAD_DLL_DEBUG_EVENT:OnUnloadDllEvent(&DebugEvent);break;  //卸载DLL
		case RIP_EVENT:OnRipEvent(&DebugEvent);break;
		case OUTPUT_DEBUG_STRING_EVENT:break;
		}
	}
}

bool Executor::OnExceptionAccessViolationEvent(DEBUG_EVENT *) const
{
	return false;
}

bool Executor::OnExceptionBreakPointEvent(DEBUG_EVENT *DebugEvent) const
{
	//RegisterWnd->AddThread(DebugEvent->dwThreadId);  //首次中断可以获得TEB地址
	return false;
}

bool Executor::OnExceptionDataTypeMisalignmentEvent(DEBUG_EVENT *) const
{
	return false;
}

bool Executor::OnExceptionSingleStepEvent(DEBUG_EVENT *) const
{
	return false;
}

bool Executor::OnDbgControlCEvent(DEBUG_EVENT *) const
{
	return false;
}

bool Executor::OnCreateThreadEvent(DEBUG_EVENT *DebugEvent) const
{
	char StrContentTmp[1024] = { 0 };
	//sprintf_s(StrContentTmp, _T("开始创建线程 %X 地址 %X"), DebugEvent->dwThreadId, DebugEvent->u.CreateThread.lpStartAddress);
	//LogWnd->Log(0, _T("Executor"), StrContentTmp, _T(""));

	//加入寄存器窗口
	//RegisterWnd->AddThread(DebugEvent->dwThreadId);

	//加入线程窗口
	//THREAD_DATA* td = new THREAD_DATA;
	//ZeroMemory(td, sizeof(THREAD_DATA));
	//td->ThreadId = (DWORD)DebugEvent->dwThreadId;
	//td->Entrance = (DWORD)DebugEvent->u.CreateThread.lpStartAddress;
	//td->DataAddr = (DWORD)DebugEvent->u.CreateThread.lpThreadLocalBase;
	//ThreadWnd->AddThread(td);

	CloseHandle(DebugEvent->u.CreateThread.hThread);
	return false;
}
bool Executor::OnExitThreadEvent(DEBUG_EVENT *DebugEvent) const
{
	//char StrContentTmp[1024] = { 0 };
	//sprintf_s(StrContentTmp, _T("TID为 %X 的线程终止，结束码为 %X"), DebugEvent->dwThreadId, DebugEvent->u.ExitThread.dwExitCode);
	//LogWnd->Log(0, _T("Executor"), StrContentTmp, _T(""));
	//从线程窗口删除
	//ThreadWnd->RemoveThread(DebugEvent->dwThreadId);
	//RegisterWnd->RemoveThread(DebugEvent->dwThreadId);
	return false;
}

bool Executor::OnCreateProcessEvent(DEBUG_EVENT *DebugEvent)
{
	char StrContentTmp[1024] = { 0 };
	m_debuggedProcessId = DebugEvent->dwProcessId;

	////设置反汇编窗口的信息
	gWndPtr[0]->UpdateDisasmData(DebugEvent->u.CreateProcessInfo.hFile);

	///*添加模块窗口信息*/	
	//ModsWnd->AddModules(DebugEvent->u.CreateProcessInfo.hFile, FileName);

	///*打印日志*/
	//char log[255] = { 0 };
	//sprintf_s(log, "句柄值%X", DebugEvent->u.CreateProcessInfo.hFile);
	//LogWnd->Log(DBG_INFO, log, _T(""));
	CloseHandle(DebugEvent->u.CreateProcessInfo.hProcess);
	CloseHandle(DebugEvent->u.CreateProcessInfo.hFile);
	CloseHandle(DebugEvent->u.CreateProcessInfo.hThread);
	return false;
}


bool Executor::OnExitProcessEvent(DEBUG_EVENT *DebugEvent) const
{
	char StrContentTmp[1024] = { 0 };
	//sprintf_s(StrContentTmp, _T("PID为 %X 的进程终止，结束码为 %X"), DebugEvent->dwProcessId, DebugEvent->u.ExitProcess.dwExitCode);
	//LogWnd->Log(0, _T("Executor"), StrContentTmp, _T(""));
	return false;
}

bool Executor::OnLoadDllEvent(DEBUG_EVENT *DebugEvent) const
{
	char StrContentTmp[1024] = { 0 };
	char StrModName[1024] = { 0 };
	DWORD size = 0;
	DWORD NameAddr = 0;
	HANDLE hDebugged = OpenProcess(PROCESS_ALL_ACCESS, NULL, m_debuggedProcessId);
	if (DebugEvent->u.LoadDll.lpImageName != nullptr)
	{
		ReadProcessMemory(hDebugged, DebugEvent->u.LoadDll.lpImageName, &NameAddr, sizeof(NameAddr), &size);
		ReadProcessMemory(hDebugged, (LPCVOID)NameAddr, StrModName, 1024, &size);
	}

	//char ModuleName[MAX_PATH_WITH_FILE_NAME] = { 0 };
	//GetFileNameFromHandle(DebugEvent->u.LoadDll.hFile, ModuleName);


	/*添加模块窗口信息*/
	//ModsWnd->AddModules(DebugEvent->u.LoadDll.hFile, ModuleName);

	CloseHandle(DebugEvent->u.LoadDll.hFile);
	CloseHandle(hDebugged);
	return false;
}

bool Executor::OnUnloadDllEvent(DEBUG_EVENT *DebugEvent) const
{
	//char StrContentTmp[1024] = { 0 };
	//sprintf_s(StrContentTmp, _T("开始卸载模块 %X"), DebugEvent->u.UnloadDll.lpBaseOfDll);
	//LogWnd->Log(0, _T("Executor"), StrContentTmp, _T(""));

	//从模块窗口删除信息
	//ModsWnd->RemoveModules((DWORD)DebugEvent->u.UnloadDll.lpBaseOfDll);
	return false;
}

bool Executor::OnRipEvent(DEBUG_EVENT *) const
{
	return false;
}

bool Executor::GetFileNameFromHandle(const HANDLE hFile, char* FileName) const
{
	USES_CONVERSION;
	typedef struct _IO_STATUS_BLOCK {
		union {
			ULONG Status;
			PVOID Pointer;
		};
		ULONG_PTR Information;
	}IO_STATUS_BLOCK,*PIO_STATUS_BLOCK;

	typedef struct _FILE_NAME_INFORMATION {
		ULONG FileNameLength;
		//WCHAR FileName[MAX_PATH_WITH_FILE_NAME];
	}FILE_NAME_INFORMATION,*PFILE_NAME_INFORMATION;

	typedef LONG (CALLBACK* ZWQUERYINFORMATIONFILE)(
			HANDLE  FileHandle,
			IO_STATUS_BLOCK *IoStatusBlock,
			PVOID  FileInformation,
			ULONG  Length,
			ULONG  FileInformationClass
			);
	HMODULE hNtDll = LoadLibrary(_T("ntdll.dll"));
	ZWQUERYINFORMATIONFILE ZwQueryInformationFile = (ZWQUERYINFORMATIONFILE)
		GetProcAddress(hNtDll,"ZwQueryInformationFile");
	if(ZwQueryInformationFile==nullptr)return false;
	FILE_NAME_INFORMATION fni = { 0 };
	IO_STATUS_BLOCK isb = { 0 };
	//获取文件路径名  //windows//.../*.dll
	if (ZwQueryInformationFile(hFile, &isb, &fni, sizeof(fni), 9) != 0)
		return false;
	//char* TmpName = W2A(fni.FileName);
	//fni.FileName[fni.FileNameLength / sizeof(char)] = 0x00;

	//获取盘符id
	BY_HANDLE_FILE_INFORMATION fi;
	if (!GetFileInformationByHandle(hFile, &fi) || (fi.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) { return 0x00; }

	//获取所有盘符字符串格式
	char  szDrive[MAX_PATH];
	char *lpDrive = szDrive;
	//if (GetLogicalDriveStrings(MAX_PATH - 1, szDrive) >= MAX_PATH) { return 0x00; }

	//while ((iPathLen = lstrlen(lpDrive)) != 0) {
		//将盘符字符串格式转为id 形式
	//	if (!GetVolumeInformation(lpDrive, NULL, NULL, &dwVolumeSerialNumber, NULL, NULL, NULL, NULL)) { return 0x00; }

		//对比
		//if (dwVolumeSerialNumber == fi.dwVolumeSerialNumber) {
		//	lstrcpy(FileName, lpDrive);
		//	lstrcat(FileName, TmpName+1);
	//		break;
	//	}
	//	lpDrive += iPathLen + 1;
	//}
	return true;

}


bool Executor::StopDebugger()
{

	//恢复所有线程 然后关闭
	char str[32] = { 0 };
	//分离进程
	HANDLE hDebugged = OpenProcess(PROCESS_TERMINATE | PROCESS_SUSPEND_RESUME|PROCESS_ALL_ACCESS, NULL, m_debuggedProcessId);

	//sprintf_s(str, "handle 1 %X\n", hDebugged);
	//printf(str);
	//if (CurrentDebuggedProcessId == 0)
	//	return false;
	DWORD id = GetProcessId(hDebugged);
	//sprintf_s(str, "id 1 %X\n", id);
	//printf(str);
	//if (DebugActiveProcessStop(id) == 0)
	{
	//	LogWnd->Log(ERROR_INFO, _T("DebugActiveProcessStop"), _T(""));
	//	sprintf(str, "error 1 %d\n", GetLastError());
	//	printf(str);
	//	return false;
	}
	//hDebugged = OpenProcess(PROCESS_TERMINATE | PROCESS_ALL_ACCESS, NULL, DebuggedProcessId);
	if (hDebugged == INVALID_HANDLE_VALUE)
	{
	//	LogWnd->Log(ERROR_INFO, _T("OpenProcess"), _T("")); 
		return false;
	}

	if (TerminateProcess(hDebugged, PROCESS_TERMINATE) == 0)
	{
		//LogWnd->Log(ERROR_INFO, _T("ternamite"), _T(""));
		sprintf_s(str, "error 1 %d\n", GetLastError());
		printf(str);
		return false;
	}
	CloseHandle(hDebugged);
	m_currentDebuggedProcessId = 0;
	m_currentDebuggedThreadId = 0;
	return true;
}

