#include <stdio.h>

// copy and replace multi-blanks with single blank
/*
int main() {
    int c = getchar();
    while (c != EOF) {
        putchar(c);
        if (c == ' ') {
            while (c == ' ')
                c = getchar();
        } else {
            c = getchar();
        }
    }
}
*/
// better approach
int main() {

    int lastc, c;
    lastc = 'a';
    while ((c = getchar()) != EOF) {
        if (lastc != ' ' || c != ' ')
            putchar((lastc = c));
    }
    
}

// copy and replace each tab by \t, backspace by \b, and backslash by "\\"
/*
int main () {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}
*/