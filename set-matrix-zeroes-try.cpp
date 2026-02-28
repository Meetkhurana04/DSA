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

vector<vector<int>> meet(3, vector<int>(3));

i = 0;
j = 0 ;
for(auto row : m){
     j = 0;
    for(auto val : row){
        meet[i][j] = i*10 + j;   // ya jo pattern chaho
        j++;
    }
    i++;
}
// i j store krliya h mene ab me chahta hu ki i j ko as a matrix ke form me print kru but ho hi nhi rha 
// 00 01 02
// 10 11 12
// 20 21 22
cout << "meet" << endl ;
for(auto row : meet){
    for(auto val : row){
        cout << val << "   ";
    }
    cout << endl ;
}

cout << "222222" << endl ;


// ek new array bnani h ya matrix bnani h jo origianl se leke print kre and desired jgh pe 0 kr e
vector<vector<int>> a = m ;
i = 0 ;
j = 0 ;

// i want to ki mer 0 11 pe h toh uske corrospondance 0 hojaye where i m workng
for(auto &val : a){
    j = 0;
    for(auto &row : val){
        if(i == 1 || j == 1){
            row = 0;
        }
        
        j++;
    }
    i++;
}

// & lgana jrui h inorder to deep dive or copy pe work na ho

for(auto val : a){
    for(auto row : val){
        cout << row << " ";
    }
    cout << endl;
}

}