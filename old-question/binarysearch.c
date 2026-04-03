
// ek a sorted ascending order me array leelana h 
//mid nikalna h'
// mid == x  ko nikalna base condition agar mid==x h toh return x
// mid>x toh left me krna h'
// mid<x h toh right me krna h
#include<stdio.h>
#include<conio.h>
int bs(int A[],int low, int high , int k,int mid);
int main(){
    int A[]={1,2,3,4,5};
    int low = 0; //index no.
    int x = (sizeof (A)/sizeof (A[0]));
    int high = x;
    int k=3;
    int mid=low+high/2;// sbse phle wale bde ka mid nikalenge

    //calling me int or yeh array h use btana jrurui nhih 
    int result = bs(A,low,high,k,mid);
    if (result != -1) {
        printf("Element %d found at index %d\n", k, result);
    } else {
        printf("Element %d not found\n", k);
    }
return 0;

}
    
int bs(int A[],int low ,int high, int k,int mid){
while(A[mid]!=k & low<=high){
    if(k<A[mid]){
        high=mid-1;
    }
    if(k>A[mid]){
        low=mid+1;
    }// in dono condition ki wjh se divide hojayeggaa
    mid=low+high/2; //ab then in dono divivde ka mid nikaloo
// then ye upr jayegaaa check  krega A[mid] khi k ke equal toh nhi mtlb khi hme mil toh mhi gyaa
// or yeh bhi  check krega khi high bda toh nhi nikal gya high<low agar aisa h mtlb hume nhi mila element 
}
if(A[mid]==k){
    return mid;
}
else{
    return -1;
}
}
//workinggggggggg
// Q thy we use mid-1 and mid+1 instead of mid ;
// The amended code includes `mid` in the new range when updating `high` and `low`,
// potentially causing `mid` to deviate from the true middle of the remaining range.
// This can lead to infinite loops if `mid` fails to move closer to `low` or `high`.
// To avoid this, adjustments ensuring the range shrinks appropriately,
// like `mid - 1` or `mid + 1`, should be made based on the comparison of `k` with `A[mid]`.
//  Otherwise, the functionality risks breaking, 
// resulting in potential infinite loops or incorrect search results.