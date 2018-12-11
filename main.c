#include <stdio.h>
#include "LClass.h"
#include "LType.h"
#include "LLinkedList.h"
#include "LCollection.h"
#include "Lnew.h"
#include "Lcast.h"
#include "ll/vcall.h"

int main () {
	LLinkedList_t* list = (LLinkedList_t*) Lnew(Lcast(&LClass, &LType, &LLinkedList), 0);
	LCollection_t* collection = (LCollection_t*) Lcast(&LLinkedList, &LCollection, list);
	__vcall(collection, add, "hello");
	__vcall(collection, add, "123");
	__vcall(collection, add, "world");
	__vcall(collection, remove, "123");
	LIterable_t* iterable = Lcast(&LLinkedList, &LIterable, list);
	LIterator_t* it = (LIterator_t*) __vcall(iterable, begin);
	LIterator_t* end = (LIterator_t*) __vcall(iterable, end);
	while ( !__vcall(it, equals, end) ) {
		printf("%s\n", (char const*) __vcall(it, get));
		__vcall(it, next);
	}
	printf("%p %p\n", Lcast(&LLinkedList, &LIterable, (void*) 0x1000), (void*) 0x1000);
	
	LType_t* type = (LType_t*) Lcast(&LClass, &LType, &LLinkedList);
	if (!type)
		printf("failed");
	printf("%lu %lu\n", (unsigned long) __vcall(type, size), sizeof(LLinkedList_t));
	LLinkedList_t* list2 = (LLinkedList_t*) Lnew(Lcast(&LClass, &LType, &LLinkedList), 0);
	return 0;
}
