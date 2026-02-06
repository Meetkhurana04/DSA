#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    vector<int> nums = {1,1,2,2,4};
    int xori = 0;

    for (int i = 0 ; i < nums.size() ; i ++){
        xori = xori^nums[i];

    }

    cout << xori ;

    return 0 ;
}