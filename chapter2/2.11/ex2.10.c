#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getlineKR(char line[], int maxline);
int lower(int c);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getlineKR(line, MAXLINE)) > 0)
    {
	int i;
	for (i = 0; i < len; ++i)
	line[i] = lower(line[i]);
	
	printf("%s\n", line);
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

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
    return c;
}
