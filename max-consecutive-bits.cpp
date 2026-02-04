#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){


    vector<int> arr = {0,1,0,1,1,1,1};
    int maxi=0;
        int cnti = 0;
        int maxo=0;
        int cnto = 0;
        
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i]==1){
                cnto = 0;
                cnti ++;
                maxi =max(maxi,cnti);
            }
            else{
                cnti = 0;
                cnto ++;
                maxo =max(maxo,cnto);
                
            }
            
        }
        
        if(maxo>maxi){
            cout << maxo;
        }
        else {
            cout << maxi;
        }

        return 0;

}