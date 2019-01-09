/*
绑定 python 中NiuJiao模块对象和项目
*/
#include "stdafx.h"
#include "NiujiaoMod.h"
#include "DbgEngine/ImageInfo.h"
#include "DbgEngine/asm.h"

static PyObject *niujiaoError;

static PyMethodDef niujiaoMethods[] = {
	{"readpe",  niujiao_readpe, METH_VARARGS,"read PE file format . input : file path"},
	{"asmfromstr",  niujiao_asmfromstr, METH_VARARGS,"asm from string . input : assembly string"},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef niujiaomodule = {
	PyModuleDef_HEAD_INIT,
	"niujiao",   /* name of module */
	NULL, /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
				 or -1 if the module keeps state in global variables. */
	niujiaoMethods
};

static PyObject *
niujiao_readpe(PyObject *self, PyObject *args)
{
	const char *FileName;
	if (!PyArg_ParseTuple(args, "s", &FileName))
		return NULL;
	TCHAR tFileName[1024] = { 0 };

	MultiByteToWideChar(CP_ACP, 0, FileName, strlen(FileName), tFileName, 32);
	CImageInfo *ImageInfo =new  CImageInfo(tFileName);
	PEFormat* pf = (PEFormat *)PEFormatType.tp_new(&PEFormatType, 
													Py_BuildValue("(i)", (int)ImageInfo) , 
													NULL);
	
	return (PyObject *)pf;
}

PyObject * niujiao_asmfromstr(PyObject * self, PyObject * args)
{
	const char *FileName;
	if (!PyArg_ParseTuple(args, "s", &FileName))
		return NULL;
	TCHAR tFileName[1024] = { 0 };

	MultiByteToWideChar(CP_ACP, 0, FileName, strlen(FileName), tFileName, 32);
	SAsmResultSet AsmResultSet = { 0 };
	CAsm aaa = CAsm();
	if (aaa.AsmFromStr(tFileName, &AsmResultSet) == 0)
	{
		return AsmObjectType.tp_new(&AsmObjectType, 
			Py_BuildValue("(s,i)",(int)FileName,(int)&AsmResultSet),
			NULL);
	}
	else
	{
		return (PyObject *)&_PyNone_Type;;
	}
}

PyMODINIT_FUNC
PyInit_niujiao(void)
{
	PyObject *m;
	if (PyType_Ready(&PEFormatType) < 0)
		return NULL;
	m= PyModule_Create(&niujiaomodule);
	if (m == NULL)
		return NULL;
	Py_INCREF(&PEFormatType);
	PyModule_AddObject(m, "PEFormat", (PyObject *)&PEFormatType);
	return m;
}
