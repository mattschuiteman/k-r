#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define BUFSIZE 100

int getint(int *pn);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch();

	if (!isdigit(next))
	{
	    ungetch(next);
	    ungetch(c);
	    return 0;
	}

        c = next;
    }

    *pn = 0;
    for (; isdigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void)
{
    int n, array[SIZE];
    int result;

    printf("Enter integers (Ctrl+D to end):\n");

    for (n = 0; n < SIZE && (result = getint(&array[n])) != EOF; ) {
        if (result > 0) {
            printf("Stored: %d\n", array[n]);
            n++;
        } else if (result == 0) {
            printf("Not a number\n");
            getch();   /* consume bad character to avoid infinite loop */
        }
    }

    printf("\nNumbers entered:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");

    return 0;
}
