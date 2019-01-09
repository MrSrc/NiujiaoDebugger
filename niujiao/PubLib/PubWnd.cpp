#include "stdafx.h"
#include "PubWnd.h"
#include <stdlib.h>
#include <Commdlg.h>

s_wnd_list* gWndHead = nullptr;

static LPCTSTR gWndXmlName[100] = { 0 }; //建立窗口的xml文件
static PVOID gWndPtr[100] = { 0 };  //窗口指针
LRESULT CPubWnd::OnNcHitTest(UINT uMsg, WPARAM wParam, const LPARAM lParam, BOOL& bHandled)
{
	POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
	::ScreenToClient(*this, &pt);

	RECT RcClient;
	::GetClientRect(*this, &RcClient);

	if (!::IsZoomed(*this))
	{
		const RECT RcSizeBox = m_PaintManager.GetSizeBox();
		if (pt.y < RcClient.top + RcSizeBox.top)
		{
			if (pt.x < RcClient.left + RcSizeBox.left) return HTTOPLEFT;
			if (pt.x > RcClient.right - RcSizeBox.right) return HTTOPRIGHT;
			return HTTOP;
		}
		else if (pt.y > RcClient.bottom - RcSizeBox.bottom)
		{
			if (pt.x < RcClient.left + RcSizeBox.left) return HTBOTTOMLEFT;
			if (pt.x > RcClient.right - RcSizeBox.right) return HTBOTTOMRIGHT;
			return HTBOTTOM;
		}

		if (pt.x < RcClient.left + RcSizeBox.left) return HTLEFT;
		if (pt.x > RcClient.right - RcSizeBox.right) return HTRIGHT;
	}

	const RECT RcCaption = m_PaintManager.GetCaptionRect();
	if (pt.x >= RcClient.left + RcCaption.left && pt.x < RcClient.right - RcCaption.right \
		&& pt.y >= RcCaption.top && pt.y < RcCaption.bottom) {
		CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(pt));
		if (pControl && _tcsicmp(pControl->GetClass(), _T("ButtonUI")) != 0 &&
			_tcsicmp(pControl->GetClass(), _T("OptionUI")) != 0 &&
			_tcsicmp(pControl->GetClass(), _T("SliderUI")) != 0 &&
			_tcsicmp(pControl->GetClass(), _T("EditUI")) != 0 &&
			_tcsicmp(pControl->GetClass(), _T("RichEditUI")) != 0)
			return HTCAPTION;
	}

	return HTCLIENT;
}

LRESULT CPubWnd::OnWindowPosChanging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	UpdateWindowBackground();
	return LRESULT();
}
/**
 * \brief 
 * \param fileName 
 */
void CPubWnd::ReadPeAttribute(const LPCTSTR fileName) const
{
	CImageInfo* ImageInfo = new CImageInfo(fileName);
	FillGeneral(ImageInfo);
	FillDataDir(ImageInfo);
	FillSeg(ImageInfo);
	FillImport(ImageInfo);
	FillExport(ImageInfo);
	delete ImageInfo;
}

/**
 * \brief 
 * \param tmp 
 */
