#include <stdio.h>
#include <conio.h>

int main() {

    int nums[] ={0,1,2,2,3,0,4,2};
    int n = sizeof nums/sizeof nums[0];
    int val = 2;

    for (int i =0 ; i<n;i++){

        if(nums[i]==val){
            for(int j = i ; j<n-1;j++){
                nums[j]=nums[j+1];
                
            }
            i=i-1;
            n=n-1;
        }
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d",nums[i]);
    }
}