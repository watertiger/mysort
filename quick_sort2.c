#include <stdio.h>
#include <stdlib.h>

#define PRINT1
#define PRINT2

#ifdef PRINT1
int round_time = 0;
#endif

#define ARRAY_SIZE 10


void
swap( int *a, int *b )
{
	if (*a != *b) {
		int tmp = *a;
		
		*a = *b;
		*b = tmp;
	}
}

void
print(int *arr,size_t n )
{
	int i = 0;
	
	printf("\t");
	for( i = 0; i < n; i++ )
		printf("%-4d\t", *(arr+i) );
	printf("\n");
	
	return;
}

int
select_key_index( int *arr, int a, int b, int c )
{
	int low = 0, high = 0;
	int va = arr[a], vb = arr[b], vc = arr[c];
	
	low = ( va <= vb ) ? a : b;
	high = a + b -low;
	
	return ( vc >= arr[high] )? high : ( (vc >= arr[low]) ? c : low );
}

int
select_index( int *arr, size_t low, size_t high)
{
	int mid = low + ( (high - low)>>1 );
	int mid_index = 0;	

	mid_index = select_key_index( arr, low, mid, high );	

	return mid_index;
}
	
void
quick_sort( int *arr, size_t low, size_t high)
{
	int i;
	int part_index = 0;

	if ( low >= high ) 
		return;
	part_index = select_index( arr, low, high);
	swap( arr+low, arr+part_index);

	part_index = low;
	for ( i = low+1; i <= high; i++) {
		if ( arr[i] < arr[low] ) {
			swap(arr+i, arr+(++part_index));
#ifdef PRINT1
			printf("\tSwap array[%d](%d) <--> array[%d](%d).\n",\
					i, arr[i], part_index, arr[part_index]);
#endif
		}
	}
	swap( arr+low, arr+part_index);
#ifdef PRINT1	
	printf("Round %-4d: part index is %-4d. scope is [%d,%d].\n",\
				++round_time, part_index, low, high );
	print( arr, high+1);
#endif
	//此处的if判断是因为 size_t是个无符号类型，
	//quick_sort(arr,0,-1)会出错，-1会被转化为(2^32 -1)
	if (low < part_index)
		quick_sort( arr, low, part_index-1);
	if ( high > part_index)
		quick_sort( arr, part_index+1, high);	
	
	return;
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
	
	quick_sort( array, 0, ARRAY_SIZE-1);

	putchar('\n');
	printf("After sort:\n");
	print( array, ARRAY_SIZE);


	return 0;
}