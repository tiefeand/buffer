#ifndef EMXARRAY_NDARRAYTYPE_H
#define EMXARRAY_NDARRAYTYPE_H


template <typename BLOCKTYPE> 
struct emxArray // TODO: refacture redundant parts like allocatedSize
{
  BLOCKTYPE* data; // pointer to data block
  int* size; // pointer to size array, one entry per dimension
  int allocatedSize; // the cumprod of size
  int numDimensions; // number of dimensions (length of *size)
  unsigned char canFreeData; 
};



#endif