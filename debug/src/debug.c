#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
    	if(!a || !b) { //a or b is null
		return -1;
	}
	return (*(uint16_t *)a - *((uint16_t *)b)); //returns the 16 bit integer value of a-b
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
    	if(!data_array || value_count == 0) { //data_array is null or the value_count is zero
		return false;
	}
	uint16_t *sorting_array = NULL;
	int size = value_count * sizeof(uint16_t); //Creates the size as value_count * the size of a 16 bit int
	sorting_array = (uint16_t *)malloc(size); //Allocates memory for the sorting array
    	/*for (int i = 0; i < value_count; ++i) {
        	sorting_array[i] = data_array[i];
    	}*/
	memcpy(sorting_array, data_array, size);

    	qsort(sorting_array, value_count, sizeof(uint16_t), comparator_func);
	bool sorted = true;
	for (int i = 0; i < value_count-1; ++i) { //Compares the sorted array to make sure it worked properly
        	if(sorting_array[i] > sorting_array[i+1]) { //The values are not in order
			sorted = false;
			break;
		}	
	}
    	if (sorted) {
        	memcpy(data_array, sorting_array, size); //Copies from the sorted array into the data array
	}
	free(sorting_array); //Frees the sorting array memory
    	return sorted;
}

