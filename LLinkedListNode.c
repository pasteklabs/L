#include "LLinkedList.h"
#include "LLinkedListNode.h"

static void
_LLinkedListNode_constructor ( LLinkedListNode_t* this, void* parameters ) {
	this->previous = 0;
	this->next = 0;
	this->data = parameters;
}

static void
_LLinkedListNode_destructor ( LLinkedListNode_t* this ) { }

static LLinkedList_t _LLinkedListNode_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = 0
};

LClass_t LLinkedListNode = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LLinkedListNode_t),
	.name = "LinkedListNode",
	.constructor = (LClassConstructor_t) _LLinkedListNode_constructor,
	.destructor = (LClassDestructor_t) _LLinkedListNode_destructor,
	.bases = &_LLinkedListNode_bases._base_LIterable
};
