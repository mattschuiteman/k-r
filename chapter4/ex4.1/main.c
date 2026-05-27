#include <stdio.h>

int strindex(char s[], char t[]);

int main(void)
{
    printf("%d\n", strindex("banana", "ana"));
    printf("%d\n", strindex("hello world", "world"));
    printf("%d\n", strindex("aaaaa", "aa"));
    printf("%d\n", strindex("abcdef", "xyz"));

    return 0;
}
