# include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    float c, f, lower, upper;
    int step;
    lower = LOWER;
    upper = UPPER;
    step = STEP;
    c = lower;

    printf("%3c %6c\n", 'C', 'F');
    while (c <= upper) {
        f = (9.0/5) * c + 32;
        printf("%3.1f %6.1f\n", c, f);
        c += step;
    }
}