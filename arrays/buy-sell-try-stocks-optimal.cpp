#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    
    int n = arr.size();
    int profit = 0 ; 
    int mini = arr[0] ; // manlete h phla hi minnimunmh iske nect wale se chl rhe hogne 

    for(int i = 1 ; i < n ; i ++){
        int cost = arr[i]-mini; 
        // humne nikal liya kitne me pda h 
        profit = max(profit , cost);
        // profit bde wala bhi pkd liya or saare se compare krliya 
        //  ab chote ko pdk lete h mini kko bhi 
        mini = min(arr[i], mini);


        // agar i or j ko pdna h toh maxor mini ki jgh if statement lgadenge and tb i or j ki vlaue store kr rheonge 
    }

    cout << "max profit is " << profit ; 


}

// merko aage move rkna h pichla minimum pkd ke 