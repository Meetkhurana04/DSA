#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n = arr.size();
    int el ;
    int count = 0; 

    for(int i = 0 ; i < n ; i ++){
        if(count==0){
            el=arr[i];
            count = 1 ; 
        }
        else if(el==arr[i]){
            count+=1;
        }
        else{
            count --;
        }
    }

    cout << el << endl;
    count = 0 ;
    for(int it : arr){
         
        if(el == it){
            count ++;
        }
        
    }

    cout << el << endl;
    cout << count << endl;

    if(count > n/2){
        cout << el << " is the majority element" << endl;

    }
    
}