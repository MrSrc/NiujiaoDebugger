#pragma once
/*
定义 python 下的PE文件的相关结构
*/
#include "python.h"
#include "structmember.h"
#include "DbgEngine/ImageInfo.h"
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
	PyObject* PESign;
	USHORT Machine;
	USHORT NumberOfSections;
	DWORD32  TimeDateStamp;
	DWORD32 PointerToSymbolTable;
	DWORD32 NumberOfSymbols;
	USHORT SizeOfOptionalHeader;
	USHORT Characteristics;
} PEHeader;
PyObject * PEHeader_new(PyTypeObject * type, PyObject * args, PyObject * kwds);

Py_ssize_t PEHeader_length(PEHeader *mp);
PyObject * PEHeader_subscript(PEHeader *mp, PyObject *key);
static PyMappingMethods PEHeader_as_mapping = {
	(lenfunc)PEHeader_length, /*mp_length*/
	(binaryfunc)PEHeader_subscript, /*mp_subscript*/
	NULL
	//(objobjargproc)PEHeader_ass_sub, /*mp_ass_subscript*/
};
static PyMemberDef PEHeader_members[] = {
	{"PESign", T_OBJECT_EX, offsetof(PEHeader, PESign), 0,"PE signature : MZP"},
	{"Machine", T_USHORT, offsetof(PEHeader, Machine), 0,""},
	{"NumberOfSections", T_USHORT, offsetof(PEHeader, NumberOfSections), 0,""},
	{"TimeDateStamp", T_UINT, offsetof(PEHeader, TimeDateStamp), 0,""},
	{"PointerToSymbolTable", T_UINT, offsetof(PEHeader, PointerToSymbolTable), 0,""},
	{"NumberOfSymbols", T_UINT, offsetof(PEHeader, NumberOfSymbols), 0,""},
	{"SizeOfOptionalHeader", T_USHORT, offsetof(PEHeader, SizeOfOptionalHeader), 0,""},
	{"Characteristics", T_USHORT, offsetof(PEHeader, Characteristics), 0,""},
	{NULL}  /* Sentinel */
};

static PyTypeObject PEHeaderType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PEHeader",
	sizeof(PEHeader),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,                                  /* tp_repr */
	0,                                  /* tp_as_number */
	0,                                  /* tp_as_sequence */
	&PEHeader_as_mapping,               /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                                  /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,                                  /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT ,                /* tp_flags */
	"PE Header",                        /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0,                                  /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                                  /* tp_iter */
	0,                                  /* tp_iternext */
	0,                                  /* tp_methods */
	PEHeader_members,                   /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,                        /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PEHeader_new,                       /* tp_new */
	PyObject_Del,                       /* tp_free */
};

typedef struct {
	PyObject_HEAD
	/* Type-specific fields go here. */
	USHORT Magic;
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD32 SizeOfCode;
	DWORD32 SizeOfInitializedData;
	DWORD32 SizeOfUninitializedData;
	DWORD32 AddressOfEntryPoint;
	DWORD32 BaseOfCode;
	DWORD32 BaseOfData;
	ULONG ImageBase;
	DWORD32 SectionAlignment;
	DWORD32 FileAlignment;
	USHORT MajorOperatingSystemVersion;
	USHORT MinorOperatingSystemVersion;
	USHORT MajorImageVersion;
	USHORT MinorImageVersion;
	USHORT MajorSubsystemVersion;
	USHORT MinorSubsystemVersion;
	DWORD32 Win32VersionValue;
	DWORD32 SizeOfImage;
	DWORD32 SizeOfHeaders;
	DWORD32 CheckSum;
	USHORT Subsystem;
	USHORT DllCharacteristics;
	ULONG SizeOfStackReserve;
	ULONG SizeOfStackCommit;
	ULONG SizeOfHeapReserve;
	ULONG SizeOfHeapCommit;
	DWORD32 LoaderFlags;
	DWORD32 NumberOfRvaAndSizes;
} PEOptionalHeader;
PyObject * PEOptionalHeader_new(PyTypeObject * type, PyObject * args, PyObject * kwds);

