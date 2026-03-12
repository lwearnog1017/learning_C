/* Write a function setbits(x,p,n,y) that returns x with the n bits
that begin at position p set to the rightmost n bits of y, leaving 
the other bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    unsigned x, y, result, expected;

    x=0xAA;
    y=0x07;
    result = setbits(x, 4, 3, y);
    expected = 0xBE;
    printf("Test 1: %s (Result: 0x%X, Expected: 0x%X)\n", (result==expected) ? "PASS" : "FAIL", result, expected);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ~(~(~0 << n) << (p+1-n))) | ((~(~0 << n) & y) << (p+1-n));
}