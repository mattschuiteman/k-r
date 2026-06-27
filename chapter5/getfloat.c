#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define BUFSIZE 100

int getfloat(float *pn);

int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

// define getch
int getch(void)
{
    return (bufp > 0) ?  buf[bufp--] : getchar();
}

// define ungetch
void ungetch(int c)
{
    if (bufp > BUFSIZE)
    {
	printf("Cannot add to buffer; buffer at max size\n");
    }
    else
    {
	buf[bufp++] = c;
    }
}

// define getfloat
int getfloat(float *pn)
{
    int c;
    int sign = 1;

    int value = 0;
    float fraction = 0;
    float power = 1;
    
    // handle white space
    while (isspace(c = getch()))
    ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	printf("not a number: %c\n", c);
	ungetch(c);
	return 0;
    }    

    // handle sign
    if (c == '-')
    {
	sign = -1;
	c = getch();
    }

    while (isdigit(c))
    {
	value = 10 * (value) + (c - '0');
	c = getch();
    }

    if (c == '.')
    {
	while (isdigit(c = getch()))
	{
	    fraction = 10 * (fraction) + (c - '0');
	    power *= 10;
	}
    }

    *pn = value + fraction / power;
    *pn *= sign;

    if (c != EOF)
    ungetch(c);

    return c;
}

// define main
int main(void)
{
    int n;
    float array[SIZE];
    int result;

    printf("Enter float (Ctrl+D to end):\n");

    for (n = 0; n < SIZE && (result = getfloat(&array[n])) != EOF; ) {
        if (result > 0) {
            printf("Stored: %f\n", array[n]);
            n++;
        } else if (result == 0) {
            printf("Not a number\n");
            getch();   /* consume bad character to avoid infinite loop */
        }
    }

    printf("\nNumbers entered:\n");
    for (int i = 0; i < n; i++)
        printf("%f ", array[i]);

    printf("\n");

    return 0;
}
