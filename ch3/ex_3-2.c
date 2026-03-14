/* Write a function escape(s,t) that converts characters like newline
and tab into visible escape sequences like \n and \t as it copies the 
string t to s. Use a switch. Write a function for the other direction
as well, converting escape sequences into the real characters. */

#include <limits.h>
#include <stdio.h>

void escapefd(char s[], char t[]);
void escapebd(char s[], char t[]);

int main() {
    char t1[6] = "hel\n\t";
    char s1[10];
    
    escapefd(s1, t1);
    printf("%s\n", s1);

    char t2[20] = "he\\nl\\tlo\\poopoo";
    char s2[20];

    escapebd(s2, t2);
    printf("%s\n", s2);
}

void escapefd(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}

void escapebd(char s[], char t[]) {
    /* if c = \ then check the next character. if it is n or t, then add */
    int i = 0, j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                switch (t[i+1]) {
                    case 'n':
                        s[j++] = '\n';
                        i++;
                        break;
                    case 't':
                        s[j++] = '\t';
                        i++;
                        break;
                    default:
                        s[j++] = '\\';
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}