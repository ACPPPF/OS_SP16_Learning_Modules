#include "../include/bitmap.h"


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
	map->data = NULL;
	map->bit_count = n_bits;
        map->byte_count = n_bits/8;
	return map;
}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit) {

	return false;
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) {

	return false;
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) {
	return false;
}

size_t bitmap_ffs(const bitmap_t *const bitmap) {

	return 0;
}

size_t bitmap_ffz(const bitmap_t *const bitmap) {

	return 0;
}

bool bitmap_destroy(bitmap_t *bitmap) {
	return false;
}
