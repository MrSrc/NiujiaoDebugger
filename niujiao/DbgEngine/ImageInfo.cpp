/*
实现PE文件格式的解析
*/
#include "stdafx.h"
#include "ImageInfo.h"


CImageInfo::CImageInfo(DWORD StartAddr)
{
//	LogWnd = CLogWndFrameWnd::GetInstance();
	GetImageInfo(StartAddr);
}

CImageInfo::CImageInfo(LPCTSTR FileName)
{
	//将句柄映射至内存
	hFile = CreateFile(FileName, GENERIC_READ, 0, nullptr, OPEN_EXISTING, NULL, nullptr);
	hMap = CreateFileMapping(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
	MapFileAddr = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);

	GetImageInfo((DWORD)MapFileAddr);



}

CImageInfo::CImageInfo(HANDLE hFile)
{
	this->hFile = nullptr;
	hMap = CreateFileMapping(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
	LPVOID StartAddr = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);

	GetImageInfo((DWORD)StartAddr);

	UnmapViewOfFile(StartAddr);
	CloseHandle(hMap);
}

CImageInfo::~CImageInfo()
{
	delete[] PeSectionHeader;	
	UnmapViewOfFile(MapFileAddr);
	CloseHandle(hMap);
	CloseHandle(hFile);
}


bool CImageInfo::Is32Image() const
{
	return (PeHeader.Characteristics & 0x100) > 0;
}

DWORD CImageInfo::GetNumberOfSections() const
{
	return PeHeader.NumberOfSections;
}

DWORD CImageInfo::GetSubSystem() const
{
	if (Is32Image())
		return OptionalPeHeader32.Subsystem;
	else
		return OptionalPeHeader64.Subsystem;
}

DWORD CImageInfo::GetOptionalHeaderSize() const
{
	return PeHeader.SizeOfOptionalHeader;
}

DWORD CImageInfo::GetDateTimeStamp() const
{
	return PeHeader.TimeDateStamp;
}


DWORD CImageInfo::GetAddressOfEntryPoint() const
{
	if (Is32Image())
		return OptionalPeHeader32.AddressOfEntryPoint;
	else
		return OptionalPeHeader64.AddressOfEntryPoint;
}

DWORD64 CImageInfo::GetImageBase() const
{
	if (Is32Image())
		return OptionalPeHeader32.ImageBase;
	else
		return OptionalPeHeader64.ImageBase;
}

DWORD CImageInfo::GetImageSize() const
{
	if (Is32Image())
		return OptionalPeHeader32.SizeOfImage;
	else
		return OptionalPeHeader64.SizeOfImage;
}

DWORD CImageInfo::GetNumOfRVA() const
{
	
		if (Is32Image())
			return OptionalPeHeader32.NumberOfRvaAndSizes;
		else
			return OptionalPeHeader64.NumberOfRvaAndSizes;
	return 0;
}

DWORD CImageInfo::GetBaseOfCode() const
{
	if (Is32Image())
		return OptionalPeHeader32.BaseOfCode;
	else
		return OptionalPeHeader64.BaseOfCode;
}

DWORD CImageInfo::GetBaseOfCodeInFile() const
{
	return PeSectionHeader->PointerToRawData;
}

DWORD CImageInfo::GetSizeOfCode() const
{
	if (Is32Image())
		return OptionalPeHeader32.SizeOfCode;
	else
		return OptionalPeHeader64.SizeOfCode;
}

DWORD CImageInfo::GetBaseOfData() const
{
	if (Is32Image())
		return OptionalPeHeader32.BaseOfData;
	else
		return OptionalPeHeader64.BaseOfData;
}

DWORD CImageInfo::GetSizeOfHeaders() const
{
	if (Is32Image())
		return OptionalPeHeader32.SizeOfHeaders;
	else
		return OptionalPeHeader64.SizeOfHeaders;
}

DWORD CImageInfo::GetMemSizeOfCode() const
{
	return PeSectionHeader->VirtualSize;
}

DWORD CImageInfo::GetMemorySize() const
{
	//获取内存页大小
	SYSTEM_INFO si = { 0 };
	GetSystemInfo(&si);
	DWORD MemorySize = 1; //PE头在段中没有体现  在内存中占用一个页面
	for (int i = 0; i < PeHeader.NumberOfSections; i++)
	{
		int Tmp = (PeSectionHeader + i)->VirtualSize%si.dwPageSize;
		MemorySize += int((PeSectionHeader + i)->VirtualSize / si.dwPageSize);
		if (Tmp)
			MemorySize++;
	}
	return MemorySize * si.dwPageSize;
}

DWORD CImageInfo::GetCheckSum() const
{
	if (Is32Image())
		return OptionalPeHeader32.CheckSum;
	else
		return OptionalPeHeader64.CheckSum;
}

