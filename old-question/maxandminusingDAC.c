#include<stdio.h>
#include<conio.h>

// Declaration of a structure named MinMax to hold the minimum and maximum values
struct MinMax {
    int min;
    int max;
    //structure kya krta h ek custom datatyple bna detas h which can bold any type of different kind of values;
};

// Declaration of the recursive function dac, which will find the minimum and maximum values in an array
struct MinMax dac(int A[], int low, int high); // It indicates that the function dac will return a value of type struct MinMax.

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int low = 0; // index no.
    int x = (sizeof(A) / sizeof(A[0]));
    int high = x - 1;

    // Calling the dac function to find the minimum and maximum values
    struct MinMax minmax = dac(A, low, high);

    // Printing the results
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}

// Definition of the dac function
struct MinMax dac(int A[], int low, int high) {
    struct MinMax minmax; // Declaring a variable of type MinMax to hold the results

    // Base case: If there is only one element in the array
    if (low == high) { 
        minmax.max = A[low]; //minmax.max kya h aao decode kre
        // minmax name h ; . access krne keliye ; humne uska max access kiya
        
         // Set the maximum and minimum values to the single element 
        minmax.min = A[low];
    } 
    // Base case: If there are two elements in the array
    else if (low == high - 1) { 
        // Compare the two elements and set the maximum and minimum accordingly
        if (A[low] > A[high]) {
            minmax.max = A[low];
            minmax.min = A[high];
        } else {
            minmax.max = A[high];
            minmax.min = A[low];
        }
        
    } 
    // Recursive case: If there are more than two elements in the array
    else { 
        int mid = (low + high) / 2; // Calculate the midpoint of the array
        // Recursively find the minimum and maximum values in the left and right halves of the array
        struct MinMax lp = dac(A, low, mid);
        struct MinMax rp = dac(A, mid + 1, high);
        // humne struct ke do new parts bnalye jinse hum ab min max alalg access krenge

        // Update the minimum and maximum values based on the results from the left and right halves
        minmax.max = (lp.max > rp.max) ? lp.max : rp.max;
        minmax.min = (lp.min < rp.min) ? lp.min : rp.min;

//         Condition: lp.max > rp.max
// This condition checks if the value of lp.max is greater than the value of rp.max.
// Value if True: lp.max
// If the condition is true, lp.max is assigned to minmax.max.
// Value if False: rp.max
// If the condition is false, rp.max is assigned to minmax.max
//     
 }

    // Return the minimum and maximum values found in the array
    return minmax;
}
