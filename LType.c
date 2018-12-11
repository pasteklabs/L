#include "LType.h"
#include "LClass.h"
#include "LLinkedList.h"

static LLinkedList_t _LType_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = 0
};

LClass_t LType = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LType_t),
	.name = "Type",
	.constructor = 0,
	.destructor = 0,
	.bases = &_LType_bases._base_LIterable
};
