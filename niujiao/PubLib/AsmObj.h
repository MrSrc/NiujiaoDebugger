#pragma once
/*
定义 python 下的 Asm 对象的相关结构
*/
#include "python.h"
#include "structmember.h"
#include "DbgEngine/asm.h"
typedef struct {
	PyObject_HEAD
		/* Type-specific fields go here. */
	PyObject* AsmStr;   //原始字符串 
	PyObject* Result;   //汇编结果
} AsmObject;
PyObject * AsmObject_new(PyTypeObject * type, PyObject * args, PyObject * kwds);

PyObject * AsmObject_subscript(AsmObject *mp, PyObject *key);
static PyMappingMethods AsmObject_as_mapping = {
	NULL, /*mp_length*/
	(binaryfunc)AsmObject_subscript, /*mp_subscript*/
	NULL
	//(objobjargproc)PEHeader_ass_sub, /*mp_ass_subscript*/
};
static PyMemberDef AsmObject_members[] = {
	{"AsmStr", T_OBJECT_EX, offsetof(AsmObject, AsmStr), 0,"original asm string"},
	{"Result", T_OBJECT_EX, offsetof(AsmObject, Result), 0,"assembly result"},
	{NULL}  /* Sentinel */
};

static PyTypeObject AsmObjectType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"AsmObject",
	sizeof(AsmObject),
	0,
	0,                                  /* tp_dealloc */
	0,                                  /* tp_print */
	0,                                  /* tp_getattr */
	0,                                  /* tp_setattr */
	0,                                  /* tp_reserved */
	0,                                  /* tp_repr */
	0,                                  /* tp_as_number */
	0,                                  /* tp_as_sequence */
	&AsmObject_as_mapping,               /* tp_as_mapping */
	0,                                  /* tp_hash */
	0,                                  /* tp_call */
	0,                                  /* tp_str */
	PyObject_GenericGetAttr,            /* tp_getattro */
	0,                                  /* tp_setattro */
	0,                                  /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT ,                /* tp_flags */
	"AsmObject",                        /* tp_doc */
	0,                                  /* tp_traverse */
	0,                                  /* tp_clear */
	0,                                  /* tp_richcompare */
	0,                                  /* tp_weaklistoffset */
	0,                                  /* tp_iter */
	0,                                  /* tp_iternext */
	0,                                  /* tp_methods */
	AsmObject_members,                   /* tp_members */
	0,                                  /* tp_getset */
	0,                                  /* tp_base */
	0,                                  /* tp_dict */
	0,                                  /* tp_descr_get */
	0,                                  /* tp_descr_set */
	0,                                  /* tp_dictoffset */
	(initproc)0,                        /* tp_init */
	PyType_GenericAlloc,                /* tp_alloc */
	AsmObject_new,                       /* tp_new */
	PyObject_Del,                       /* tp_free */
};
