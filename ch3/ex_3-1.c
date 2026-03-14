/* Write a version of binary search with only one test inside the loop
and measure the difference in run-time. */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int test[6] = {1,3,5,9,13,15};
    printf("%d", binsearch(9, test, 6));
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high - 1) {
        mid = (low + high) / 2;
        if (x < v[mid]) high = mid-1;
        else low = mid;
    }
    mid = (low + high) / 2;
    if (x == v[mid]) return mid;
    else if (x == v[mid + 1]) return mid + 1;
    else return -1;
}