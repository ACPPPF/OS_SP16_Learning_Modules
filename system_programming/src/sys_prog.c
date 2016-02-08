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
	errno = 0; //sets errno to zero
	if(!input_filename || !dst || dst_size == 0) { //file is null, dest is null, or destination has no size
		return false;
	}
	int file_desc = open(input_filename, O_RDONLY); //Opens file for read only
	if(errno == ENOENT || errno == EBADF) { //Couldn't open file 
		return false;
	}
	lseek(file_desc, offset, 0); //Sets the offset of the file
	read(file_desc, dst, dst_size * sizeof(char)); //reads from the open file into the destination
	close(file_desc); //closes the file
	return true;
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size) {
	errno = 0; //Sets errno to zero 
	if(!src || !output_filename || src_size == 0) { //file is null, source is null, or source has no size

		return false;
	}
	int file_desc = open(output_filename, O_WRONLY); //Opens file for write only
	if(errno == ENOENT || errno == EBADF) { //File does not exist
		return false;
	}
	lseek(file_desc, offset, 0); //Sets the offset
	write(file_desc, src, src_size * sizeof(char)); //Writes to the source from the open file
   	close(file_desc); //Close file
    	return true;
}

// Returns the file metadata given a filename   
// \param query_filename the filename that will be queried for stats
// \param metadata the buffer that contains the metadata of the queried filename
// return true if operation was successful, else false
bool file_stat(const char *query_filename, struct stat *metadata) {
	errno = 0; //Set errno to zero
	if(!query_filename || !metadata) { //Filename is null or metadata is null
		return false;
	}
	int file_desc = open(query_filename, O_RDONLY); //Opens file for readonly
	if(errno == ENOENT) { //File does not exist
		return false;
	} else {
		fstat(file_desc, metadata); //Gets stat data from open file
		close(file_desc); //Closes file
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
	if(!src_data || !dst_data || src_count == 0) { //Source data is null, destination data is null, or source count is zero
		return false;
	}
	int counter;
	for(counter = 0; counter < src_count; counter++) {
		*dst_data = ((*src_data>>24)&0xff) | // move byte 3 to byte 0
                    ((*src_data<<8)&0xff0000) | // move byte 1 to byte 2
                    ((*src_data>>8)&0xff00) | // move byte 2 to byte 1
                    ((*src_data<<24)&0xff000000); // byte 0 to byte 3
		dst_data++;
		src_data++;
	}
	return true;
}
