#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records) {
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
<<<<<<< HEAD
	int fd = open(input_filename, O_RDONLY);
	if(fd == -1) {
		close(fd);
		return -2;
  	}
	ssize_t data_read = 0;
  	for (size_t i = 0; i < num_records; ++i) {
		*records = (Record_t*) malloc(sizeof(Record_t) * num_records);
		memset(*records,0,sizeof(Record_t) * num_records);
	}
	return 0;	
}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) {
	int fd = open(input_filename, O_RDONLY);
	ssize_t data_read = 0;
	for (size_t i = 0; i < num_records; ++i) {
=======

	int fd = open(input_filename, O_RDONLY);
	if(fd == -1) {
		return -2;
	}
  	ssize_t data_read = 0;
	size_t i;
	for (i = 0; i < num_records; ++i) {
>>>>>>> 8d2e7ef0126274119a9033963a965867b5689514
		data_read = read(fd,&records[i], sizeof(Record_t));	
	}
	if(i != num_records) {
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
