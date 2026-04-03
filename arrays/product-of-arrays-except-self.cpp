#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() {
    vector <int> arr = { 1 ,2 ,3 ,4};
    
    int n = arr.size();
    vector <int> ans(n);
    int mult = 1;
    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i]!=arr[j]){
                mult = mult * arr[j];
            } 
        }
        if(mult == 1){
            arr[i] == arr[i];
        }
        else{
        ans[i]=mult;
        mult = 1 ; 
        }
    }

    for(auto it : ans){
        cout << it << " ";
    }

    cout << endl << "optimal way se krte h " << endl;
    mult = 1 ;
    for (int i = 0 ; i < n ; i ++){
        // mult nikaleng ovverall array ka
        mult = arr[i] * mult ;

    }

    cout << mult << endl;
    
     for (int i = 0 ; i < n ; i ++){
        // mult nikaleng ovverall array ka
        int x = mult / arr[i];
        arr[i] = x ;

    }

    for(int it : arr){
        cout << it << " ";
    }

    cout << endl << "new method" << endl ;

    // yeh wala optimal un testcases pe fial horha hoga jha 0 honge
    // toh hum yhe nhi use krenge hum ek or method 2n wala use kren
    vector<int> a(n) ;
// vector <int> arr = { 1 ,2 ,3 ,4};
    
    for(int i = 0 ; i < n ; i ++){
        int li = 1 ; 
        li = li * arr[i]; 
        a[i]=li ;
       
    }

    for(auto it : a){
        cout << it << " "; 
    }

    // left side ka nikalenge phle 
    
}