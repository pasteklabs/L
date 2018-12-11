#ifndef __L_LLINKEDLISTITERATOR__
#define __L_LLINKEDLISTITERATOR__

#include "LIterator.h"
#include "LLinkedListNode.h"

typedef struct _LLinkedListIterator_t {
	LIterator_t _base_LIterator;
	LLinkedListNode_t* node;
} LLinkedListIterator_t;

extern LClass_t LLinkedListIterator;
extern LIteratorVTable_t LLinkedListIterator_LIteratorVTable;

#endif
