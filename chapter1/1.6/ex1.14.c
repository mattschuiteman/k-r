#include <stdio.h>

#define OUT 0
#define ARRAY_SIZE 26


int main()
{
    int c, i, j, ncount;

    int charcount[ARRAY_SIZE];
    ncount = 0;

    for (i = 0; i < ARRAY_SIZE; ++i)
    charcount[i] = 0;
    
        while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    continue;
	}
	else if (c >= 97 && c <= 122) {
	    ++charcount[c - 97];
	    
	}
	else
	continue;
    }

    printf(" ----- Char Count Histogram -----\n");
    for (i = 0; i < ARRAY_SIZE; ++i) {
	ncount = charcount[i];
	printf("%c:", i + 97);
	for (j = 0; j < ncount; ++j)
	printf("*");
	printf("\n");
    }
    printf("-----------------------------------");
}
