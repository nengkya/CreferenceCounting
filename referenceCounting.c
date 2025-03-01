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
