#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 


int main() {
    vector<int> arr = {1,1,1,2,3,4};
    int k = 3 ; 
    int j = 1 ;
    int i = 0 ; 
    int sum =0 ; 
    int count = 0 ; 
    while(i<arr.size()){
        sum=sum+arr[j];
        if(sum==k){
            count++;
        }
        if(sum>k){
            if(i==j){
                sum = 0 ; 
                i++ ; 
                j++ ; 
            }
            sum = sum - arr[i];
            i++;
            
        }
        if(sum<k){
            j++;
        }
       
        if(i==j){
            i++;
            j++;

        }
    }
    









}