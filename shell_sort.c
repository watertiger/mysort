#include <stdio.h>
#include <stdlib.h>

#define PRINT1
#define PRINT2

#define ARRAY_SIZE 10
#define ROUND_COUNT 4

int delta[ROUND_COUNT] = {5,3,2,1};

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void
print(int *arr, size_t n )
{
	int i = 0;
	
	printf("\t");
	for( i = 0; i < n; i++ )
		printf("%-4d\t", *(arr+i) );
	printf("\n");
	
	return;
}

void shell_insert( int *arr, size_t n, int d)
{
	int i = 0, j = 0;

	for ( i = d; i < n; i++) {
		if ( arr[i] < arr[i-d] ) {
			for (j = i-d; (j >= 0) && (arr[j+d] < arr[j]); j-=d) {
				swap( &arr[j+d], &arr[j]);
			}
		}
	}

	return;
}
	
int
shell_sort( int *arr, size_t n, int *delta_arr )
{
	int i = 0;
	
	for ( ; i < ROUND_COUNT; i++) {
		shell_insert( arr, n, delta_arr[i]);
		print( arr, n);
	}

	return 0;
}



int
main()
{
	int array[ARRAY_SIZE];
	int i = 0;

	srand( (unsigned int)time(NULL) );
	for (i = 0; i < ARRAY_SIZE; i++)  
		array[i] = rand() % 100;
	printf("Before sort:\n");
	print( array, ARRAY_SIZE);
	putchar('\n');
	
	shell_sort( array, ARRAY_SIZE, delta);

	putchar('\n');
	printf("After sort:\n");
	print( array, ARRAY_SIZE);


	return 0;
}
