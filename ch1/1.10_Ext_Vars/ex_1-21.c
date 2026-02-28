/* Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use 
the same tab stops as for detab. When either a tab or a single blank
would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TABSTOP 4

int main()
{
    int i = 0, c = getchar();

    while (c != EOF) {
        if (c == ' ' || c == '\t') {
            int end = i;

            while (c != EOF && (c == ' ' || c == '\t')) {
                if (c == ' ')
                    end++;
                else   
                    end += (TABSTOP - (end % TABSTOP));
                c = getchar();
            }

            for (; i / TABSTOP != end / TABSTOP; i += (TABSTOP - (i % TABSTOP))) 
                putchar('\t');
            for (; i < end; i++)
                putchar(' ');
        } else {
            putchar(c);
            if (c == '\n')
                i = 0;
            else
                i++;
            c = getchar();

        }
    }

}