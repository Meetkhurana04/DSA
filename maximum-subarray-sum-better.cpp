#include<stdio.h>
#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main() {

    

    // chlo remind krte h better apporach kya thi woh thi dynamic programming pe 
    // jisme hum reverse enginerring krte teh and reverse engineering ke waqt hum phle pure array ka one by one 
    // sum nikaal rhe hote the and if hume bta chlta tha ki koi aisa sum h jo hum minus krde toh humara sum aajye
    // for eg huamra sum h 6 
    // and hum iterate krte huye 9 tk aagye h and by mapint hume bta h ki 9-6 exist krta h 3
    // toh wha se lkee yha tk ka sum humara desired sum hoga 
    // unorderd set use krskte h jo ki o(n*1) one deta h but agar kaafi collisoin hone lge toh 
    // yeh hi chij o (n * n) nsquare bn jayega jo ki bura hoga ordered set jbki o(n(logm)) krta h at worst scenario
    // isme toh hum mapping use krenge
    unordered_map<int, int> mp;
    int k= 5 ;
    vector<int> nums = {2,3,5,3,1,1};
    auto summ = 0 ; 
    int len = 0 ;
    int maxx = 0;
    for(int i = 0 ; i < nums.size(); i ++){
        summ = summ + nums[i];
        if(summ == k ){
            maxx = max(maxx, i + 1);
        }
        if(mp.find(summ-k) != mp.end()){
            len = i - mp[summ-k];
            // Agar 7 prefix sum pehle index 1 pe mila tha, toh matlab next line se 
            maxx = max(maxx,len);
        }
        if(mp.find(summ) == mp.end()){
            // gar ye prefix pehli baar aa raha hai tabhi store karo kyuki isse hi bda wala mil rha hoga iske baad jo bhi 
            // milega chota hi hoga 
    mp[summ] = i;
}

    }

    cout << "output : " << maxx << endl ; 
}
 