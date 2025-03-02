#include "stdio.h"
#include "stdlib.h" /*malloc();*/

/* deallocator, is a pointer to function that take void pointer as a parameter, returning void */
typedef void(* deallocator)(void *);

struct refcount {int count; deallocator free;};


void * rc_malloc(size_t size, deallocator free) {

	/*
	the addition of + size in the malloc call is necessary
	because the memory allocation needs to include space both metadata (refcount)
	and the actual user data requested by the caller
	*/
	struct refcount * p = (struct refcount *)malloc(sizeof(struct refcount) + size);

	/*suppressed warning about possibility derefenrencing nullptr*/
	if (p) * p = (struct refcount){.count = 1, .free = free};

	/*
	p + 1 increments p by 1 unit of the size of struct refcount,
	effectively moving the pointer past the metadata portion of the memory.
	*/
	return p + 1;

	/*suppressed warning: control reaches end of non-void function [-Wreturn-type] }*/
	return 0;

}


void print_free(void * p) {

	int * ip = p;

	printf("freeing %d\n", * ip);

}


int main() {

	/*
	sizeof(datatype);
	sizeof expression;
 	printf("%ld", sizeof 1);
	*/

	int * p = rc_malloc(sizeof * p, print_free);





}
