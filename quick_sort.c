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
	for( i = 0; i <= n; i++ )
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
part( int *arr, size_t low, size_t high)
{
	int mid = low + ( (high - low)>>1 );
	int mid_key = 0, mid_index = 0;
	

	mid_index = select_key_index( arr, low, mid, high );
	mid_key = *(arr + mid_index);
	arr[mid_index] = arr[low];
	
	for (;low < high;) {
		for (;(low < high) && (arr[high] >= mid_key);)
			--high;
		arr[low] = arr[high];
		for (; (low < high) && (arr[low] <= mid_key);)
			++low;
		arr[high] = arr[low];
	}
	arr[low] = mid_key;

	return low;
}
	
void
quick_sort( int *arr, size_t low, size_t high)
{
	int part_index = 0;

	if ( low < high ) {
		part_index = part( arr, low, high);
#ifdef PRINT1
		printf("Round %-4d: part index is %-4d. scope is [%d,%d].\n",\
					++round_time, part_index, low, high );
		print( arr, high);
		putchar('\n');
#endif
		if (low < part_index)
			quick_sort( arr, low, part_index-1);
		if ( high > part_index)
			quick_sort( arr, part_index+1, high);	
	}
	
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
	print( array, ARRAY_SIZE-1);
	putchar('\n');
	
	quick_sort( array, 0, ARRAY_SIZE-1);

	putchar('\n');
	printf("After sort:\n");
	print( array, ARRAY_SIZE-1);


	return 0;
}