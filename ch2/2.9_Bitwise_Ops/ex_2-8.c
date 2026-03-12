/* Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions. */

#include <stdio.h>
#define NUMBITS 32

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned rightrot(unsigned x, int n);

int main() {
    unsigned x, y;

    x = 0xfffffffc;
    printf("%x", rightrot(x, 2));
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ~(~(~0 << n) << (p+1-n))) | ((~(~0 << n) & y) << (p+1-n));
}

unsigned rightrot(unsigned x, int n) {
    return setbits(x >> n, NUMBITS - 1, n, x);
}
