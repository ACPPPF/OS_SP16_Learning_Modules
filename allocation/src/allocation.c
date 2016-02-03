#include "../include/allocation.h"

void* allocate_array(size_t member_size, size_t nmember,bool clear) {
	if(member_size == 0 || nmember == 0) {
		return NULL;
	}
	void* array = NULL;
	if(clear == 1) {
		array = calloc(nmember, member_size);
	} else if(clear == 0) {
		array = malloc(nmember * member_size);
		if(array == NULL) {
			return NULL;
		}
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
	void** temp = ptr;
	int counter = 0;
	while(temp[counter + 1]) {
		counter++;
	}
	for(int index = 0; index < counter; ++index) {
		if(ptr[index] != NULL) {
			free(ptr[index]);
			ptr[index] = NULL;
		}
	}
}

char* read_line_to_buffer(char* filename) {
	return NULL;
}
