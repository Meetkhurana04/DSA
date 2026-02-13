#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // nums = [2,7,11,15], target = 9
    vector<int> nums = {3,2,4};
    int k = 6 ;;
    unordered_map<int,int> mp ;
    int arr[2] ;

    for (int i = 0 ; i < nums.size(); i++){
        mp[nums[i]]=i;

    }

    for(int i = 0 ;i< nums.size() ; i++){
        if(mp.find(k-nums[i]) != mp.end()){
            arr[1]=i;
            // cout << i << endl;
            // cout << mp[k-nums[i]];
            arr[0]=mp[k-nums[i]];
            
        }
    }

    for(auto it : arr){
        cout << it ;
    }
}