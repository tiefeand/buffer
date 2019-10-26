#ifndef EMXARRAY_NDARRAY_UCHAR_H
#define EMXARRAY_NDARRAY_UCHAR_H


#include "emxArrayType.h"


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/
emxArray<unsigned char>* emxArrayView_uchar(emxArray<unsigned char>*);
unsigned char* emxArrayGetData_uchar(emxArray<unsigned char>*);
int emxArrayGetNumDimensions_uchar(emxArray<unsigned char>*);
int* emxArrayGetSize_uchar(emxArray<unsigned char>*);
int emxArrayGetAllocatedSize_uchar(emxArray<unsigned char>*);
emxArray<unsigned char>* emxArrayCopy_uchar(emxArray<unsigned char>*);
//emxArray<int>* emxArrayCast_uchar_int32(emxArray<unsigned char>*);

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
emxArray<unsigned char>* emxArrayCreate_uchar(unsigned char*, int, int*);
void emxArrayDestroy_uchar(emxArray<unsigned char>*);


#endif