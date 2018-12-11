#include "Lnew.h"
#include "KMemoryAllocator.h"
#include "ll/vcall.h"

/* with (type T) */
void* /* T */
Lnew ( LType_t* type /* type T */, void* parameters /* Args... args */ ) {
	/* Kernel::MemoryAllocator ma = Kernel::MemoryAllocator::instance */
	KMemoryAllocator_t* ma = KMemoryAllocator_instance;
	/* Pointer object = ma.allocate(T.size()) */
	unsigned long size = (unsigned long) __vcall(type, size);
	void* object = __vcall(ma, allocate, size);
	/* T.descriptor().construct(p, args...) */
	__vcall(type, construct, object, parameters);
	/* return object */
	return object;
}
