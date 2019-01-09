/*
ÊµÏÖÇ°×ºËÑË÷Ê÷
*/
#include "stdafx.h"
#include "StrTrie.h"
#include <tchar.h>


CStrTrie::CStrTrie()
{
	m_trieHead = new STrieNode;
	ZeroMemory(m_trieHead, sizeof(STrieNode));
}

CStrTrie::~CStrTrie()
{
	if (m_trieHead->m_Next)
		DestroyTrie(m_trieHead->m_Next);
	delete m_trieHead;
	m_trieHead = nullptr;
}

int CStrTrie::TrieAddStr(char * str, const int value, const int func) const
{
	STrieNode* TmpNode = m_trieHead;
	char* TmpStr = str;
	int Seq = 0;
	while (*TmpStr)
	{
		if ((TmpNode + Seq)->m_Next == nullptr)
		{
			(TmpNode + Seq)->m_Next = new STrieNode[255];
			ZeroMemory((TmpNode + Seq)->m_Next, sizeof(STrieNode) * 255);
		}
		TmpNode = (TmpNode + Seq)->m_Next;
		Seq = *TmpStr;
		TmpStr++;
	}
	(TmpNode + Seq)->m_Value = value;
	(TmpNode + Seq)->m_Func = func;
	return 0;
}

bool CStrTrie::GetDataInTrie(char * index, int * value, int * func) const
{
	if (index == nullptr || *index == 0x00) return false;
	STrieNode* TmpNode = m_trieHead;
	char* TmpStr = index;
	int Seq = 0;
	while (*TmpStr)
	{
		TmpNode = (TmpNode + Seq)->m_Next;
		if (TmpNode == nullptr) return false;
		Seq = *TmpStr;
		TmpStr++;
	}
	if (TmpNode + Seq)
	{
		if(value)
			*value = (TmpNode + Seq)->m_Value;
		if(func)
			*func = (TmpNode + Seq)->m_Func;
		return true;
	}
	return false;
}

void CStrTrie::DestroyTrie(STrieNode* Node)
{
	for (int i = 0; i < 255; i++)
	{
		if ((Node+i)->m_Next)
			DestroyTrie((Node + i)->m_Next);
	}
	delete Node;
	Node = nullptr;
}

DWORD CStrTrie::GetColorValue(LPCTSTR pstrValue)
{
	if (*pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
	LPTSTR pstr = nullptr;
	return _tcstoul(pstrValue, &pstr, 16);;
}

SIZE CStrTrie::GetSizeValue(LPCTSTR pstrValue)
{
	SIZE szXY = { 0 };
	LPTSTR pstr = nullptr;
	szXY.cx = _tcstol(pstrValue, &pstr, 10);
	szXY.cy = _tcstol(pstr + 1, &pstr, 10);
	return szXY;
}

RECT CStrTrie::GetRectValue(LPCTSTR pstrValue)
{
	RECT rcTextPadding = { 0 };
	LPTSTR pstr = nullptr;
	rcTextPadding.left = _tcstol(pstrValue, &pstr, 10);
	rcTextPadding.top = _tcstol(pstr + 1, &pstr, 10);
	rcTextPadding.right = _tcstol(pstr + 1, &pstr, 10);
	rcTextPadding.bottom = _tcstol(pstr + 1, &pstr, 10);
	return rcTextPadding;
}

