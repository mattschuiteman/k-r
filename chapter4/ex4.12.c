#include <stdio.h>
/* printd: print n in decimal */

void itoaMS(int n, char s[]);

int main() {
    int n = -100;
    char s[1000];
    itoaMS(n, s);
    printf("%s\n",s);
}
 
void itoaMS(int n, char s[])
{
    static int index = 0;
    if (n < 0) {
	 s[index++] = '-';
	 n = -n;
     }

     if (n / 10)
     {
	 itoaMS(n / 10, s);
	 s[index++] = (n % 10 + '0');
     }
     else {
	 s[index++] = (n + '0');
     }
     s[index] = '\0';
 }
