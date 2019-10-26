/*****************************************************************************
PURPOSE: 
BUFFER routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "buffer_uchar.h"
#include "buffer_template.h"


/*****************************************************************************
/ memory view / public
*****************************************************************************/
unsigned char* bufferView_uchar(unsigned char* block)
{
	return bufferView<unsigned char, unsigned char>(block);
}


unsigned char bufferGetItem_uchar(unsigned char* block, int index)
{
	return bufferGetItem(block, index);
}


void bufferSetItem_uchar(unsigned char* block, int index, unsigned char item)
{
	return bufferSetItem(block, index, item);
}


unsigned char* bufferCopy_uchar(unsigned char* block, int numel)
{
	return bufferCopy(block, numel);
}

/*
int* bufferCast_uchar_int32(unsigned char* block, int numel)
{
	return bufferCast<unsigned char, int>(block, numel);
}
*/

/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
void bufferDestroy_uchar(unsigned char* block)
{
	return bufferDestroy(block);
}


unsigned char* bufferCreate_uchar(int numel)
{
	return bufferCreate<unsigned char>(numel);
}

