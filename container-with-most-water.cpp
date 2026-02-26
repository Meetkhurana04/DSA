#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ; 

int main() { 

    vector<int> arr = {2,3,4,5,18,17,6};
    int n = arr.size() ; 

    // rule h area nikalne ka ki 
    // min nikalna h  dono kisi height ka or index wale se minus krdena h 
    // for eg here in optimal array 
    // min ( 8,7) = 7 7*7 optimal 

    //  brute force likhne ka try krte h phle
    int maxx = 0 ; 
    int smaxx = 0 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j ++){
            if(i<j){
            maxx = min(arr[i],arr[j]) * (j-i); 
            }
            smaxx = max(maxx,smaxx);
        }
    }
    cout << smaxx;


}