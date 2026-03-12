/* Write a function invert(x,p,n) that returns x with the n bits that
begin at position p inverted, leaving the others unchanged.*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main() {
    unsigned x, y, result, expected;

    x=0156;
    printf("%o", invert(x, 3, 3));
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ~(~(~0 << n) << (p+1-n))) | ((~(~0 << n) & y) << (p+1-n));
}

unsigned invert(unsigned x, int p, int n) {
    return setbits(x, p, n, ~(x >> (p+1-n)));
}