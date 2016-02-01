#include "../include/allocation.h"

void* allocate_array(size_t member_size, size_t nmember,bool clear)
{
<<<<<<< HEAD
	if(member_size < 0 || nmember < 0) {
		return NULL;
	}
	void* array = NULL;
	if(clear == 1) {
		array = calloc(nmember, member_size);
	} else if(clear == 0) {
		array = malloc(nmember * member_size);
	}
	return array;
=======
	return NULL;
>>>>>>> 7c5715c1507b617c9a9ed11c5f2e3a9293dcdf35
}

void* reallocate_array(void* ptr, size_t size)
{
	return NULL;
}

void deallocate_array(void** ptr)
{

}

char* read_line_to_buffer(char* filename)
{
	return NULL;
}
