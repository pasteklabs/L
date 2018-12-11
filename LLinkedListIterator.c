#include "LLinkedList.h"
#include "LLinkedListIterator.h"
#include "ll/direct_cast.h"

static void*
_LLinkedListIterator_get ( LIterator_t* instance ) {
	LLinkedListIterator_t* this = __direct_downcast(LIterator, LLinkedListIterator, instance);
	if ( !this->node )
		return 0;
	return this->node->data;
}

static int
_LLinkedListIterator_next ( LIterator_t* instance ) {
	LLinkedListIterator_t* this = __direct_downcast(LIterator, LLinkedListIterator, instance);
	if ( this->node ) {
		this->node = this->node->next;
		return 1;
	}
	return 0;
}

static int
_LLinkedListIterator_equals ( LIterator_t* _this, LIterator_t* _other ) {
	if ( _other->_vptr != &LLinkedListIterator_LIteratorVTable )
		return 0;
	LLinkedListIterator_t* this = __direct_downcast(LIterator, LLinkedListIterator, _this);
	LLinkedListIterator_t* other = __direct_downcast(LIterator, LLinkedListIterator, _other);
	return this->node == other->node;
}

LIteratorVTable_t LLinkedListIterator_LIteratorVTable = {
	.get = _LLinkedListIterator_get,
	.next = _LLinkedListIterator_next,
	.equals = _LLinkedListIterator_equals
};

static void
_LLinkedListIterator_constructor (LLinkedListIterator_t* this, void* data) {
	this->_base_LIterator._vptr = &LLinkedListIterator_LIteratorVTable;
	this->node = (LLinkedListNode_t*) data;
}

static void
_LLinkedListIterator_destructor (LLinkedListIterator_t* this) { }

static LLinkedListNode_t _LLinkedListIterator_bases_0 = {
	.next = 0,
	.data = &LIterator
};

static LLinkedList_t _LLinkedListIterator_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = &_LLinkedListIterator_bases_0
};

LClass_t LLinkedListIterator = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LLinkedListIterator_t),
	.name = "LinkedListIterator",
	.constructor = (LClassConstructor_t) _LLinkedListIterator_constructor,
	.destructor = (LClassDestructor_t) _LLinkedListIterator_destructor,
	.bases = &_LLinkedListIterator_bases._base_LIterable
};
