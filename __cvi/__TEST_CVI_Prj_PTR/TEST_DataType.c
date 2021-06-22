//==============================================================================
//
// Title:		TEST_DataType
// Purpose:		A short description of the library.
//
// Created on:	5/28/2021 at 10:26:56 AM by Tong Li.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <utility.h>
#include "TEST_DataType.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
BOOL getData_Bool (U8Ptr inputs)
{
	BOOL*Ptr = (BOOL*) inputs;
	return *Ptr;
}

unsigned long getData_U32 (U8Ptr inputs)
{
	unsigned long * Ptr = (unsigned long *)inputs;
	
	return *Ptr;
}

int getData_I32 (U8Ptr inputs)
{
	int *Ptr = (int *)inputs; 
	return *Ptr;
}


double getData_DBL (U8Ptr inputs)
{
	double *Ptr = (double*)inputs;
	return *Ptr;
}

int getData_Str (U8Ptr inputs)
{
	char* Str = (char*) inputs;
	return 0;
}

unsigned long getData_Array_DBL (U8Ptr inputs)
{
	NI_Array* Ptr = (NI_Array*) inputs;
	double* pData = (double *) Ptr->Addr;
	return Ptr->Len;
}

unsigned long getData_Array_Str (U8Ptr inputs)
{
	//Array_Str *Ptr = (Array_Str*) inputs;
	NI_Array* Ptr = (NI_Array*) inputs;
	for(int i = 0; i < Ptr->Len; i++){
		char* pData = (char*) (Ptr->Addr + i*MAX_STR_LEN);
	}
	//char* pData = (char *) Ptr->Addr;
	return Ptr->Len;
}

unsigned long getData_Array_Waveform(U8Ptr inputs)
{
	NI_Array* Ptr = (NI_Array*) inputs;
	for(int i = 0; i < Ptr->Len; i++){
		NI_Array* wavPtr = (((NI_Array*) (Ptr->Addr)) + i);
		double* pData = (double*) wavPtr->Addr; 
	}
	return Ptr->Len;
}


int getData_Cluster (U8Ptr inputs)
{
	ClusterType* Ptr = (ClusterType*) inputs;
	double* pData = (double*) Ptr->para_Array.Addr;
	return 0;
}

double getData_TimeStamp (U8Ptr inputs)
{
	double* timeStamp = (double*) inputs;
	return *timeStamp;
}

unsigned long getData_Waveform (U8Ptr inputs)
{
	NI_Array* Ptr = (NI_Array*) inputs;
	double* pData = (double*) Ptr->Addr;
	return Ptr->Len;
}

int getData_Path (U8Ptr inputs)
{
	char *Str = (char*) inputs;
	return 0;
}

//==============================================================================
// DLL main entry-point functions

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			if (InitCVIRTE (hinstDLL, 0, 0) == 0)
				return 0;	  /* out of memory */
			break;
		case DLL_PROCESS_DETACH:
			CloseCVIRTE ();
			break;
	}
	
	return 1;
}
