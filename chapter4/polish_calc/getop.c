#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

    s[1] = '\0';


    if (!isdigit(c) && c!= '.' && c != '-')
    {
	return c; // not a number
    }

    i = 0;

    if (isdigit(c))
    {
	while (isdigit(s[++i] = c = getch()))
	;
    }

    if (c == '.')
    {
	while (isdigit(s[++i] = c = getch()))
	;
    }

    if (c == '-')
    {
	// we look ahead to determine if the negative sign follows a digit
	// if it does, we add it to the buffer to be processed
	// if it doesn't, return it, it's an operator
	int next = getch();
	if (!isdigit(next) && next != '.')
	{
	    ungetch(next);
	    return c;
	}

	else
	{
	    ungetch(next);
	    while(isdigit(s[++i] = c = getch()))
	    ;
	}
    }

    s[i] = '\0';

    if (c != EOF)
    ungetch(c);

    return NUMBER;
}


