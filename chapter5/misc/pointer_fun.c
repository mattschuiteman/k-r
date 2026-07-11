#include <stdio.h>

int MS_strlen(char *s);
int MS_strlen_2(char *s);
void MS_strcpy(char *s, char *t);

int main()
{
    int test_array[6] = {0, 1, 2, 3, 4, 5};
    int var = 10;
    int *ip;
    ip = &var;
    printf("addr: %p\n", ip);
    printf("value: %d\n", *ip);
    printf("Change values\n");
    *ip = 11;
    printf("value: %d\n", *ip);
    int *pa;
    int value_at = 3;
    pa = &test_array[value_at];
    printf("value_at %d: %d\n", value_at, *pa);
    char s[] = "Hello World!";
    printf("Length of %s: %d\n", s, MS_strlen(s));
    printf("trying other func\n");
    printf("Length of %s, %d\n", s, MS_strlen_2(s));
    int x;
    int y;
    int *ip1 = &x;
    *ip1 = 12;
    int *ip2 = &y;
    printf("Value of ip2: %d\n", (*ip2 = *ip1));
    char string1[] = "Hello World!";
    char string2[] = "Hello World Again!";

    printf("string1: %s\n", string1);
    printf("string2: %s\n", string2);

    MS_strcpy(string1, string2);

    printf("strcpy, now string1: %s\n", string1);
}

int MS_strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
    n++;
    return n;
}

int MS_strlen_2(char *s)
{
    char *p = s;

    while (*p != '\0')
    p++;
    return p - s;
}

void MS_strcpy(char *s, char *t)
{
    while ((*s++ = *t++))
    ;
}



