#include <stdio.h>
#include <math.h>
#include <stdlib.h>

# define MAXLINE 1000

int getlineKR(char s[], int lim);
double atoiMS(char s[]);
double atoiMSPlus(char s[]);

int main(void)
{
    int len;
    char line [MAXLINE];
    while ((len = getlineKR(line, MAXLINE)) > 0)
    {
	double scientific_number = atoiMSPlus(line);
	printf("%f\n", scientific_number);
    }
    
    return 0;
}

double atoiMS(char s[])
{
    int i;
    char num [MAXLINE];
    int j = 0;
    char exponent_char [MAXLINE];
    int k = 0;
    int signed_num = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
	if (s[i] == 'e')
	{
	    if (s[i + 1] == '-')
	    {
		signed_num = 1;
		++i;
	    }

	    ++i;
	    
	    while (s[i] != '\0')
	    exponent_char[k++] = s[i++];
		
	}
	else
	{
	    num[j++] = s[i];
	}
    }

    num[j] = '\0';
    exponent_char[k] = '\0';

    // convert numbers
    printf("num: %s\n", num);
    double mantissa = atof(num);
    int exponent = (signed_num == 1) ? -(atoi(exponent_char)) : atoi(exponent_char);
    printf("Mantissa: %f\n", mantissa);
    printf("Exponent: %d\n", exponent);
    return mantissa * pow(10, exponent);
}

double atoiMSPlus(char s[])
{
    double val = 0.0;
    double power = 1.0;
    int exponent = 0;
    int sign;
    int exp_sign;
    int i;

    // handle leading whitespace
    while (s[i] == ' ' || s[i] == '\t')
    i++;

    // handle sign
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    i++;

    // handle integer part
    while (s[i] >= '0' && s[i] <= '9')
    val = 10 * val + (s[i++] - '0');

    if (s[i] == '.')
    i++;

    // handle fractional part
    while (s[i] >= '0' && s[i] <= '9')
    {
	val = 10 * val + (s[i++] - '0');
	power *= 10;
    }

    val = sign * val / power;

    // handle exponent

    if (s[i] == 'e' || s[i] == 'E')
    {
	i++;

	// handle exponent sign
	exp_sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '-' || s[i] == '+')
	i++;

	while (s[i] >= '0' && s[i] <= '9')
	exponent = 10 * exponent + (s[i++] - '0');

	int e = exp_sign * exponent;

	while (e > 0)
	{
	    val *= 10;
	    e--;
	}
	while (e < 0)
	{
	    val /= 10;
	    e++;
	}
	
    }

    return val;
}

int getlineKR(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    {
	s[i++] = c;
    }
    
    if (c == '\n')
    {
	s[i++] = c;
    }
 
    s[i] = '\0';
    return i;
}

