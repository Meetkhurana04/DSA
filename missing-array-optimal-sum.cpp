#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {

    vector<int> x = {3,0,1};
    cout << x.size() << endl; // 3 output derha h 
    // n natural number ;
    auto n = x.size();

    auto sum = n*(n+1)/2;
 
    int xsum = 0;
    for(int it : x){
        xsum = xsum + it;

    }
    cout << xsum ;
    cout << " sum of n natural number approach ";
    cout << sum << endl; 
    cout << "final ans : ";
    cout << sum - xsum ;


    // xor
    // wala bhi rty krte h 

    int xor1 = 0 ;
    int xor2 = 0 ;
    int sz = x.size() - 1;

    for ( int i = 0 ; i < sz; i++){
        xor1 = xor1^x[i];
        xor2 = xor2^(i+1);
        

    }
    xor2 = xor2^sz;
    cout << endl;
    cout << "xor new approach " << endl;
    auto k = xor2 ^ xor1;
    cout << k;

    sz = x.size() + 1;
    // hashing wala trika
    // hashing me hum ek array bnate h jo 0 se intialise horha hoga
    cout << endl << "hashing new approach";
    int hash[sz]={0}; // sz = x.size() -1 ; 
    // x huamra vector h 
    // x top pe define h 
    // vector<int> x = {3,0,1};
    // jonsa miss hoga woh 0 rh jayega 
    for (int i = 0 ; i < sz ; i ++){
        hash[x[i]]=1;
    }

    for(int i=0;i<sz;i++){
        if(hash[i]==0){
            cout << endl << "we found : " << i;  
            break ;
        }

    }
    
}

