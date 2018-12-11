#ifndef __L_LTYPE_T__
#define __L_LTYPE_T__

struct _LType_t;
struct _LBuildContext_t;

typedef unsigned long (*LType_size_v)( struct _LType_t* );
typedef void (*LType_stackAllocate_v)( struct _LType_t*, struct _LBuildContext_t* );
typedef void (*LType_stackDeallocate_v)( struct _LType_t*, struct _LBuildContext_t* );
typedef void (*LType_construct_v)( struct _LType_t*, void*, void* );
typedef void (*LType_destruct_v)( struct _LType_t*, void* );

typedef struct {
	LType_size_v size;
	LType_stackAllocate_v stackAllocate;
	LType_stackDeallocate_v stackDeallocate;
	LType_construct_v construct;
	LType_destruct_v destruct;
} LTypeVTable_t;

typedef struct _LType_t {
	LTypeVTable_t* _vptr;
} LType_t;

#endif
