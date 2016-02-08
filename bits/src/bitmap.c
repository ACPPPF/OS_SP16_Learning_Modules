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
	if(n_bits <= 0 || n_bits == SIZE_MAX) {
		return NULL;
	}
	bitmap *map;
	map = (bitmap *)malloc(sizeof(bitmap));
	map->bit_count = n_bits;
        map->byte_count = ceil(n_bits/8.0);
	map->data = (uint8_t *)calloc(map->byte_count, 1);
	return map;
}

/// Sets the requested bit in bitmap
/// \param bitmap The bitmap
/// \param bit The bit to set
bool bitmap_set(bitmap_t *const bitmap, const size_t bit) {
	if(!bitmap || (signed int)bit < 0 || bit == SIZE_MAX) {
		return false;
	}
	bitmap->data[bit/8] |= 1 << (bit%8);
	return true;
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) {
	if(!bitmap || (signed int)bit < 0 || bit == SIZE_MAX) {
                return false;
        }
	bitmap->data[bit/8] &= ~(1 << (bit%8));
	return true;
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) {
	if(!bitmap || (signed int)bit < 0 || bit == SIZE_MAX) {
		return false;
	}
	return ((bitmap->data[bit/8] & (1 << (bit%8))) != 0);
}

size_t bitmap_ffs(const bitmap_t *const bitmap) {
	if(!bitmap) {
		return SIZE_MAX;
	}
	for(int counter = 0; counter < bitmap->bit_count; ++counter) {
		if(bitmap_test(bitmap, counter)) {
			return counter;
		}
	
	}
	return SIZE_MAX;
}

size_t bitmap_ffz(const bitmap_t *const bitmap) {
	if(!bitmap) {
                return SIZE_MAX;
        }
        for(int counter = 0; counter < bitmap->bit_count; ++counter) {
                if(!bitmap_test(bitmap, counter)) {
                        return counter;
                }

        }
        return SIZE_MAX;
}

bool bitmap_destroy(bitmap_t *bitmap) {
	if(!bitmap) {
		return false;
	}
	free(bitmap->data);
	free(bitmap);
	return true;
}
