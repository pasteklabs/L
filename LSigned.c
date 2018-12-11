#include "LSigned.h"
#include "LPrimitive.h"

LPrimitive_t LSigned = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(int),
	.name = "Signed"
};

LPrimitive_t LSigned8 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(char),
	.name = "Signed8"
};

LPrimitive_t LSigned16 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(short),
	.name = "Signed16"
};

LPrimitive_t LSigned32 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(int),
	.name = "Signed32"
};

LPrimitive_t LSigned64 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(long),
	.name = "Signed64"
};
