#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = { -100, -90, 1, 2, 3};
    int n = arr.size();

    // isme sirf do hi scenario bn rhe honge ek scenario ki
    // first sort kro 
    // ke last ke three bde  ho toh sbse bda denge 
    // and first ke two mtlb negative ke
    sort(arr.begin() , arr.end());
    int sum1 = arr[n-3] *arr[n-2] * arr[n-1] ;
    int sum2 = arr[0] * arr[1] * arr[n-1] ;
    sum1 = max(sum1, sum2 );
    cout << sum1 ; 


}
