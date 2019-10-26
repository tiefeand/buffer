#ifndef EMXARRAY_NDARRAY_DBL_H
#define EMXARRAY_NDARRAY_DBL_H


#include "emxArrayType.h"


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/
emxArray<double>* emxArrayView_dbl(emxArray<double>*);
double* emxArrayGetData_dbl(emxArray<double>*);
int emxArrayGetNumDimensions_dbl(emxArray<double>*);
int* emxArrayGetSize_dbl(emxArray<double>*);
int emxArrayGetAllocatedSize_dbl(emxArray<double>*);
emxArray<double>* emxArrayCopy_dbl(emxArray<double>*);
//emxArray<unsigned char>* emxArrayCast_dbl_uchar(emxArray<double>*);

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
emxArray<double>* emxArrayCreate_dbl(double*, int, int*);
void emxArrayDestroy_dbl(emxArray<double>*);


#endif