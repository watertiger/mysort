#include <stdio.h>
#include <stdlib.h>

#define PRINT1
#define PRINT2

#define ARRAY_SIZE 10


void
swap( int *a, int *b )
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
	
int
bubble_sort( int *arr, size_t n )
{
	int i = 0, j = 0;

	for ( i = n; i > 0; i-- ) {
		for ( j = 0; j < i-1; j++ ) {
			if ( *(arr+j) > *(arr+j+1) )
				swap( arr+j, arr+j+1 );
#ifdef PRINT2
			printf(" Step %-4d:", j+1);
			print( arr, n );
#endif		
		}
#ifdef PRINT1
		printf("Round %-4d:", n-i+1 );
		print( arr, n );
		putchar('\n');
#endif	
	}
	
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
	
	bubble_sort( array, ARRAY_SIZE);

	putchar('\n');
	printf("After sort:\n");
	print( array, ARRAY_SIZE);


	return 0;
}
