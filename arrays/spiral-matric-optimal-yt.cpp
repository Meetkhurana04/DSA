#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 
int  main() {

        int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}} ;
        int n = sizeof(mat) / sizeof(mat[0]);
        int m = sizeof(mat[0]) / sizeof(mat[0][0]);
        int left = 0 , right = m - 1 ; 
        int top = 0 , bottom = n - 1 ; 
        vector<int> ans ; 
        // right
        while(top <= bottom && left <= right){
        for(int i = left ; i <=right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        // top to bottom jana h 
        for(int i = top ; i <= bottom ; i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top<=bottom){ // left check horha h but yeh nhi check horha ki is bottom exist or not 
        for(int i = right ; i >=left ; i--){
            ans.push_back(mat[bottom][i]);
        }
        bottom--;
        }
        // is wale me bottom cehck horha h but yeh nhi chekc horha ki is left still have elements 
        if(left<=right){
        for(int i = bottom ; i>=top;i-- ){
            ans.push_back(mat[i][left]);
        }
        left++;
        }
        // but yeh toh sirf one pass krega next pass ke liye 
        }
for(int i : ans){
    cout << i << " ";
}
        return 1;
}