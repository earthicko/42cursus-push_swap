#include <stdio.h>
#include "array.h"

int main()
{
	t_array *array;
	
	array = array_init(1);
	array_append(array, 1);
	printf("array len %d cap %d\n", array->len, array->cap);
	for(int i=0;i<array->len;i++) printf("[%d] ", array->data[i]);
	printf("\n");
	array_append(array, 2);
	printf("array len %d cap %d\n", array->len, array->cap);
	for(int i=0;i<array->len;i++) printf("[%d] ", array->data[i]);
	printf("\n");
	array_append(array, 3);
	printf("array len %d cap %d\n", array->len, array->cap);
	for(int i=0;i<array->len;i++) printf("[%d] ", array->data[i]);
	printf("\n");
	return 0;
}
