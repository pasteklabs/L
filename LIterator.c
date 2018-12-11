#include "LIterator.h"
#include "LClass.h"
#include "LLinkedList.h"

static LLinkedList_t _LIterator_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = 0
};

LClass_t LIterator = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LIterator_t),
	.name = "Iterator",
	.constructor = 0,
	.destructor = 0,
	.bases = &_LIterator_bases._base_LIterable
};
