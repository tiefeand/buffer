/*****************************************************************************
PURPOSE: 
BUFFER routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "buffer_dbl.h"
#include "buffer_template.h"


/*****************************************************************************
/ memory view / public
*****************************************************************************/
double* bufferView_dbl(double* block)
{
	return bufferView<double, double>(block);
}


double bufferGetItem_dbl(double* block, int index)
{
	return bufferGetItem(block, index);
}


void bufferSetItem_dbl(double* block, int index, double item)
{
	return bufferSetItem(block, index, item);
}


double* bufferCopy_dbl(double* block, int numel)
{
	return bufferCopy(block, numel);
}

/*
int* bufferCast_dbl_int32(double* block, int numel)
{
	return bufferCast<double, int>(block, numel);
}
*/

/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
double* bufferCreate_dbl(int numel)
{
	return bufferCreate<double>(numel);
}


void bufferDestroy_dbl(double* block)
{
	return bufferDestroy(block);
}