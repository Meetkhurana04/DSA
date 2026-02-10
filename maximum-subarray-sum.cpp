#include<stdio.h>
#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main() {

    vector<int> nums = {2,3,5};
     
    int maxx = 0 ;
    int k = 5;
    for(int i = 0 ; i < nums.size() ; i++){
        int sum = 0 ;
        for(int j = i ; j < nums.size() ; j++){
            sum = sum + nums[j];
            if(sum==k){
            maxx = max(maxx,j-i+1); 
            }
        }
    }
    cout << "output : ";
    cout << maxx ;
}