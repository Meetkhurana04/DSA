#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main(){
    int nums1[] = {1,2,3,0,0,0};
    int n = 3;
    int nums2[] = {2,5,6};
    int m = 3;
     int i = m-1;
        int j = n-1;
        int k = n+ m -1 ;
        while(j >= 0){
            if (i >= 0 && nums1[i] > nums2[j]){
                nums1[k]=nums1[i];
                i--; 
            }
            else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }


        for ( int i = 0 ; i < n+m ; i++){
            cout << nums1[i];
        }


}