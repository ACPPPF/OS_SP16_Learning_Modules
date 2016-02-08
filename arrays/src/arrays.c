#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count) {
	if(!src || !dst || elem_size == 0 || elem_count == 0) { //Source or dest is null, elem size or elem count is zero
		return false;
	}
	memcpy(dst, src, elem_size * elem_count); //copies from the source into the destination
	return true;
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count) {
	if(!data_one || !data_two || elem_size == 0 || elem_count == 0) { //If the data sources are null or if the elements have no size or count	
		return false;
	}
	if(memcmp(data_one, data_two, elem_size * elem_count) == 0) { //Compares the two data sources to see if they are the same
		return true; //Same
	}
	else {
		return false; //Different
	}
}
// Attempts to locate the target from an array
// \param data the data that may contain the target
// \param target the target that may be in the data
// \param elem_size the number of bytes each array element uses and same as the target
// \param elem_count the number of elements in the data array
// returns an index to the located target, else return -1 for failure
ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) { 
	if(!data || !target || elem_size == 0 || elem_count == 0) { //If the data or source is null, or if the element has no size or count
		return -1;
	}
	int index = 0;
	while(index < elem_count) {
		if(memcmp(data, target, elem_size) == 0) { //compares the target to the data
			return index; //Returns the index
		}
		index++;
		data = (char*)data + elem_size; //Increments the data array
	}
	return -1;
}

// Writes an array into a binary file
// \param src_data the array the will be wrote into the destination file
// \param dst_file the file that will contain the wrote src_data
// \param elem_size the number of bytes each array element uses
// \param elem_count the number of elements in the source array 
// return true if operation was successful, else false
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
