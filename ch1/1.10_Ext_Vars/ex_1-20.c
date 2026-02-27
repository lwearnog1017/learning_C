/* Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed
set of tab stops, say every n columns. Should n be a variable or a
symbolic parameter? */


#include <stdio.h>
#define TABSTOP 4

int i;

void untiltabstop();

int main() {
    extern int i;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            untiltabstop();
        else {
            putchar(c);
            i++;
            if (c == '\n')
                i = 0;
        }
    }
}

void untiltabstop() {
    extern int i;
    int numuntil = TABSTOP - i % TABSTOP;
    for (int j = 0; j < numuntil; j++) {
        putchar(' ');
        i++;
    }
}