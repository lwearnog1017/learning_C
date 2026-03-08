/* Write a program to check a C program for rudimentary syntax 
errors like unbalanced parantheses, brackets and braces. Don't forget
about quotes, both single and double, escape sequences, & comments. */

#include <stdio.h>

#define OK 0
#define ERROR 1

#define INSQUOTE 0
#define INDQUOTE 1
#define OUT 2
#define INSLCOMM 3
#define INMLCOMM 4

#define MAXSTACK 1000

int size = 0;

int modifystackandstate(char stack[], char curr);

int main() {
    int c, prev = 0, state = OUT;
    char stack[MAXSTACK];

    while ((c = getchar()) != EOF) {
        if (state == OUT && prev == '/' && c == '/')
            state = INSLCOMM;
        else if (state == INSLCOMM && prev == '\n')
            state = OUT;
        else if (state == OUT && prev == '/' && c == '*') {
            state = INMLCOMM;
            c = getchar();
        } else if (state == INMLCOMM && prev == '*' && c == '/') {
            state = OUT;
        } else if (state == OUT && c == '\'') {
            state = INSQUOTE;
        } else if (state == OUT && c == '"') {
            state = INDQUOTE;
        } else if (state == INSQUOTE && prev != '\\' && c == '\'') {
            state = OUT;
        } else if (state == INDQUOTE && prev != '\\' && c == '"') {
            state = OUT;
        }

        if (state == OUT) {
            if (c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}') {
                if (modifystackandstate(stack, c) == OK) {}
                else {
                    printf("The program is invalid.");
                    return 0;
                }
            }
        }

        if ((state == INSQUOTE || state == INDQUOTE) && prev == '\\' && c == '\\') {
            prev = 'a';
        } else {
            prev = c;
        }
    }

    if ((state == OUT || state == INSLCOMM) && size == 0) printf("The program is valid.");
    else printf("The program is invalid.");
}

int modifystackandstate(char stack[], char curr) {
    if (size == 0 || curr == '(' || curr == '[' || curr == '{') {
        stack[size++] = curr;
        return OK;
    } else if (stack[size - 1] == '(') {
        if (curr == ')') {
            --size;
            return OK;
        } else return ERROR;
    } else if (stack[size - 1] == '[') {
        if (curr == ']') {
            --size;
            return OK;
        } else return ERROR;
    } else {
        if (curr == '}') {
            --size;
            return OK;
        } else return ERROR;
    }
}