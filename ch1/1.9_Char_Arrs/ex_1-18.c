/*
Write a program to remove trailing blanks and tabs from 
each line of input, and to delete entirely blank lines.
*/
#include <stdio.h>
#define MAXLINE 100
#define IP 0
#define DONE 1

int nextline(char line[], int maxline);
void removetrailing(char line[], int size);

int main() {

    char line[MAXLINE];
    int size;

    
    while ((size = nextline(line, MAXLINE)) != 0) {
        removetrailing(line, size);
        if (line[0] != 0)
            printf("%s\n", line);
    }

}

// does not put the \0 character at the end
int nextline(char line[], int maxline) {
    int c, i, len = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < maxline-1){
            line[i] = c;
            ++len;
        }
    }

    if (c=='\n')
        line[len++] = '\n';
    
    return len;
}

void removetrailing(char line[], int size) {

    int begin = 0, end = size-1, c, len;

    for (int i = 0; i < size - 1 && ((c = line[i]) == ' ' || c == '\t' || c == '\n'); i++)
        begin++;
    
    for (int i = size-1; i > 0 && i > begin && ((c = line[i]) == ' ' || c == '\t' || c == '\n'); i--)
        end--;

    len = end - begin + 1;
    for (int i = 0; i < len; i++) {
        line[i] = line[i+begin];
    }

    line[len] = 0;
    if (line[0] == ' ' || line[0] == '\t' || line[0] == '\n')
        line[0] = 0;
}
