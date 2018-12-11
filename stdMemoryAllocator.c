#include <stdlib.h>
#include "stdMemoryAllocator.h"

static void*
_stdMemoryAllocator_allocate ( KMemoryAllocator_t* instance, unsigned long size ) {
	return malloc(size);
}

static void
_stdMemoryAllocator_deallocate ( KMemoryAllocator_t* instance, void* p ) {
	free(p);
}

static KMemoryAllocatorVTable_t _stdMemoryAllocator_KMemoryAllocatorVTable = {
	.allocate = _stdMemoryAllocator_allocate,
	.deallocate = _stdMemoryAllocator_deallocate
};

static stdMemoryAllocator_t _stdMemoryAllocator_instance = {
	._base_KMemoryAllocator = { ._vptr = &_stdMemoryAllocator_KMemoryAllocatorVTable }
};

KMemoryAllocator_t* KMemoryAllocator_instance = &_stdMemoryAllocator_instance._base_KMemoryAllocator;
