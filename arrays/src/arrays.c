#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count) {
	if(!src || !dst || elem_size == 0 || elem_count == 0) {
		return false;
	}
	memcpy(dst, src, elem_size * elem_count);
	return true;
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count) {
	if(!data_one || !data_two || elem_size == 0 || elem_count == 0) {	
		return false;
	}
	if(memcmp(data_one, data_two, elem_size * elem_count) == 0) {
		return true;
	}
	else {
		return false;
	}
}
// Attempts to locate the target from an array
// \param data the data that may contain the target
// \param target the target that may be in the data
// \param elem_size the number of bytes each array element uses and same as the target
// \param elem_count the number of elements in the data array
// returns an index to the located target, else return -1 for failure
ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) { 
	if(!data || !target || elem_size == 0 || elem_count == 0) {
		return -1;
	}
	int index = 0;
	while(index * elem_size < elem_size * elem_count) { 
		if(memcmp(data, target, elem_size) == 0) {
			return index;
		}
	index++;
	data = (char*)data + elem_size; 
	}
	return -1;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) {
	if(!src_data || !dst_file || elem_size == 0 || elem_count == 0) {
		return false;
	}
	return true;
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) {
	if(!src_file || !dst_data || elem_size == 0 || elem_count == 0) {
                return false;
        }
	FILE *binFile;
	fread(
	return true;
}
