/* Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[], int size);
int nextline(char line[], int maxline);

int main() {

    /* TESTING
    char s[7];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 'd';
    s[4] = 'e';
    s[5] = '\n';
    s[6] = '\0';

    reverse(s, 6);
    printf("%s", s);
    */

    char line[MAXLINE];
    int size;

    while((size = nextline(line, MAXLINE)) != 0) {
        reverse(line, size);
        printf("%s", line);
    }
}

// this implementation actually gets rid of \n if the length of the line is exactly maxline - 1
int nextline(char line[], int maxline) {
    int i, c;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
    
}

void reverse(char s[], int size) {
    int i = 0, j = size - 1;
    char l;

    if (s[j] == '\n')
        j--;
    while (j - i > 0) {
        l = s[i];
        s[i++] = s[j];
        s[j--] = l;
    }
}