#ifndef __L_LINKEDLIST__
#define __L_LINKEDLIST__

#include "LCollection.h"
#include "LIterable.h"
#include "LClass.h"
#include "LLinkedListNode.h"

typedef struct _LLinkedList_t {
	LCollection_t _base_LCollection;
	LIterable_t _base_LIterable;
	LLinkedListNode_t* firstNode;
	LLinkedListNode_t* lastNode;
} LLinkedList_t;

extern LClass_t LLinkedList;
extern LCollectionVTable_t LLinkedList_LCollectionVTable;
extern LIterableVTable_t LLinkedList_LIterableVTable;

#endif
