#ifndef __L_LLINKEDLISTNODE__
#define __L_LLINKEDLISTNODE__

#include "LClass.h"

typedef struct _LLinkedListNode_t {
	struct _LLinkedListNode_t* previous;
	struct _LLinkedListNode_t* next;
	void* data;
} LLinkedListNode_t;

extern LClass_t LLinkedListNode;

#endif
