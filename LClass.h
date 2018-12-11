#ifndef __L_LCLASS__
#define __L_LCLASS__

#include "LType_t.h"

struct _LIterable_t;

typedef void (*LClassConstructor_t)( void*, void* );
typedef void (*LClassDestructor_t)( void* );

typedef struct _LClass_t {
	LType_t _base_LType;
	unsigned long fixedSize;
	char const* name;
	LClassConstructor_t constructor;
	LClassDestructor_t destructor;
	struct _LIterable_t* bases;
} LClass_t;

extern LClass_t LClass;
extern LTypeVTable_t LClass_LTypeVTable;

#endif

