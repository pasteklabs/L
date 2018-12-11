#include "Ldelete.h"
#include "KMemoryAllocator.h"
#include "ll/vcall.h"

void
Ldelete ( LType_t* type, void* object ) {
	KMemoryAllocator_t* ma = KMemoryAllocator_instance;
	__vcall(ma, deallocate, object);
}
