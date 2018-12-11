#ifndef __L_LL_DIRECT_CAST__
#define __L_LL_DIRECT_CAST__

#include "offset_of.h"

#define __direct_downcast(B,D,o) \
	((D##_t*)((void*) o - __offset_of(D##_t, _base_##B)))

#define __direct_upcast(B,D,o) \
	((B##_t*)((void*) o + __offset_of(D##_t, _base_##B)))

#endif
