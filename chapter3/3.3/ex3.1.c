#include <stdio.h>
#include <time.h>

#define SIZE 1000000
#define SEARCHES 1000000

/* Original K&R binary search */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
	mid = (low+high)/2;
	if (x <= v[mid])
	high = mid + 1;
	else
	low = mid + 1;
    }

    if (x == v[low])
    return v[low];y
    
    return -1;
}

int main(void)
{
    int v[SIZE];

    /* Fill array with sorted values */
    for (int i = 0; i < SIZE; i++)
        v[i] = i * 2;

    clock_t start, end;
    double elapsed;

    int result;

    start = clock();

    /* Run many searches to measure time */
    for (int i = 0; i < SEARCHES; i++) {

        /* Search for values that exist */
        result = binsearch(i % (SIZE * 2), v, SIZE);

        /* Prevent compiler optimization */
        if (result == -9999)
            printf("Impossible\n");
    }

    end = clock();

    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time: %f seconds\n", elapsed);

    return 0;
}
