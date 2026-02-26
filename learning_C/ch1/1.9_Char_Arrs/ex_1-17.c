/* Print all input lines longer than 80 chars.

MY APPROACH

int getline(char line[], int maxline) is going to return the size of the line
that the user just entered, and will return 0 if EOF and copy maxline-1 characters into line[].

this edit has been done with vim! 
*/

#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 10

int nextline(char line[], int maxline);

int main() {
    int size;
    char line[MAXLINE];

    while ((size = nextline(line, MAXLINE)) != 0) {
        if (size > THRESHOLD)
            printf("%s", line);
    }
}

// save the next line to a Chararacter Array, return the size of that line
int nextline(char line[], int maxline) {
    int c, i, len;
    i = len = 0;
    while((c = getchar()) != EOF && c != '\n') {
        if (i < maxline-2) 
            line[i++] = c;
        ++len;
    }

    if (c == '\n') {
        line[i++] = c;
        ++len;
    }

    line[i] = 0;

    return len;

}

