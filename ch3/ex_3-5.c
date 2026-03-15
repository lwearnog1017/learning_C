/* write the function itob(n,s,b) that converts the integer n into a
base b character representation in the string s. In particular, 
itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int n = 1234956789;
    char s[50];
    itob(n, s, 30);
    printf("%s", s);
}

// unsigned idea for handling INT_MIN is from gemini
void itob(int n, char s[], int b) {
    int i = 0, sign;
    unsigned un = n;
    unsigned d;

    if ((sign = n) < 0)
        un = -(unsigned)n;
    do {
        if ((d = un % b) > 9) {
            s[i++] = d - 10 + 'a';
        } else {
            s[i++] = d + '0';
        }
    } while ((un /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
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