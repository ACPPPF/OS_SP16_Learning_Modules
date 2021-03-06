
#include "../include/structures.h"

int compare_structs(sample_t* a, sample_t* b)
{
	if(!a || !b) {
		return 0;
	}
	if(a->a == b->a && a->b == b->b && a->c == b->c) {
		return 1;
	}
	else {
		return 0;
	}	
}

void print_alignments()
{
	printf("Alignment of int is %zu bytes\n",__alignof__(int));
	printf("Alignment of double is %zu bytes\n",__alignof__(double));
	printf("Alignment of float is %zu bytes\n",__alignof__(float));
	printf("Alignment of char is %zu bytes\n",__alignof__(char));
	printf("Alignment of long long is %zu bytes\n",__alignof__(long long));
	printf("Alignment of short is %zu bytes\n",__alignof__(short));
	printf("Alignment of structs are %zu bytes\n",__alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a,int* apples,int* oranges, const size_t size)
{
	return 0;
}

int initialize_array(fruit_t* a, int apples, int oranges)
{
	if(!a) {
		return 0;
	}
}

int initialize_orange(orange_t* a)
{
	if(!a) {
		return -1;
	}
	a = {.type = ORANGE, .weight = ORANGE};
	return 0;

}

int initialize_apple(apple_t* a)
{	if(!a) {	
		return 0;
	}
}
