#ifndef EMXARRAY_NDARRAY_TEMPLATE_H
#define EMXARRAY_NDARRAY_TEMPLATE_H


#include "emxArrayType.h"


/*template declaration*/
/*****************************************************************************
/ ndarray view / public
*****************************************************************************/
template<typename DTYPE, typename BLOCKTYPE> emxArray<DTYPE>* emxArrayView(emxArray<BLOCKTYPE>* ndarr);
template<typename BLOCKTYPE> BLOCKTYPE* emxArrayGetData(emxArray<BLOCKTYPE>*);
template<typename BLOCKTYPE> int emxArrayGetNumDimensions(emxArray<BLOCKTYPE>*);
template<typename BLOCKTYPE> int* emxArrayGetSize(emxArray<BLOCKTYPE>*);
template<typename BLOCKTYPE> int emxArrayGetAllocatedSize(emxArray<BLOCKTYPE>*);
template<typename BLOCKTYPE> emxArray<BLOCKTYPE>* emxArrayCopy(emxArray<BLOCKTYPE>*);
//template<typename BLOCKTYPE, typename DTYPE> emxArray<DTYPE>* emxArrayCast(emxArray<BLOCKTYPE>*);
template<typename BLOCKTYPE> void emxArrayPrint(emxArray<BLOCKTYPE>*);
template<typename BLOCKTYPE> void emxArrayWrite2File(emxArray<BLOCKTYPE>*, const char*);

/*****************************************************************************
/ ndarray / private
*****************************************************************************/
template<typename BLOCKTYPE> void emxArrayAlloc(emxArray<BLOCKTYPE>**, int);
template<typename BLOCKTYPE> void emxArrayFree(emxArray<BLOCKTYPE>**);

/*****************************************************************************
/ ndarray / public
*****************************************************************************/
template<typename BLOCKTYPE> emxArray<BLOCKTYPE>* emxArrayNew(int);
template<typename BLOCKTYPE> void emxArrayInit(emxArray<BLOCKTYPE>*, BLOCKTYPE*, int, int*);
template<typename BLOCKTYPE> emxArray<BLOCKTYPE>* emxArrayCreate(BLOCKTYPE*, int, int*);
template<typename BLOCKTYPE> void emxArrayDestroy(emxArray<BLOCKTYPE>*);

/*template definition*/
#include "emxArray_template.cpp"



#endif