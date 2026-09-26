#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "stack_ops.c"

#define MAX_ARG 10

int is_sign(char value);

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
	// verify
	int j = 0;
	int num = 0;
	int found_digit = 0;
	while (argv[i][j] != '\0')
	{
	    if (isdigit(argv[i][j]))
	    {
		found_digit = 1;
		num = num * 10 + (argv[i][j] - '0');
		j++;
	    }

	    else
	    break;
	}

	if (found_digit == 1)
	{
	    push(num);
	    continue;
	}

	// is it a sign?
	if (is_sign(argv[i][0]) == 1)
	{
	    double op2;
	    // do sign things
	    switch(argv[i][0]) {
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() * pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 == 0)
		{
		    printf("Cannot divide by 0\n");
		    return -1;
		}
		push(pop() / op2);
		break;
	    case '%':
		op2 = pop();
		push(fmod(pop(), op2));
		break;
	    default:
		printf("Unknown operator\n");
		return -1;
	    }
	}
	else
	{
	    printf("Invalid character found in argument %d\n", i);
	    return -1;
	}
    }
    print_stack();
    return 0;
}


int is_sign(char value)
{
    if (value == '+' || value == '-' || value == '/' || value == '*' || value == '%')
    return 1;
    else
    return 0;
}

