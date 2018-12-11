#include "LUnsigned.h"
#include "LPrimitive.h"

LPrimitive_t LUnsigned = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(unsigned int),
	.name = "Unsigned"
};

LPrimitive_t LUnsigned8 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(unsigned char),
	.name = "Unsigned8"
};

LPrimitive_t LUnsigned16 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(unsigned short),
	.name = "Unsigned16"
};

LPrimitive_t LUnsigned32 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(unsigned int),
	.name = "Unsigned32"
};

LPrimitive_t LUnsigned64 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(unsigned long),
	.name = "Unsigned64"
};
