/*
Write a program to remove trailing blanks and tabs from 
each line of input, and to delete entirely blank lines.

APPROACH:


*/
#include <stdio.h>
#define MAXLINE 30
#define IP 0
#define DONE 1

int nextline(char line[], int maxline);
void removetrailing(char line[], int size);

int main() {

    /* run this loop until we hit a line that contains EOF. in that case if 
    the line had other characters before EOF we want to printf those chars + \n
    otherwise just print \n. to check if the line contains EOF, run*/
    char line[MAXLINE];
    int size;

    
    while ((size = nextline(line, MAXLINE)) != 0) {
        removetrailing(line, size);
        printf("%s\n", line);
    }
    

    /* Testing removetrailing()
    line[0] = '\t';
    line[1] = 'a';
    line[2] = 'b';
    line[3] = '\t';
    line[4] = '\n';

    removetrailing(line,5);
    printf("%s", line);
    */
    

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
    /*
    if (c=='\n')
        if (i == maxline-1)
            line[i-1] = c;
        else
            line[i++] = c;
    
    line[i] = 0;
    */

    if (c=='\n')
        line[len++] = '\n';
    
    return len;
}

void removetrailing(char line[], int size) {
    int i, begin, end, bprog, eprog, bitem, eitem, len;
    begin = 0;
    end = size - 1;
    bprog = eprog = IP;
    for (i = 0; i < size && (bprog == IP || eprog == IP); i++) {
        if (bprog == IP && (bitem = line[i]) != ' ' && bitem != '\t' && bitem != '\n') {
            bprog = DONE;
            begin = i;
        }
        if (eprog == IP && (eitem = line[end - i]) != ' ' && eitem != '\t' && eitem != '\n') {
            eprog = DONE;
            end = end - i;
        }
    }
    len = end - begin + 1;
    for (i = 0; i < len; i++) {
        line[i] = line[i + begin];
    }
    
    line[i] = '\0';
}

// DON"T HAVE TO KEEP TRACK OF END JUST KEEP TRACK OF LENGTH