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
simple_select_sort( int *arr, size_t n )
{
	int i = 0, j = 0, k = 0;
	int tmp_index = 0;

	for ( i = 0; i < n; i++ ) {
		tmp_index = i;
		for ( j = i+1; j < n; j++ ) {
/*
 * 此处处理方式有两种：
 * 1、不断交换，直到一轮结束时，arr[i]最小，j循环结束不需要交换
 * 2、利用临时变量记录索引，一轮找到最小的元素，再进行交换,在j循环结束后交换
 */
/*不断交换
 *			if ( *(arr+j) < *(arr+i) )
 *				swap( arr+j, arr+i );
 *#ifdef PRINT2
 *			printf(" Step %-4d:", j);
 *			print( arr, j );
 *#endif
*/		
//临时索引
			if ( *(arr+j) < *(arr+tmp_index) ) 
				tmp_index = j;			
		}
		swap( arr+tmp_index, arr+i );
#ifdef PRINT1
		printf("Round %-4d:", i+1 );
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
	
	simple_select_sort( array, ARRAY_SIZE);

	putchar('\n');
	printf("After sort:\n");
	print( array, ARRAY_SIZE);


	return 0;
}