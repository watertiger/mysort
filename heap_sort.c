#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void
swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
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

void
heap_adjust(int *arr, int root_index, int size)
{
	int left_child = root_index << 1 ;
	int right_child = (root_index << 1) + 1;
	int child_root = root_index;
	
	if ( root_index > (size >> 1))
		return;
	/*
	 * 刚开始 接下来的两个if语句中的arr[]比较没有用child_root，
	 * 而是用的root_index，导致没有找到三个元素中的最大者
	 * 使堆排序不成功
	 */
	if ( (left_child <= size) && (arr[left_child] > arr[child_root]) )
		child_root = left_child;
	if ( (right_child <= size) && (arr[right_child] > arr[child_root]) )
		child_root = right_child;
	if (child_root != root_index) {
		swap(arr+child_root, arr+root_index);
		heap_adjust(arr, child_root, size);
	}

	return;
}

void
heap_build(int *arr, int n)
{
	int i;

	for ( i = (n>>1); i >= 1; i--) {
		heap_adjust( arr, i, n);	
	}

	return;
}

void
heap_sort(int *arr, int n)
{
	int i;
	
	heap_build(arr, n);
	print(arr, n+1);
	for (i = n; i>=1; i--) {
		swap(arr+1, arr+i);
		print(arr, i+1);
		heap_adjust(arr, 1, i-1);
	}

	return;
}

int
main(int argc, char **argv)
{
	int array[ARRAY_SIZE];
        int i = 0;

        srand( (unsigned int)time(NULL) );
	array[0] = -1;
        for (i = 1; i < ARRAY_SIZE; i++)
                array[i] = rand() % 100;
        printf("Before sort:\n");
        print( array, ARRAY_SIZE);
        putchar('\n');

        heap_sort( array, ARRAY_SIZE-1);

        putchar('\n');
        printf("After sort:\n");
        print( array, ARRAY_SIZE);	

	return 0;
}
