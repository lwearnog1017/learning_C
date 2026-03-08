/* Write the function any(s1, s2), which returns the first location in
the string s1 where any character from the string s2 occurs, or -1 if 
s1 contains no characters from s2. */

#include <stdio.h>

int contains(char s[], char c);
int any(char s1[], char s2[]);

int main() {
    char s1[10] = "Hi there!";
    char s2[10] = "aeou";

    printf("%d", any(s1, s2));
}

int contains(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) return 1;
    }
    return 0;
}

int any(char s1[], char s2[]) {
    int i = 0;
    for (; s1[i] != '\0' && !contains(s2, s1[i]); i++);
    if (s1[i] == '\0') return -1;
    else return i;
}