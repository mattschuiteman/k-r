#include <stdio.h>

void swap(int *px, int *py);

int main()
{
    int a = 5;
    int b = 6;

    printf("a: %d\n", a);
    printf("b: %d\n", b);

    swap(&a, &b);

    printf("a: %d\n", a);
    printf("b: %d\n", b);
}

void swap (int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

    
