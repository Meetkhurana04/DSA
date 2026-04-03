#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 3 ;
    cout << "before rotated" << endl ;
 int arr[n][n] = {{1,2,3},{4,5,6},{7,8,9}};
 for (int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
        cout<<arr[i][j] << " ";
    }
    cout << endl ;
 }   

 cout << endl ;
 int newarr[n][n] = {{0}};
   
 int l = 0 ; 
 int m = 0 ;
    for(int j = n-1 ; j>=0 ; j--){
        for(int i = 0 ; i < n ; i ++){
            newarr[l][m] = arr[j][i] ; 
            l=l+1;
            if(l>n-1){
                l=0;
                m++;
            }
            if(m>n-1){
                break ;
            }
        }
    }

for (int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
        cout<<newarr[i][j] << " ";
    }
    cout << endl ;
 }
 

}
