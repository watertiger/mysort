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
simple_insert_sort( int *arr, size_t n )
{
	int i = 0, j = 0, k = 0;
	int tmp_data = 0;

	for ( i = 1; i < n; i++ ) {
		for ( j = 0; j < i; j++ ) {
			if ( *(arr+j) > *(arr+i) ) {	/* 寻找arr[i]应该插入的位置*/
				tmp_data = *(arr+i);
				for ( k = i; k > j; k-- )
					arr[k] = arr[k-1];
				*(arr+j) = tmp_data;
			}
#ifdef PRINT2
			printf(" Step %-4d:", j+1);
			print( arr, i );
#endif		
		}
#ifdef PRINT1
		printf("Round %-4d:", i );
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
	
	simple_insert_sort( array, ARRAY_SIZE);

	putchar('\n');
	printf("After sort:\n");
	print( array, ARRAY_SIZE);


	return 0;
}