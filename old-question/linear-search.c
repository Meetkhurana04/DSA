#include<stdio.h>
#include<stdlib.h>

int sort(int A[], int Lb, int Ub, int key);

int main() {
    int A[] = {5, 10, 20, 8, 50};
    int Lb = 0;
    //printf("%d", Lb); //5

    // Finding length of the array
    int x = sizeof(A) / sizeof(A[0]);
    int Ub = x - 1; // Correcting index
    //printf(" %d \n ", Ub); //50
    int key =10;
    sort(A, Lb, Ub, key);
    return 0;
}

int sort(int A[], int Lb, int Ub, int key) {
    int k;
    for (k = Lb; k <= Ub; k++) {
        if (A[k] == key) {
            printf("We found at index: %d\n", k);
            return k;
        }
    }
    return -1;
}
// me glti kya kr rha tha m a(0) se leke a (x-1) tk chla rha tha
// jo first element ki value 5 se leke 50 tk chla rha tha isliye 10 dhundne pe 6 answer derha tha
// kyuki 10 second element h ;
