#ifndef __std_MEMORYALLOCATOR__
#define __std_MEMORYALLOCATOR__

#include "KMemoryAllocator.h"

typedef struct _stdMemoryAllocator_t {
	KMemoryAllocator_t _base_KMemoryAllocator;
} stdMemoryAllocator_t;

extern LClass_t stdMemoryAllocator;

#endif