void CPubWnd::FillGeneral(CImageInfo * tmp) const
{
	TCHAR str[64] = { 0 };
	wsprintf(str, _T("0x%X"), tmp->GetAddressOfEntryPoint());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_entrance")))->SetText(str);

	wsprintf(str, _T("%d"), tmp->GetNumberOfSections());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_numofsec")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetOptionalHeaderSize());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_optionh")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetImageBase());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_imagebase")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetImageSize());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_imagesize")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetNumOfRVA());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_numofrva")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetBaseOfCode());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_codebase")))->SetText(str);
	wsprintf(str, _T("0x%X"), tmp->GetBaseOfData());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_database")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetSizeOfHeaders());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_headsize")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetAlignmentOfBlock());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_bkalign")))->SetText(str);

	wsprintf(str, _T("0x%X"), tmp->GetAlignmentOfFile());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_filealign")))->SetText(str);
	wsprintf(str, _T("%X"), tmp->GetCheckSum());
	static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pe_checksum")))->SetText(str);

	CComboUI* Combo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("pe_machn")));
	switch (tmp->GetMachine())
	{
	case 0:Combo->SelectItem(0); break;
	case 0x1d3:Combo->SelectItem(1); break;
	case 0x8664:Combo->SelectItem(2); break;
	case 0x1c0:Combo->SelectItem(3); break;
	case 0xebc:Combo->SelectItem(4); break;
	case 0x14c:Combo->SelectItem(5); break;
	case 0x200:Combo->SelectItem(6); break;
	case 0x9041:Combo->SelectItem(7); break;
	case 0x266:Combo->SelectItem(8); break;
	case 0x366:Combo->SelectItem(9); break;
	case 0x466:Combo->SelectItem(10); break;
	case 0x1f0:Combo->SelectItem(11); break;
	case 0x1f1:Combo->SelectItem(12); break;
	case 0x166:Combo->SelectItem(13); break;
	case 0x1a2:Combo->SelectItem(14); break;
	case 0x1a3:Combo->SelectItem(14); break;
	case 0x1a6:Combo->SelectItem(14); break;
	case 0x1a8:Combo->SelectItem(14); break;
	case 0x1c2:Combo->SelectItem(14); break;
	case 0x169:Combo->SelectItem(14); break;
	default: ;
	}

	const DWORD Characteristic = tmp->GetCharacteritic();
	wsprintf(str, _T(" 0x%X (该域取位或值，以下是各个相关的位)"), Characteristic);
	static_cast<CListLabelElementUI*>(m_PaintManager.FindControl(_T("pe_c_0")))->SetText(str);
	static_cast<CListLabelElementUI*>(m_PaintManager.FindControl(_T("pe_c_0")))->SetBkColor(0xff4cb4e7);
	static_cast<CComboUI*>(m_PaintManager.FindControl(_T("pe_charater")))->SelectItem(0);
	for (UINT Counter = 0; Counter < 16; Counter++)
	{
		const UINT Off = 1;
		wsprintf(str, _T("pe_c_%d"), Counter + 1);
		if (Characteristic&(Off << Counter))
			static_cast<CListLabelElementUI*>(m_PaintManager.FindControl(str))->SetVisible(true);
		else
			static_cast<CListLabelElementUI*>(m_PaintManager.FindControl(str))->SetVisible(false);
	}

	Combo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("pe_subsystem")));
	switch (tmp->GetSubSystem())
	{
	case 0:
	case 1:
	case 2:
	case 3:Combo->SelectItem(tmp->GetSubSystem()); break;
	case 7:Combo->SelectItem(4); break;
	case 9:Combo->SelectItem(5); break;
	case 10:Combo->SelectItem(6); break;
	case 11:Combo->SelectItem(7); break;
	case 12:Combo->SelectItem(8); break;
	case 13:Combo->SelectItem(9); break;
	case 14:Combo->SelectItem(10); break;
	}
	CDateTimeUI* DateTime = static_cast<CDateTimeUI*>(m_PaintManager.FindControl(_T("pe_datetime")));
	SYSTEMTIME SystemTime = { 0 };
	FILETIME FileTime = { 0 };
	FileTime.dwLowDateTime = tmp->GetDateTimeStamp();
	FileTimeToSystemTime(&FileTime, &SystemTime);
	DateTime->SetTime(&SystemTime);
}
void CPubWnd::FillDataDir(CImageInfo * tmp) const
{
	TCHAR str[16];
	TCHAR DataName[][20] = { _T("  导出表"), _T("  导入表"), _T("  资源表"), _T("  异常表"), _T("  属性证书表"), _T("  基址重定位表"),
		_T("  调试数据起始地址"), _T("  全局指针"), _T("  线程局部存储"), _T("  加载配置表"), _T("  绑定导入表"), _T("  导入地址表"), _T("  延迟导入描述表"),
		_T("  CLR运行时") };
	DATA_DIRECTORY* dd = tmp->GetDataDirectory();
	static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_datadirlist")))->RemoveAll();
	for (int i = 0; i < DD_MAX_DIRECTORY_NAME_VALUE; i++)
	{
		CListTextElementUI* p = new CListTextElementUI();

		static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_datadirlist")))->Add(p);
		p->SetText(0, DataName[i]);
		wsprintf(str, _T("  0x%X"), (dd + i)->VirtualAddress);
		p->SetText(1, str);
		wsprintf(str, _T("  0x%X"), (dd + i)->Size);
		p->SetText(2, str);
	}
}
/**
 * \brief 
 * \param tmp 
 */
