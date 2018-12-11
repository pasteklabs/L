#ifndef __L_LCOLLECTION__
#define __L_LCOLLECTION__

#include "LIterator.h"

struct _LCollection_t;

typedef void (*LCollectionVTable_add_t)( struct _LCollection_t*, void* );
typedef void (*LCollectionVTable_remove_t)( struct _LCollection_t*, void* );

typedef struct {
	LCollectionVTable_add_t add;
	LCollectionVTable_remove_t remove;
} LCollectionVTable_t;

typedef struct _LCollection_t {
	LCollectionVTable_t* _vptr;
} LCollection_t;

extern LClass_t LCollection;

#endif
