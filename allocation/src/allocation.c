#include "../include/allocation.h"
#include <stdint.h>

void* allocate_array(size_t member_size, size_t nmember,bool clear) {
	if((signed int)member_size <= 0 || (signed int)nmember <= 0) { //Checks if the signed member_size or signed nmember is less than or equal to zero
		return NULL;
	}
	void* array = NULL; //New array
	if(clear == true) { //If the clear flag is 1
		array = calloc(nmember, member_size); //Clear and allocate the memory
	} else if(clear == false) { //Clear flag is zero
		array = malloc(nmember * member_size); //Malloc the memory
	}
	if(array == NULL) { //Allocation did not work
		return NULL;
	}
	return array;
}

void* reallocate_array(void* ptr, size_t size) {
	if((signed int)size < 0) { //Signed size is less than zero
		return NULL;
	}
	return realloc(ptr, size); //Reallocate the space
}

void deallocate_array(void** ptr) {
	if(!ptr) { //Checks if the pointer is already null
		return;
	}
	free(*ptr); //Free the array
	*ptr = NULL; //Set the pointer to null
}

/// Takes a file name and reads a line into a newly allocated buffer
/// \param char* - filename to read from
/// \return char* - Pointer to malloced heap space containing buffer
char* read_line_to_buffer(char* filename) {
	if(!filename) { //File name is null
		return NULL;
	}
	FILE *fp;
	size_t size;
	char* buffer;
	
	fp = fopen(filename, "rb"); //Opens the file pointer as a read buffer
	fseek(fp, 0, SEEK_END); //Sets the file position indicator of fp to the end
	size = ftell(fp); //Obtains the file position of fp
	fseek(fp, 0, SEEK_SET); //Rewind
	if(fp == NULL) { //Fseek and ftell did not obtain a file position
		return NULL;
	}
	buffer = (char *)malloc(size + 1); //Malloc size for the buffer
	fread(buffer, sizeof(char), size, fp); //Reads size number of bytes from the fp into buffer
	fclose(fp); //Closes the file
	buffer[size] = 0; //Null terminator
	return buffer;
}
