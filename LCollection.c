#include "LCollection.h"
#include "LLinkedList.h"
#include "LIterable.h"

static LLinkedList_t _LCollection_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = 0
};

LClass_t LCollection = {
	.fixedSize = sizeof(LCollection_t),
	.name = "Collection",
	.constructor = 0,
	.destructor = 0,
	.bases = &_LCollection_bases._base_LIterable
};
