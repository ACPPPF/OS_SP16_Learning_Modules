#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records) {
	if(*records || num_records == 0) { //Returns -1 if the records array is not null or size is zero
		return -1;
	}
	*records = (Record_t*) malloc(sizeof(Record_t) * num_records); //Allocates size for the records array
	if(!*records) { //Allocation did not work
		return -2;
	}
	memset(*records,0,sizeof(Record_t) * num_records); //fills in the array with the size of Record_t
	return 0;
}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) {
	if(!input_filename || !records || num_records == 0) { //Return -1 if the filename is null, records is null, or size is 0
		return -1;
	}
	int fd = open(input_filename, O_RDONLY); //Opens the file
	if(fd == -1) { //File does not exist or opening it failed
		return -2;
	}
  	ssize_t data_read = 0;
	ssize_t current_size = 0;
	size_t i;
	for (i = 0; i < num_records; ++i) {
		ssize_t temp = read(fd,&records[i], sizeof(Record_t)); //Temporarily stores the size of this record
		if(temp == 0) { //Nothing was stored, no memory in array index
			break;
		} else {
			current_size = temp; //Size of each array index
			data_read += current_size; //Increases size of array
		}
	}
	if((int)data_read/(int)current_size != num_records) { //Checks to see if num_records is the same size as the actual array
		return -3;
	}
	return 0;
}

int create_record(Record_t **new_record, const char* name, int age) {
	if(!new_record || (*new_record) || !name || name[0] == '\0' || name[0] == '\n' || strlen(name) > MAX_NAME_LEN || age <= 0 || age > 200) {
		return -1;
	}

	*new_record = (Record_t*) malloc(sizeof(Record_t));
	
	memcpy((*new_record)->name,name,sizeof(char) * strlen(name));
	(*new_record)->name[MAX_NAME_LEN - 1] = 0;	
	(*new_record)->age = age;
	return 0;

}
