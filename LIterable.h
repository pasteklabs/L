#ifndef __L_ITERABLE__
#define __L_ITERABLE__

#include "LIterator.h"

struct _LIterable_t;

typedef LIterator_t* (*LIterableVTable_begin_t)( struct _LIterable_t* );
typedef LIterator_t* (*LIterableVTable_end_t)( struct _LIterable_t* );

typedef struct {
	LIterableVTable_begin_t begin;
	LIterableVTable_end_t end;
} LIterableVTable_t;

typedef struct _LIterable_t {
	LIterableVTable_t* _vptr;
} LIterable_t;

extern LClass_t LIterable;

#endif
