#include<stdio.h>
#include<conio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax dac(int A[], int low, int high);

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int low = 0; //index no.
    int x = (sizeof(A) / sizeof(A[0]));
    int high = x - 1;

    struct MinMax minmax = dac(A, low, high);
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}

struct MinMax dac(int A[], int low, int high) {
    struct MinMax minmax;

    if (low == high) { // Base case: single element
        minmax.max = A[low];
        minmax.min = A[low];
    } 
    else if (low == high - 1) { // Base case: two elements
        if (A[low] > A[high]) {
            minmax.max = A[low];
            minmax.min = A[high];
        } else {
            minmax.max = A[high];
            minmax.min = A[low];
        }
    } 
    else { // More than two elements
        int mid = (low + high) / 2;
        struct MinMax lp = dac(A, low, mid);
        struct MinMax rp = dac(A, mid + 1, high);

        minmax.max = (lp.max > rp.max) ? lp.max : rp.max;
        minmax.min = (lp.min < rp.min) ? lp.min : rp.min;
    }

    return minmax;
}
