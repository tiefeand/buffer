/*****************************************************************************
PURPOSE: 
BUFFER routines
implements exportable wrappers for type specialised templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "buffer.h"

#include "buffer_dbl.h"
#include "buffer_int32.h"
#include "buffer_uchar.h"


double* testGetPtr_dbl()
{
	double aa = 99;
	int numel = 1;
	double* bb = (double*)malloc(numel*sizeof(double));
	bb[0] = aa;
	return bb;
}
