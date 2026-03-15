/* In a two's complement number representation, our version of itoa
does not handle the largest negative number, that is, the value of n
equal to -2^(wordsize-1). Explain why not. Modify it to print that
value correctly, regardless of the machine on which it runs. */

/* If n is the largest negative number, we then negate n to become
positive, which is out of range due to the two's complement number repr.
That step makes it so that the rest of the code does not work. */

#include <stdio.h>
#include <limits.h>

void itoa2(int n, char s[]);
void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    int n = INT_MIN;
    char s[20] = {0};
    itoa2(n, s);
    printf("%s", s);
}

void itoa2(int n, char s[]) {
    int i, sign, ismin;
    ismin = n == INT_MIN;

    if ((sign = n) < 0) {
        if (ismin) n = INT_MAX;
        else n = -n;
    }
    i = 0;
    do {
        if (ismin && i == 0) {
            s[i++] = n % 10 + '1';
        } else {
            s[i++] = n % 10 + '0';
        }
    } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i = 0, j;
    for (j = 0; s[j++] != '\0';);
    j-=2;
    char l;

    if (s[j] == '\n')
        j--;
    while (j - i > 0) {
        l = s[i];
        s[i++] = s[j];
        s[j--] = l;
    }
}

void itoa(int n, char s[]) {
    int i, sign;
    
    if ((sign = n) < 0) n = -n;
    i=0;
    do {
        s[i++] = n%10+'0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}