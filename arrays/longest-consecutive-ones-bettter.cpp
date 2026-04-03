#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() {
    vector<int> arr = { 100 , 102 , 100 , 101 , 101 , 4 ,3 ,2 ,3 , 2 , 1 , 1, 1, 2};
    int n = arr.size() ; 

     if(arr.size() == 0){
        cout << 0;
        return 0;
    }

    sort(arr.begin() , arr.end());
// sorting hogyi ab hum krenge traverse
    int small = INT_MIN;
    int largest = 0 ; 
    int cnt = 0 ; 

    for(int i = 0 ; i < n ; i ++){
        if(arr[i]>small){
            // mtlb bda h fresh start kro 
            if(arr[i]-1==small){
                cnt = cnt + 1 ; 
            }
            
            else{
            cnt = 1 ; // sirf cnt hi reset hoga 
            }
            small = arr[i];
            largest = max (largest,cnt );

        }
        else if(arr[i]==small){
            // ignore 
            continue ; 
        }
        
    }

    cout << largest ;
}

// yeh mera handwritten code h accoriding to striver do if lgenge
// ek if arr[i]-1 == last smaller
// ek arr[i] ! = last smaller )

// == ki exactly likhne ki jrurat nhi h khud dekhhga kuch nhi h toh skip kr hi dega 
/// hume inhi dono ki likhni chaiye 