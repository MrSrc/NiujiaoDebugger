#pragma once
/*
定义 python 下的 NiuJiao 模块的相关处理函数
*/
#include "PeObj.h"
#include "AsmObj.h"

static PyObject * niujiao_readpe(PyObject * self, PyObject * args);
static PyObject * niujiao_asmfromstr(PyObject * self, PyObject * args);

PyMODINIT_FUNC PyInit_niujiao(void);
