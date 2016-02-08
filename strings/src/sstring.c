#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {
	if(!str || length == 0) { //If string is null or length equals zero
		return false;
	}
	if(str[length - 1] == '\0') { //End is a null terminator
		return true;
	}
	return false; //End was not a null terminator
}

char *string_duplicate(const char *str, const size_t length) {
	if(!str || length == 0) {
		return NULL; //String is null or length is zero
	}
	return strndup(str, sizeof(char) * length); //Duplicates string using strndup
}

bool string_equal(const char *str_a, const char *str_b, const size_t length) {
/*string a or string b is null, length is zero, memcompare of a and b shows they are not the same*/
	if(!str_a || !str_b || length == 0 || memcmp(str_a, str_b, length * sizeof(char)) != 0) {
		return false;
	}
	else {
		return true;	
	}
}

int string_length(const char *str, const size_t length) {
	if(!str || length == 0) { //String is null or length is zero
		return -1;
	}
	const char *ptr = str; //Make a temp copy of string into pointer
	int counter;
	for(counter = 0; counter < length; counter++, ptr++) { //Searches for the null terminator
		if(ptr[0] == '\0') {
			return counter; //End was found, return length
		}
	}
	return 0; //No null terminator
}

// Split the incoming string to tokens that are stored in a passed allocated tokens string array
// \param str the string that will be used for tokenization
// \param delims the delimiters that will be used for splitting the str into segments
// \param str_length the lengt of the str
// \param tokens the string array that is pre-allocated and will contain the parsed tokens
// \param max_token_length the max length of a token string in the tokens string array with null terminator
// \param requested_tokens the number of possible strings that tokens string array can contain
// \return returns the number of actual parsed tokens, 0 for incorrect params, and -1 for incorrect token allocation
int string_tokenize(const char *str, const char *delims, const size_t str_length,char **tokens, const size_t max_token_length, const size_t requested_tokens) {
	if(!str || !delims || str_length == 0 || !tokens || max_token_length == 0 || requested_tokens == 0) {
		return 0;
	}
	return 1;
}

bool string_to_int(const char *str, int *converted_value) {
	errno = 0;
	if(!str || !converted_value || sizeof(str) >= 10) { //String is null, converted value is null, string is too long
		return false;
	}
	char* end;
	*converted_value = strtol(str, &end, 10); //String to long
	if(errno == ERANGE) { //String is too long
		*converted_value = 0; //Converted value is zero
		return false;
	}
	else {
		return true;
	}
}
