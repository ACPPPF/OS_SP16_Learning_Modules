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

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) { 
	
	return 0;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) {
	if(!src_data || !dst_file || elem_size == 0 || elem_count == 0) {
		return false;
	}
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) {
	
	return false;
}
