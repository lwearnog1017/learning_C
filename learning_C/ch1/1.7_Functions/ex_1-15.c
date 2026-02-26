// rewrite temp conversion, but use func for conversion

#include <stdio.h>

float convert(int fahr);

int main() {
    for (int f = 0; f <= 300; f += 20) 
        printf("%3d %6.1f\n", f, convert(f));
    return 0;
}

float convert(int fahr) {
    return (5/9.0)*(fahr - 32);
}
