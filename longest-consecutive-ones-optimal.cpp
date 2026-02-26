#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 


int main()  {

    vector<int> arr = { 100 , 102 , 100 , 101 , 101 , 4 ,3 ,2 ,3 , 2 , 1 , 1, 1, 2};
    int n = arr.size() ; 
    // int count = 0 ; 
    int mcount = 0 ; 

     if(arr.size() == 0){
        cout << 0;
        return 0;
    }

    // ab hume set me dalna h ek ke element 
    unordered_set<int> us ; 
    for(int it : arr){
        us.insert(it);
    }

    for (int it : us){
        // iterate in the set  isi tirke se kar skta h 
        if(us.find(it-1)==us.end()){ // this mean if not found you have to return end 
            // agar chota nhi h tbhi hum aage jaana h 
            int cnt = 1 ; 
            int x = it ; 
            while(us.find(x+1)!=us.end()){ // this mean jb tk mil rha h toh return true derh ahoga 
                x=x+1;
                cnt = cnt + 1;
                 // mtlb hume bda milta jarha h hum cnt bdhate jaayenge 
                //  and x ko bhi 

            }
            mcount = max(mcount , cnt);
        }
    }

    cout << mcount ;
}


// 1️⃣ us.find(key) == us.end()

// 👉 Iska matlab: key container me nahi mila

// find(key) agar element nahi milta to end() return karta hai.

// To agar find(key) == end() true hai, iska matlab element present nahi hai.

// Example:

// if(us.find(key) == us.end()) {
//     cout << "Key not found";
// }
// 2️⃣ us.find(key) != us.end()

// 👉 Iska matlab: key container me mil gaya

// Agar element mil jata hai to find() us element ka iterator return karta hai.

// Wo end() ke barabar nahi hoga.

// Example:

// if(us.find(key) != us.end()) {
//     cout << "Key found";
// }