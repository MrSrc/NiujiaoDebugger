#pragma once
/*
定义PE文件格式结构，参考pecoff_81.pdf
*/
#include <Windows.h>

typedef struct pe_header
{
	BYTE PE[4];
	unsigned short machine;
	unsigned short NumberOfSections;
	DWORD32  TimeDateStamp;
	DWORD32 PointerToSymbolTable;
	DWORD32 NumberOfSymbols;
	unsigned short SizeOfOptionalHeader;
	unsigned short Characteristics;
}PE_HEADER;
typedef struct optional_pe_header_32
{
	unsigned short Magic;
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD32 SizeOfCode;
	DWORD32 SizeOfInitializedData;
	DWORD32 SizeOfUninitializedData;
	DWORD32 AddressOfEntryPoint;
	DWORD32 BaseOfCode;
	DWORD32 BaseOfData;
	DWORD32 ImageBase;
	DWORD32 SectionAlignment;
	DWORD32 FileAlignment;
	unsigned short MajorOperatingSystemVersion;
	unsigned short MinorOperatingSystemVersion;
	unsigned short MajorImageVersion;
	unsigned short MinorImageVersion;
	unsigned short MajorSubsystemVersion;
	unsigned short MinorSubsystemVersion;
	DWORD32 Win32VersionValue;
	DWORD32 SizeOfImage;
	DWORD32 SizeOfHeaders;
	DWORD32 CheckSum;
	unsigned short Subsystem;
	unsigned short DllCharacteristics;
	DWORD32 SizeOfStackReserve;
	DWORD32 SizeOfStackCommit;
	DWORD32 SizeOfHeapReserve;
	DWORD32 SizeOfHeapCommit;
	DWORD32 LoaderFlags;
	DWORD32 NumberOfRvaAndSizes;
}OPTIONAL_PE_HEADER_32;
typedef struct optional_pe_header_64
{
	unsigned short Magic;
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD32 SizeOfCode;
	DWORD32 SizeOfInitializedData;
	DWORD32 SizeOfUninitializedData;
	DWORD32 AddressOfEntryPoint;
	DWORD32 BaseOfCode;
	DWORD32 BaseOfData;
	DWORD64 ImageBase;
	DWORD32 SectionAlignment;
	DWORD32 FileAlignment;
	unsigned short MajorOperatingSystemVersion;
	unsigned short MinorOperatingSystemVersion;
	unsigned short MajorImageVersion;
	unsigned short MinorImageVersion;
	unsigned short MajorSubsystemVersion;
	unsigned short MinorSubsystemVersion;
	DWORD32 Win32VersionValue;
	DWORD32 SizeOfImage;
	DWORD32 SizeOfHeaders;
	DWORD32 CheckSum;
	unsigned short Subsystem;
	unsigned short DllCharacteristics;
	DWORD64 SizeOfStackReserve;
	DWORD64 SizeOfStackCommit;
	DWORD64 SizeOfHeapReserve;
	DWORD64 SizeOfHeapCommit;
	DWORD32 LoaderFlags;
	DWORD32 NumberOfRvaAndSizes;
}OPTIONAL_PE_HEADER_64;


typedef struct data_directory
{
	DWORD VirtualAddress;
	DWORD Size;
}DATA_DIRECTORY;

typedef struct pe_section_header
{
	BYTE Name[8];
	DWORD32 VirtualSize;
	DWORD32 VirtualAddress;
	DWORD32 SizeOfRawData;
	DWORD32 PointerToRawData;
	DWORD32 PointerToRelocations;
	DWORD32 PointerToLinenumbers;
	short NumberOfRelocations;
	short NumberOfLinenumbers;
	DWORD32 Characteristics;
}PE_SECTION_HEADER,*PPE_SECTION_HEADER;


typedef struct hwnd_arr
{
	HWND hWndTab;
	HWND hEnumProcess;
	HWND hDatDirList;
	HWND hSectionList;
	HWND hPeTool;
	HWND hDllNameList;
	HWND hFuncNameList;
	HWND hExportFuncNameList;
	HWND hEnumProcessTree;
}HWND_ARR;

typedef struct import_directory_table
{
	DWORD32 ImportLookUpTableRVA;
	DWORD32 TimeDateStamp;
	DWORD32 ForwarderChain;
	DWORD32 NameRVA;
	DWORD32 ImportAdressTableRVA;
}IMPORT_DIRECTORT_TABLE;

