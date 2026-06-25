#include <stdio.h>
#include <string.h>

void reverseMS(char s[], int i, int j);

int main()
{
    char s[] = "Hello World!";
    printf("%s\n", s);
    reverseMS(s, 0, strlen(s) - 1);
    printf("%s\n", s);
}

void reverseMS(char s[], int i, int j)
{
    char c;

    if (i >= j)
    return;

    c = s[i];
    s[i] = s[j];
    s[j] = c;

    reverseMS(s, i + 1, j - 1);
}
    
