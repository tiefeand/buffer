#ifndef BUFFER_BLOCK_DBL_H
#define BUFFER_BLOCK_DBL_H


/*****************************************************************************
/ memory view / public
*****************************************************************************/
double* bufferView_dbl(double*);
double bufferGetItem_dbl(double* block, int index);
void bufferSetItem_dbl(double* block, int index, double item);
double* bufferCopy_dbl(double*, int);
//int* bufferCast_dbl_int32(double*);

/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
//double qsPtrDeref_dbl(double*);
void bufferDestroy_dbl(double*);
double* bufferCreate_dbl(int);


#endif