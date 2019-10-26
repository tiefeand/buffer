#ifndef BUFFER_BLOCK_INT32_H
#define BUFFER_BLOCK_INT32_H


/*****************************************************************************
/ memory view / public
*****************************************************************************/
int* bufferView_int32(int*);
int bufferGetItem_int32(int*, int);
void bufferSetItem_int32(int*, int, int);
int* bufferCopy_int32(int*, int);
//unsigned char* bufferCast_int32_uchar(int*);

/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
//int qsPtrDeref_int32(int*);
void bufferDestroy_int32(int*);
int* bufferCreate_int32(int);


#endif