#include <stdio.h>

int getSecondLargest(int *arr, int n) {
    // code here
    // brute force kya hoga 
    
    // sort kro or n-2 wala hoga
    // but what if saare hi same ho ya aise ho 1 7 7 7 7
    
    // better approach first pass largest nikalo
    // second pass -- > second largest nikaalo 
    
    //optimal apporach jb aap largest nikaal rhe ho tbhi second largest 
    //bhi nikaalte chlo 
 
    int largest = arr[0];
    int slargest = -1;
    int i;
    for ( i = 0 ; i < n ; i ++){
        if ( arr[i] > largest ){
            slargest = largest ;
            largest = arr[i];
        }
        if ( arr[i]< largest && arr[i]> slargest){
            slargest = arr[i];
        }
    }
    
    return slargest ;
    
}

int main () {
    int arr[]={1 ,3,4,7,7,5};
    int n = sizeof arr / sizeof arr[0];

    int x = getSecondLargest(arr , n);
    printf( "%d",x);
}
    
