#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
	if(!data || !target || elem_size == 0 || elem_count == 0) {
		return -1;
	}
	int index = 0;
	while(index < elem_count) { 
		if(memcmp(data, target, elem_size) == 0) {
			return index;
		}
		index++;
		data = (char*)data + elem_size; 
	}
	return -1;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) {
	if(!src_data || !dst_file || strlen(dst_file) == 0 || elem_size == 0 || elem_count == 0) {
		return false;
	}
	const char *ptr = dst_file; //Creates a pointer to the file name
	while (*ptr != '\0') { //Parsing through until the null terminator
    		if (isspace(*ptr)) { //Checks for any spaces, end lines, etc.
      			return false;
		}
    		ptr++; //Move down the pointer
  	}
	FILE *fp;
	fp = fopen(dst_file, "w");
	if(fwrite(src_data, elem_size *sizeof(char), elem_count, fp)) {
		fclose(fp);
		return true;
	}
	else {
		fclose(fp);
		return false;
	}
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) {
	if(!src_file || !dst_data || strlen(src_file) == 0 || elem_size == 0 || elem_count == 0) {
                return false;
        }
        const char *ptr = src_file; //Creates a pointer to the file name
        while (*ptr != '\0') { //Parsing through until the null terminator
                if (isspace(*ptr)) { //Checks for any spaces, end lines, etc.
                        return false;
                }
                ptr++; //Move down the pointer
        }
        FILE *fp;
        fp = fopen(src_file, "r");
        if(fread(dst_data, elem_size *sizeof(char), elem_count, fp)) {
                fclose(fp);
                return true;
        }
        else {
                fclose(fp);
                return false;
        }
}
