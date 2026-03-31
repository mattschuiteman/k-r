#include <stdio.h>

int main()
{
    double c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
	    putchar(92);
	    putchar(116);
	    continue;
	}
		
        else if (c == '\\') {
	    putchar(92);
	    putchar(92);
	    continue;
	}
	else if (c == '\b') {
	    putchar(92);
	    putchar(8);
	    continue;
	    }
	else
        putchar(c);
    }
    return 0;
}


    
    
