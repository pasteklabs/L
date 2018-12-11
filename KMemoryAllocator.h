#ifndef __K_MEMORYALLOCATOR__
#define __K_MEMORYALLOCATOR__

#include "LClass.h"

struct _KMemoryAllocator_t;

typedef void* (*KMemoryAllocator_allocate_t)( struct _KMemoryAllocator_t*, unsigned long );
typedef void (*KMemoryAllocator_deallocate_t)( struct _KMemoryAllocator_t* this, void* );

typedef struct {
	KMemoryAllocator_allocate_t allocate;
	KMemoryAllocator_deallocate_t deallocate;
} KMemoryAllocatorVTable_t;

typedef struct _KMemoryAllocator_t {
	KMemoryAllocatorVTable_t* _vptr;
} KMemoryAllocator_t;

extern LClass_t KMemoryAllocator;
/*
 * This function must be defined by the default memory allocator
 */
extern KMemoryAllocator_t* KMemoryAllocator_instance;

#endif
