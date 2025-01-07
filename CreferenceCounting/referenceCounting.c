#include <stddef.h> /*size_t*/

typedef void (* deallocator)(void *);

struct refcount {
	int count;
	deallocator free;
};


/*size_t is an unsigned integer*/
static void * rc_malloc(size_t size, deallocator free) {

	struct refcount * p = malloc(sizeof(struct refcount) + size);

	* p = (struct refcount){ .count = 1, .free = free };

}


static void print_free(void * p) {

}


int main() {

	int * p = rc_malloc(sizeof * p, print_free);

}