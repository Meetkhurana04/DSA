#include<stdio.h>
#include<conio.h>


int largest(int arr[], int n) {
    // Code Here
    // brute force jo m soch parha hu woh ki yeh hoga ki 
    // m phle sort kru but kaafi bda hojayega 
    // m sidha optimal pe aaata hu 
    int largest = arr[0];
    int i ;
    for( i = 1 ; i < n ;  i ++){
        if ( largest < arr[i]){
            largest = arr[i];
        }
    }
    return largest ;
}

int main() {
    int arr[] = {1,2,3,4,5,90};
    int n = sizeof arr / sizeof arr[0]; 
    printf("%d",largest(arr,n));

    return 0;
}