PyObject * PEOptionalHeader_subscript(PEOptionalHeader *mp, PyObject *key);
static PyMappingMethods PEOptionalHeader_as_mapping = {
	NULL, /*mp_length*/
	(binaryfunc)PEOptionalHeader_subscript, /*mp_subscript*/
	NULL
	//(objobjargproc)PEHeader_ass_sub, /*mp_ass_subscript*/
};
static PyMemberDef PEOptionalHeader_members[] = {
	{"Magic", T_USHORT, offsetof(PEOptionalHeader, Magic), 0,""},
	{"MajorLinkerVersion", T_BYTE, offsetof(PEOptionalHeader, MajorLinkerVersion), 0,""},
	{"MinorLinkerVersion", T_BYTE, offsetof(PEOptionalHeader, MinorLinkerVersion), 0,""},
	{"SizeOfCode", T_UINT, offsetof(PEOptionalHeader, SizeOfCode), 0,""},
	{"SizeOfInitializedData", T_UINT, offsetof(PEOptionalHeader, SizeOfInitializedData), 0,""},
	{"SizeOfUninitializedData", T_UINT, offsetof(PEOptionalHeader, SizeOfUninitializedData), 0,""},
	{"AddressOfEntryPoint", T_UINT, offsetof(PEOptionalHeader, AddressOfEntryPoint), 0,""},
	{"BaseOfCode", T_UINT, offsetof(PEOptionalHeader, BaseOfCode), 0,""},
	{"BaseOfData", T_UINT, offsetof(PEOptionalHeader, BaseOfData), 0,""},
	{"ImageBase", T_ULONG, offsetof(PEOptionalHeader, ImageBase), 0,""},
	{"SectionAlignment", T_UINT, offsetof(PEOptionalHeader, SectionAlignment), 0,""},
	{"FileAlignment", T_UINT, offsetof(PEOptionalHeader, FileAlignment), 0,""},
	{"MajorOperatingSystemVersion", T_USHORT, offsetof(PEOptionalHeader, MajorOperatingSystemVersion), 0,""},
	{"MinorOperatingSystemVersion", T_USHORT, offsetof(PEOptionalHeader, MinorOperatingSystemVersion), 0,""},
	{"MajorImageVersion", T_USHORT, offsetof(PEOptionalHeader, MajorImageVersion), 0,""},
	{"MinorImageVersion", T_USHORT, offsetof(PEOptionalHeader, MinorImageVersion), 0,""},
	{"MajorSubsystemVersion", T_USHORT, offsetof(PEOptionalHeader, MajorSubsystemVersion), 0,""},
	{"MinorSubsystemVersion", T_USHORT, offsetof(PEOptionalHeader, MinorSubsystemVersion), 0,""},
	{"Win32VersionValue", T_UINT, offsetof(PEOptionalHeader, Win32VersionValue), 0,""},
	{"SizeOfImage", T_UINT, offsetof(PEOptionalHeader, SizeOfImage), 0,""},
	{"SizeOfHeaders", T_UINT, offsetof(PEOptionalHeader, SizeOfHeaders), 0,""},
	{"CheckSum", T_UINT, offsetof(PEOptionalHeader, CheckSum), 0,""},
	{"Subsystem", T_USHORT, offsetof(PEOptionalHeader, Subsystem), 0,""},
	{"DllCharacteristics", T_USHORT, offsetof(PEOptionalHeader, DllCharacteristics), 0,""},
	{"SizeOfStackReserve", T_ULONG, offsetof(PEOptionalHeader, SizeOfStackReserve), 0,""},
	{"SizeOfStackCommit", T_ULONG, offsetof(PEOptionalHeader, SizeOfStackCommit), 0,""},
	{"SizeOfHeapReserve", T_ULONG, offsetof(PEOptionalHeader, SizeOfHeapReserve), 0,""},
	{"SizeOfHeapCommit", T_ULONG, offsetof(PEOptionalHeader, SizeOfHeapCommit), 0,""},
	{"LoaderFlags", T_UINT, offsetof(PEOptionalHeader, LoaderFlags), 0,""},
	{"NumberOfRvaAndSizes", T_UINT, offsetof(PEOptionalHeader, NumberOfRvaAndSizes), 0,""},
	{NULL}  /* Sentinel */
};

static PyTypeObject PEOptionalHeaderType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PEOptionalHeader",
	sizeof(PEOptionalHeader),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,           /* tp_repr */
	0,               /* tp_as_number */
	0,             /* tp_as_sequence */
	&PEOptionalHeader_as_mapping,              /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                      /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,               /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT , /* tp_flags */
	"PE OptionalHeader",                      /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0, /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                     /* tp_iter */
	0,                                  /* tp_iternext */
	0,                  /* tp_methods */
	PEOptionalHeader_members,                                  /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,           /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PEOptionalHeader_new,                  /* tp_new */
	PyObject_Del,                       /* tp_free */
};
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
} PEDataDir;

