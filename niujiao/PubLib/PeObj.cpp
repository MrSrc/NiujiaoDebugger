/*
绑定 python 中PE文件格式对象和项目的PE解析结构
*/
#include "stdafx.h"
#include "PeObj.h"
#define NJ_CHECK_PY_OBJECT_NEW(PyObject,Type,TypeObj) if((PyObject = PyObject_New(Type, TypeObj))==NULL)\
													  {\
															Py_DECREF(self);\
															return NULL;\
													  }
PyObject * PEHeader_new(PyTypeObject * type, PyObject * args, PyObject * kwds)
{
	
	PEHeader *self;
	self = (PEHeader *)type->tp_alloc(type, 0);
	if (self != NULL) {
		PE_HEADER* pe_header = nullptr;
		if (args && ((PyTupleObject*)args)->ob_base.ob_size == 1)
		{
			PyArg_ParseTuple(args, "i", &pe_header);
		}
		if(pe_header)
		{
			self->PESign = PyUnicode_FromString((char*)&(pe_header->PE));
			self->Machine = pe_header->machine;
			self->NumberOfSections = pe_header->NumberOfSections;
			self->TimeDateStamp = pe_header->TimeDateStamp;
			self->PointerToSymbolTable = pe_header->PointerToSymbolTable;
			self->NumberOfSymbols = pe_header->NumberOfSymbols;
			self->SizeOfOptionalHeader = pe_header->SizeOfOptionalHeader;
			self->Characteristics = pe_header->Characteristics;
			Py_DECREF(args);
		}
		else
		{
			self->PESign = PyUnicode_FromString("");
			self->Machine = 0;
			self->NumberOfSections = 0;
			self->TimeDateStamp = 0;
			self->PointerToSymbolTable = 0;
			self->NumberOfSymbols = 0;
			self->SizeOfOptionalHeader = 0;
			self->Characteristics = 0;
		}
	}
	return (PyObject *)self;
}

Py_ssize_t PEHeader_length(PEHeader * mp)
{
	return sizeof(PEHeader_members)/sizeof(PyMemberDef)-1;
}

PyObject * PEHeader_subscript(PEHeader * mp, PyObject * key)
{
	char* ttt = (char*)key + sizeof(PyASCIIObject); //TODO 找不到 key 的实际类型   先暂时这样解决
	for (int i = 0; i < (sizeof(PEHeader_members) / sizeof(PyMemberDef) - 1); i++)
	{
		if (strcmp(ttt, PEHeader_members[i].name) == 0)
		{
			switch (PEHeader_members[i].type)
			{
			case T_OBJECT_EX: return (PyObject *)*(int*)((int)mp + PEHeader_members[i].offset);
			case T_USHORT: return PyLong_FromLong(*(USHORT*)((int)mp + PEHeader_members[i].offset));
			case T_UINT: return PyLong_FromLong(*(UINT*)((int)mp + PEHeader_members[i].offset));
			}
		}
	}
	return (PyObject *)&_PyNone_Type;
}

