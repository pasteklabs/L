#include "LClass.h"
#include "LBuildContext.h"
#include "LType_t.h"
#include "LType.h"
#include "LIterator.h"
#include "LLinkedList.h"
#include "LLinkedListNode.h"
#include "ll/direct_cast.h"
#include "ll/unused.h"
#include "ll/vcall.h"

static unsigned long
_LClass_size ( LType_t* _this ) {
	LClass_t* this = __direct_downcast(LType, LClass, _this);
	return this->fixedSize;
}

static void
_LClass_stackAllocate ( LType_t* _this, LBuildContext_t* buildContext ) {
	__unused(_this);
	__unused(buildContext);
}

static void
_LClass_stackDeallocate ( LType_t* _this, LBuildContext_t* buildContext ) {
	__unused(_this);
	__unused(buildContext);
}

static void
_LClass_construct ( LType_t* _this, void* object, void* parameters ) {
	LClass_t* this = __direct_downcast(LType, LClass, _this);
	if (this->constructor)
		this->constructor(object, parameters);
}

static void
_LClass_destruct ( LType_t* _this, void* object ) {
	LClass_t* this = __direct_downcast(LType, LClass, _this);
	if (this->destructor)
		this->destructor(object);
}

static void
_LClass_constructor ( LClass_t* this, void* parameters ) { }

static void
_LClass_destructor ( LClass_t* this ) { }

static LLinkedListNode_t _LClass_bases_0 = {
	.next = 0,
	.data = &LType
};

static LLinkedList_t _LClass_bases = {
	._base_LCollection = { ._vptr = &LLinkedList_LCollectionVTable },
	._base_LIterable = { ._vptr = &LLinkedList_LIterableVTable },
	.firstNode = &_LClass_bases_0
};

LTypeVTable_t LClass_LTypeVTable = {
	.size = _LClass_size,
	.stackAllocate = _LClass_stackAllocate,
	.stackDeallocate = _LClass_stackDeallocate,
	.construct = _LClass_construct,
	.destruct = _LClass_destruct
};

LClass_t LClass = {
	._base_LType = { ._vptr = &LClass_LTypeVTable },
	.fixedSize = sizeof(LClass_t),
	.name = "Class",
	.constructor = (LClassConstructor_t) _LClass_constructor,
	.destructor = (LClassDestructor_t) _LClass_destructor,
	.bases = &_LClass_bases._base_LIterable
};
