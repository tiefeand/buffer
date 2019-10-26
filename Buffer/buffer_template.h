#ifndef BUFFER_TEMPLATE_H
#define BUFFER_TEMPLATE_H


/*template declaration*/
/*****************************************************************************
/ memory view / private
*****************************************************************************/
template<typename ELEMENTTYPE> void bufferToItem(ELEMENTTYPE**, int, ELEMENTTYPE*);

/*****************************************************************************
/ memory view / public
*****************************************************************************/
template<typename DESTINATIONTYPE, typename ELEMENTTYPE> DESTINATIONTYPE* bufferView(ELEMENTTYPE*);
template<typename ELEMENTTYPE> ELEMENTTYPE bufferDereference(ELEMENTTYPE* ref);
template<typename ELEMENTTYPE> ELEMENTTYPE bufferGetItem(ELEMENTTYPE*, int);
template<typename ELEMENTTYPE> void bufferSetItem(ELEMENTTYPE*, int, ELEMENTTYPE);
template<typename ELEMENTTYPE> void bufferToNull(ELEMENTTYPE** pref);
template<typename ELEMENTTYPE> ELEMENTTYPE* bufferCopy(ELEMENTTYPE*, int);
template<typename ELEMENTTYPE> void bufferPrint(ELEMENTTYPE*, int);
template<typename ELEMENTTYPE> void bufferWrite2File(ELEMENTTYPE*, int, const char*);

/*****************************************************************************
/ dyn. memory management / private
*****************************************************************************/
template<typename ELEMENTTYPE> void bufferMalloc(ELEMENTTYPE**, int);
template<typename ELEMENTTYPE> void bufferFree(ELEMENTTYPE**);

/*****************************************************************************
/ dyn. memory management / public
*****************************************************************************/
template<typename ELEMENTTYPE> ELEMENTTYPE* bufferNew(int numel);
template<typename ELEMENTTYPE> ELEMENTTYPE* bufferCreate(int);
template<typename ELEMENTTYPE> void bufferDestroy(ELEMENTTYPE*);


/*template definition*/
#include "buffer_template.cpp"


#endif