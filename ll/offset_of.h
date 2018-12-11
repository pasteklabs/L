#ifndef __L_LL_OFFSETOF__
#define __L_LL_OFFSETOF__

#define __offset_of(S,m) \
	((unsigned long) (&((S*) 0)->m))

#endif
