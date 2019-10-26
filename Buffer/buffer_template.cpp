/*****************************************************************************
PURPOSE: 
BUFFER routines
defines the templates

@author Andreas Tiefenauer
*****************************************************************************/


#include <cstdlib>		// calloc, malloc
//#include <algorithm>    // std::copy
#include <cstring>
#include <iostream>		// std::cout
#include <fstream>		// std::ofstream
//#include <iterator>


//using namespace stdext; //checked_array_iterator


/*****************************************************************************
/ memory view / private
*****************************************************************************/
/*
template<typename ELEMENTTYPE>
ELEMENTTYPE* qsReference(ELEMENTTYPE* original, ELEMENTTYPE* destination)
{
	original = destination;
	//*original = destination; // if ELEMENTTYPE** original
}
*/

template<typename ELEMENTTYPE>
void bufferToItem(ELEMENTTYPE** pblock, int index, ELEMENTTYPE* item)
// assign pointer to an item
// (make address available outside the function by pointing to the pointer)
{
	(*pblock)[index] = *item;
}


/*****************************************************************************
/ memory view / public
*****************************************************************************/
//template<typename DESTINATIONTYPE, typename ELEMENTTYPE>
//DESTINATIONTYPE* bufferView(ELEMENTTYPE* block)
//// returns a new pointer that is assigned to memory block 'block'
//// view an existing memory block interpreted as a potential different data type
//// without making a copy of the memory
//{
//	DESTINATIONTYPE* view;
//	bufferToNull(&view);
//	view = static_cast<DESTINATIONTYPE*>(block); // cast with compile time check
//	//view = (DESTINATIONTYPE*)block; // naive cast without check
//	return view;
//}

template<typename DESTINATIONTYPE, typename ELEMENTTYPE>
DESTINATIONTYPE* bufferView(ELEMENTTYPE* block)
{
	return block;
}


template<typename ELEMENTTYPE>
ELEMENTTYPE bufferDereference(ELEMENTTYPE* block)
// savely accesses element of memory block 'ref'
{
	if (block != (ELEMENTTYPE*)NULL) {
		return *block;
	}
	else {
		return NULL;
	}
}


template<typename ELEMENTTYPE>
ELEMENTTYPE bufferGetItem(ELEMENTTYPE* block, int index)
// accesses element of memory block 'block'
{
	return block[index];
}


template<typename ELEMENTTYPE>
void bufferSetItem(ELEMENTTYPE* block, int index, ELEMENTTYPE item)
// sets element of memory block 'block'
{
	return bufferToItem(&block, index, &item);
}


template<typename ELEMENTTYPE>
void bufferToNull(ELEMENTTYPE** pblock)
// assign pointer to NULL
// (make address available outside the function by pointing to the pointer)
{
	*pblock = (ELEMENTTYPE*)NULL;
}


template<typename ELEMENTTYPE>
ELEMENTTYPE* bufferCopy(ELEMENTTYPE* block, int numel)
// returns a copy of the memory block 'block' 
{
	ELEMENTTYPE* newblock;
	bufferMalloc(&newblock, numel);
	//std::copy(block, block+numel, checked_array_iterator<ELEMENTTYPE*>(newblock, numel));
	//// no need for checked_array_iterator if using <vector>
	memcpy(newblock, block, numel*sizeof(ELEMENTTYPE));
	return newblock;
}


template<typename ELEMENTTYPE>
void bufferPrint(ELEMENTTYPE* block, int numel)
// print object to terminal
{
	int* view = bufferView<int, ELEMENTTYPE>(block);
	std::cout << std::endl;
	int ii;
	for (ii = 0; ii < numel; ii++) {
		std::cout << " " << *(view + ii);
	}
}


template<typename ELEMENTTYPE>
void bufferWrite2File(ELEMENTTYPE* block, int numel, const char* filename)
// write object to file
{
	std::ofstream testfile;
	testfile.open(filename);
	int ii;
	for (ii = 0; ii < numel; ii++) {
		testfile << std::endl << *(block + ii);
	}
	testfile.close();
}


/*****************************************************************************
/ dynamical memory / private 
*****************************************************************************/
template<typename ELEMENTTYPE>
void bufferMalloc(ELEMENTTYPE** pblock, int numel)
// assign pointer to allocated memory 
// (make address available outside the function by pointing to the pointer)
{
	*pblock = (ELEMENTTYPE*)malloc(numel*sizeof(ELEMENTTYPE));
}


template<typename ELEMENTTYPE>
void bufferFree(ELEMENTTYPE** pblock)
// free memory to which pointed to and assigne pointer to NULL
// (make address available outside the function by pointing to the pointer)
{
	if (*pblock != (ELEMENTTYPE*)NULL) {
		free((void *)*pblock);
		bufferToNull(pblock);
	}
}


/*****************************************************************************
/ dynamical memory / public
*****************************************************************************/
template<typename ELEMENTTYPE>
ELEMENTTYPE* bufferNew(int numel)
// returns a new uninitalized block of memory
{
	ELEMENTTYPE* block;
	bufferToNull(&block);
	bufferMalloc(&block, numel);
	return block;
}


template<typename ELEMENTTYPE>
ELEMENTTYPE* bufferCreate(int numel)
// returns a new uninitalized block of memory
{
	ELEMENTTYPE* block = bufferNew<ELEMENTTYPE>(numel);
	return block;
}


template<typename ELEMENTTYPE>
void bufferDestroy(ELEMENTTYPE* block)
// destroys and cleans up memory to which pointed to 
{
	bufferFree(&block);
}




