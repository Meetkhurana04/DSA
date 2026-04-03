#include<bits/stdc++.h>
#include<stdio.h>
using namespace std ; 

int main() {

    // tc 0(n)
    // sc 0(n)


 vector<int> ar = {1,2,-4,-5};
 int n = ar.size();
 vector<int> ans(n) ; 
 cout << "meet " << endl;

 int pi = 0 ;
 int ni =  1; 
 for(int i = 0 ; i < n ; i ++){
   if(ar[i]>0){
      // mtlb positive h 
      ans[pi] = ar[i];
      pi+=2;
   }
   else{
      ans[ni] = ar[i];
      ni+=2;
   }
 }
   cout << "approach " << endl ;
   for(auto it : ans){
      cout << it << " ";
   }
}