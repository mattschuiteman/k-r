#include <stdio.h>

void reverse(char *s, char *r);

int main(void)
{
    char result[100];

    reverse("hello", result);
    printf("Test 1: \"%s\" (expected \"olleh\")\n", result);

    reverse("a", result);
    printf("Test 2: \"%s\" (expected \"a\")\n", result);

    reverse("", result);
    printf("Test 3: \"%s\" (expected \"\")\n", result);

    reverse("racecar", result);
    printf("Test 4: \"%s\" (expected \"racecar\")\n", result);

    reverse("abcdef", result);
    printf("Test 5: \"%s\" (expected \"fedcba\")\n", result);

    reverse("12345", result);
    printf("Test 6: \"%s\" (expected \"54321\")\n", result);

    reverse("Hello, world!", result);
    printf("Test 7: \"%s\" (expected \"!dlrow ,olleH\")\n", result);

    reverse("ab ba", result);
    printf("Test 8: \"%s\" (expected \"ab ba\")\n", result);

    return 0;
}

void reverse(char *s, char *t)
{
    char *begin_s;
    begin_s = s;
    
    while (*s++ != '\0')
    ;

    s--;

    while (s-- != begin_s)
    *t++ = *s;

    *t = '\0';
}
