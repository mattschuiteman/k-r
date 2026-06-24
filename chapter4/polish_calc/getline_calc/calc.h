#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define VARIABLE 'a' // signal that variable was found
#define MAXLINE 1000

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

int getlineMS(char s[], int);
