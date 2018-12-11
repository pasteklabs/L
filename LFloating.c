#include "LSigned.h"
#include "LPrimitive.h"

LPrimitive_t LFloating = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(float),
	.name = "Floating"
};

LPrimitive_t LFloating32 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(float),
	.name = "Floating32"
};

LPrimitive_t LFloating64 = {
	._base_LType = { ._vptr = &LPrimitive_LTypeVTable },
	.fixedSize = sizeof(double),
	.name = "Floating64"
};
