#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    /*
     * VALUES FROM STANDARD HEADERS
     */

    printf("=== VALUES FROM <limits.h> ===\n\n");

    printf("signed char:      %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:    0 to %u\n\n", UCHAR_MAX);

    printf("signed short:     %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:   0 to %u\n\n", USHRT_MAX);

    printf("signed int:       %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:     0 to %u\n\n", UINT_MAX);

    printf("signed long:      %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:    0 to %lu\n\n", ULONG_MAX);


    printf("=== VALUES FROM <float.h> ===\n\n");

    printf("float:            %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double:           %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double:      %Le to %Le\n\n", LDBL_MIN, LDBL_MAX);


    /*
     * DIRECT COMPUTATION
     */

    printf("=== DIRECT COMPUTATION ===\n\n");

    /* unsigned maximums using bitwise NOT */

    unsigned char uchar_max = (unsigned char) ~0;
    unsigned short ushort_max = (unsigned short) ~0;
    unsigned int uint_max = (unsigned int) ~0;
    unsigned long ulong_max = (unsigned long) ~0;

    printf("computed unsigned char max:    %u\n", uchar_max);
    printf("computed unsigned short max:   %u\n", ushort_max);
    printf("computed unsigned int max:     %u\n", uint_max);
    printf("computed unsigned long max:    %lu\n\n", ulong_max);


    /*
     * Signed ranges from unsigned ranges
     *
     * Example:
     * unsigned char max = 255
     * signed char max = 127
     * signed char min = -128
     */

    signed char schar_max = (signed char)(uchar_max >> 1);
    signed char schar_min = -schar_max - 1;

    short short_max = (short)(ushort_max >> 1);
    short short_min = -short_max - 1;

    int int_max = (int)(uint_max >> 1);
    int int_min = -int_max - 1;

    long long_max = (long)(ulong_max >> 1);
    long long_min = -long_max - 1;

    printf("computed signed char:      %d to %d\n",
           schar_min, schar_max);

    printf("computed signed short:     %d to %d\n",
           short_min, short_max);

    printf("computed signed int:       %d to %d\n",
           int_min, int_max);

    printf("computed signed long:      %ld to %ld\n",
           long_min, long_max);

    return 0;
}
