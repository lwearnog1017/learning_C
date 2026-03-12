/* Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else. */

#include <stdio.h>

void lower(char s[]);

int main() {
    char s[] = "Hello, WOrlD";
    lower(s);
    printf("%s\n", s);
}

void lower(char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] - ('A' - 'a')) : s[i];
}