#include <stdio.h>
#include <string.h>

#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}

int main()
{

    int a = 5;
    int b = 4;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    swap(int, a, b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0;
}
