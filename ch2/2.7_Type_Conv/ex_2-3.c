/* Write the function htoi(s), which converts a string of hexadecimal
digits (including an optional 0x or 0X) into its equivalent integer 
value. The allowable digits are 0 through 9, a through f, and A
through F.*/

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);
int getnumval(char c);

// TESTS
int main() {
    char hex1[10] = "0x345dE";
    char hex2[10] = "7f3d9da";

    int a = 0x345dE;

    printf("%-10d%-10d", htoi(hex1), htoi(hex2));

}

int htoi(char s[]) {
    int intval = 0, i = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;
    for (; s[i] != '\0'; i++) {
        intval = intval * 16 + getnumval(s[i]);
    }
    return intval;
}

// c must be a digit or a-f or A-F
int getnumval(char c) {
    if (isdigit(c)) return c - '0';
    else return tolower(c) - 'a' + 10;
}
