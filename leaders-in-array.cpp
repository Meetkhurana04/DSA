#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 


int main() { 

    vector<int> arr = {10 ,22,12,3,0,6};
    int n = arr.size() ; 
    vector<int> ans;
    for (int i = 0 ; i < n ; i ++){
        bool sf = true ; 
        // maanke chlo aage saare chote h 
        for(int j = i + 1; j < n ; j ++){
            if(arr[j]>arr[i]){
                sf = false;
            // glti se ek bhi bda aagya toh false hojaye
            }
        }
        if(sf==true){ // kya saare chote h ?
            ans.push_back(arr[i]);
        }
    }

    for(int it : ans){
        cout << it << " ";
    }

}