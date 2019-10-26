/*****************************************************************************
PURPOSE: 
EMXARRAY routines
defines the templates

@author Andreas Tiefenauer
*****************************************************************************/


#include "emxArrayType.h"
#include "buffer.h"

#include <algorithm>    // std::copy
#include <iostream>		// std::cout
#include <fstream>		// std::ofstream


/*****************************************************************************
/ ndarray view / public
*****************************************************************************/

template<typename DTYPE, typename BLOCKTYPE> // TODO: verify this function to be working
emxArray<DTYPE>* emxArrayView(emxArray<BLOCKTYPE>* ndarr)
// returns a shallow copy of emxArray and reinterprets with different data type
{
	emxArray<DTYPE>* view;
	DTYPE* data = bufferView<DTYPE, BLOCKTYPE>(ndarr->data);
	view = emxArrayCreate(data, ndarr->numDimensions, ndarr->size);
	return view;
}


template<typename BLOCKTYPE>
BLOCKTYPE* emxArrayGetData(emxArray<BLOCKTYPE>* ndarr)
// accesses attribute of emxArray object
{
	return ndarr->data;
}


template<typename BLOCKTYPE>
int emxArrayGetNumDimensions(emxArray<BLOCKTYPE>* ndarr)
// accesses attribute of emxArray object
{
	return ndarr->numDimensions;
}


template<typename BLOCKTYPE>
int* emxArrayGetSize(emxArray<BLOCKTYPE>* ndarr)
// accesses attribute of emxArray object
{
	return ndarr->size;
}


template<typename BLOCKTYPE>
int emxArrayGetAllocatedSize(emxArray<BLOCKTYPE>* ndarr)
// accesses attribute of emxArray object
{
	return ndarr->allocatedSize;
}


template<typename BLOCKTYPE>
emxArray<BLOCKTYPE>* emxArrayCopy(emxArray<BLOCKTYPE>* ndarr)
// returns a deep copy of emxArray (copy on memory)
{
	emxArray<BLOCKTYPE>* newarray;
	BLOCKTYPE* data = bufferCopy<BLOCKTYPE>(ndarr->data, ndarr->allocatedSize);
	newarray = emxArrayCreate(data, ndarr->numDimensions, ndarr->size);
	return newarray;
}


template<typename BLOCKTYPE>
void emxArrayPrint(emxArray<BLOCKTYPE>* ndarr)
// print emxArray object to terminal
{
	std::cout << std::endl;
	std::cout << std::endl << "allocated size:" << ndarr->allocatedSize;
	std::cout << std::endl << "num dimensions:" << ndarr->numDimensions;
	std::cout << std::endl << "size:          ";
	bufferPrint(ndarr->size, ndarr->numDimensions);
	std::cout << std::endl << "can free data :" << ndarr->canFreeData;
	std::cout << std::endl << "data:          ";
	bufferPrint(ndarr->data, ndarr->allocatedSize);
}


template<typename BLOCKTYPE>
void emxArrayWrite2File(emxArray<BLOCKTYPE>* ndarr, const char* filename)
// write emxArray object to file
{
	std::ofstream testfile;
	testfile.open(filename);
	testfile << std::endl << ndarr->allocatedSize;
	testfile << std::endl << ndarr->numDimensions;
	int ii;
	for (ii = 0; ii < ndarr->allocatedSize; ii++) {
		testfile << std::endl << *(ndarr->data + ii);
	}
	testfile.close();
}


/*****************************************************************************
/ ndarray / private
*****************************************************************************/
template<typename BLOCKTYPE> 
void emxArrayAlloc(emxArray<BLOCKTYPE>** pndarr, int numDimensions)
	// allocates memory for the emxArray object
{
	bufferMalloc(pndarr, 1);
	bufferToNull<BLOCKTYPE>(&(*pndarr)->data);
	(*pndarr)->numDimensions = numDimensions;
	bufferMalloc<int>(&(*pndarr)->size, numDimensions);
	(*pndarr)->allocatedSize = 0;
	(*pndarr)->canFreeData = true;
}


template<typename BLOCKTYPE>
void emxArrayFree(emxArray<BLOCKTYPE>** pndarr)
	// frees memory for the emxArray object
{
	if (*pndarr != (emxArray<BLOCKTYPE>*)NULL) {
		if ((*pndarr)->canFreeData) {
			bufferFree(&(*pndarr)->data);
		}
		bufferFree(&(*pndarr)->size);
		bufferFree(pndarr);
		bufferToNull(pndarr);
	}
}


/*****************************************************************************
/ ndarray / public
*****************************************************************************/
template<typename BLOCKTYPE> 
emxArray<BLOCKTYPE>* emxArrayNew(int numDimensions)
	// returns a new instance of emxArray none-initialized
{
	emxArray<BLOCKTYPE>* ndarr;
	emxArrayAlloc(&ndarr, numDimensions);
	return ndarr;
}


template<typename BLOCKTYPE> 
void emxArrayInit(emxArray<BLOCKTYPE>* ndarr, BLOCKTYPE* data, int numDimensions, int* size)
	// initializes the new emxArray instance
{
	int numEl = 1;
	int i;
	for (i = 0; i < numDimensions; i++) {
		numEl *= size[i];
		ndarr->size[i] = size[i];
	}
	ndarr->data = data;
	ndarr->numDimensions = numDimensions;
	ndarr->allocatedSize = numEl;
	ndarr->canFreeData = false;
}


template<typename BLOCKTYPE>
emxArray<BLOCKTYPE>* emxArrayCreate(BLOCKTYPE* data, int numDimensions, int* size)
	// returns an newly initialized object of emxArray
{
	emxArray<BLOCKTYPE>* ndarr;
	ndarr = emxArrayNew<BLOCKTYPE>(numDimensions);
	emxArrayInit(ndarr, data, numDimensions, size);
	return ndarr;
}


template<typename BLOCKTYPE>
void emxArrayDestroy(emxArray<BLOCKTYPE>* ndarr)
// destroys and cleans up emxArray object
{
	emxArrayFree(&ndarr);
}
