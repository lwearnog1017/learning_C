// Write a program ot print a histogram of the frequencies of different characters in its input.

#include <stdio.h>
#define NUMCHAR 128

int main() {

    char counts[NUMCHAR];
    int c, i, j, maxcount;

    for (i = 0; i < NUMCHAR; ++i)
        counts[i] = 0;

    while ((c = getchar()) != EOF)
        ++counts[c];

    maxcount = 0;

    for (i = 0; i < NUMCHAR; ++i)
        if (counts[i] > maxcount)
            maxcount = counts[i];

    for (i = maxcount; i > 0; --i) {
        printf("\n");
        for (j = 0; j < NUMCHAR; ++j)
            if (counts[j] >= i)
                printf("*  ");
            else if (counts[j] != 0)
                printf("   ");
    }

    printf("\n");

    for (i = 0; i < NUMCHAR; ++i)
        if (counts[i] != 0) {
            if (i == ' ')
                {printf("\\s ");}
            else if (i == '\n')
                {printf("\\n ");}
            else if (i == '\t')
                {printf("\\t ");}
            else
                {printf("%-3c", i);}
        }

}
