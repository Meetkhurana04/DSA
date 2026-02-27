#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ; 

int main() { 

    vector<int> arr = {1,8,6,2,5,4,8,3,7};
                    // 0,1,2,3,4,5,6,7,8,
    int n = arr.size() ; 
    // jo chtoa h  use move krke fix kro or sum claculate kro 
    // jo chota h use move kro bde ko fix rkho  ; 
    // width toh km ho hi rhi h 
    // apka main motive h ki width jyada and hieght min me jyada gap na ho 
    // toh here humne width km ho hi rhi h but agar merko jo chota mil rha h use m move krke bda dhunde ki koshis krunga 
    // aise me almost saare shi combination check krlunga or max se fir unka max nikal lunga 
    // me kuch aisa solution nhi derha hounga ki ek hi baar me max de paau / mereko super max toh nikalna hi hoga
    int i = 0 ; 
    int j = n-1;
    int maxx = 0 ; 
    int smaxx = 0 ; 
    while(i!=j){
        maxx = min(arr[i],arr[j]) * (j-i); 
        smaxx = max(maxx,smaxx);
        if(arr[i]<arr[j]){
            i++;
        }
        else {
            j--;
        }

    }


    

    cout << smaxx ;



}