/* Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before 
the n-th column of input. Make sure your program does something
intelligent with very long lines, and if there are no blanks or
tabs before the specified column. */

#include <stdio.h>
#define MAXCOL 70
#define MAXWORD 200
#define TABSTOP 4
#define IN 0
#define OUT 1

int main() {
    char word[MAXWORD];
    int c, col = 0, status = IN;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (c == ' ')
                ++col;
            else
                col += TABSTOP - (col % TABSTOP);
            status = OUT;
        } else {
            if (status == OUT) {

            }
        }
    }

}
