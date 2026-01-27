#include <stdio.h>
#include <conio.h>

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize ;
    if (k == 0) return;
    // phle temp me store kardete h 
    int temp[k]; //store 3 hi hounga counting 0 se hogi 0 1 2 
    
    for (int i = 0 ; i < k ; i++){
        temp[i] = nums[numsSize - k + i] ;
    } 

    // shifting kr lete h 
    for ( int i = numsSize - k -1 ; i >= 0 ; i-- ){
        //a [0] ko a[3 ]
        nums[i+k] = nums[i];
    }

    for (int i = 0 ; i <k ; i++){
        nums[i] = temp[i];
    }

   
    
    for ( int i = 0 ; i < numsSize ; i++){
        printf("%d ", nums[i]);
       

    }
    
}

int main() {

    int nums[] = {1,2,3,4,5,6,7};
    int k = 3;
    int x =  sizeof nums / sizeof nums[0] ;
    rotate(nums , x , k );

}