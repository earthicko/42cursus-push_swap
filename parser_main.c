#include <stdio.h>
#include "parser.h"

int main(int argc, char **argv)
{
	t_array	*arr;

	arr = parse_args(argc, argv);
	printf("Parsed %d args\n", arr->len);
	for(int i=0;i<arr->len;i++)printf("%d ", arr->data[i]);
	printf("\n");
	return 0;
}
