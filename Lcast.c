#include "Lcast.h"
#include "LIterable.h"
#include "LIterator.h"
#include "ll/vcall.h"

static long
_upcast ( LClass_t* input, LClass_t* output ) {
	long n, x = 0;
	LClass_t* base;
	LIterator_t* it = __vcall(input->bases, begin);
	while (( base = (LClass_t*) __vcall(it, get) )) {
		if ( base == output )
			return x;
		if ( (n = _upcast(base, output)) >= 0 )
			return n + x;
		x += base->fixedSize;
		__vcall(it, next);
	}
	return -1;
}

void* /* to */
Lcast ( LClass_t* from, LClass_t* to, void* instance ) {
	long offset = _upcast(from, to);
	if (offset >= 0)
		return instance + offset;
	offset = _upcast(to, from);
	if (offset >= 0)
		return instance - offset;
	return 0;
}
