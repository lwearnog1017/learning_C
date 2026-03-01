/* Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before 
the n-th column of input. Make sure your program does something
intelligent with very long lines, and if there are no blanks or
tabs before the specified column. */

#include <stdio.h>
#define MAXCOL 10
#define MAXWORD 200
#define TABSTOP 4
#define IN 0
#define OUT 1
#define FINISHED 400

void printword(char word[], int wordlen);
// void getword(char word[]);

int col = 0;

int main() {
    char word[MAXWORD];
    int c, status = 2, wordidx = 0, done = 0;

    while (done != FINISHED) {
        c = getchar();
        if (c == ' ' || c == '\t' || c == '\n' || c == EOF) {
            if (status == IN) {
                printword(word, wordidx);
            }
            if (c == ' ')
                ++col;
            else if (c == '\t')
                col += TABSTOP - (col % TABSTOP);
            else
                col = 0;
            if (c == EOF)
                done = FINISHED;
            else
                putchar(c);
            status = OUT;
        } else {
            if (status == OUT)
                wordidx = 0;
            word[wordidx++] = c;
            status = IN;
            ++col;
        }
    }
}

void printword(char word[], int wordlen) {
    word[wordlen] = '\0';
    if (col > MAXCOL && wordlen <= MAXCOL) {
        printf("\n%s", word);
        col = wordlen;
    } else if (wordlen > MAXCOL) {
        if (col - wordlen > 0)
            putchar('\n');
        col = 0;
        for (int i = 0; i < wordlen; ++col) {
            //printf("%d", col);
            if (col == MAXCOL) {
                putchar('\n');
                col = 0;
            }
            putchar(word[i++]);
        }
    } else {
        printf("%s", word);
    }
}

/* gets all chars from after the end of the previous "word", including blank space
void getword(char word[]) {
    for (int c, i = 0, start; (c = getchar()) != ' ' && c != '\t' && c != '\n'; i++) {
        word[i] = c;
    }
} */
