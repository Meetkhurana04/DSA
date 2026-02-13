#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main() {

    //using two pointer
    vector<int> nums = {2,3,5,3,1,1};
    int right = 0;
    int left = 0 ;
    int sam = nums[0];
    int n = nums.size();
    int k = 5; 
    int maxx = 0 ; 


    while(right<n){
        while(sam > k){
            // aap aage nikl gye ho trim kro 
            sam = sam - nums[left]; 
            left++;
             
        }
        if(sam==k){
            maxx = max(maxx,right-left+1);
        }
        right++;
        if(right<n){
        sam = sam + nums[right];
        }
    }

    cout << "output : " << maxx ;
}