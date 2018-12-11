#include "LIterable.h"
#include "LClass.h"
#include "LLinkedList.h"

static LLinkedList_t _LIterable_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = 0
};

LClass_t LIterable = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LIterable_t), /* should be 0 */
	.name = "Iterable",
	.constructor = 0,
	.destructor = 0,
	.bases = &_LIterable_bases._base_LIterable
};
