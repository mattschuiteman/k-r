#include <stdio.h>

// Symbolic contants
#define MAXLINE 1000 /* maximum input line length */
#define TABSTOP 4

// Extern declarations
int i, j, spaces,  col;


// Function declartions
int getlineKR(char line[], int maxline);
void copy(char to[], char from[]);
void entab(char line[]);


/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char characters[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getlineKR(line, MAXLINE)) > 0) {
	entab(line);
    }
    
    return 0;
}

void entab(char line[])
{
    int i, col, space_count, spaces_to_tabstop, start_col;

    i = 0;
    col = 0;
    space_count = 0;
    spaces_to_tabstop = 0;
    start_col = 0;

    while(line[i] != '\0')
    {
	if (line[i] == ' ')
	{
	    space_count++;
	}
	else
	{
	    while (space_count > 0)
	    {
		int next_tab = TABSTOP - (col % TABSTOP);

		if (space_count >= next_tab)
		{
		    putchar('\t');
		    space_count -= next_tab;
		    col += next_tab;
		}
		else
		{
		    putchar(' ');
		    space_count--;
		    col++;
		}
	    }

	    printf("%c", line[i]);
	    col++;
	    
	}
	++i;
    }
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
