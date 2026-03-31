#include <stdio.h>

int main(void) {
    int c, sc;

    while ((c = getchar()) != EOF) {
	putchar(c);
	while (c == ' ') {
	    c = getchar();
	    if (c != ' ')
	    putchar(c);
	    }

    }
    return 0;
}
