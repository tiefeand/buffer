#ifndef EMXARRAY_NDARRAY_INT32_H
#define EMXARRAY_NDARRAY_INT32_H


#include "emxArrayType.h"


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/
emxArray<int>* emxArrayView_int32(emxArray<int>*);
int* emxArrayGetData_int32(emxArray<int>*);
int emxArrayGetNumDimensions_int32(emxArray<int>*);
int* emxArrayGetSize_int32(emxArray<int>*);
int emxArrayGetAllocatedSize_int32(emxArray<int>*);
emxArray<int>* emxArrayCopy_int32(emxArray<int>*);
//emxArray<unsigned char>* emxArrayCast_int32_uchar(emxArray<int>*);

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
emxArray<int>* emxArrayCreate_int32(int*, int, int*);
void emxArrayDestroy_int32(emxArray<int>*);


#endif