#ifndef __L_LNEW__
#define __L_LNEW__

#include "LType_t.h"

/* with (type T) */
void* /* T */
Lnew (
	LType_t* type /* type T */,
	void* parameters /* Args... args */
);

#endif
