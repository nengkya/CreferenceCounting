#include "stdio.h"

/* deallocator, is a pointer to function that take void pointer as a parameter, returning void */
typedef void(* deallocator)(void *);

struct refcount {int count; deallocator free;};


void * rc_malloc(size_t size, deallocator free) {






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

	int * p = rc_malloc(size of * p, print_free);





}
