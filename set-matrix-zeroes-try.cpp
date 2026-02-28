#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() { 
vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
for(auto row : m){
    for(auto val : row){
        cout << val << " ";
    }
    cout << endl ;
}

// humne print kar liya saare ko mtlb ek ek pe jaana agya kya ab hum 0 nikal skte h 
// 
int i = 0 ; 
int j = 0 ; 
cout << "trial" << endl;
vector<vector<int>> ans ; 
for(auto row : m){
     j = 0 ; 
    for(auto val : row){
        if(val == 0){
            // agar me i j store krlu toh merko bta chl jaayega 
            ans.push_back({i,j});   
        } 
        j++;
    }
    i++;
}


for(auto it : ans){
    cout << it[0] << " " << it[1] << endl;
}
i=0 ;
j= 0 ;
// ab merko jake har i = 1 or j = 1 pe 0 krna h 
vector<vector<int>> meet ; 
for(auto row : m){
    int j = 0 ; 
    for(auto val : row){
            // agar me i j store krlu toh merko bta chl jaayega 
            meet.push_back({i,j});   
        j++;
    }
    i++;
}

cout << "meet" << endl ;
for(auto row : meet){
    for(auto val : row){
        cout << val << " ";
    }
    cout << endl ;
}

}