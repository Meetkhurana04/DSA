#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

void selection_sort(int start ,int n, int smallest , int smallest_n,int arr[]){
   for(int i =  start ; i < n ; i++){
  if(smallest > arr[i]) {
      smallest = arr[i];// kya intmax  bda h 13 se yes bda h toh smallest 13 hojayege 
      smallest_n = i ;  //1
    }
    //second iteration pe kya hoga kya 13>46 no 13>24 no 13>52 13>9 yes 
    // smallest 9 aayega i = 5
  }
  // ab smallest milgya ab swap krwate h 
  // 9<13 yes toh 
    swap(arr[start], arr[smallest_n]);
  // arr[0], arr[5] change hojayenge apas me ; 
    cout << "smallest:" << smallest << endl ;
}
int main() {
  int arr[] = {13, 46, 24, 52, 20, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  // cout << n ; 
  
  int start = 0 ; 
  for(int i =0; i < n ; i++){
  int smallest = INT_MAX ; 
  int smallest_n = start;
  selection_sort(start , n, smallest , smallest_n,arr);
  
  for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
  }
  start++;
  cout << endl ;
}
  // merko phla dhund ke dega and use apni sahi jgh pe lgayega asie mereko har ke liye krna h 
}

