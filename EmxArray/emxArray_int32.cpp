/*****************************************************************************
PURPOSE: 
EMXARRAY routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "emxArray_int32.h"
#include "emxArray_template.h"
#include "emxArrayType.h"


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/

emxArray<int>* emxArrayView_int32(emxArray<int>* ndarr)
{
	return emxArrayView<int>(ndarr);
}


int* emxArrayGetData_int32(emxArray<int>* ndarr)
{
	return emxArrayGetData(ndarr);
}


int emxArrayGetNumDimensions_int32(emxArray<int>* ndarr)
{
	return emxArrayGetNumDimensions(ndarr);
}


int* emxArrayGetSize_int32(emxArray<int>* ndarr)
{
	return emxArrayGetSize(ndarr);
}


int emxArrayGetAllocatedSize_int32(emxArray<int>* ndarr)
{
	return emxArrayGetAllocatedSize(ndarr);
}


emxArray<int>* emxArrayCopy_int32(emxArray<int>* ndarr)
{
	return emxArrayCopy(ndarr);
}

/*
emxArray<unsigned char>* emxArrayCast_int32_uchar(emxArray<int>* ndarr)
{
return emxArrayCast<int, unsigned char>(ndarr);
}
*/

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
emxArray<int>* emxArrayCreate_int32(int* data, int numDimensions, int* size)
{
	return emxArrayCreate(data, numDimensions, size);
}


void emxArrayDestroy_int32(emxArray<int>* ndarr)
{
	return emxArrayDestroy(ndarr);
}