void CPubWnd::FillSeg(CImageInfo * tmp) const
{
	TCHAR Str[16];
	PE_SECTION_HEADER* PeSectionHeader = tmp->GetSectionHeader();
	static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_seglist")))->RemoveAll();
	for (UINT Seq = 0; Seq < tmp->GetNumberOfSections(); Seq++)
	{
		CListTextElementUI* p = new CListTextElementUI();
		static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_seglist")))->Add(p);
		MultiByteToWideChar(CP_ACP, 0, reinterpret_cast<char*>((PeSectionHeader + Seq)->Name), 8, Str, 16);
		p->SetText(0, Str);
		wsprintf(Str, _T("  0x%X"), (PeSectionHeader + Seq)->VirtualAddress);
		p->SetText(1, Str);
		wsprintf(Str, _T("  0x%X"), (PeSectionHeader + Seq)->VirtualSize);
		p->SetText(2, Str);
		wsprintf(Str, _T("  0x%X"), (PeSectionHeader + Seq)->PointerToRawData);
		p->SetText(3, Str);
		wsprintf(Str, _T("  0x%X"), (PeSectionHeader + Seq)->SizeOfRawData);
		p->SetText(4, Str);
		wsprintf(Str, _T("  %X"), (PeSectionHeader + Seq)->Characteristics);
		p->SetText(5, Str);
	}
}
void CPubWnd::FillImport(CImageInfo * tmp) const
{
	DATA_DIRECTORY* DataDir = tmp->GetDataDirectory();
	DWORD ImpTblFileOffset = tmp->VoaToFoa((DataDir + 1)->VirtualAddress);
	if (ImpTblFileOffset)
	{
		for (int Seq = 0;; Seq++)
		{

			IMPORT_DIRECTORT_TABLE* ImportDirectoryTable = (IMPORT_DIRECTORT_TABLE*)((DWORD)tmp->GetMapFileAddr() + ImpTblFileOffset) + Seq;
			if (ImportDirectoryTable->ForwarderChain == 0
				&& ImportDirectoryTable->ImportAdressTableRVA == 0
				&& ImportDirectoryTable->ImportLookUpTableRVA == 0
				&& ImportDirectoryTable->NameRVA == 0
				&& ImportDirectoryTable->TimeDateStamp == 0)
			{
				break;
			}
			DWORD TmpNameAddr = tmp->VoaToFoa(ImportDirectoryTable->ImportAdressTableRVA) + (DWORD)tmp->GetMapFileAddr();  //函数名称总表 pecoff 44
			int FuncNum = 0; //函数总个数
			TCHAR WideCharName[32] = { 0 };
			TCHAR wSeq[4] = { 0 };
			while (*((DWORD*)TmpNameAddr + FuncNum))
			{
				DWORD TmpAddr = tmp->VoaToFoa(*((DWORD*)TmpNameAddr + FuncNum)) + (DWORD)tmp->GetMapFileAddr() + 2;
				memset(WideCharName, 0x00, sizeof(WideCharName));
				MultiByteToWideChar(CP_ACP, 0, (char*)TmpAddr, strlen((char*)TmpAddr), WideCharName, sizeof(WideCharName));
				CListTextElementUI* p = new CListTextElementUI();
				static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_impfunc")))->Add(p);
				p->SetText(0, WideCharName);
				_itot(Seq, wSeq, 10);
				p->SetUserData(wSeq);
				FuncNum++;
			}

			//返回dll名称
			TmpNameAddr = tmp->VoaToFoa(ImportDirectoryTable->NameRVA) + (DWORD)tmp->GetMapFileAddr();

			memset(WideCharName, 0x00, sizeof(WideCharName));
			MultiByteToWideChar(CP_ACP, 0, (char*)TmpNameAddr, strlen((char*)TmpNameAddr), WideCharName, sizeof(WideCharName));
			CListTextElementUI* p = new CListTextElementUI();
			static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_impdll")))->Add(p);
			p->SetText(0, WideCharName);
		}
		static_cast<CListUI*>(m_PaintManager.FindControl(_T("pe_impdll")))->SelectItem(0);
	}
}
void CPubWnd::FillExport(CImageInfo * tmp) const
{
}

