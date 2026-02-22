#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ; 

int  main() { 


    vector<int> arr = {1,3,2,4};
    int ind = -1 ; 

    int n = arr.size(); 

    for(int i= n-1 ; i > 0 ; i --){

        // breakpoint dhundna h 
        if(arr[i]<arr[i+1]){
            // agar aisa h toh isse hi pkdna h 

            ind = i ; 
        }

        if(ind == - 1 ){
            reverse(arr.begin() , arr.end());
            // for(int it: arr){
            //     cout << it << " " ;
            // }
            break;
        }
        // breakkpoint milgya ab next number dhundn ah jo bda ho 

        for(int i = n -1 ; i > ind ; i --){
            if(arr[i]>arr[ind]);
            // kuch aisa dhund h jo just bda ho jaya nhi 
            swap(arr[i],arr[ind]);
            break ;
        }

        // ab swap hogya h  next me kya kra h ki just ek number bda chaiye toh 
        // hum aage wale ko plt denge 

        // 1 2 3
        // 1 3 2 krenge toh yeh hogya sort  krna ya kind of say reverse krna 

        reverse(arr.begin() + ind + 1, arr.end());


    }

    cout << endl ;
    for(auto it : arr){
        cout << it << " " ;
    }

}