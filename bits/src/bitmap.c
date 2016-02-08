#include "../include/bitmap.h"

// data is an array of uint8_t and needs to be allocated in bitmap_create
// and used in the remaining bitmap functions. You will use data for any bit operations and bit logic   
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create 

struct bitmap {
	uint8_t *data;
	size_t bit_count, byte_count;
};

/// Creates a bitmap to contain 'n' bits (zero initialized)
/// \param n_bits
/// \return New bitmap pointer, NULL on error
bitmap_t *bitmap_create(size_t n_bits) {
	if((signed int)n_bits <= 0 || n_bits == SIZE_MAX) { //Not too big or negative
		return NULL;
	}
	bitmap *map;
	map = (bitmap *)malloc(sizeof(bitmap)); //Allocated memory for map
	map->bit_count = n_bits; //Sets bit count
        map->byte_count = ceil(n_bits/8.0); //Sets byte count, rounds up
	map->data = (uint8_t *)calloc(map->byte_count, 1); //Allocates and sets everything to zero
	return map;
}

/// Sets the requested bit in bitmap
/// \param bitmap The bitmap
/// \param bit The bit to set
bool bitmap_set(bitmap_t *const bitmap, const size_t bit) {
	if(!bitmap || (signed int)bit < 0 || bit == SIZE_MAX) { //Bitmap exists and the bit location is not below zero or too big
		return false;
	}
	bitmap->data[bit/8] |= 1 << (bit%8); //These array spots are one byte each, must divide by 8 to get bit location, set to one
	return true;
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) {
	if(!bitmap || (signed int)bit < 0 || bit == SIZE_MAX) { //Bitmap exists and the bit location is not below zero or too bit
                return false;
        }
	bitmap->data[bit/8] &= ~(1 << (bit%8)); //These array indices are one byte each, must divide by 8 to get bit location, set to zero
	return true;
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) {
	if(!bitmap || (signed int)bit < 0 || bit == SIZE_MAX) { //Bitmap exists and the bit location is not below zero or too big
		return false;
	}
	return ((bitmap->data[bit/8] & (1 << (bit%8))) != 0); //Returns true if the bit is set, false if not
}

size_t bitmap_ffs(const bitmap_t *const bitmap) {
	if(!bitmap) { //Bitmap does not exist
		return SIZE_MAX;
	}
	for(int counter = 0; counter < bitmap->bit_count; ++counter) { //Loops through all of the bits and tests fo find the first set bit
		if(bitmap_test(bitmap, counter)) {
			return counter;
		}
	
	}
	return SIZE_MAX; //Return SIZE_MAX if not found
}

size_t bitmap_ffz(const bitmap_t *const bitmap) {
	if(!bitmap) { //Bitmap does not exist
                return SIZE_MAX;
        }
        for(int counter = 0; counter < bitmap->bit_count; ++counter) { //Loops through all of the bits and tests to find the first not set bit
                if(!bitmap_test(bitmap, counter)) {
                        return counter;
                }

        }
        return SIZE_MAX; //Return SIZE_MAX if not found
}

bool bitmap_destroy(bitmap_t *bitmap) {
	if(!bitmap) { //Bitmap is not found
		return false;
	}
	free(bitmap->data); //Free the data in the bitmap
	free(bitmap); //Free the bitmap
	return true;
}
