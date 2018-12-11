#include "LPointer.h"
#include "LPrimitive.h"

LPrimitive_t LPointer = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(void*),
	.name = "Pointer"
};
