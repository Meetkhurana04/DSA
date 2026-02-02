#include<iostream>
#include<vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> n1 = {2,2,3,4,5};
    vector<int> n2 = {2,2,3,4,5};

    int i = 0;
    int j = 0;
    vector<int> ans ;


    while(i<n1.size() && j<n2.size()){
        if(n1[i]==n2[j]){
            ans.push_back(n1[i]);
            int val = n1[i];
            while(i<n1.size() && n1[i] == val) i++;
            while(j<n2.size() && n2[j] == val) j++;

        }
        if(n1[i]<n2[j]){
            //mtlb bda h i ++
            i++;
        }
        // if(n1[i]>n2[j]){
        else{
            j++;
        }
    }

    for (auto x: ans){
        cout << x << "" ;
    }

}