PyObject * PEOptionalHeader_new(PyTypeObject * type, PyObject * args, PyObject * kwds)
{
	PEOptionalHeader *self;
	self = (PEOptionalHeader *)type->tp_alloc(type, 0);
	if (self != NULL) {
		optional_pe_header_64 * pe_optional_header = nullptr;
		int Is32Image = 0;
		if (args && ((PyTupleObject*)args)->ob_base.ob_size == 1)
		{
			PyArg_ParseTuple(args, "i", &pe_optional_header);
		}
		if (pe_optional_header)
		{
			self->Magic=                             pe_optional_header->Magic ;
			self->MajorLinkerVersion = 				 pe_optional_header->MajorLinkerVersion ;
			self->MinorLinkerVersion = 				 pe_optional_header->MinorLinkerVersion ;
			self->SizeOfCode = 						 pe_optional_header->SizeOfCode ;
			self->SizeOfInitializedData = 			 pe_optional_header->SizeOfInitializedData ;
			self->SizeOfUninitializedData = 		 pe_optional_header->SizeOfUninitializedData ;
			self->AddressOfEntryPoint = 			 pe_optional_header->AddressOfEntryPoint ;
			self->BaseOfCode = 						 pe_optional_header->BaseOfCode ;
			self->BaseOfData = 						 pe_optional_header->BaseOfData ;
			self->ImageBase = 						 pe_optional_header->ImageBase ;
			self->SectionAlignment = 			     pe_optional_header->SectionAlignment ;
			self->FileAlignment = 					 pe_optional_header->FileAlignment ;
			self->MajorOperatingSystemVersion = 	 pe_optional_header->MajorOperatingSystemVersion ;
			self->MinorOperatingSystemVersion = 	 pe_optional_header->MinorOperatingSystemVersion ;
			self->MajorImageVersion = 				 pe_optional_header->MajorImageVersion ;
			self->MinorImageVersion = 				 pe_optional_header->MinorImageVersion ;
			self->MajorSubsystemVersion = 			 pe_optional_header->MajorSubsystemVersion ;
			self->MinorSubsystemVersion = 			 pe_optional_header->MinorSubsystemVersion ;
			self->Win32VersionValue = 				 pe_optional_header->Win32VersionValue ;
			self->SizeOfImage = 					 pe_optional_header->SizeOfImage ;
			self->SizeOfHeaders = 					 pe_optional_header->SizeOfHeaders ;
			self->CheckSum = 						 pe_optional_header->CheckSum ;
			self->Subsystem = 						 pe_optional_header->Subsystem ;
			self->DllCharacteristics = 				 pe_optional_header->DllCharacteristics ;
			self->SizeOfStackReserve = 				 pe_optional_header->SizeOfStackReserve ;
			self->SizeOfStackCommit = 				 pe_optional_header->SizeOfStackCommit ;
			self->SizeOfHeapReserve = 				 pe_optional_header->SizeOfHeapReserve ;
			self->SizeOfHeapCommit = 				 pe_optional_header->SizeOfHeapCommit ;
			self->LoaderFlags = 					 pe_optional_header->LoaderFlags ;
			self->NumberOfRvaAndSizes = 			 pe_optional_header->NumberOfRvaAndSizes ;
			Py_DECREF(args);
		}
		else
		{
			self->Magic=0;                        
			self->MajorLinkerVersion=0;
			self->MinorLinkerVersion=0;
			self->SizeOfCode=0;
			self->SizeOfInitializedData=0;
			self->SizeOfUninitializedData=0;
			self->AddressOfEntryPoint=0;
			self->BaseOfCode=0;
			self->BaseOfData=0;
			self->ImageBase=0;
			self->SectionAlignment=0;
			self->FileAlignment=0;
			self->MajorOperatingSystemVersion=0;
			self->MinorOperatingSystemVersion=0;
			self->MajorImageVersion=0;
			self->MinorImageVersion=0;
			self->MajorSubsystemVersion=0;
			self->MinorSubsystemVersion=0;
			self->Win32VersionValue=0;
			self->SizeOfImage=0;
			self->SizeOfHeaders=0;
			self->CheckSum=0;
			self->Subsystem=0;
			self->DllCharacteristics=0;
			self->SizeOfStackReserve=0;
			self->SizeOfStackCommit=0;
			self->SizeOfHeapReserve=0;
			self->SizeOfHeapCommit=0;
			self->LoaderFlags=0;
			self->NumberOfRvaAndSizes=0;
		}
	}
	return (PyObject *)self;
}

PyObject * PEOptionalHeader_subscript(PEOptionalHeader * mp, PyObject * key)
{
	char* ttt = (char*)key + sizeof(PyASCIIObject); //TODO 找不到 key 的实际类型   先暂时这样解决
	for (int i = 0; i < (sizeof(PEOptionalHeader_members) / sizeof(PyMemberDef) - 1); i++)
	{
		if (strcmp(ttt, PEOptionalHeader_members[i].name) == 0)
		{
			switch (PEOptionalHeader_members[i].type)
			{
			case T_USHORT: return PyLong_FromLong(*(USHORT*)((int)mp + PEOptionalHeader_members[i].offset));
			case T_UINT: return PyLong_FromLong(*(UINT*)((int)mp + PEOptionalHeader_members[i].offset));
			case T_BYTE: return PyLong_FromLong(*(BYTE*)((int)mp + PEOptionalHeader_members[i].offset));
			case T_ULONG: return PyLong_FromLong(*(ULONG*)((int)mp + PEOptionalHeader_members[i].offset));
			}
		}
	}
	return (PyObject *)&_PyNone_Type;
}

PyObject * PEFormat_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	PEFormat *self;
	self = (PEFormat *)type->tp_alloc(type, 0);
	if (self != NULL) {
		int ImageInfo = 0;
		int PeHeader = 0;
		int PeOptionalHeader = 0;
		int Is32Image = 1;
		if (args&&((PyTupleObject*)args)->ob_base.ob_size>0)  //允许无参构造
		{
			PyArg_ParseTuple(args, "i", &ImageInfo);
			PeHeader = (int)((CImageInfo*)ImageInfo)->GetPeHeader();
			PeOptionalHeader = (int)((CImageInfo*)ImageInfo)->GetOptionalHeader();
		}
		self->PeHeader = (PEHeader *)PEHeaderType.tp_new(&PEHeaderType, Py_BuildValue("(i)", PeHeader), NULL);
		if (self->PeHeader == NULL)
		{
			Py_DECREF(self);
			return NULL;
		}
		self->PeOptionalHeader = (PEOptionalHeader *)PEOptionalHeaderType.tp_new(&PEOptionalHeaderType, Py_BuildValue("(i)", PeOptionalHeader), NULL);
		if (self->PeHeader == NULL)
		{
			Py_DECREF(self);
			return NULL;
		}
		NJ_CHECK_PY_OBJECT_NEW(self->PeDataDir, PEDataDir, &PEDataDirType)
		NJ_CHECK_PY_OBJECT_NEW(self->PeSectionHeader, PESectionHeader, &PESectionHeaderType)
		NJ_CHECK_PY_OBJECT_NEW(self->PeImportTable, PEImportTable, &PEImportTableType)
		NJ_CHECK_PY_OBJECT_NEW(self->PeExportTable, PEExportTable, &PEExportTableType)
	}		
	if (args)
		Py_DECREF(args);
	return (PyObject *)self;
}