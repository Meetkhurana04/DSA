#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3 };
    int n = arr.size() ;
    int summ = 0 ;
    int maxx = INT_MIN;

    for (int i = 0  ; i < n ; i ++){
        summ = summ + arr[i];
        maxx = max(maxx,summ);
        if(summ<0){
            summ=0;
        }
    }
    cout << "sum is " << summ ; 
}