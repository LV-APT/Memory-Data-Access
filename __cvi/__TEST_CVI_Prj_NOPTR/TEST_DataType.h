//==============================================================================
//
// Title:		TEST_DataType
// Purpose:		A short description of the interface.
//
// Created on:	5/28/2021 at 10:26:56 AM by Tong Li.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

#ifndef __TEST_DataType_H__
#define __TEST_DataType_H__

#pragma pack(1)

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include <stdint.h>		
//==============================================================================
// Constants

#define MAX_STR_LEN 1024
//==============================================================================
// Types
typedef uint8_t* U8Ptr;

typedef struct Array_DBL{
	unsigned long *Len;
	double* pData;
}Array_DBL;

typedef struct Array_Str{
	unsigned long *Len;
	char* pStr;
}Array_Str;


typedef struct ClusterType{
	int *para_I32;
	double *para_DBL;
	char* para_Str;
	double *para_ArrayDBL;
}ClusterType;


//==============================================================================
// External variables

//==============================================================================
// Global functions

BOOL getData_Bool (U8Ptr inputs);
unsigned long getData_U32 (U8Ptr inputs);
int getData_I32 (U8Ptr inputs);
double getData_DBL (U8Ptr inputs);
int getData_Str (U8Ptr inputs);
unsigned long getData_Array_DBL (U8Ptr inputs);
unsigned long getData_Array_Str (U8Ptr inputs);
unsigned long getData_Array_Waveform(U8Ptr inputs);
int getData_Cluster (U8Ptr inputs);
double getData_TimeStamp (U8Ptr inputs);
unsigned long getData_Waveform (U8Ptr inputs);
int getData_Path (U8Ptr inputs);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __TEST_DataType_H__ */
