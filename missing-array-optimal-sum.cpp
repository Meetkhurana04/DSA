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
    cout << " hello ";
    cout << sum << endl; 

    cout << sum - xsum ;

    
}