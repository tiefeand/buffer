/*****************************************************************************
PURPOSE: 
EMXARRAY routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "emxArray_dbl.h"
#include "emxArray_template.h"
#include "emxArrayType.h"


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/

emxArray<double>* emxArrayView_dbl(emxArray<double>* ndarr)
{
	return emxArrayView<double>(ndarr);
}


double* emxArrayGetData_dbl(emxArray<double>* ndarr)
{
	return emxArrayGetData(ndarr);
}


int emxArrayGetNumDimensions_dbl(emxArray<double>* ndarr)
{
	return emxArrayGetNumDimensions(ndarr);
}


int* emxArrayGetSize_dbl(emxArray<double>* ndarr)
{
	return emxArrayGetSize(ndarr);
}


int emxArrayGetAllocatedSize_dbl(emxArray<double>* ndarr)
{
	return emxArrayGetAllocatedSize(ndarr);
}


emxArray<double>* emxArrayCopy_dbl(emxArray<double>* ndarr)
{
	return emxArrayCopy(ndarr);
}

/*
emxArray<unsigned char>* emxArrayCast_dbl_uchar(emxArray<double>* ndarr)
{
return emxArrayCast<int, unsigned char>(ndarr);
}
*/

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
emxArray<double>* emxArrayCreate_dbl(double* data, int numDimensions, int* size)
{
	return emxArrayCreate(data, numDimensions, size);
}


void emxArrayDestroy_dbl(emxArray<double>* ndarr)
{
	return emxArrayDestroy(ndarr);
}


