#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/sstring.h"


// Verifies if the passed character array is a null terminated or not.
// \param str the character array that may be null terminated
// \param length to prevent buffer overflow while checking the 
// \return true if the character array is a string
bool string_valid(const char *str, const size_t length) {
	if(!str || length == 0) {
		return false;
	}
	if(str[length - 1] == '\0') {
		return true;
	}
	return false;
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

// Finds the number of characters in the string, not including the null terminator
// \param str the string to count the number of characters in the string
// \param length the max possible string length for the application
// \return the length of the string or 0 for invalid string 
int string_length(const char *str, const size_t length) {
	if(!str || length == 0) {
		return -1;
	}
	const char *ptr = str;
	int counter;
	for(counter = 0; counter < length; counter++, ptr++) {	
		if(ptr[0] == '\0') {
			return counter;
		}
	}
	return 0;
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
	if(!str || !converted_value || sizeof(str) >= 10) {
		return false;
	}
	char* end;
	*converted_value = strtol(str, &end, 10);
	if(errno == ERANGE) {
		*converted_value = 0;
		return false;
	}
	else {
		return true;
	}
}
