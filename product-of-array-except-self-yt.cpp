#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() {

    vector<int> arr = {1 ,2 ,3, 4};
    int n = arr.size();

    
    for(int it:arr){
        cout << it << " ";
    }

    cout << endl << "brute force" << endl ;

    vector<int>ans(n,1);
    for(int i = 0 ; i < n ; i ++){
        // int prod = 1; 
        for(int j = 0 ; j < n ; j ++){
            if(j!=i){
                ans[i]=ans[i] * arr[j];
            }
        }
    }

    for(int it:ans){
        cout << it << " ";
    }

    cout << endl << "more better" << endl ;
    cout << "prefix" << endl;
 
    vector<int> pref (n,1);
    for(int i = 1 ; i < n ; i ++){
        // suffix sum nikalenge 
        pref[i]=arr[i-1]*pref[i-1];
    }
    for(int it:pref){
        cout << it << " ";
    }

    vector<int> suff(n,1);
    for(int i = n-2; i >=0 ; i--){
        suff[i] = suff[i+1] * arr[i+1];
    }

    cout << endl ;
    cout << "suffix" << endl;
    
    for(int it:suff){
        cout << it << " ";
    }

    cout << endl;

    // vector<int> ans(n,1);

    for(int i = 0 ; i < n; i ++){
        ans[i]=suff[i]*pref[i];
    }

    
    for(int it:ans){
        cout << it << " ";
    }

    
   
    ans.assign(n, 1);
    cout << endl << "most optimised" << endl ; 

    // phle array jisme prefi ans me hi store krenge 

    for(int i = 1 ; i < n ; i ++){
        ans[i] = ans[i-1] * arr[i-1];
    }
    // ab suffix 
    int suffix = 1 ; 
    for(int i = n-2 ; i >= 0 ; i--){
        suffix = suffix * arr[i+1];
        ans[i]*= suffix ; 
    }

    for(int it : ans){
        cout << it  << " "; 
    }
}