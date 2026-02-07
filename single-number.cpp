#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    vector<int> nums = {1,1,2,2,4};
    int xori = 0;
    cout << "Optimal" << endl;

    for (int i = 0 ; i < nums.size() ; i ++){
        xori = xori^nums[i];
    }
    cout << xori << endl;

    cout << "brute force " << endl;
    for(int i = 0 ; i < nums.size(); i++){
        int countt = 0 ; 
        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j]==nums[i]){
                countt ++;
            }
        
        }    

        
        if(countt == 1){
            cout << endl << "output : " <<  nums[i]  ;
            break;
    }
}

cout << endl << "via hashing" << endl;
// phle hum max nikalenge 
int maxx = 0 ;
for(int i = 0 ; i < nums.size(); i ++){
    maxx = max(nums[i],maxx);
}

int hash[maxx+1]={0};
// saare 0 kridye

for ( int i = 0 ; i < nums.size() ; i ++){
    hash[nums[i]]++;
}
for ( int i = 0 ; i < nums.size() ; i ++){
    if(hash[i]==1){
        cout << i ; 
        break ;
    }

    
}

cout << endl << "via nordered set or ordered set ";

// unorderd set lenge usme best case 0n h 

unordered_map<int, int> mp;

for(int i = 0 ; i < nums.size(); i ++){
    mp[nums[i]]++;
}

for(auto it :mp){
    if(it.second==1){
        cout << it.first ;
    }
}


    return 0 ;
}