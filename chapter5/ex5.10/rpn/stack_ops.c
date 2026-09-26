#include <stdio.h>

#define MAXVAL 100

int sp;
int val[MAXVAL];

void push(int value)
{
    if (sp < MAXVAL)
    val[sp++] = value;
    else
    printf("Stack is full. %d not pushed\n", value);
}

int pop()
{
    if (sp < 1)
    printf("No value in stack\n");
    else
    return val[--sp];

    return -1;
}

void print_stack()
{
    int spc = sp;
    printf("--- Top of Stack ---\n");
    while (spc >= 0)
    printf("%d\n", val[spc--]);
    printf("--- Bottom of Stack\n");
}



    
