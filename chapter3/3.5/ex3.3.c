#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line length */
int getlineKR(char line[], int maxline);
void expandMS(char s1[], char s2[]);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getlineKR(line, MAXLINE)) > 0)
    {
	char expanded_line[MAXLINE];
	expandMS(line, expanded_line);
	printf("Expand: %s\n", expanded_line);
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

void expandMS(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (s1[i] != '\0')
    {
	if (s1[i] == '-')
	{
	    // handle case where - is the first character
	    if (i == 0)
	    {
		s2[k++] = s1[i++];
		continue;
	    }
	    
	    if (isalnum(s1[i - 1]) && isalnum(s1[i + 1]))
	    {
		for (j = s1[i - 1] + 1; j < s1[i + 1]; j++)
		s2[k++] = j;

		i++;
		continue;
	    }

	    else
	    s2[k++] = s1[i];

	    s2[k++] = s1[++i];
	}

	else
	{
	    s2[k++] = s1[i++];
	}
    }

    s2[k] = '\0';
}

    
	



	

	

	

	

