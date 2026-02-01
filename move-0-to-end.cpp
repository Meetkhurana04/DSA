#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 5, 0, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);   // arr ka size

    vector<int> temp(n);   // temp ko pehle se size diya
    int k = 0;

    // step 1: non-zero elements temp me daalna
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[k] = arr[i];
            k++;
        }
    }

    // step 2: jitne non-zero the utne arr me wapas
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
    // yeh sb bhardega jitne non zero the

    // step 3
    // filling of zero in the back
    // no.of non zero = k
    for (int i = k; i < n; i++) {
        arr[i] = 0;
    }

    // printing array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
