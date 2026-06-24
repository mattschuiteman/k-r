#include <stdio.h>

#define BUFSIZE 100

// Assume there will only ever be one character of pushback
char placeholder = EOF;

int getch(void)
{
    if (placeholder != EOF)
    {
	char ret = placeholder;
	placeholder = EOF;
	return ret;
    }
    else
    {
	return getchar();
    }
}

void ungetch(int c)
{
    if (placeholder != EOF)
    {
	printf("Cannot ungetch(), placeholder in use\n");
    }
    else
    {
	placeholder = c;
    }
}

void ungets(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    i++;

    for (i = i - 1; i >= 0; i--)
    {
	ungetch(s[i]);
    }
}
