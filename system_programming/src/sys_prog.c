#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP

bool bulk_read(const char *input_filename, void *dst, const size_t offset, const size_t dst_size) {	
	if(!input_filename || !dst || dst_size == 0) {
		return false;
	}
	int file_desc = open(input_filename, O_RDONLY);
	if(!file_desc) {
		close(file_desc);
		return false;
	}
	if(lseek(file_desc, offset, 0) >= 0) {
		read(file_desc, dst, dst_size * sizeof(char));
		close(file_desc);
		return true;
	}
	else {
		close(file_desc);
		return false;
	}
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size) {
	if(!src || !output_filename || src_size == 0) {
		return false;
	}
	int file_desc = open(output_filename, O_WRONLY);
	if(!file_desc) {
		close(file_desc);
		return false;
	}
	if(lseek(file_desc, offset, 0) >= 0) {
                write(file_desc, src, src_size * sizeof(char));
                close(file_desc);                
		return true;
        }
        else {
                close(file_desc);
                return false;
        }
}

// Returns the file metadata given a filename   
// \param query_filename the filename that will be queried for stats
// \param metadata the buffer that contains the metadata of the queried filename
// return true if operation was successful, else false
bool file_stat(const char *query_filename, struct stat *metadata) {
	if(!query_filename || !metadata) {
		return false;
	}
	int file_desc = open(query_filename, O_RDONLY);
	if(file_desc <= 0) {
		close(file_desc);
		return false;
	} else {
		fstat(file_desc, metadata);
		close(file_desc);
		return true;
	}	
}

// Converts the endianess of the source data contents before storing into the dst_data.
// The passed source data bits are swapped from little to big endian and vice versa. 
// \param src_data the source data that contains content to be stored into the destination
// \param dst_data the destination that stores src data
// \param src_count the number of src_data elements
// \return true if successful, else false for failure
bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count) {
	if(!src_data || !dst_data || src_count == 0) {
		return false;
	}
	return true;
}