DWORD CImageInfo::GetAlignmentOfBlock() const
{
	if (Is32Image())
		return OptionalPeHeader32.SectionAlignment;
	else
		return OptionalPeHeader64.SectionAlignment;
}

DWORD CImageInfo::GetAlignmentOfFile() const
{
	if (Is32Image())
		return OptionalPeHeader32.FileAlignment;
	else
		return OptionalPeHeader64.FileAlignment;
}

DWORD CImageInfo::GetMachine() const
{
	return PeHeader.machine;
}

PVOID CImageInfo::GetMapFileAddr() const
{
	return MapFileAddr;
}

DWORD CImageInfo::GetCharacteritic() const
{
	return PeHeader.Characteristics;
}

DWORD CImageInfo::VoaToFoa(DWORD Voa) const
{
	//判断 Voa c处于哪个段上面
	int i = GetNumberOfSections() - 1;
	for (; i>-1  ; i--)
	{
		PE_SECTION_HEADER* TmpHeader = (PeSectionHeader + i);
		if (Voa > TmpHeader->VirtualAddress || Voa== TmpHeader->VirtualAddress)
		{
			//TODO 理论上，段序号和地址是递增关系的，所以可以这样写。那存不存在段的序号和地址关系是乱序的呢？
			DWORD aa= (Voa - TmpHeader->VirtualAddress) + TmpHeader->PointerToRawData;
			return aa;
		}
	}
	return 0;
}

DWORD CImageInfo::GetImportTable(char** FuncName,char** DllName,int Flag) const
//0 重头开始遍历 1 继续上一次遍历
{
	static int Num = 0;
	if (Flag == 0) Num = 0;
	DWORD ImpTblFileOffset = VoaToFoa(DataDirectory[1].VirtualAddress);
	if (ImpTblFileOffset)
	{
		IMPORT_DIRECTORT_TABLE* TblAddr = (IMPORT_DIRECTORT_TABLE*)((DWORD)MapFileAddr + ImpTblFileOffset)+Num;

		if (TblAddr->ForwarderChain == 0
			&& TblAddr->ImportAdressTableRVA == 0
			&& TblAddr->ImportLookUpTableRVA == 0
			&& TblAddr->NameRVA == 0
			&& TblAddr->TimeDateStamp == 0)
		{
			return false;
		}
		else
		{
			//根据序号查找
			//ImportDirTable->ImportLookUpTableRVA = TblAddr->ImportLookUpTableRVA;
			//ImportDirTable->ForwarderChain = TblAddr->ForwarderChain;
			//根据名称查找
			DWORD TmpNameAddr = VoaToFoa(TblAddr->ImportAdressTableRVA) + (DWORD)MapFileAddr;  //函数名称总表 pecoff 44
			int FuncNum = 0; //函数总个数
			int NameLen = 0; //名称总长度
			while (*((DWORD*)TmpNameAddr + FuncNum))
			{
				DWORD TmpAddr= VoaToFoa(*(DWORD*)TmpNameAddr) + (DWORD)MapFileAddr;
				NameLen = NameLen + strlen((char*)TmpAddr + 2) + 1; //补上最后一个名称的长度
				FuncNum++;
			}		

			
			*FuncName = (char*)malloc(NameLen);
			memcpy(*FuncName, (char*)TmpNameAddr, NameLen);
			
			//返回dll名称
			TmpNameAddr = VoaToFoa(TblAddr->NameRVA) + (DWORD)MapFileAddr;
			strcpy(*DllName, (char*)TmpNameAddr);
			Num++;
			return FuncNum;
		}
	}
	return 0;
}

DATA_DIRECTORY * CImageInfo::GetDataDirectory()
{
	return DataDirectory;
}

DWORD CImageInfo::GetNumOfSections() const
{
	return PeHeader.NumberOfSections;
}

PE_SECTION_HEADER * CImageInfo::GetSectionHeader() const
{
	return PeSectionHeader;
}

pe_header * CImageInfo::GetPeHeader()
{
	return &PeHeader;
}

