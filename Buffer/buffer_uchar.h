#ifndef BUFFER_BLOCK_UCHAR_H
#define BUFFER_BLOCK_UCHAR_H


/*****************************************************************************
/ memory view / public
*****************************************************************************/
unsigned char* bufferView_uchar(unsigned char*);
unsigned char bufferGetItem_uchar(unsigned char* block, int index);
void bufferSetItem_uchar(unsigned char* block, int index, unsigned char item);
unsigned char* bufferCopy_uchar(unsigned char*, int);
//int* bufferCast_uchar_int32(unsigned char*);

/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
//unsigned char qsPtrDeref_uchar(unsigned char*);
void bufferDestroy_uchar(unsigned char*);
unsigned char* bufferCreate_uchar(int);


#endif