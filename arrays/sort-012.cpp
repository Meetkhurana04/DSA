#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main(){


    vector<int> arr = {1,1,1,0,0,2};
    // sort krna h 
    // brute force hoga ki me koi si sorting lgadu jisme sbse achi o logn hi rhegi 

    // chlo achi baat h aage chlte h 
    //  better apporach 
    //  first count each occurencte of count 0 1 2 
    //  and then overwrite
    int c0 = 0 ;
    int c1 = 0;
    int c2 = 0 ;
    int n = arr.size(); 

    for(int i = 0 ; i < n ; i ++){
        if(arr[i]==0){
            c0++;
        }
        else if(arr[i]==1){
            c1++;
        }
        else {
            c2++;
        }
    }
   for(int i = 0 ; i < c0 ; i ++){
    arr[i]=0;
   }
    for(int i = c0 ; i < c1+c0 ; i ++){
    arr[i]=1;
   }
    for(int i = c1+c0 ; i < n ; i ++){
    arr[i]=2;
   }

   for(int it : arr ){
    cout << it;
   }

}