#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main() { 

    vector<int> arr = {0,0,0,1,1,1,0,0,2,2};

    // dutch wale method se kr rhe honge 
    int n = arr.size();
    int high = n-1 ; 
    int low = 0 ; 
    int mid = 0 ; 

    while(mid<=high){
    
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;

        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;

        }
    }

}