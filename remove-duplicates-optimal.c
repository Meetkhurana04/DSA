#include <stdio.h>
#include <conio.h>

int main() {

    int nums[] ={0,1,2,2,3,0,4,2};
    int n = sizeof nums/sizeof nums[0];
    int val = 2;
    int k = 0 ;
    for (int i =0 ; i<n;i++){

       if(nums[i]!=val){
        nums[k]=nums[i];
        k++;
       }
    }
    n = k ; 

    for(int i = 0 ; i < n ; i++){
        printf("%d",nums[i]);
    }
}