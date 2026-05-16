#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line length */
#define MAX_LINE_ALLOWED 80
#define BASE 16
int getlineKR(char line[], int maxline);
int htoiKR(char s[], int len);
/* print the longest input line */
int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getlineKR(line, MAXLINE)) > 0)
    {
	int number = htoiKR(line, len);
	printf("%d\n", number);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getlineKR(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

int htoiKR(char s[], int len)
{
    if (len < 3)
    {
	printf("Hex numbers cannot have less than 3 characters!\n");
	return -1;
    }

    int i = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    i = i + 2;
    
    // Now begin algorithm
    int result = 0;

    int digit;
    while (s[i] != '\0')
    {
	char c = s[i];
	
	if (c  >= '0' && c <= '9')
	{
	    digit = c - '0';
	}

	else if (c >= 'A' && c <= 'F')
	{
	    digit = c - 'A' + 10;
	}
	
	else if (c >= 'a' && c <= 'f')
	{
	    digit = c - 'a' + 10;
	}

	else if (c == '\n' || c == '\0')
	break;

	else
	{
	    printf("%c is not a valid digit in hexadecimal.\n", c);

	    return -1;
	}

	result = result * BASE + digit;
	++i;
    }

    return result;
}


	

	
	
