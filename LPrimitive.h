#ifndef __L_LPRIMITIVE__
#define __L_LPRIMITIVE__

#include "LType_t.h"
#include "LClass.h"

typedef struct _LPrimitive_t {
	LType_t _base_LType;
	unsigned long fixedSize;
	char const* name;
} LPrimitive_t;

extern LTypeVTable_t LPrimitive_LTypeVTable;
extern LClass_t LPrimitive;

#endif
