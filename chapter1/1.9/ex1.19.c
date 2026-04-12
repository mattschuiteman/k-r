#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MAX_LINE_ALLOWED 80
int getlineKR(char line[], int maxline);
void reverse(char s[], char r[], int len);
void copy(char to[], char from[]);
/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char reversed[MAXLINE];
    max = 0;
    while ((len = getlineKR(line, MAXLINE)) > 0) {
	reverse(line, reversed, len);
	printf("%s\n", reversed);
    }
    return 0;
}

void reverse(char s[], char r[],  int len)
{
    int i, j;
    j = 0;
    for (i = len - 1; i >= 0; --i)
    {
	r[j] = s[i];
	j++;
    }

    r[j] = '\0';
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    ++i;
}
