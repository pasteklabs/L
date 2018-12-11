#ifndef __L_LL_VCALL__
#define __L_LL_VCALL__

#define __vcall(p, m, ...) \
	((void*(*)()) (p)->_vptr->m)(p, ##__VA_ARGS__)

#endif
