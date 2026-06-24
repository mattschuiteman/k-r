#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
	val[sp++] = f;
    }

    else
    {
	printf("Error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
	return val[--sp];
    }
    else {
	printf("Error: stack empty\n");
	return 0.0;
    }
}

void print_stack(void)
{
    int i = sp - 1;
    printf("---- Top of Stack ----\n");

    for (i = sp - 1; i >= 0; i--)
    {
	printf("%g\n", val[i]);
    }

    printf("--- Bottom of Stack ---\n");
}

void duplicate_stack(void)
{
    if (sp < 1)
    {
	printf("Error: stack empty\n");
	return;
    }

    else
    {
	push(val[sp - 1]);
    }
}

void swap_top_two(void)
{
    if (sp < 2)
    {
	printf("Error: stack needs at least two values to swap.\n");
    }

    int top = sp - 1;
    double placeholder = val[top - 1];
    val[top - 1] = val[top];
    val[top] = placeholder;
}

void clear_stack(void)
{
    sp = 0;
}
