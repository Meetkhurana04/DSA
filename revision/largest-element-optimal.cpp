#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() {
 int arr[] = {10, 5, 8};
 int n = 3 ;
 int l = INT_MIN;
 int sl = INT_MIN; 
 for(int i = 0 ; i < n ; i++){
  if(l<arr[i]){
    sl=l;
    l = arr[i];
  }
  else if(arr[i]<l && arr[i]>sl){
    sl = arr[i];
  }

// yeh code un testcase ke liye best h jisme phle pe nhi milta but ; for the scenario jsim first me hi largest miljaayega usme yeh work nhi krega 
 }
 cout << l ; 
 cout << endl ;
 cout << sl ;

}