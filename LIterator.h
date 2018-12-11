#ifndef __L_LITERATOR__
#define __L_LITERATOR__

#include "LClass.h"

struct _LIterator_t;

typedef void* (*LIterator_get_vptr_t)( struct _LIterator_t* );
typedef int (*LIterator_next_vptr_t)( struct _LIterator_t* );
typedef int (*LIterator_equals_vptr_t)( struct _LIterator_t*, struct _LIterator_t* );

typedef struct {
	LIterator_get_vptr_t get;
	LIterator_next_vptr_t next;
	LIterator_equals_vptr_t equals;
} LIteratorVTable_t;

typedef struct _LIterator_t {
	LIteratorVTable_t* _vptr;
} LIterator_t;

extern LClass_t LIterator;

#endif
