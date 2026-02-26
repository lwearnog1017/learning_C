#include <stdio.h>

 /* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating-point version */
 /*
 int main()
 {
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; 
    upper = 300;
    step = 20;
    fahr = lower;
    printf("%3c%6s\n", 'F', "placeholder");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
*/

int main() {
    for (int f = 300; f >= 0; f -= 20) 
        printf("%3d %6.1f\n", f, (5.0/9.0)*(f-32));
}

