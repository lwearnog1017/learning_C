/* Write an alternate version of squeeze(s1, s2) that deletes each
character in s1 that matches any character in the string s2. */

#include <stdio.h>

void squeeze(char s1[], char s2[]);
int contains(char s[], char c);



int main() {
    char s1[100] = "The quick brown fox jumps over the lazy dog.";
    char s2[10] = "aeiou";

    squeeze(s1, s2);
    printf("%s", s1);
}

void squeeze(char s1[], char s2[]) {
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!contains(s2, s1[i])) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int contains(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) return 1;
    }
    return 0;
}
