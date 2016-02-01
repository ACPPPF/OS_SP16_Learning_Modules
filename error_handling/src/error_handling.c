#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records) {
<<<<<<< HEAD
	if(*records || num_records == 0) {
		return -1;
	}
	*records = (Record_t*) malloc(sizeof(Record_t) * num_records);
	if(!*records) {
		return -2;
	}
	memset(*records,0,sizeof(Record_t) * num_records);
	return 0;
}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) {
	if(!input_filename || !records || num_records == 0) {
		return -1;
	}
	int fd = open(input_filename, O_RDONLY);
	if(fd == -1) {
		close(fd);
		return -2;
  	}
	ssize_t data_read = 0;
  	for (size_t i = 0; i < num_records; ++i) {
=======

	*records = (Record_t*) malloc(sizeof(Record_t) * num_records);

	memset(*records,0,sizeof(Record_t) * num_records);
	return 0;	
}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) {

	int fd = open(input_filename, O_RDONLY);

  ssize_t data_read = 0;
  for (size_t i = 0; i < num_records; ++i) {
>>>>>>> 7c5715c1507b617c9a9ed11c5f2e3a9293dcdf35
		data_read = read(fd,&records[i], sizeof(Record_t));	
	}
	return 0;
}

int create_record(Record_t **new_record, const char* name, int age) {
<<<<<<< HEAD
	if(!new_record || (*new_record) || !name || name[0] == '\0' || name[0] == '\n' || strlen(name) > MAX_NAME_LEN || age <= 0 || age > 200) {
		return -1;
	}
=======

>>>>>>> 7c5715c1507b617c9a9ed11c5f2e3a9293dcdf35
	*new_record = (Record_t*) malloc(sizeof(Record_t));
	
	memcpy((*new_record)->name,name,sizeof(char) * strlen(name));
	(*new_record)->name[MAX_NAME_LEN - 1] = 0;	
	(*new_record)->age = age;
	return 0;

}