static PyTypeObject PEDataDirType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PEDataDir",
	sizeof(PEDataDir),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,           /* tp_repr */
	0,               /* tp_as_number */
	0,             /* tp_as_sequence */
	0,              /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                      /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,               /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT , /* tp_flags */
	"PE DataDir",                      /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0, /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                     /* tp_iter */
	0,                                  /* tp_iternext */
	0,                  /* tp_methods */
	0,                                  /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,           /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PyType_GenericNew,                  /* tp_new */
	PyObject_Del,                       /* tp_free */
};
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
} PESectionHeader;

static PyTypeObject PESectionHeaderType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PESectionHeader",
	sizeof(PESectionHeader),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,           /* tp_repr */
	0,               /* tp_as_number */
	0,             /* tp_as_sequence */
	0,              /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                      /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,               /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT , /* tp_flags */
	"PE SectionHeader",                      /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0, /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                     /* tp_iter */
	0,                                  /* tp_iternext */
	0,                  /* tp_methods */
	0,                                  /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,           /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PyType_GenericNew,                  /* tp_new */
	PyObject_Del,                       /* tp_free */
};
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
} PEImportTable;
static PyTypeObject PEImportTableType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PEImportTabler",
	sizeof(PEImportTable),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,           /* tp_repr */
	0,               /* tp_as_number */
	0,             /* tp_as_sequence */
	0,              /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                      /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,               /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT , /* tp_flags */
	"PE ImportTable",                      /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0, /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                     /* tp_iter */
	0,                                  /* tp_iternext */
	0,                  /* tp_methods */
	0,                                  /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,           /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PyType_GenericNew,                  /* tp_new */
	PyObject_Del,                       /* tp_free */
};
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
} PEExportTable;
static PyTypeObject PEExportTableType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PEExportTable",
	sizeof(PEExportTable),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,           /* tp_repr */
	0,               /* tp_as_number */
	0,             /* tp_as_sequence */
	0,              /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                      /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,               /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT , /* tp_flags */
	"PE ExportTable",                      /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0, /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                     /* tp_iter */
	0,                                  /* tp_iternext */
	0,                  /* tp_methods */
	0,                                  /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,           /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PyType_GenericNew,                  /* tp_new */
	PyObject_Del,                       /* tp_free */
};
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
		PEHeader* PeHeader;
	PEOptionalHeader* PeOptionalHeader;
	PEDataDir* PeDataDir;
	PESectionHeader* PeSectionHeader;
	PEImportTable* PeImportTable;
	PEExportTable* PeExportTable;
} PEFormat;
static PyMemberDef PEFormat_members[] = {
	{"PeHeader", T_OBJECT_EX, offsetof(PEFormat, PeHeader), 0,"PE Header"},
	{"PeOptionalHeader", T_OBJECT_EX, offsetof(PEFormat, PeOptionalHeader), 0,"PE Optional Header"},
	{"PeDataDir", T_OBJECT_EX, offsetof(PEFormat, PeDataDir), 0,"PE Data Dirtory"},
	{"PeSectionHeader", T_OBJECT_EX, offsetof(PEFormat, PeSectionHeader), 0,"PE Section Header"},
	{"PeImportTable", T_OBJECT_EX, offsetof(PEFormat, PeImportTable), 0,"PE Import Table"},
	{"PeExportTable", T_OBJECT_EX, offsetof(PEFormat, PeExportTable), 0,"PE Export Table"},
	{NULL}  /* Sentinel */
};


PyObject * PEFormat_new(PyTypeObject * type, PyObject * args, PyObject * kwds);
static PyTypeObject PEFormatType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"PEFormat",
	sizeof(PEFormat),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,           /* tp_repr */
	0,               /* tp_as_number */
	0,             /* tp_as_sequence */
	0,              /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                      /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,               /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT , /* tp_flags */
	"PE format",                      /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0, /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                     /* tp_iter */
	0,                                  /* tp_iternext */
	0,                  /* tp_methods */
	PEFormat_members,                                  /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,           /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	PEFormat_new,                  /* tp_new */
	PyObject_Del,                       /* tp_free */
};