#include "LCString.h"
#include "LPrimitive.h"

LPrimitive_t LCString = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(void*),
	.name = "CString"
};
