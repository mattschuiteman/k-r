#include <stdio.h>

int main(void) {
    double c, ct, cs, cn;
    while ((c = getchar()) != EOF) {
        if (c == '\t')      ++ct;
        else if (c == ' ')   ++cs;
        else if (c == '\n')  ++cn;
        else                  printf("");
    }
    printf("\nTABS: %.0f\nSPACES: %.0f\nNEWLINES: %.0f\n", ct, cs, cn);
    return 0;
}
