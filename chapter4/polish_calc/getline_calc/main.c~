#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define VARIABLE 'a' // signal that variable was found

double vars[26];
int lastvar;

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
	printf("Type: %d \n", type);
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
	case 'P':
	    print_stack();
	    break;
	case 'D':
	    duplicate_stack();
	    break;
	case 'W':
	    swap_top_two();
	    break;
	case 'C':
	    clear_stack();
	    break;
	case 'E':
	    push(exp(pop()));
	    break;
	case 'S':
	    push(sin(pop()));
	    break;
	case 'O':
	    op2 = pop();
	    push(pow(pop(), op2));
	    break;
	case VARIABLE:
	    lastvar = s[0] - VARIABLE;
	    push(vars[lastvar]);
	    break;
	case '=':
	    pop();
	    vars[lastvar] = pop();
	    break;
        default:
	    printf("Error: unknown command %s\n", s);
	    break;
	}
    }
    return 0;
}
