/* Write a program to remove all comments from a C progarm.
Don't forget to handle quoted strings and character constants
properly. C comments do not nest. */

#include <stdio.h>

#define INSQUOTE 0
#define INDQUOTE 1
#define OUT 2
#define INSLCOMM 3
#define INMLCOMM 4


int main() {

    int c, prev = 0, state = OUT;
    while ((c = getchar()) != EOF) {
  
        if (state == OUT && prev == '/' && c == '/')
            state = INSLCOMM;
        else if (state == INSLCOMM && prev == '\n') {
            state = OUT;
        }
        else if (state == OUT && prev == '/' && c == '*')
            state = INMLCOMM;
        else if (state == INMLCOMM && prev == '*' && c == '/') {
            state = OUT;
            c = getchar();
            prev = c;
            c = getchar();
        }
        else if (state == OUT && c == '\'') {
            state = INSQUOTE;
            putchar(prev);
            prev = c;
            c = getchar();
        }
        else if (state == OUT && c == '"') {
            state = INDQUOTE;
            putchar(prev);
            prev = c;
            c = getchar();
        }
        else if (state == INSQUOTE && prev != '\\' && c == '\'') {
            state = OUT;
            putchar(prev);
            prev = c;
            c = getchar();
        }
        else if (state == INDQUOTE && prev != '\\' && c == '"') {
            state = OUT;
            putchar(prev);
            prev = c;
            c = getchar();
        }
        
        if ((state == OUT || state == INSQUOTE || state == INDQUOTE) && prev != 0) {
            putchar(prev);
        }

        prev = c;
    }

    putchar(prev);
}