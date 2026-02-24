#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 


int main() { 
    vector<int> arr = {10 ,22,12,3,0,6};
    int n = arr.size() ; 
    vector<int> ans ;
    // ab hume ulta chlna h bda jha max = 0 rkh rhe honge 
    // fir at har point max nikalenge 
    // maanlo 6 agya max push jese hi max mila
    // then piche aaye dekha kya max se bda h nhi okay then again 3 kya max se bda h nhi move 
    // fir piche aaye 12 dekha max se bda h then hn max mila h push krdoo 
    // then asie hi krenge or sb ko push krte chlegne 
    int max = -1 ;
    for(int i = n-1; i>=0; i--){
        if(arr[i]>max){
            max = arr[i];
            ans.push_back(max);
        }
    }

    for(auto it : ans){
        cout << it << " " ; 
    }

}