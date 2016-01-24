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
	if(lseek(file_desc, offset, 0) >= 0) {
		read(file_desc, dst, dst_size * sizeof(char));
		return true;
	}
	else {
		return false;
	}
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size) {
	if(!src || !output_filename || src_size == 0) {
		return false;
	}
	int file_desc = open(output_filename, O_WRONLY);
	if(lseek(file_desc, offset, 0) >= 0) {
                write(file_desc, src, src_size * sizeof(char));
                return true;
        }
        else {
                return false;
        }
}


bool file_stat(const char *query_filename, struct stat *metadata) {

	return false;
}

bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count) {

	return false;
}
