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
sub_print(int *arr, size_t start, size_t end)
{
	int i = start;

	printf("\tThe scope is [%d,%d].\n\t", start, end);
	for (; i <= end; i++ ) {
		printf("%-4d\t", arr[i]);
	}	
	printf("\n");

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
merge( int *sarr, int *darr, int s, int m, int e)
{
	int i = 0, j = 0, k = 0;
	
	for ( i = s, j = m+1, k = s; (i <= m) && ( j <= e); k++ ) {
		if ( sarr[i] <= sarr[j])
			darr[k] = sarr[i++];
		else 
			darr[k] = sarr[j++];
	}
	for (; i <= m;) 
		darr[k++] = sarr[i++];
	for (;j <= e;)
		darr[k++] = sarr[j++];

	return;
}

void
msort( int *sarr, int *darr, int s, int e)
{
	int m = s + ((e-s) >> 1);

	if ( s == e) {
		darr[s] = sarr[s];
	} else {
		msort( sarr, darr, s, m);
		msort( sarr, darr, m+1, e);
		merge( sarr, darr, s, m, e);	
		sub_print( darr, s, e);
	}

	return;
}

void
merge_sort( int *sarr, int *darr, size_t n)
{
	msort( sarr, darr, 0, n-1);

	return;
}



int
main()
{
	int sarray[ARRAY_SIZE];
	int darray[ARRAY_SIZE];
	int i = 0;

	srand( (unsigned int)time(NULL) );
	for (i = 0; i < ARRAY_SIZE; i++) { 
		sarray[i] = rand() % 100;
		darray[i] = 0;
	}
	printf("Before sort:\n");
	print( sarray, ARRAY_SIZE);
	putchar('\n');
	
	merge_sort( sarray, darray, ARRAY_SIZE);

	putchar('\n');
	printf("After sort:\n");
	print( darray, ARRAY_SIZE);

	return 0;
}