typedef struct import_search_table_32
{

}IMPORT_SEARCH_TABLE_32;
typedef struct export_directory_table
{
	DWORD32 ExportFlags;
	DWORD32 DateTimeStamp;
	short MajorVersion;
	short MinorVersion;
	DWORD32 NameRVA;
	DWORD32 OrdinalBase;
	DWORD32 AdressTableEntries;
	DWORD32 NumbersOfNamePointers;
	DWORD32 ExportAdressTableRVA;
	DWORD32 NamePointerRVA;
	DWORD32 OrdinalTableRVA;
}EXPORT_DIRECTORY_TABLE;

typedef  struct tls_table_32
{
	DWORD32 RawDataStart;
	DWORD32 RawDataEnd;
	DWORD32 AddressOfIndex;
	DWORD32 AddressOfCallback;
	DWORD32 SizeOfZeroFill;
	DWORD32 Characteristics;
}
TLS_TABLE_32;
typedef  struct tls_table_64
{
	DWORD RawDataStart;
	DWORD RawDataEnd;
	DWORD AddressOfIndex;
	DWORD AddressOfCallback;
	DWORD32 SizeOfZeroFill;
	DWORD32 Characteristics;
}
TLS_TABLE_64;
typedef struct point_arr
{
	DWORD FileStart;
	PE_HEADER* PeHeader;
	union {
		OPTIONAL_PE_HEADER_64* OptionPeHeader64;
		OPTIONAL_PE_HEADER_32* OptionPeHeader32;
	};
	DATA_DIRECTORY* PeDataDir;
	PE_SECTION_HEADER* PeSectionHeader;
	IMPORT_DIRECTORT_TABLE* ImportDirectoryTable;
	EXPORT_DIRECTORY_TABLE* ExportDirectoryTable;
	union
	{
		TLS_TABLE_32* TlsTable32;
		TLS_TABLE_64* TlsTable64;
	};
}POINT_ARR;

//分别区分 64位和32位  PE和dll
enum DATA_DIRECTORY_NAME{
	DD_EXPORT_TABLE,
	DD_IMPORT_TABLE,
	DD_RESOURCCE_TABLE,
	DD_EXCEPTION_TABLE,
	DD_ATTR_CERT_TABLE,
	DD_RELOCATION_TABLE,
	DD_DEBUG_INFO_BASE_ADDR,
	DD_GLOBAL_POINTER,
	DD_LOCAL_THREAD_STORAGE,
	DD_LOAD_CONFIG_TABLE,
	DD_BIND_IMPORT_TABLE,
	DD_EXPORT_ADDR_TABLE,
	DD_DELAY_IMPORT_DESCRIPTOR,
	DD_CLR_RUNTIME,
	DD_MAX_DIRECTORY_NAME_VALUE
};

class CImageInfo
{
private:
	pe_header PeHeader;
	optional_pe_header_32 OptionalPeHeader32;
	optional_pe_header_64 OptionalPeHeader64;
	optional_pe_header_64 OptionalPeHeader;
	DATA_DIRECTORY DataDirectory[DD_MAX_DIRECTORY_NAME_VALUE];
	PE_SECTION_HEADER* PeSectionHeader;
	PVOID MapFileAddr;
	HANDLE hFile;
	HANDLE hMap;
	
public :
	bool IsFailed; //处理过程是否出错
	DWORD ErrorNo;

	CImageInfo(DWORD StartAddr);
	CImageInfo(LPCTSTR FileName);
	CImageInfo(HANDLE hFile);
	~CImageInfo();
	bool Is32Image() const;
	DWORD GetNumberOfSections() const;
	DWORD GetSubSystem() const;
	DWORD GetOptionalHeaderSize() const;
	DWORD GetDateTimeStamp() const;
	DWORD GetAddressOfEntryPoint() const;
	DWORD64 GetImageBase() const;
	DWORD GetImageSize() const;
	DWORD GetNumOfRVA() const;
	DWORD GetBaseOfCode() const;
	DWORD GetBaseOfCodeInFile() const;
	DWORD GetSizeOfCode() const;
	DWORD GetBaseOfData() const;
	DWORD GetSizeOfHeaders() const;
	DWORD GetMemSizeOfCode() const;
	DWORD GetMemorySize() const;
	DWORD GetCheckSum() const;
	DWORD GetAlignmentOfBlock() const;
	DWORD GetAlignmentOfFile() const;
	DWORD GetMachine() const;
	PVOID GetMapFileAddr() const;
	DWORD GetCharacteritic() const;
	DWORD VoaToFoa(DWORD Voa) const;
	DWORD GetImportTable(char** FuncName, char** DllName, int Flag) const;
	
	DATA_DIRECTORY*GetDataDirectory();

	DWORD GetNumOfSections() const;
	PE_SECTION_HEADER* GetSectionHeader() const;
	pe_header* GetPeHeader();
	bool GetImageInfo(DWORD);
	optional_pe_header_64* GetOptionalHeader();
};