void CPubWnd::HandleCommandEvt(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	LPCTSTR TmpName = msg.pSender->GetUserData();
	if (TmpName != nullptr && lstrlen(TmpName))
	{
		char ProcName[1024] = { 0 };
		WideCharToMultiByte(CP_ACP, 0, TmpName, lstrlen(TmpName), ProcName, sizeof(ProcName), nullptr, nullptr);
		system(ProcName); //TODO 运行会闪过一个控制台窗口  
	}
}

void CPubWnd::HandleNewWndEvt(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	LPCTSTR XmlName = msg.pSender->GetUserData().GetData();
	if (XmlName != NULL && lstrlen(XmlName))
	{
		int i = 0;
		//TODO 如果添加了换肤功能 xml名称地址应该会改变，此处也要跟着改
		while (gWndXmlName[i] && i < 100)
		{
			if (gWndXmlName[i] == XmlName)
			{
				((CPubWnd*)gWndPtr[i])->ShowWindow(True);
				return;
			}
			i++;
		}
		gWndXmlName[i] = XmlName;
		CPubWnd *SubDlg = new CPubWnd(XmlName);
		SubDlg->hWnd = SubDlg->Create(pBase->GetHWND(), msg.pSender->GetText(), WS_CHILD | WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS, WS_EX_WINDOWEDGE);

		RECT rc1, rc2;
		GetWindowRect(SubDlg->hWnd, &rc1);
		GetWindowRect(pBase->GetHWND(), &rc2);

		MoveWindow(SubDlg->hWnd, ((rc2.right - rc2.left) - (rc1.right - rc1.left)) / 2, ((rc2.bottom - rc2.top) - (rc1.bottom - rc1.top)) / 2, rc1.right - rc1.left, rc1.bottom - rc1.top, True);
		SubDlg->ShowWindow(True);
		gWndPtr[i] = SubDlg;
	}
}

void CPubWnd::HandleFunction(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
}

void CPubWnd::HandleCaptionMsg(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	pBase->SendMessage(WM_SYSCOMMAND, Value, 0);
}

void CPubWnd::HandleSubWndClose(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	//TODO 删除窗口之后，按钮相关内存会被释放。但是后续触发的LButtonUp事件会寻找按钮的内存信息，会报错
	//先设置隐藏窗口  后续再处理此问题
	//((CPubWnd*)pBase)->Destroyed = True;
	pBase->ShowWindow(False);
}

void CPubWnd::HandleBrowserFile(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	OPENFILENAME ofn = { 0 };
	TCHAR FileName[255 + 1] = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = _T("*.exe;*.dll\0*.exe;*.dll\0全部\0*.*\0\0");
	ofn.lpstrInitialDir = _T("C:\\");
	ofn.lpstrFile = FileName;
	ofn.nMaxFile = sizeof(FileName);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
	if (GetOpenFileName(&ofn))
	{
		CEditUI *Edit = static_cast<CEditUI*> (pBase->m_PaintManager.FindControl(_T("browser_edit")));
		if (Edit)
		{
			Edit->SetText(FileName);
		}
	}
	else
	{
		if (CommDlgExtendedError()) //取消或者关闭时为0
			MessageBox(NULL, _T("错误提示"), _T("获取文件名称失败"), MB_OK);
	}
}

void CPubWnd::HandlePeBrowser(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	OPENFILENAME ofn = { 0 };
	TCHAR FileName[255 + 1] = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = _T("*.exe;*.dll\0*.exe;*.dll\0全部\0*.*\0\0");
	ofn.lpstrInitialDir = _T("C:\\");
	ofn.lpstrFile = FileName;
	ofn.nMaxFile = sizeof(FileName);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
	if (GetOpenFileName(&ofn))
	{
		((CPubWnd*)pBase)->ReadPeAttribute(FileName);
	}
	else
	{
		if (CommDlgExtendedError()) //取消或者关闭时为0
			MessageBox(NULL, _T("错误提示"), _T("获取文件名称失败"), MB_OK);
	}
}

