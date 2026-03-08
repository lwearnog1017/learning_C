/* Write a loop equivalent to the for loop above without using && or ||. */

/*
SOLUTION:

for (i = 0; i<lim-1; ++i) {
    if ((c = getchar()) == '\n') {
        break;
    }
    if (c == EOF) {
        break;
    }
    s[i] = c;
}
*/