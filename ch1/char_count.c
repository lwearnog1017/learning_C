# include <stdio.h>

// if there is text stream, then getchar() executes and moves on.
// if there is no text stream, program freezes on getchar().

/*
int main() {
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
*/

// testing if 'A' and 'B' are actually ints
/*
int main() {
    printf("%d", 'A'+'B');
}
*/

// counting lines, blanks, tabs
int main() {
    int count = 0;
    int c = getchar();
    while (c != EOF) {
        if (c == '\n' || c == ' ' || c == '\t')
            ++count;
        c = getchar();
    }
    printf("%d\n", count);
}