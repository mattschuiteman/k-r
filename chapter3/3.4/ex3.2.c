#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getlineKR(char line[], int maxline);
void escapeMS(char s[], char t[]);
void unescapeMS(char s[], char t[]);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getlineKR(line, MAXLINE)) > 0)
    {
	char escaped_line[MAXLINE];
	char unescaped_line[MAXLINE];
	escapeMS(line, escaped_line);
	printf("Escape: %s\n", escaped_line);
	unescapeMS(escaped_line, unescaped_line);
	printf("Unescape: %s\n", unescaped_line);
	
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

void escapeMS(char s[], char t[])
{
    int i = 0;
    int j = 0;
    while (s[i] != '\0')
    {
	switch (s[i]) {
	case '\n':
	    t[j++] = '\\';
	    t[j++] = 'n';
	    break;
	case '\b':
	    t[j++] = '\\';
	    t[j++] = 'b';
	    break;
	case '\t':
	    t[j++] = '\\';
	    t[j++] = 't';
	    break;
	default:
	    t[j++] = s[i];
	}
	
	i++;
    }

    t[j] = '\0';
}

void unescapeMS(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int slash_flag = 0;
    while (s[i] != '\0')
    {
	switch (s[i]) {
	case '\\':
	    slash_flag = 1;
	    break;
	case 'n':
	    if (slash_flag)
	    {
		t[j++] = '\n';
		slash_flag = 0;
		break;
	    }
	    else
	    {
		t[j++] = s[i];
		break;
	    }
	case 't':
	    if (slash_flag)
	    {
		t[j++] = '\t';
		slash_flag = 0;
		break;
	    }
	    else
	    {
		t[j++] = s[i];
		break;
	    }
	case 'b':
	    if (slash_flag)
	    {
		t[j++] = '\b';
		slash_flag = 0;
		break;
	    }
	    else
	    {
		t[j++] = s[i];
		break;
	    }
	default:
	    t[j++] = s[i];
	    slash_flag = 0;
	}

	i++;
    }

    t[j] = '\0';
}



	    
	    

	    
	    
