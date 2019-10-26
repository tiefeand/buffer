/*****************************************************************************
PURPOSE: 
EMXARRAY routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "emxArray_uchar.h"
#include "emxArray_template.h"
#include "emxArrayType.h"


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/

emxArray<unsigned char>* emxArrayView_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayView<unsigned char>(ndarr);
}


unsigned char* emxArrayGetData_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayGetData(ndarr);
}


int emxArrayGetNumDimensions_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayGetNumDimensions(ndarr);
}


int* emxArrayGetSize_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayGetSize(ndarr);
}


int emxArrayGetAllocatedSize_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayGetAllocatedSize(ndarr);
}


emxArray<unsigned char>* emxArrayCopy_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayCopy(ndarr);
}

/*
emxArray<int>* emxArrayCast_uchar_int32(emxArray<unsigned char>* ndarr)
{
	return emxArrayCast<unsigned char, int>(ndarr);
}
*/

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
emxArray<unsigned char>* emxArrayCreate_uchar(unsigned char* data, int numDimensions, int* size)
{
	return emxArrayCreate(data, numDimensions, size);
}


void emxArrayDestroy_uchar(emxArray<unsigned char>* ndarr)
{
	return emxArrayDestroy(ndarr);
}