bool CImageInfo::GetImageInfo(DWORD PeAddr)
{
	//读取peheader
	DWORD Tmp = PeAddr;
	DWORD32 PeHeaderPoint = *(DWORD32*)(Tmp + 0x3c);

	Tmp = Tmp + PeHeaderPoint;
	memcpy(&PeHeader, LPVOID(Tmp), sizeof(PeHeader));

	Tmp = Tmp + sizeof(PeHeader);
	if (PeHeader.Characteristics & 0x100)//区分32位还是64位程序
	{
		ZeroMemory(&OptionalPeHeader32, sizeof(OptionalPeHeader32));
		memcpy(&OptionalPeHeader32, (LPVOID)Tmp, sizeof(OptionalPeHeader32));
		Tmp = Tmp + sizeof(OptionalPeHeader32);
		OptionalPeHeader.Magic=                        OptionalPeHeader32.Magic;
		OptionalPeHeader.MajorLinkerVersion=			  OptionalPeHeader32.MajorLinkerVersion;
		OptionalPeHeader.MinorLinkerVersion=			  OptionalPeHeader32.MinorLinkerVersion;
		OptionalPeHeader.SizeOfCode=					  OptionalPeHeader32.SizeOfCode;
		OptionalPeHeader.SizeOfInitializedData=		  OptionalPeHeader32.SizeOfInitializedData;
		OptionalPeHeader.SizeOfUninitializedData=	  OptionalPeHeader32.SizeOfUninitializedData;
		OptionalPeHeader.AddressOfEntryPoint=		  OptionalPeHeader32.AddressOfEntryPoint;
		OptionalPeHeader.BaseOfCode=					  OptionalPeHeader32.BaseOfCode;
		OptionalPeHeader.BaseOfData=					  OptionalPeHeader32.BaseOfData;
		OptionalPeHeader.ImageBase=					  OptionalPeHeader32.ImageBase;
		OptionalPeHeader.SectionAlignment=			  OptionalPeHeader32.SectionAlignment;
		OptionalPeHeader.FileAlignment=				  OptionalPeHeader32.FileAlignment;
		OptionalPeHeader.MajorOperatingSystemVersion=  OptionalPeHeader32.MajorOperatingSystemVersion;
		OptionalPeHeader.MinorOperatingSystemVersion=  OptionalPeHeader32.MinorOperatingSystemVersion;
		OptionalPeHeader.MajorImageVersion=			  OptionalPeHeader32.MajorImageVersion;
		OptionalPeHeader.MinorImageVersion=			  OptionalPeHeader32.MinorImageVersion;
		OptionalPeHeader.MajorSubsystemVersion=		  OptionalPeHeader32.MajorSubsystemVersion;
		OptionalPeHeader.MinorSubsystemVersion=		  OptionalPeHeader32.MinorSubsystemVersion;
		OptionalPeHeader.Win32VersionValue=			  OptionalPeHeader32.Win32VersionValue;
		OptionalPeHeader.SizeOfImage=				  OptionalPeHeader32.SizeOfImage;
		OptionalPeHeader.SizeOfHeaders=				  OptionalPeHeader32.SizeOfHeaders;
		OptionalPeHeader.CheckSum=					  OptionalPeHeader32.CheckSum;
		OptionalPeHeader.Subsystem=					  OptionalPeHeader32.Subsystem;
		OptionalPeHeader.DllCharacteristics=			  OptionalPeHeader32.DllCharacteristics;
		OptionalPeHeader.SizeOfStackReserve=			  OptionalPeHeader32.SizeOfStackReserve;
		OptionalPeHeader.SizeOfStackCommit=			  OptionalPeHeader32.SizeOfStackCommit;
		OptionalPeHeader.SizeOfHeapReserve=			  OptionalPeHeader32.SizeOfHeapReserve;
		OptionalPeHeader.SizeOfHeapCommit=			  OptionalPeHeader32.SizeOfHeapCommit;
		OptionalPeHeader.LoaderFlags=				  OptionalPeHeader32.LoaderFlags;
		OptionalPeHeader.NumberOfRvaAndSizes=		  OptionalPeHeader32.NumberOfRvaAndSizes;
	}
	else
	{
		ZeroMemory(&OptionalPeHeader64, sizeof(OptionalPeHeader64));
		memcpy(&OptionalPeHeader64, (LPVOID)Tmp, sizeof(OptionalPeHeader64));
		memcpy(&OptionalPeHeader, &OptionalPeHeader64, sizeof(OptionalPeHeader64));
		Tmp = Tmp + sizeof(OptionalPeHeader64);
	}

	//读取数据目录
	memcpy(&DataDirectory, (LPVOID)Tmp, sizeof(DATA_DIRECTORY)*DD_MAX_DIRECTORY_NAME_VALUE);
	Tmp = Tmp + sizeof(DATA_DIRECTORY)*(DD_MAX_DIRECTORY_NAME_VALUE+1);
	Tmp= Tmp + sizeof(DWORD) * 2;

	//读取区段
	//PeSectionHeader = (PE_SECTION_HEADER*)malloc(sizeof(PE_SECTION_HEADER)*PeHeader.NumberOfSections);
	PeSectionHeader = new PE_SECTION_HEADER[PeHeader.NumberOfSections];
	memcpy(PeSectionHeader, (LPVOID)Tmp, sizeof(PE_SECTION_HEADER)*PeHeader.NumberOfSections);

	return true;

}

optional_pe_header_64 * CImageInfo::GetOptionalHeader()
{
	return &OptionalPeHeader;
}
