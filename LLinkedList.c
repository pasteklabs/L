#include "LLinkedList.h"
#include "LLinkedListNode.h"
#include "LLinkedListIterator.h"
#include "LType.h"
#include "Lnew.h"
#include "Ldelete.h"
#include "ll/direct_cast.h"
#include "ll/unused.h"

static void
_LLinkedList_add ( LCollection_t* _this, void* item ) {
	LLinkedList_t* this = __direct_downcast(LCollection, LLinkedList, _this);
	LType_t* nodeType = __direct_upcast(LType, LClass, &LLinkedListNode);
	LLinkedListNode_t* node = (LLinkedListNode_t*) Lnew(nodeType, item);
	if ( !this->firstNode )
		this->firstNode = node;
	if ( this->lastNode )
		this->lastNode->next = node;
	node->previous = this->lastNode;
	this->lastNode = node;
}

static void
_LLinkedList_remove ( LCollection_t* _this, void* item ) {
	LLinkedList_t* this = __direct_downcast(LCollection, LLinkedList, _this);
	LLinkedListNode_t* node = this->firstNode;
	while ( node ) {
		if ( node->data == item )
			break;
		node = node->next;
	}
	if ( !node )
		return;
	if ( this->firstNode == node )
		this->firstNode = node->next;
	if ( this->lastNode == node )
		this->lastNode = node->previous;
	if ( node->previous )
		node->previous->next = node->next;
	if ( node->next )
		node->next->previous = node->previous;
	LType_t* nodeType = __direct_upcast(LType, LClass, &LLinkedListNode);
	Ldelete(nodeType, node);
}

static LIterator_t*
_LLinkedList_begin ( LIterable_t* _this ) {
	LLinkedList_t* this = __direct_downcast(LIterable, LLinkedList, _this);
	LType_t* iteratorType = __direct_upcast(LType, LClass, &LLinkedListIterator);
	LLinkedListIterator_t* iterator = Lnew(iteratorType, this->firstNode);
	return __direct_upcast(LIterator, LLinkedListIterator, iterator);
}

static LIterator_t*
_LLinkedList_end ( LIterable_t* _this ) {
	__unused(_this);
	LType_t* iteratorType = __direct_upcast(LType, LClass, &LLinkedListIterator);
	LLinkedListIterator_t* iterator = Lnew(iteratorType, 0);
	return __direct_upcast(LIterator, LLinkedListIterator, iterator);
}


static void
_LLinkedList_constructor ( LLinkedList_t* this ) {
	this->_base_LCollection._vptr = &LLinkedList_LCollectionVTable;
	this->_base_LIterable._vptr = &LLinkedList_LIterableVTable;
	this->firstNode = 0;
}

static void
_LLinkedList_destructor ( LLinkedList_t* this ) {
}

static
LLinkedListNode_t _LLinkedList_bases_1 = {
	.next = 0,
	.data = &LIterable
};

static
LLinkedListNode_t _LLinkedList_bases_0 = {
	.next = &_LLinkedList_bases_1,
	.data = &LCollection
};

static
LLinkedList_t _LLinkedList_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = &_LLinkedList_bases_0
};

LCollectionVTable_t LLinkedList_LCollectionVTable = {
	.add = _LLinkedList_add,
	.remove = _LLinkedList_remove
};

LIterableVTable_t LLinkedList_LIterableVTable = {
	.begin = _LLinkedList_begin,
	.end = _LLinkedList_end
};

LClass_t LLinkedList = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LLinkedList_t),
	.name = "LinkedList",
	.constructor = (LClassConstructor_t) _LLinkedList_constructor,
	.destructor = (LClassDestructor_t) _LLinkedList_destructor,
	.bases = &_LLinkedList_bases._base_LIterable
};
