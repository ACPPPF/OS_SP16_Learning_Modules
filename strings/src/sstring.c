#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {
	if(!str || length == 0) {
		return false;
	}
	return true;
}
/**
* Checks if the passed string is null and the length is 
* greater than 0 then returns a duplicate of the string
* param str: string to be duplicated
* param length: length of the string
*/
char *string_duplicate(const char *str, const size_t length) {
	if(!str || length == 0) {
		return NULL; //String is null or length is zero
	}
	return strndup(str, sizeof(char) * length); //Duplicates string using strndup
}

bool string_equal(const char *str_a, const char *str_b, const size_t length) {	
	if(!str_a || !str_b || length == 0 || memcmp(str_a, str_b, length * sizeof(char)) != 0) {
		return false;
	}
	else {
		return true;	
	}
}

int string_length(const char *str, const size_t length) {
	printf("%d\n", length);
	return true;	
}

int string_tokenize(const char *str, const char *delims, const size_t str_length,char **tokens, const size_t max_token_length, const size_t requested_tokens) {

	return 0;
}

bool string_to_int(const char *str, int *converted_value) {
	if(!str || !converted_value || sizeof(str) >= 10) {
		return false;
	}
	unsigned long long test = atol(str);
	if(test/(UINT16_MAX+1) > 0) {
		return false;
	}
	else {
		*converted_value = atoi(str);
		return true;
	}
}
