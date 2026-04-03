#include <stdio.h>

// Function to merge two sorted subarrays into one sorted array
// First subarray is arr[l..m], second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Calculate size of left subarray
    int n2 = r - m;     // Calculate size of right subarray

    // Create temporary arrays to hold the elements of left and right subarrays
    int L[n1], R[n2];

    // Copy data from arr[] to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i]; // l + i isliye kiya kyuki l+i futere me help krega any kind of subarrays dealing 
        
        // Copy elements from left subarray
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; // Copy elements from right subarray

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of left subarray
    j = 0; // Initial index of right subarraykk 
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        // Compare elements of L[] and R[], and store the smaller element in arr[]
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Store element from left subarray
            i++;
        } else {
            arr[k] = R[j]; // Store element from right subarray
            j++;
        }
        k++; // Move to next position in merged subarray
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point to divide the array into two halves
        int m = l + (r - l) / 2;

        // Call mergeSort() for the left half
        mergeSort(arr, l, m);
        // Call mergeSort() for the right half
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]); // Print each element of the array
    printf("\n"); // Print a newline after printing all elements
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Initialize an array
    int arr_size = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array

    printf("Given array is \n");
    printArray(arr, arr_size); // Print the original array

    mergeSort(arr, 0, arr_size - 1); // Sort the array using merge sort

    printf("\nSorted array is \n");
    printArray(arr, arr_size); // Print the sorted array

    return 0; // Indicate successful execution
}

