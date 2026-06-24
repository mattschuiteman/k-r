#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define VARIABLE 'a'
#define MAXLINE 1000

int getlineMS(char s[], int);

int getop(char s[])
{

    static char line[MAXLINE];
    static int pos = 0;
    
    int i = 0;

    if (line[pos] == '\0')
    {
	if (getlineMS(line, MAXLINE) == 0)
	{
	    return EOF;
	}

	pos = 0;
    }
    
    while ((line[pos] == ' ' || line[pos] == '\t'))
    {
	pos++;
    }

    char c = line[pos++];

    if (!isdigit(c) && c!= '.')
    {
	return c; // not a number
    }

    s[i++] = c;

    while (isdigit(line[pos]))
    {
	s[i++] = line[pos++];
    }

    if (line[pos] == '.')
    {
	s[i++] = line[pos++];
    }

    while (isdigit(line[pos]))
    {
	s[i++] = line[pos++];
    }
    
    s[i] = '\0';

    return NUMBER;
}


