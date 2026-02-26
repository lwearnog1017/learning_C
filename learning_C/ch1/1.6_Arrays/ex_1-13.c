// print a histogram of the lengths of words in its input
#include <stdio.h>
#define MAXLEN 30

int main()
{
    int counts[MAXLEN];
    int i, j, c, len, maxcount;

    for (i = 0; i < MAXLEN; ++i)
        counts[i] = 0;
    
    len = 0;

    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && len != 0) {
            ++counts[len];
            len = 0;
        } else
            ++len;
    }

    // a little bit sneaky but it works
    ++counts[len];

    // horizontal version
    /*
    for (i = 1; i < MAXLEN; ++i) {
        printf("\n%2d   ", i);
        for (j = 0; j < counts[i]; ++j)
            printf("*");
    }

    printf("\n");
    */

    // vertical version
    maxcount = 0;
    for (i = 1; i < MAXLEN; ++i)
        if (counts[i] > maxcount)
            maxcount = counts[i];

    printf("\n\n\n");
    
    for (i = 0; i < maxcount; ++i) {
        for (j = 1; j < MAXLEN; ++j)
            if (maxcount - counts[j] <= i)
                printf("*  ");
            else
                printf("   ");
        printf("\n");
    }

    for (i = 1; i < MAXLEN; ++i)
        printf("%-2d ", i);
    
    printf("\n");
}
