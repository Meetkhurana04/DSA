#include<conio.h>
#include<stdio.h>
#include<stdbool.h>
bool check(int* nums, int numsSize) {
int next;
int prev;





// isme koi brute optimal nhi h ek hi method h 
for(int  i = 1 ; i < numsSize ; i ++ ){
    if(nums[i] >= nums[i-1] ){

    }
    else {
        return false;
    }

}
return true ; 
}

int main(){
    int nums[] = {3,4,5,1,2};
    int numsSize = sizeof nums / sizeof nums[0];

    printf("%d", check(nums , numsSize));
}