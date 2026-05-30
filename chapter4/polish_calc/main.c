#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found

// stack_ops.c commands
int getop(char []);
void push(double);
double pop(void);

void print_stack(void);
void duplicate_stack(void);
void swap_top_two(void);
void clear_stack(void);

// reverse Polish notation
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
	switch (type) {
	case NUMBER:
	    push(atof(s));
	    break;
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
	    if (op2 != 0.0)
	    push((pop() / op2));
	    else
	    printf("Error: zero divisor\n");
	    break;
	case '%':
	    op2 = pop();
	    if (op2 != 0.0)
	    push(fmod(pop(), op2));
	    else
	    printf("Error: zero divisor\n");
	    break;
	case '\n':
	    break;
	case 'p':
	    print_stack();
	    break;
	case 'd':
	    duplicate_stack();
	    break;
	case 's':
	    swap_top_two();
	    break;
	case 'c':
	    clear_stack();
	    break;
	default:
	    printf("Error: unknown command %s\n", s);
	    break;
	}
    }
    return 0;
}

	    
	
