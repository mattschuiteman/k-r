#include <stdio.h>

// Symbolic contants
#define MAXLINE 1000 /* maximum input line length */
#define TABSTOP 4

// Extern declarations
int i, j, spaces,  col;


// Function declartions
int getlineKR(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char line[], int len);


/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char characters[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getlineKR(line, MAXLINE)) > 0) {
	detab(line, len);
    }
    
    return 0;
}

void detab(char line[], int len)
{
    col = 0;
    for (i = 0; i < len; i++)
    {
	col++;
	if (line[i] == '\t')
	{
	    spaces = TABSTOP - (col % TABSTOP);
	    for (j = 0; j <= spaces; ++j)
	    {
		printf(" ");
		col++;
	    }
	}
	printf("%c", line[i]);
    }
    printf("\n");
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
