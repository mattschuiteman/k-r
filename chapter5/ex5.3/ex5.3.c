// strcat pointer version

#include <stdio.h>

void MS_strcat(char s[], char t[]);
void MS_strcat_2(char *s, char *t);

int main()
{
    char string1[] = "Hello";
    char string2[] = " World!";

    // concatenate strings
    MS_strcat(string1, string2);

    printf("Test non pointer strcat\n");
    printf("%s\n", string1);

    // now with pointers

    char string3[] = "Hello";
    char string4[] = " World!";
    printf("Test with pointer strcat\n");
    MS_strcat_2(string3, string4);
    printf("%s\n", string3);
}

/* strcat: concatenate t to end of s; s must be big enough */
void MS_strcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
    i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
    ;
}

void MS_strcat_2(char *s, char *t)
{
    while (*s != '\0')
    s++;

    while ((*s++ = *t++))
    ;
}

    

