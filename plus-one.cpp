#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    vector<int> digits = {1,1,2,2,9};
    int x = digits[digits.size()-1] + 1;
    if (x<10){
        digits[digits.size()-1]=x;
    }
    else{
        digits[digits.size()-1]=x/10; //10/10 = 0 
        digits.push_back(x%10); // 10%10 = 1
    }

     for (int i = 0 ; i < digits.size() ; i ++){
        cout << digits[i];
    }

    
}