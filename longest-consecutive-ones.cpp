#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

bool ls (vector<int> arr , int num){
    int n = arr.size() ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==num){
            return true
        }
    }
    return false ;
}
// milega toh true ajayega
// nhi milega toh false dega

int main() { 
    vector<int> arr = {100,4,200,1,3,2};
    int n = arr.size() ; 
    // ek number pkdenge fir us number ke liye uska next dekhenge 
    // next dhundhenge agar next mil rh ahoga toh aage bdhenge 
    // 100 ko pkda via first loop 100 and next 101 dhundunga
    // you only check next number because of break 
    int len = 1;
    int maxl = 1 ; 
    for(int i = 0 ; i < n ; i++){
        int x=arr[i];
        len = 1 ; 
        // merko kya krna h 100 ke liye 101 dhundna h 
        // agar 101 milta h toh 102 dhundna h 
       while(ls(arr,x+1)==true){
             // but yeh tb tk chlega jb tk condition true h 
             // phle ke liye dekhega ki true h 
             // jb tk chlega jb tk true h 
             x = x+1 ; // next wala dhundho 
             len = len + 1 ; 
             maxl = max(len , maxl);
       }
       
    }
    cout << "hello" << endl;
    cout << maxl << endl;
    for(auto it : arr){
        cout << it ; 
    }

}