#include<conio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() { 

 // array ko arrange knra h on the basis of negative and positive 
//  ek negative ek poitive 

//but int he variety 1 here negative or positive are same 
// and length of given array is alway negative 
 vector<int> arr = {1,2,-4,-5};
 int n = arr.size();


 // brute force me kya hog aphle chhhat lenge 
 vector<int> pos , neg;
 for(int i = 0 ; i < n; i++){
    if(arr[i]<0){
    neg.push_back(arr[i]);
    }
    else{
    pos.push_back(arr[i]);
    }
 } // o(N)
 // ab ek temp array me sort kr de 
 for(int i =0 ; i < n/2 ; i++){
    arr[2*i]=pos[i];
    arr[2*i + 1]=neg[i];
 }

 // 0(n)
cout << "brute force " << endl ;
for(auto it : arr){
    cout << it  << " " ;
}

cout << endl ;


// brute force hogyaa 

// extra space toh h do chote do chote array arhe le rha h do 

// pcihele wali ki time compleccity h 0(n) + 0(n/2);
// sc 0(n) ; 
// but hume ab optimise krna h jisme hum sc ko toh km nhi krskte h but tc 
// ka n/2 htaskte h 

// arr[] = [ 3 ,1 ,-2,-5,2 ,-4]

 vector<int> ar = {1,2,-4,-5};
  n = ar.size();
 vector<int> ans = {} ; 

 int index = 0 ;
 for(int i = 0 ; i < n ; i ++){
   if(ar[i]>0){
      // mtlb positive h 
      ans[2*i] = ar[i];
   }
   else{
      ans[2*i + 1] = ar[i];
   }
 }
   cout << " approach " << endl ;
   for(auto it : ans){
      cout << it ;
   }

 




}