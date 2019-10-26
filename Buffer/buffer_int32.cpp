/*****************************************************************************
PURPOSE: 
BUFFER routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "buffer_int32.h"
#include "buffer_template.h"


/*****************************************************************************
/ memory view / public
*****************************************************************************/
int* bufferView_int32(int* block)
{
	return bufferView<int, int>(block);
}


int bufferGetItem_int32(int* block, int index)
{
	return bufferGetItem(block, index);
}


void bufferSetItem_int32(int* block, int index, int item)
{
	return bufferSetItem(block, index, item);
}


int* bufferCopy_int32(int* block, int numel)
{
	return bufferCopy(block, numel);
}

/*
unsigned char* bufferCast_int32_uchar(int* block, int numel)
{
	return bufferCast<int, unsigned char>(block, numel);
}
*/

/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
int* bufferCreate_int32(int numel)
{
	return bufferCreate<int>(numel);
}


void bufferDestroy_int32(int* block)
{
	return bufferDestroy(block);
}