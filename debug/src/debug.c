#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
    	if(!a || !b) {
		return -1;
	}
	return (*(uint16_t *)a - *((uint16_t *)b));
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
    	if(!data_array || value_count == 0) {
		return false;
	}
	uint16_t *sorting_array = NULL;
	int size = value_count * sizeof(uint16_t);
	sorting_array = (uint16_t *)malloc(size);
    	for (int i = 0; i < value_count; ++i) {
        	sorting_array[i] = data_array[i];
    	}

    	qsort(sorting_array, value_count, sizeof(uint16_t), comparator_func);
	bool sorted = true;
	for (int i = 0; i < value_count-1; ++i) {
        	if(sorting_array[i] > sorting_array[i+1]) {
			sorted = false;
			break;
		}	
	}
    	if (sorted) {
        	memcpy(data_array, sorting_array, size);
    		free(sorting_array);
	}
    	return sorted;
}

