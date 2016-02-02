#include "../include/allocation.h"

<<<<<<< HEAD
void* allocate_array(size_t member_size, size_t nmember,bool clear)
{
=======
void* allocate_array(size_t member_size, size_t nmember,bool clear) {
	printf("Number of members is %d\n", nmember);
>>>>>>> 8d2e7ef0126274119a9033963a965867b5689514
	if(member_size == 0 || nmember == 0) {
		return NULL;
	}
	void* array = NULL;
	if(clear == 1) {
		array = calloc(nmember, member_size);
	} else if(clear == 0) {
		array = malloc(nmember * member_size);
<<<<<<< HEAD
=======
		if(array == NULL) {
			return NULL;
		}
>>>>>>> 8d2e7ef0126274119a9033963a965867b5689514
	}
	return array;
}

/// Realloc
/// - Does not initialize expanded memory
/// - Original contents remain unchanged
/// - If passed a null pointer then a malloc will occur.
/// - May move memory to a new location

/// Simple wrapper around realloc.
/// \param void* - pointer to memory to resize.
/// \param size_t - size of memory to allocate
/// \return void* - pointer to reallocated memory region, may be same as original pointer.
void* reallocate_array(void* ptr, size_t size) {
	if(size == 0) {
		return NULL;
	} else if(!ptr) {
		ptr = malloc(size);
		return ptr;
	} else {
		return realloc(ptr, size);
	}
}

void deallocate_array(void** ptr) {
	if(!ptr) {
		return;
	}
	int counter = 0;
	while(ptr + 1) {
		if(ptr[counter]) {
			printf("x %s\n", ptr[counter]);
		}
		ptr++;
		counter++;
	}
	free(ptr);
}

char* read_line_to_buffer(char* filename) {
	return NULL;
}
