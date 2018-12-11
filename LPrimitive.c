#include "LPrimitive.h"
#include "LBuildContext.h"
#include "LLinkedList.h"
#include "LType.h"
#include "ll/direct_cast.h"
#include "ll/unused.h"

static unsigned long
_LPrimitive_size ( LType_t* _this ) {
	LPrimitive_t* this = __direct_downcast(LType, LPrimitive, _this);
	return this->fixedSize;
}

static void
_LPrimitive_stackAllocate ( LType_t* _this, LBuildContext_t* buildContext ) {
	__unused(_this);
	__unused(buildContext);
}

static void
_LPrimitive_stackDeallocate ( LType_t* _this, LBuildContext_t* buildContext) {
	__unused(_this);
	__unused(buildContext);
}

static void
_LPrimitive_construct ( LType_t* _this, void* object, void* parameters ) {
	__unused(_this);
	__unused(object);
	__unused(parameters);
}

static void
_LPrimitive_destruct ( LType_t* _this, void* object ) {
	__unused(_this);
	__unused(object);
}

static LLinkedListNode_t _LPrimitive_bases_0 = {
	.next = 0,
	.data = &LType
};

static LLinkedList_t _LPrimitive_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = &_LPrimitive_bases_0
};

LTypeVTable_t LPrimitive_LTypeVTable = {
	.size = _LPrimitive_size,
	.stackAllocate = _LPrimitive_stackAllocate,
	.stackDeallocate = _LPrimitive_stackDeallocate,
	.construct = _LPrimitive_construct,
	.destruct = _LPrimitive_destruct
};

LClass_t LPrimitive = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LPrimitive_t),
	.name = "Primitive",
	.constructor = 0,
	.destructor = 0,
	.bases = &_LPrimitive_bases._base_LIterable
};
