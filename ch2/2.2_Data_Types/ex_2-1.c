/* Write a program to determine the ranges of char, short, int, and
long variables, both and signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you
compute them: determine the ranges of the various floating-point types. */

// UNFINISHED

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define COL_WIDTH 40

int main() {
    printf("%-7s%-40s%-40s\n\n", "Type", "Min", "Max");
    printf("%-7s%-40d%-40d\n", "SCHAR", SCHAR_MIN, SCHAR_MAX);
    printf("%-7s%-40d%-40d\n", "UCHAR", 0, UCHAR_MAX);
    printf("%-7s%-40d%-40d\n", "SHRT", SHRT_MIN, SHRT_MAX);
    printf("%-7s%-40d%-40d\n", "USHRT", 0, USHRT_MAX);
    printf("%-7s%-40d%-40d\n", "INT", INT_MIN, INT_MAX);
    printf("%-7s%-40d%-40u\n", "UINT", 0, UINT_MAX);
    printf("%-7s%-40ld%-40ld\n", "LONG", LONG_MIN, LONG_MAX);
    printf("%-7s%-40d%-40lu\n", "ULONG", 0, ULONG_MAX);
    
    signed char schar_min = 0;
    while (schar_min > (signed char) (schar_min-1)) {
        schar_min = (signed char) (schar_min - 1);
    }
    printf("%d", schar_min);

    signed char schar_max = 0;
    while (schar_max < (signed char) (schar_max+1)) {
        schar_max = (signed char) (schar_max+1);
    }
    printf("%d", schar_max);
}