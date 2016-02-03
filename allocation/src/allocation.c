#include "../include/allocation.h"
#include <stdint.h>

void* allocate_array(size_t member_size, size_t nmember,bool clear) {
	if((signed int)member_size <= 0 || (signed int)nmember <= 0) {
		return NULL;
	}
	if((short)member_size < 0 || (short)nmember < 0) {
		return NULL;
	}
	void* array = NULL;
	if(clear == 1) {
		array = calloc(nmember, member_size);
		if(array == NULL) {
			return NULL;
		}
	} else if(clear == 0) {
		array = malloc(nmember * member_size);
		if(array == NULL) {
			return NULL;
		}
	}
	return array;
}

void* reallocate_array(void* ptr, size_t size) {
	if((signed int)size <= 0) {
		return NULL;
	} else if(!ptr) {
		ptr = malloc(size);
	} else {
		ptr = realloc(ptr, size);
	}
	if(ptr == NULL) {
		return NULL;
	}
	return ptr;
}

void deallocate_array(void** ptr) {
	if(!ptr) {
		return;
	}
	free(*ptr);
	*ptr = NULL;
}

/// Takes a file name and reads a line into a newly allocated buffer
/// \param char* - filename to read from
/// \return char* - Pointer to malloced heap space containing buffer
char* read_line_to_buffer(char* filename) {
	if(!filename) {
		return NULL;
	}
	FILE *fp;
	size_t size;
	char* buffer;
	
	fp = fopen(filename, "rb");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if(fp == NULL) {
		return NULL;
	}
	buffer = (char *)malloc(size + 1);
	fread(buffer, sizeof(char), size, fp);
	fclose(fp);
	buffer[size] = 0;
	return buffer;
}
