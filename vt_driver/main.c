/*
VT虚拟化驱动的实现
*/
#include "main.h"
#include "VmCheck.h"

#ifdef _WIN64
#include "../intel64/intel64.h"
#ifdef _DEBUG
#pragma comment(lib,"..\\x64\\Debug\\intel64.lib")
#else
#pragma comment(lib,"..\\x64\\Release\\intel64.lib")
#endif
#else
#include "../intel32/intel32.h"
#pragma comment(lib,"..\\Release\\intel32.lib")
#endif

EXTERN_C NTSTATUS CreateDevice(IN PDRIVER_OBJECT pDriverObject)
{
	NTSTATUS status;
	PDEVICE_OBJECT pDevObj;
	PDEVICE_EXTENSION pDevExt;

	UNICODE_STRING devName;
	RtlInitUnicodeString(&devName, L"\\Device\\VtDriver");

	status = IoCreateDevice(pDriverObject, sizeof(DEVICE_EXTENSION), &devName, FILE_DEVICE_UNKNOWN, 0, TRUE, &pDevObj);
	if (!NT_SUCCESS(status)) return status;

	pDevObj->Flags |= DO_BUFFERED_IO;
	pDevExt = (PDEVICE_EXTENSION)pDevObj->DeviceExtension;
	pDevExt->pDevice = pDevObj;
	pDevExt->ustrDeviceName = devName;
	UNICODE_STRING SymLinkName;
	RtlInitUnicodeString(&SymLinkName, L"\\??\\VtDriver");
	pDevExt->ustrSymLinkName = SymLinkName;
	status = IoCreateSymbolicLink(&SymLinkName, &devName);
	if (!NT_SUCCESS(status))
	{
		IoDeleteDevice(pDevObj);
		return status;
	}
	return STATUS_SUCCESS;
}
void VtDriverUnload(IN PDRIVER_OBJECT pDriverObject)
{
	if (pDriverObject == NULL) return;
	PDEVICE_OBJECT pNextObj;
	pNextObj = pDriverObject->DeviceObject;
	while (pNextObj != NULL)
	{
		PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pNextObj->DeviceExtension;
		UNICODE_STRING pLinkName = pDevExt->ustrSymLinkName;
		IoDeleteSymbolicLink(&pLinkName);
		pNextObj = pNextObj->NextDevice;
		if (pDevExt->pDevice != NULL)
		{
			IoDeleteDevice(pDevExt->pDevice);			
		}
		int aa = 0;
		aa = 1;
	}
}

NTSTATUS testDispatchRoutine(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp)
{
	UNREFERENCED_PARAMETER(pDevObj);
	NTSTATUS status = STATUS_SUCCESS;
	pIrp->IoStatus.Status = status;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);

	return status;
}

 NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObject, IN PUNICODE_STRING pRegistryPath)
{
	UNREFERENCED_PARAMETER(pRegistryPath);
	NTSTATUS status;
	DbgPrint(("Entry DriverEntry\n!"));

	pDriverObject->DriverUnload = VtDriverUnload;
	pDriverObject->MajorFunction[IRP_MJ_CREATE] = testDispatchRoutine;
	pDriverObject->MajorFunction[IRP_MJ_CLOSE] = testDispatchRoutine;
	pDriverObject->MajorFunction[IRP_MJ_READ] = testDispatchRoutine;
	pDriverObject->MajorFunction[IRP_MJ_WRITE] = testDispatchRoutine;


	status = CreateDevice(pDriverObject);

	StartVmm();
	DbgPrint(("DriverEntry End!\n"));
	return status;
}