void CPubWnd::HandlePeSwitchImportDll(WindowImplBase* pBase, TNotifyUI& msg, int Value)
{
	TCHAR wSeq[8] = { 0 };
	_itot(msg.wParam, wSeq, 10);
	CListUI* pList = static_cast<CListUI*>(pBase->m_PaintManager.FindControl(_T("pe_impfunc")));
	int Count = pList->GetCount();
	for (int i = 0; i < Count; i++)
	{
		if (pList->GetItemAt(i)->GetUserData() == wSeq)
			pList->GetItemAt(i)->SetVisible(True);
		else
			pList->GetItemAt(i)->SetVisible(False);
	}
}

void HandleNotify(WindowImplBase* pBase, TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK || msg.sType == DUI_MSGTYPE_ITEMSELECT)
	{
		char NameStr[MAX_STRING_LENGTH] = { 0 };
		LPCTSTR TmpStr = msg.pSender->GetName().GetData();
		WideCharToMultiByte(CP_ACP, 0, TmpStr, lstrlen(TmpStr), NameStr, sizeof(MAX_STRING_LENGTH), 0, 0);
		int Func = 0, Value = 0;
		if (pBase->m_strTrie->GetDataInTrie(NameStr, &Value, &Func))
		{
			const SEventHandle HandleFunc = SEventHandle(Func);
			HandleFunc(pBase, msg, Value);
		}
	}
	else if (msg.sType == DUI_MSGTYPE_SELECTCHANGED)
	{
		if (lstrcmp(msg.pSender->GetClass(), _T("OptionUI")) == 0)
		{
			CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(pBase->m_PaintManager.FindControl(msg.pSender->GetUserData()));
			if (pControl)
			{
				pControl->SelectItem(_ttoi(msg.pSender->GetName()));
				UpdateWindowBackground();
			}
		}
	}
}

WCHAR* GenerateClassName()
{
#ifdef _UNICODE
	TCHAR* ClassName = (TCHAR*)malloc(32);
	memset(ClassName, 0x00, 32);
	char RandValue[16] = { 0 };
#else
	char* RandValue = (char*)malloc(16);
	memset(RandValue, 0x00, 16);
#endif
	srand(GetTickCount());
	int a = rand();
	int size = a % 3 + 5;
	for (int i = 0; i < size; i++)
	{
		a = rand();
		RandValue[i] = (33 + a % 93);
	}

#ifdef _UNICODE
	MultiByteToWideChar(CP_ACP, 0, RandValue, sizeof(RandValue), ClassName, 32);
	return ClassName;
#else
	return RandValue;
#endif
}

void UpdateWindowBackground()
{
	HWND  hWnd = GetForegroundWindow();
	RECT rc;
	GetClientRect(hWnd, &rc);
	RedrawWindow(hWnd, 0, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
}

CPubWnd::CPubWnd(LPCTSTR pszXMLPath) : m_strXMLPath(pszXMLPath)
{
	m_className = GenerateClassName();
	if (gWndHead == NULL)
	{
		gWndHead = new s_wnd_list;
		gWndHead->WndClass = this;
		gWndHead->Next = NULL;
	}
	else
	{
		s_wnd_list* Tmp;
		for (Tmp = gWndHead; Tmp->Next != NULL; Tmp = Tmp->Next);
		Tmp->Next = new s_wnd_list;
		Tmp->Next->WndClass = this;
		Tmp->Next->Next = NULL;
	}

	//初始化前缀树 
	m_strTrie = new CStrTrie();
	for(int i=0;i<(sizeof(gEventString)/sizeof(SEventString));i++)
	{
		m_strTrie->TrieAddStr(gEventString[i].m_Str, gEventString[i].Value, int(gEventString[i].EventHandle));
	}
}

CPubWnd::~CPubWnd()
{
	if (gWndHead)
	{
		if (gWndHead->WndClass == this)
		{
			gWndHead = gWndHead->Next;
		}
		else
		{
			s_wnd_list* Tmp;
			for (Tmp = gWndHead; Tmp->Next->WndClass == this; Tmp = Tmp->Next);
			delete Tmp->Next;
			Tmp->Next = Tmp->Next->Next;
		}
	}
	free(m_className);
	if (m_strTrie) delete m_strTrie;
}

void CPubWnd::Notify(TNotifyUI & msg)
{
	
}
