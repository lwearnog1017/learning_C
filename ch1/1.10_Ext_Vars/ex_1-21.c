/* Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use 
the same tab stops as for detab. When either a tab or a single blank
would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define TABSTOP 4
#define WASBLANK 0
#define WASCHAR 1

// UNFINISHED
int main()
{
    int i, c, cb, nt, ns, was;

    for (i = 0; (c = getchar()) != EOF; i++) {
        if (c == ' ' || c == '\t') {
            was = WASBLANK;
        }
        else if (was == WASBLANK) {
            cb += TABSTOP;
        }
        else if (cb != 0) {
            nt = cb / TABSTOP;
        }
    }
}