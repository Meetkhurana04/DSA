#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main() {
    
    vector<int> arr = {1 ,1, 2, 1, 3, 5, 1};
    int x = arr.size();
    
    for (int i = 0 ; i < x ; i ++){
        int count = 0 ;
        for (int j = i ; j < x; j ++){
            if(arr[i]==arr[j]){
                count ++ ;
            }
        }
        if(count > x/2){
            cout << arr[i];
        }
    }

    cout << "better try via hashing" << endl ;
    unordered_map<int,int> mp = {};

    for (int i = 0 ; i < x; i ++){
        mp[arr[i]]=mp[arr[i]]+1;

    }
    for (auto it : mp) {
    if (it.second > x/2) {
        cout << it.first << endl;
        break;
    }
}



    // yeh brute force h output bhi shi dehr h abut bhot faltu chl rha h 
    // mtlb aage walo ko bhi kyu check krna 
    // but yeh kr skte h j = i ki aap apne aage walo ka hi kruo check piche walo ka na kro 
    // kyuki piche wala agar hoga toh voh aapko count karke aa hi rha hoga 
}





// class Solution {
//   public:
//     int majorityElement(vector<int>& arr) {
//         // code here
//           int x = arr.size();
    
//     for (int i = 0 ; i < x ; i ++){
//         int count = 0 ;
//         for (int j = i ; j < x; j ++){
//             if(arr[i]==arr[j]){
//                 count ++ ;
//             }
//         }
//         if(count > x/2){
//             return arr[i];
//         }
//     }
    
//     return -1;
//     }
// };  code chl rha h brute force h saare testcases pe chlega but issue yeh h ki time limit exceed horhi h isme 